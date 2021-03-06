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
//                            avtGTCFileFormat.h                           //
// ************************************************************************* //

#ifndef AVT_GTC_FILE_FORMAT_H
#define AVT_GTC_FILE_FORMAT_H

#include <avtMTSDFileFormat.h>

#include <vector>
#include <memory>
#include <map>
#include <adios2.h>


class vtkUnstructuredGrid;
class vtkPoints;

// ****************************************************************************
//  Class: avtGTCFileFormat
//
//  Purpose:
//      Reads in GTC files as a plugin to VisIt.
//
//  Programmer: pugmire -- generated by xml2avt
//  Creation:   Thu Apr 12 08:39:47 PDT 2018
//
// ****************************************************************************

class avtGTCFileFormat : public avtMTSDFileFormat
{
  public:
    static bool Identify(const std::string &fname,
                         const std::map<std::string, adios2::Params> &vars,
                         const std::map<std::string, adios2::Params> &attrs);
    static avtFileFormatInterface *CreateInterface(const char *const *list,
                                                   int nList,
                                                   int nBlock,
                                                   std::shared_ptr<adios2::ADIOS> adios,
                                                   adios2::Engine &reader,
                                                   adios2::IO &io,
                                                   std::map<std::string, adios2::Params> &variables,
                                                   std::map<std::string, adios2::Params> &attributes);

    avtGTCFileFormat(const char *);
    avtGTCFileFormat(std::shared_ptr<adios2::ADIOS> adios,
                     adios2::Engine &reader,
                     adios2::IO &io,
                     std::map<std::string, adios2::Params> &variables,
                     std::map<std::string, adios2::Params> &attributes,
                     const char *);

    virtual           ~avtGTCFileFormat();

    //
    // This is used to return unconvention data -- ranging from material
    // information to information about block connectivity.
    //
    // virtual void      *GetAuxiliaryData(const char *var, int timestep,
    //                                     const char *type, void *args,
    //                                     DestructorFunction &);
    //

    //
    // If you know the times and cycle numbers, overload this function.
    // Otherwise, VisIt will make up some reasonable ones for you.
    //
    virtual void        GetCycles(std::vector<int> &c);
    virtual void        GetTimes(std::vector<double> &t);

    virtual int            GetNTimesteps();

    virtual const char    *GetType()   { return "GTC"; };
    virtual void           FreeUpResources();

    virtual vtkDataSet    *GetMesh(int, const char *);
    virtual vtkDataSet    *GetPtMesh(int, const char *);
    virtual vtkDataArray  *GetVar(int, const char *);
    virtual vtkDataArray  *GetVectorVar(int, const char *);

  protected:
    // DATA MEMBERS
    vtkUnstructuredGrid * CreateMesh(bool xyzMesh);

    std::shared_ptr<adios2::ADIOS> adios;
    adios2::IO io;
    adios2::Engine reader;
    std::map<std::string, adios2::Params> variables, attributes;
    std::map<std::string, std::pair<int,std::string>> meshInfo;

    vtkUnstructuredGrid *grid, *ptGrid, *cylGrid;
    int numTimeSteps;

    virtual void           PopulateDatabaseMetaData(avtDatabaseMetaData *, int);
};


#endif
