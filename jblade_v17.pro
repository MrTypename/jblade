# -------------------------------------------------
# Project created by QtCreator 2009-02-14T15:30:46
# -------------------------------------------------
QT += opengl widgets
TEMPLATE = app
SOURCES += src/MainFrame.cpp \
    src/Main.cpp \
    src/Globals.cpp \
    src/TwoDWidget.cpp \
    src/GLWidget.cpp \
    src/XFLR5Application.cpp \
    src/Miarex/ArcBall.cpp \
    src/Miarex/BodyGridDlg.cpp \
    src/Miarex/BodyScaleDlg.cpp \
    src/Miarex/BodyTableDelegate.cpp \
    src/Miarex/BodyTransDlg.cpp \
    src/Miarex/CtrlTableDelegate.cpp \
    src/Miarex/GLCreateLists.cpp \
    src/Miarex/GL3dWingDlg.cpp \
    src/Miarex/GL3DScales.cpp \
    src/Miarex/GL3dBodyDlg.cpp \
    src/Miarex/GLLightDlg.cpp \
    src/Miarex/LLTAnalysisDlg.cpp \
    src/Miarex/LLTAnalysis.cpp \
    src/Miarex/ImportWingDlg.cpp \
    src/Miarex/InertiaDlg.cpp \
    src/Miarex/Miarex.cpp \
    src/Miarex/ManageBodiesDlg.cpp \
    src/Miarex/ManageUFOsDlg.cpp \
    src/Miarex/PlaneDlg.cpp \
    src/Miarex/PanelAnalysisDlg.cpp \
    src/Miarex/StabPolarDlg.cpp \
    src/Miarex/StabViewDlg.cpp \
    src/Miarex/UFOTableDelegate.cpp \
    src/Miarex/W3dPrefsDlg.cpp \
    src/Miarex/WAdvancedDlg.cpp \
    src/Miarex/WingDelegate.cpp \
    src/Miarex/WingScaleDlg.cpp \
    src/Miarex/WPolarDlg.cpp \
    src/XDirect/BatchDlg.cpp \
    src/XDirect/BatchThreadDlg.cpp \
    src/XDirect/XFoilTask.cpp \
    src/XDirect/CAddDlg.cpp \
    src/XDirect/FoilCoordDlg.cpp \
    src/XDirect/FoilGeomDlg.cpp \
    src/XDirect/FoilPolarDlg.cpp \
    src/XDirect/FlapDlg.cpp \
    src/XDirect/InterpolateFoilsDlg.cpp \
    src/XDirect/LEDlg.cpp \
    src/XDirect/ManageFoilsDlg.cpp \
    src/XDirect/NacaFoilDlg.cpp \
    src/XDirect/ReListDlg.cpp \
    src/XDirect/TEGapDlg.cpp \
    src/XDirect/TwoDPanelDlg.cpp \
    src/XDirect/XDirectStyleDlg.cpp \
    src/XDirect/XFoil.cpp \
    src/XDirect/XFoilAnalysisDlg.cpp \
    src/XDirect/XFoilAdvancedDlg.cpp \
    src/XDirect/XDirect.cpp \
    src/Objects/Body.cpp \
    src/Objects/CVector.cpp \
    src/Objects/Foil.cpp \
    src/Objects/Frame.cpp \
    src/Objects/OpPoint.cpp \
    src/Objects/Panel.cpp \
    src/Objects/Plane.cpp \
    src/Objects/Polar.cpp \
    src/Objects/POpp.cpp \
    src/Objects/Quaternion.cpp \
    src/Objects/Sf.cpp \
    src/Objects/Spline.cpp \
    src/Objects/WPolar.cpp \
    src/Objects/WOpp.cpp \
    src/Misc/SaveOptionsDlg.cpp \
    src/Misc/ProgressDlg.cpp \
    src/Misc/ModDlg.cpp \
    src/Misc/EditPlrDlg.cpp \
    src/Misc/PolarFilterDlg.cpp \
    src/Misc/TranslatorDlg.cpp \
    src/Misc/UnitsDlg.cpp \
    src/Misc/RenameDlg.cpp \
    src/Misc/LinePickerDlg.cpp \
    src/Misc/LineDelegate.cpp \
    src/Misc/LineCbBox.cpp \
    src/Misc/LineButton.cpp \
    src/Misc/FloatEditDelegate.cpp \
    src/Misc/DisplaySettingsDlg.cpp \
    src/Misc/ColorButton.cpp \
    src/Misc/FloatEdit.cpp \
    src/Misc/AboutQ5.cpp \
    src/Misc/NewNameDlg.cpp \
    src/Misc/ObjectPropsDlg.cpp \
    src/Graph/QGraph.cpp \
    src/Graph/GraphWidget.cpp \
    src/Graph/GraphDlg.cpp \
    src/Graph/Graph.cpp \
    src/Graph/Curve.cpp \
    src/XInverse/FoilSelectionDlg.cpp \
    src/XInverse/PertDlg.cpp \
    src/XInverse/XInverse.cpp \
    src/XInverse/InverseOptionsDlg.cpp \
    src/Design/FoilTableDelegate.cpp \
    src/Design/AFoilGridDlg.cpp \
    src/Design/LECircleDlg.cpp \
    src/Design/AFoil.cpp \
    src/Design/SplineCtrlsDlg.cpp \
    src/Design/AFoilTableDlg.cpp \
    src/XBEM/TData.cpp \
    src/XBEM/TBEMData.cpp \
    src/XBEM/SimuWidget.cpp \
    src/XBEM/OptimizeDlg.cpp \
    src/XBEM/Edit360PolarDlg.cpp \
    src/XBEM/CreateBEMDlg.cpp \
    src/XBEM/BladeScaleDlg.cpp \
    src/XBEM/BEMData.cpp \
    src/XBEM/BEM.cpp \
    src/XBEM/BData.cpp \
    src/XBEM/Blade.cpp \
    src/Objects/Wing.cpp \
    src/Objects/Surface.cpp \
    src/XBEM/BladeDelegate.cpp \
    src/XBEM/BladeAxisDelegate.cpp \
    src/XBEM/BladeStructureDlg.cpp \
    src/XBEM/AboutBEM.cpp \
    src/XBEM/AboutJBLADE.cpp

HEADERS += src/MainFrame.h \
    src/Params.h \
    src/Globals.h \
    src/TwoDWidget.h \
    src/GLWidget.h \
    src/XFLR5Application.h \
    src/Miarex/Miarex.h \
    src/Miarex/W3dPrefsDlg.h \
    src/Miarex/GLCreateLists.h \
    src/Miarex/WingScaleDlg.h \
    src/Miarex/CtrlTableDelegate.h \
    src/Miarex/ManageBodiesDlg.h \
    src/Miarex/WPolarDlg.h \
    src/Miarex/WingDelegate.h \
    src/Miarex/PlaneDlg.h \
    src/Miarex/PanelAnalysisDlg.h \
    src/Miarex/ManageUFOsDlg.h \
    src/Miarex/UFOTableDelegate.h \
    src/Miarex/StabViewDlg.h \
    src/Miarex/InertiaDlg.h \
    src/Miarex/StabPolarDlg.h \
    src/Miarex/LLTAnalysisDlg.h \
    src/Miarex/LLTAnalysis.h \
    src/Miarex/ImportWingDlg.h \
    src/Miarex/GLLightDlg.h \
    src/Miarex/ArcBall.h \
    src/Miarex/BodyGridDlg.h \
    src/Miarex/BodyTableDelegate.h \
    src/Miarex/BodyScaleDlg.h \
    src/Miarex/WAdvancedDlg.h \
    src/Miarex/GL3dWingDlg.h \
    src/Miarex/BodyTransDlg.h \
    src/Miarex/GL3DScales.h \
    src/Miarex/GL3dBodyDlg.h \
    src/XDirect/XFoil.h \
    src/XDirect/XFoilAnalysisDlg.h \
    src/XDirect/XFoilAdvancedDlg.h \
    src/XDirect/XDirect.h \
    src/XDirect/TwoDPanelDlg.h \
    src/XDirect/TEGapDlg.h \
    src/XDirect/InterpolateFoilsDlg.h \
    src/XDirect/FoilGeomDlg.h \
    src/XDirect/FoilCoordDlg.h \
    src/XDirect/ReListDlg.h \
    src/XDirect/XDirectStyleDlg.h \
    src/XDirect/ManageFoilsDlg.h \
    src/XDirect/NacaFoilDlg.h \
    src/XDirect/LEDlg.h \
    src/XDirect/FoilPolarDlg.h \
    src/XDirect/FlapDlg.h \
    src/XDirect/CAddDlg.h \
    src/XDirect/BatchDlg.h \
    src/XDirect/BatchThreadDlg.h \
    src/XDirect/XFoilTask.h \
    src/XInverse/XInverse.h \
    src/XInverse/InverseOptionsDlg.h \
    src/XInverse/FoilSelectionDlg.h \
    src/XInverse/PertDlg.h \
    src/Objects/WPolar.h \
    src/Objects/WOpp.h \
    src/Objects/Wing.h \
    src/Objects/Surface.h \
    src/Objects/Spline.h \
    src/Objects/Sf.h \
    src/Objects/OpPoint.h \
    src/Objects/Quaternion.h \
    src/Objects/POpp.h \
    src/Objects/Polar.h \
    src/Objects/CVector.h \
    src/Objects/Plane.h \
    src/Objects/CRectangle.h \
    src/Objects/Panel.h \
    src/Objects/Frame.h \
    src/Objects/Foil.h \
    src/Objects/Body.h \
    src/Misc/SaveOptionsDlg.h \
    src/Misc/ModDlg.h \
    src/Misc/PolarFilterDlg.h \
    src/Misc/TranslatorDlg.h \
    src/Misc/UnitsDlg.h \
    src/Misc/RenameDlg.h \
    src/Misc/LinePickerDlg.h \
    src/Misc/LineDelegate.h \
    src/Misc/FloatEditDelegate.h \
    src/Misc/DisplaySettingsDlg.h \
    src/Misc/ColorButton.h \
    src/Misc/LineCbBox.h \
    src/Misc/LineButton.h \
    src/Misc/EditPlrDlg.h \
    src/Misc/AboutQ5.h \
    src/Misc/FloatEdit.h \
    src/Misc/ProgressDlg.h \
    src/Misc/NewNameDlg.h \
    src/Misc/ObjectPropsDlg.h \
    src/Graph/GraphWidget.h \
    src/Graph/Graph.h \
    src/Graph/GraphDlg.h \
    src/Graph/Curve.h \
    src/Graph/QGraph.h \
    src/Design/AFoil.h \
    src/Design/AFoilGridDlg.h \
    src/Design/LECircleDlg.h \
    src/Design/SplineCtrlsDlg.h \
    src/Design/FoilTableDelegate.h \
    src/Design/AFoilTableDlg.h \
    src/XBEM/TData.h \
    src/XBEM/TBEMData.h \
    src/XBEM/SimuWidget.h \
    src/XBEM/OptimizeDlg.h \
    src/XBEM/Edit360PolarDlg.h \
    src/XBEM/CreateBEMDlg.h \
    src/XBEM/BladeScaleDlg.h \
    src/XBEM/BEMData.h \
    src/XBEM/BEM.h \
    src/XBEM/BData.h \
    src/XBEM/AboutBEM.h \
    src/XBEM/Blade.h \
    src/XBEM/BladeDelegate.h \
    src/XBEM/BladeAxisDelegate.h \
    src/XBEM/BladeStructureDlg.h \
    src/XBEM/AboutJBLADE.h

TRANSLATIONS = translations/xflr5v6.ts \
    translations/xflr5v6_de.ts \
    translations/xflr5v6_fr.ts \
    translations/xflr5v6_ja.ts

RESOURCES += qblade.qrc

win32 { 
    TARGET = JBLADE
    RC_FILE = win/jblade.rc
}

unix { 
    TARGET = JBLADE
    
    # VARIABLES
    isEmpty(PREFIX):PREFIX = /usr
    BINDIR = $$PREFIX/bin
    DATADIR = $$PREFIX/share
    
    # MAKE INSTALL
    INSTALLS += target
#    target.path = $$BINDIR
}

macx { 
    CONFIG(release, debug|release) { 
        OBJECTS_DIR = ./build/release
        MOC_DIR = ./build/release
        RCC_DIR = ./build/release
        UI_HEADERS_DIR = ./build/release
    }
    CONFIG(debug, debug|release) { 
        OBJECTS_DIR = ./build/debug
        MOC_DIR = ./build/debug
        RCC_DIR = ./build/debug
        UI_HEADERS_DIR = ./build/debug
    }
    TARGET = JBLADE
    TEMPLATE = app
    CONFIG += i386 \
        ppc
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.4
    QMAKE_MAC_SDK = /Developer/SDKs/MacOSX10.5.sdk
    OTHER_FILES += mac/Info.plist
    LIBS += -framework \
        CoreFoundation
    QMAKE_INFO_PLIST = mac/Info.plist
    ICON = mac/JBLADE.icns
}
OTHER_FILES += doc/ReleaseNotes.txt


# for the libqglviewer
#________________________________
INCLUDEPATH *= $$PWD/src
CONFIG(debug, debug|release) {
    LIBS += -L$$PWD/src/QGLViewer/debug -ldQGLViewer2 -lOpengl32
}
CONFIG(release, debug|release) {
    LIBS += -L$$PWD/src/QGLViewer/release -lQGLViewer2 -lOpengl32
}
#LIBS += -L$$PWD/src -lQGLViewerd2
#________________________________

#QMAKE_CFLAGS+=-pg
#QMAKE_CXXFLAGS+=-pg
#QMAKE_LFLAGS+=-pg
