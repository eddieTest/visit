# ----------------------------------------------------------------------------
#  CLASSES: nightly
#
#  Test Case:  mili.py
#
#  Tests:      mesh      - 3D unstructured,multi-domain, 
#              plots     - Pseudocolor, material, vector, tensor
#
#  Defect ID:  none
#
#  Programmer: Alister Maguire
#  Date:       
#
#  Modifications:
#
# ----------------------------------------------------------------------------
RequiredDatabasePlugin("Mili")
serial_path       = data_path("mili_test_data/single_proc/d3samp6.plt.mili")
multi_domain_path = data_path("mili_test_data/multi_proc/d3samp6.plt.mili")

def TestComponentVis():
    OpenDatabase(serial_path)
    v = GetView3D()
    v.viewNormal = (0.9, 0.35, -0.88)
    SetView3D(v)
    SetTimeSliderState(90)
    
    
    AddPlot("Pseudocolor", "Primal/brick/edrate")
    DrawPlots()
    Test("mili_brick_comp")
    
    ChangeActivePlotsVar("Primal/beam/svec/svec_x")
    Test("mili_beam_comp")
    ChangeActivePlotsVar("Primal/node/nodacc/ax")
    Test("mili_nodacc_comp")
    
    DeleteAllPlots()


def TestElementSetComponents():
    OpenDatabase(serial_path)
    v = GetView3D()
    v.viewNormal = (0.9, 0.35, -0.88)
    SetView3D(v)
    SetTimeSliderState(90)

    AddPlot("Pseudocolor", "Primal/shell/strain/exy")
    DrawPlots()
    Test("mili_es_comp_01")
    ChangeActivePlotsVar("Primal/beam/stress/sz")
    Test("mili_es_comp_02")

    DeleteAllPlots()


def TestMaterialVar():
    OpenDatabase(serial_path)
    v = GetView3D()
    v.viewNormal = (0.9, 0.35, -0.88)
    SetView3D(v)
    SetTimeSliderState(90)

    AddPlot("Pseudocolor", "Primal/mat/matcgy")
    DrawPlots()
    Test("mili_mat_var_01")
    ChangeActivePlotsVar("Primal/mat/matke")
    Test("mili_mat_var_02")
    DeleteAllPlots()


def TestMaterials():
    OpenDatabase(serial_path)
    v = GetView3D()
    v.viewNormal = (0.9, 0.35, -0.88)
    SetView3D(v)
    SetTimeSliderState(90)

    AddPlot("FilledBoundary", "materials1")
    DrawPlots()
    Test("mili_materials_01")

    DeleteAllPlots()


def TestTensors():
    OpenDatabase(serial_path)
    v = GetView3D()
    v.viewNormal = (0.9, 0.35, -0.88)
    SetView3D(v)
    SetTimeSliderState(90)

    AddPlot("Tensor", "Primal/brick/stress")
    DrawPlots()
    Test("mili_tensors_01")

    ChangeActivePlotsVar("Primal/brick/stress")
    Test("mili_tensors_02")
    
    ChangeActivePlotsVar("Primal/shell/stress")
    Test("mili_tensors_03")
    DeleteAllPlots()


def TestVectors():
    OpenDatabase(serial_path)
    v = GetView3D()
    v.viewNormal = (0.9, 0.35, -0.88)
    SetView3D(v)
    SetTimeSliderState(90)

    AddPlot("Vector", "Primal/node/nodpos")
    DrawPlots()
    Test("mili_vectors_01")
    
    ChangeActivePlotsVar("Primal/shell/bend")
    Test("mili_vectors_02")
    
    ChangeActivePlotsVar("Primal/beam/svec")
    Test("mili_vectors_03")
    DeleteAllPlots()


def TestSandMesh():
    OpenDatabase(serial_path)
    v = GetView3D()
    v.viewNormal = (0.9, 0.35, -0.88)
    SetView3D(v)
    SetTimeSliderState(70)
    
    AddPlot("Pseudocolor", "sand_mesh/Primal/brick/edrate")
    DrawPlots()
    Test("mili_sand_mesh_01")
    
    ChangeActivePlotsVar("sand_mesh/Primal/beam/svec/svec_x")
    Test("mili_sand_mesh_02")
    ChangeActivePlotsVar("sand_mesh/Primal/node/nodacc/ax")
    Test("mili_sand_mesh_03")
    
    DeleteAllPlots()

def TestMaterials():
    OpenDatabase(serial_path)
    v = GetView3D()
    v.viewNormal = (0.9, 0.35, -0.88)
    SetView3D(v)
    SetTimeSliderState(70)
    
    AddPlot("FilledBoundary", "materials1(mesh1)")
    DrawPlots()
    Test("mili_materials_00")
    DeleteAllPlots()

def TestMultiDomain():
    OpenDatabase(multi_domain_path)
    v = GetView3D()
    v.viewNormal = (0.9, 0.35, -0.88)
    SetView3D(v)
    SetTimeSliderState(90)

    AddPlot("Pseudocolor", "Primal/shell/strain/exy")
    DrawPlots()
    Test("mili_multi_dom_01")
    ChangeActivePlotsVar("Primal/beam/stress/sz")
    Test("mili_multi_dom_02")

    DeleteAllPlots()



def Main():
    TestComponentVis()    
    TestElementSetComponents()
    TestMaterialVar()
    TestTensors()
    TestVectors()
    TestSandMesh()
    TestMaterials()
    TestMultiDomain()

Main()
Exit()

