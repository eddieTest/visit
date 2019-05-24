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

extern const char *visit_ActivateDatabase_doc;
extern const char *visit_AddArgument_doc;
extern const char *visit_AddMachineProfile_doc;
extern const char *visit_AddOperator_doc;
extern const char *visit_AddPlot_doc;
extern const char *visit_AddWindow_doc;
extern const char *visit_AlterDatabaseCorrelation_doc;
extern const char *visit_ApplyNamedSelection_doc;
extern const char *visit_ChangeActivePlotsVar_doc;
extern const char *visit_CheckForNewStates_doc;
extern const char *visit_ChooseCenterOfRotation_doc;
extern const char *visit_ClearAllWindows_doc;
extern const char *visit_ClearCache_doc;
extern const char *visit_ClearCacheForAllEngines_doc;
extern const char *visit_ClearMacros_doc;
extern const char *visit_ClearPickPoints_doc;
extern const char *visit_ClearReferenceLines_doc;
extern const char *visit_ClearViewKeyframes_doc;
extern const char *visit_ClearWindow_doc;
extern const char *visit_CloneWindow_doc;
extern const char *visit_Close_doc;
extern const char *visit_CloseComputeEngine_doc;
extern const char *visit_CloseDatabase_doc;
extern const char *visit_ColorTableNames_doc;
extern const char *visit_ConstructDataBinning_doc;
extern const char *visit_CopyAnnotationsToWindow_doc;
extern const char *visit_CopyLightingToWindow_doc;
extern const char *visit_CopyPlotsToWindow_doc;
extern const char *visit_CopyViewToWindow_doc;
extern const char *visit_CreateAnnotationObject_doc;
extern const char *visit_CreateDatabaseCorrelation_doc;
extern const char *visit_CreateNamedSelection_doc;
extern const char *visit_DatabasePlugins_doc;
extern const char *visit_DeIconifyAllWindows_doc;
extern const char *visit_DefineArrayExpression_doc;
extern const char *visit_DefineCurveExpression_doc;
extern const char *visit_DefineMaterialExpression_doc;
extern const char *visit_DefineMeshExpression_doc;
extern const char *visit_DefinePythonExpression_doc;
extern const char *visit_DefineScalarExpression_doc;
extern const char *visit_DefineSpeciesExpression_doc;
extern const char *visit_DefineTensorExpression_doc;
extern const char *visit_DefineVectorExpression_doc;
extern const char *visit_DeleteActivePlots_doc;
extern const char *visit_DeleteAllPlots_doc;
extern const char *visit_DeleteDatabaseCorrelation_doc;
extern const char *visit_DeleteExpression_doc;
extern const char *visit_DeleteNamedSelection_doc;
extern const char *visit_DeletePlotDatabaseKeyframe_doc;
extern const char *visit_DeletePlotKeyframe_doc;
extern const char *visit_DeleteViewKeyframe_doc;
extern const char *visit_DeleteWindow_doc;
extern const char *visit_DemoteOperator_doc;
extern const char *visit_DisableRedraw_doc;
extern const char *visit_DrawPlots_doc;
extern const char *visit_EnableTool_doc;
extern const char *visit_ExecuteMacro_doc;
extern const char *visit_ExportDatabase_doc;
extern const char *visit_Expressions_doc;
extern const char *visit_GetActiveContinuousColorTable_doc;
extern const char *visit_GetActiveDiscreteColorTable_doc;
extern const char *visit_GetActiveTimeSlider_doc;
extern const char *visit_GetAnimationAttributes_doc;
extern const char *visit_GetAnimationTimeout_doc;
extern const char *visit_GetAnnotationAttributes_doc;
extern const char *visit_GetAnnotationObject_doc;
extern const char *visit_GetAnnotationObjectNames_doc;
extern const char *visit_GetCallbackArgumentCount_doc;
extern const char *visit_GetCallbackNames_doc;
extern const char *visit_GetDatabaseNStates_doc;
extern const char *visit_GetDebugLevel_doc;
extern const char *visit_GetDefaultFileOpenOptions_doc;
extern const char *visit_GetDomains_doc;
extern const char *visit_GetEngineList_doc;
extern const char *visit_GetEngineProperties_doc;
extern const char *visit_GetGlobalAttributes_doc;
extern const char *visit_GetGlobalLineoutAttributes_doc;
extern const char *visit_GetInteractorAttributes_doc;
extern const char *visit_GetKeyframeAttributes_doc;
extern const char *visit_GetLastError_doc;
extern const char *visit_GetLight_doc;
extern const char *visit_GetLocalHostName_doc;
extern const char *visit_GetLocalUserName_doc;
extern const char *visit_GetMachineProfile_doc;
extern const char *visit_GetMachineProfileNames_doc;
extern const char *visit_GetMaterialAttributes_doc;
extern const char *visit_GetMaterials_doc;
extern const char *visit_GetMeshManagementAttributes_doc;
extern const char *visit_GetMetaData_doc;
extern const char *visit_GetNumPlots_doc;
extern const char *visit_GetOperatorOptions_doc;
extern const char *visit_GetPickAttributes_doc;
extern const char *visit_GetPickOutput_doc;
extern const char *visit_GetPickOutputObject_doc;
extern const char *visit_GetPipelineCachingMode_doc;
extern const char *visit_GetPlotInformation_doc;
extern const char *visit_GetPlotList_doc;
extern const char *visit_GetPlotOptions_doc;
extern const char *visit_GetPreferredFileFormats_doc;
extern const char *visit_GetQueryOutputObject_doc;
extern const char *visit_GetQueryOutputString_doc;
extern const char *visit_GetQueryOutputValue_doc;
extern const char *visit_GetQueryOutputXML_doc;
extern const char *visit_GetQueryOverTimeAttributes_doc;
extern const char *visit_GetQueryParameters_doc;
extern const char *visit_GetRenderingAttributes_doc;
extern const char *visit_GetSaveWindowAttributes_doc;
extern const char *visit_GetSelection_doc;
extern const char *visit_GetSelectionList_doc;
extern const char *visit_GetSelectionSummary_doc;
extern const char *visit_GetTimeSliders_doc;
extern const char *visit_GetUltraScript_doc;
extern const char *visit_GetView2D_doc;
extern const char *visit_GetView3D_doc;
extern const char *visit_GetViewAxisArray_doc;
extern const char *visit_GetViewCurve_doc;
extern const char *visit_GetWindowInformation_doc;
extern const char *visit_HideActivePlots_doc;
extern const char *visit_HideToolbars_doc;
extern const char *visit_IconifyAllWindows_doc;
extern const char *visit_InitializeNamedSelectionVariables_doc;
extern const char *visit_InvertBackgroundColor_doc;
extern const char *visit_Launch_doc;
extern const char *visit_LaunchNowin_doc;
extern const char *visit_Lineout_doc;
extern const char *visit_ListDomains_doc;
extern const char *visit_ListMaterials_doc;
extern const char *visit_ListPlots_doc;
extern const char *visit_LoadAttribute_doc;
extern const char *visit_LoadNamedSelection_doc;
extern const char *visit_LoadUltra_doc;
extern const char *visit_LocalNameSpace_doc;
extern const char *visit_LongFileName_doc;
extern const char *visit_MoveAndResizeWindow_doc;
extern const char *visit_MovePlotDatabaseKeyframe_doc;
extern const char *visit_MovePlotKeyframe_doc;
extern const char *visit_MovePlotOrderTowardFirst_doc;
extern const char *visit_MovePlotOrderTowardLast_doc;
extern const char *visit_MoveViewKeyframe_doc;
extern const char *visit_MoveWindow_doc;
extern const char *visit_NodePick_doc;
extern const char *visit_NumColorTableNames_doc;
extern const char *visit_NumOperatorPlugins_doc;
extern const char *visit_NumPlotPlugins_doc;
extern const char *visit_OpenComputeEngine_doc;
extern const char *visit_OpenDatabase_doc;
extern const char *visit_OpenMDServer_doc;
extern const char *visit_OperatorPlugins_doc;
extern const char *visit_OverlayDatabase_doc;
extern const char *visit_Pick_doc;
extern const char *visit_PickByGlobalNode_doc;
extern const char *visit_PickByGlobalZone_doc;
extern const char *visit_PickByNode_doc;
extern const char *visit_PickByNodeLabel_doc;
extern const char *visit_PickByZone_doc;
extern const char *visit_PickByZoneLabel_doc;
extern const char *visit_PlotPlugins_doc;
extern const char *visit_PointPick_doc;
extern const char *visit_PrintWindow_doc;
extern const char *visit_PromoteOperator_doc;
extern const char *visit_PythonQuery_doc;
extern const char *visit_Queries_doc;
extern const char *visit_QueriesOverTime_doc;
extern const char *visit_Query_doc;
extern const char *visit_QueryOverTime_doc;
extern const char *visit_ReOpenDatabase_doc;
extern const char *visit_ReadHostProfilesFromDirectory_doc;
extern const char *visit_RecenterView_doc;
extern const char *visit_RedoView_doc;
extern const char *visit_RedrawWindow_doc;
extern const char *visit_RegisterCallback_doc;
extern const char *visit_RegisterMacro_doc;
extern const char *visit_RemoveAllOperators_doc;
extern const char *visit_RemoveLastOperator_doc;
extern const char *visit_RemoveMachineProfile_doc;
extern const char *visit_RemoveOperator_doc;
extern const char *visit_RemovePicks_doc;
extern const char *visit_RenamePickLabel_doc;
extern const char *visit_ReplaceDatabase_doc;
extern const char *visit_ResetLineoutColor_doc;
extern const char *visit_ResetOperatorOptions_doc;
extern const char *visit_ResetPickLetter_doc;
extern const char *visit_ResetPlotOptions_doc;
extern const char *visit_ResetView_doc;
extern const char *visit_ResizeWindow_doc;
extern const char *visit_RestoreSession_doc;
extern const char *visit_RestoreSessionWithDifferentSources_doc;
extern const char *visit_SaveAttribute_doc;
extern const char *visit_SaveNamedSelection_doc;
extern const char *visit_SaveSession_doc;
extern const char *visit_SaveWindow_doc;
extern const char *visit_SendSimulationCommand_doc;
extern const char *visit_SetActiveContinuousColorTable_doc;
extern const char *visit_SetActiveDiscreteColorTable_doc;
extern const char *visit_SetActivePlots_doc;
extern const char *visit_SetActiveTimeSlider_doc;
extern const char *visit_SetActiveWindow_doc;
extern const char *visit_SetAnimationTimeout_doc;
extern const char *visit_SetAnnotationAttributes_doc;
extern const char *visit_SetBackendType_doc;
extern const char *visit_SetCenterOfRotation_doc;
extern const char *visit_SetColorTexturingEnabled_doc;
extern const char *visit_SetCreateMeshQualityExpressions_doc;
extern const char *visit_SetCreateTimeDerivativeExpressions_doc;
extern const char *visit_SetCreateVectorMagnitudeExpressions_doc;
extern const char *visit_SetDatabaseCorrelationOptions_doc;
extern const char *visit_SetDebugLevel_doc;
extern const char *visit_SetDefaultAnnotationAttributes_doc;
extern const char *visit_SetDefaultFileOpenOptions_doc;
extern const char *visit_SetDefaultInteractorAttributes_doc;
extern const char *visit_SetDefaultMaterialAttributes_doc;
extern const char *visit_SetDefaultMeshManagementAttributes_doc;
extern const char *visit_SetDefaultOperatorOptions_doc;
extern const char *visit_SetDefaultPickAttributes_doc;
extern const char *visit_SetDefaultPlotOptions_doc;
extern const char *visit_SetGlobalLineoutAttributes_doc;
extern const char *visit_SetInteractorAttributes_doc;
extern const char *visit_SetKeyframeAttributes_doc;
extern const char *visit_SetLight_doc;
extern const char *visit_SetMachineProfile_doc;
extern const char *visit_SetMaterialAttributes_doc;
extern const char *visit_SetMeshManagementAttributes_doc;
extern const char *visit_SetNamedSelectionAutoApply_doc;
extern const char *visit_SetOperatorOptions_doc;
extern const char *visit_SetPickAttributes_doc;
extern const char *visit_SetPipelineCachingMode_doc;
extern const char *visit_SetPlotDatabaseState_doc;
extern const char *visit_SetPlotDescription_doc;
extern const char *visit_SetPlotFollowsTime_doc;
extern const char *visit_SetPlotFrameRange_doc;
extern const char *visit_SetPlotOptions_doc;
extern const char *visit_SetPlotOrderToFirst_doc;
extern const char *visit_SetPlotOrderToLast_doc;
extern const char *visit_SetPlotSILRestriction_doc;
extern const char *visit_SetPrecisionType_doc;
extern const char *visit_SetPreferredFileFormats_doc;
extern const char *visit_SetPrinterAttributes_doc;
extern const char *visit_SetQueryFloatFormat_doc;
extern const char *visit_SetQueryOutputToObject_doc;
extern const char *visit_SetQueryOutputToString_doc;
extern const char *visit_SetQueryOutputToValue_doc;
extern const char *visit_SetQueryOverTimeAttributes_doc;
extern const char *visit_SetRemoveDuplicateNodes_doc;
extern const char *visit_SetRenderingAttributes_doc;
extern const char *visit_SetSaveWindowAttributes_doc;
extern const char *visit_SetTimeSliderState_doc;
extern const char *visit_SetTreatAllDBsAsTimeVarying_doc;
extern const char *visit_SetTryHarderCyclesTimes_doc;
extern const char *visit_SetUltraScript_doc;
extern const char *visit_SetView2D_doc;
extern const char *visit_SetView3D_doc;
extern const char *visit_SetViewAxisArray_doc;
extern const char *visit_SetViewCurve_doc;
extern const char *visit_SetViewExtentsType_doc;
extern const char *visit_SetViewKeyframe_doc;
extern const char *visit_SetWindowArea_doc;
extern const char *visit_SetWindowLayout_doc;
extern const char *visit_SetWindowMode_doc;
extern const char *visit_ShowAllWindows_doc;
extern const char *visit_ShowToolbars_doc;
extern const char *visit_Source_doc;
extern const char *visit_SuppressMessages_doc;
extern const char *visit_SuppressQueryOutputOff_doc;
extern const char *visit_SuppressQueryOutputOn_doc;
extern const char *visit_TimeSliderGetNStates_doc;
extern const char *visit_TimeSliderNextState_doc;
extern const char *visit_TimeSliderPreviousState_doc;
extern const char *visit_TimeSliderSetState_doc;
extern const char *visit_ToggleBoundingBoxMode_doc;
extern const char *visit_ToggleCameraViewMode_doc;
extern const char *visit_ToggleFullFrameMode_doc;
extern const char *visit_ToggleLockTime_doc;
extern const char *visit_ToggleLockTools_doc;
extern const char *visit_ToggleLockViewMode_doc;
extern const char *visit_ToggleMaintainViewMode_doc;
extern const char *visit_ToggleSpinMode_doc;
extern const char *visit_TurnDomainsOff_doc;
extern const char *visit_TurnDomainsOn_doc;
extern const char *visit_TurnMaterialsOff_doc;
extern const char *visit_TurnMaterialsOn_doc;
extern const char *visit_UndoView_doc;
extern const char *visit_UpdateNamedSelection_doc;
extern const char *visit_Version_doc;
extern const char *visit_WriteConfigFile_doc;
extern const char *visit_WriteScript_doc;
extern const char *visit_ZonePick_doc;
