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

#ifndef VIEWER_ACTION_UI_SINGLE_H
#define VIEWER_ACTION_UI_SINGLE_H
#include <viewer_exports.h>
#include <ViewerActionUI.h>

class QAction;
class QIcon;
class QMenu;
class QToolBar;

// ****************************************************************************
// Class: ViewerActionUISingle
//
// Purpose:
//   This class defines an action that the viewer can perform. An action is
//   special in that it can appear in the menu or the toolbar besides being
//   callable from the viewer's clients.
//
// Notes:      This class is abstract so it forces derived classes to
//             define their own Execute method.
//
// Programmer: Brad Whitlock
// Creation:   Wed Jan 29 09:44:00 PDT 2003
//
// Modifications:
//
// ****************************************************************************

class VIEWER_API ViewerActionUISingle : public ViewerActionUI
{
    Q_OBJECT
public:
    ViewerActionUISingle(ViewerActionLogic *L);
    virtual ~ViewerActionUISingle();
    
    virtual void Update();

    // Methods to add the action to the menu and toolbar.
    virtual void ConstructMenu(QMenu *menu);
    virtual void RemoveFromMenu(QMenu *menu);
    virtual void ConstructToolbar(QToolBar *toolbar);
    virtual void RemoveFromToolbar(QToolBar *toolbar);
    virtual void UpdateConstruction();
protected:
    // Methods to set the action's attributes.
    virtual void SetText(const QString &text);
    virtual void SetMenuText(const QString &text);
    virtual void SetToolTip(const QString &text);
    virtual void SetIcon(const QIcon &icons);
    virtual void SetToggleAction(bool val);
protected:
    QAction *action;
};

#endif
