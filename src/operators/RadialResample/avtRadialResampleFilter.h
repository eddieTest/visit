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
//  File: avtRadialResampleFilter.h
// ************************************************************************* //

#ifndef AVT_RadialResample_FILTER_H
#define AVT_RadialResample_FILTER_H


#include <avtPluginDataTreeIterator.h>
#include <RadialResampleAttributes.h>
#include <avtPluginDatasetToDatasetFilter.h>

#include <vtkStructuredGrid.h>
#include <vtkUnstructuredGrid.h>
#include <vtkDataSet.h>


// ****************************************************************************
//  Class: avtRadialResampleFilter
//
//  Purpose:
//      A plugin operator for RadialResample.
//
//  Programmer: Kevin Griffin
//  Creation:   Tue May 20 13:15:11 PST 2014
//
//  Modifications:
//
//    Kevin Griffin, Fri Mar 24 18:06:06 PDT 2017
//    Added ModifyContract and UpdateDataObjectInfo methods.
//
// ****************************************************************************

class avtRadialResampleFilter : public avtPluginDatasetToDatasetFilter
{
  public:
                         avtRadialResampleFilter();
    virtual             ~avtRadialResampleFilter();

    static avtFilter    *Create();

    virtual const char  *GetType(void)  { return "avtRadialResampleFilter"; };
    virtual const char  *GetDescription(void) { return "Radial Resample"; };

    virtual void         SetAtts(const AttributeGroup*);
    virtual bool         Equivalent(const AttributeGroup*);
    virtual avtContract_p   ModifyContract(avtContract_p);
    virtual void            UpdateDataObjectInfo(void);

  protected:
    RadialResampleAttributes   atts;
    std::string resampleVarName;
    
    bool GetBounds(double[6]);

    virtual void Execute();
    
    static vtkStructuredGrid    *CreateFast2DRadialGrid(int[3], const float *, float, float, float);
    static vtkUnstructuredGrid  *CreateNormal2DRadialGrid(int[3], const float *, float, float, float);
    static vtkDataSet           *Create2DRadialGrid(const double *, const float *, float, float, float, float, float, bool);
    
    static vtkStructuredGrid    *CreateFast3DRadialGrid(int[3], const float *, float, float, float, float, float);
    static vtkUnstructuredGrid  *CreateNormal3DRadialGrid(int[3], const float *, float, float, float, float, float);
    static vtkDataSet           *Create3DRadialGrid(const double *, const float *, float, float, float, float, float, float, float, float, bool);
};


#endif
