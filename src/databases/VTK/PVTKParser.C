/*****************************************************************************
*
* Copyright (c) 2000 - 2019, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

// ************************************************************************* //
//                               PVTKParser.C                                //
// ************************************************************************* //

#include <PVTKParser.h>
#include <vtkXMLDataElement.h>
#include <vtkXMLDataParser.h>

#include <FileFunctions.h>

#include <string>
#include <vector>

using std::string;
using std::vector;


// ****************************************************************************
//  Method: PVTKParser constructor
//
//  Programmer: Kathleen Biagas
//  Creation:   September 21, 2017
//
// ****************************************************************************

PVTKParser::PVTKParser() : fileName(), baseDir(), pieceName(),
  pieceFileNames(), pieceExtent(), pieceExtents(), errorMessage()
{
    parser = NULL;
    hasExtents = false;
}


// ****************************************************************************
//  Method: PVTKParser destructor
//
//  Programmer: Kathleen Biagas
//  Creation:   September 21, 2017
//
// ****************************************************************************

PVTKParser::~PVTKParser()
{
    pieceFileNames.clear();
    pieceExtents.clear();
    pieceExtent.clear();
    if (parser)
    {
        parser->Delete();
        parser = NULL;
    }
}


// ****************************************************************************
//  Method: PVTKParser::SetFileName
//
//  Purpose:
//    Set's the file that will be parsed.
//
//  Arguments:
//    fn        The file name.
//
//  Programmer: Kathleen Biagas
//  Creation:   September 21, 2017
//
// ****************************************************************************

void
PVTKParser::SetFileName(const char *fn)
{
    fileName = fn;
    baseDir = FileFunctions::Dirname(fileName);
}


// ****************************************************************************
//  Method: PVTKParser::GetPieceFileName
//
//  Return:
//      The file name for the piece at given index.
//
//  Arguments:
//      index   The piece index.
//
//  Programmer: Kathleen Biagas
//  Creation:   September 21, 2017
//
//  Modifications:
//   Cyrus Harrison, Wed Apr 17 12:48:31 PDT 2019
//   Change valid check, size_t is unsigned, no need to check for lower bound
//
// ****************************************************************************

string &
PVTKParser::GetPieceFileName(size_t index)
{
    pieceName.clear();
    // index is unsigned, it will always be >=0
    if( index < pieceFileNames.size() )
    {
        pieceName = pieceFileNames[index];
    }
    return pieceName;
}


// ****************************************************************************
//  Method: PVTKParser::GetPieceExtent
//
//  Return:
//      The extents for the piece at given index.
//
//  Arguments:
//      index   The piece index.
//
//  Programmer: Kathleen Biagas
//  Creation:   September 21, 2017
//
//  Modifications:
//   Cyrus Harrison, Wed Apr 17 12:48:31 PDT 2019
//   Change valid check, size_t is unsigned, no need to check for lower bound
//
// ****************************************************************************

vector <int>  &
PVTKParser::GetPieceExtent(size_t index)
{
    pieceExtent.clear();
    // index is unsigned, it will always be >=0
    if( index < pieceExtents.size() )
    {
        pieceExtent = pieceExtents[index];
    }
    return pieceExtent;
}


// ****************************************************************************
//  Method: PVTKParser::GetNumberOfPieces
//
//  Return:  The number of Pieces.
//
//  Programmer: Kathleen Biagas
//  Creation:   September 21, 2017
//
// ****************************************************************************

size_t
PVTKParser::GetNumberOfPieces()
{
    return pieceFileNames.size();
}

// ****************************************************************************
//  Method: PVTKParser::Parse
//
//  Purpose:
//    Parses the 'pvtk' file for Piece file names, and extents if available.
//
//  Programmer: Kathleen Biagas
//  Creation:   September 21, 2017
//
//  Modifications:
//   Cyrus Harrison, Wed Apr 17 12:48:31 PDT 2019
//   Add parents to clarify if statement and avoid compiler warning
//
// ****************************************************************************

bool
PVTKParser::Parse()
{
    if(parser == NULL)
       parser = vtkXMLDataParser::New();

    parser->SetFileName(fileName.c_str());
    if (!parser->Parse())
    {
        errorMessage = "Error parsing file: " + fileName;
        return false;
    }

    vtkXMLDataElement *root = parser->GetRootElement();
    if (!root)
    {
        errorMessage = "Error retrieving RootElement after parsing file.";
        return false;
    }

    if (!root->GetAttribute("version"))
    {
        errorMessage = "Error retrieving version after parsing file.";
        return false;
    }
    const char *v = root->GetAttribute("version");
    if (strcmp("pvtk-1.0", v) != 0)
    {
        errorMessage = "Unexpected version: " + string(v);
        return false;
    }
    int numPieces;
    if (!root->GetScalarAttribute("numberOfPieces", numPieces))
    {
        errorMessage = "Error retrieving 'numberOfPieces' tag.";
        return false;
    }

    // set to true, then if any piece doesn't have extents, will be
    // set to false for all pieces, even if some have extents.
    hasExtents = true;
    bool success = true;
    for (int i = 0; i < numPieces && success; ++i)
    {
        vtkXMLDataElement *pieceNode = root->GetNestedElement(i);
        if (!pieceNode)
        {
            errorMessage =  "Error retrieving Piece.";
            success = false;
            continue;
        }
        if (!pieceNode->GetAttribute("fileName"))
        {
            errorMessage = "Error retrieving fileName for Piece.";
            success = false;
            continue;
        }

        string pfn(pieceNode->GetAttribute("fileName"));
        string pieceBase = FileFunctions::Dirname(pfn);
        if (!pieceBase.empty() && ( pieceBase[0] == '/' || pieceBase[1] == ':') )
            pieceFileNames.push_back(pfn);
        else
            pieceFileNames.push_back(baseDir + VISIT_SLASH_STRING + pfn);

        vector<int> ext(6);
        if (pieceNode->GetVectorAttribute("extent", 6, &ext[0]) == 6)
        {
            pieceExtents.push_back(ext);
        }
        else
        {
            pieceExtents.clear();
            hasExtents = false;
        }
    }
    return success;
}

