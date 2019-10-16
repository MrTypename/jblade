/****************************************************************************

    SimuWidget Class
        Copyright (C) 2010 David Marten qblade@web.de

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*****************************************************************************/

#include "SimuWidget.h"
#include <QtWidgets>
#include <QWidget>
#include "../Misc/LineCbBox.h"
#include "../Misc/LineButton.h"
#include "../Misc/LineDelegate.h"

SimuWidget::SimuWidget(QWidget *parent)
{

    SetupLayout();
    Connect();

    m_pctrlCurveColor->setEnabled(false);
    m_pctrlCurveStyle->setEnabled(false);
    m_pctrlCurveWidth->setEnabled(false);
    m_pctrlShowCurve->setEnabled(false);
    m_pctrlShowPoints->setEnabled(false);

}




void SimuWidget::SetupLayout()
{

    /////////top Layout//////////
    m_pctrlRho = new QLabel(tr("Rho"));
    m_pctrlElements = new QLabel(tr("Elements"));
    m_pctrlIteration = new QLabel(tr("max Iterations"));
    m_pctrlEpsilon = new QLabel(tr("Epsilon"));
    m_pctrlRelax = new QLabel(tr("Relax Factor"));
    m_pctrlVisc = new QLabel(tr("Viscosity"));


    m_pctrlRhoVal = new QLabel;
    m_pctrlElementsVal = new QLabel;
    m_pctrlIterationVal = new QLabel;
    m_pctrlEpsilonVal = new QLabel;
    m_pctrlRelaxVal = new QLabel;
    m_pctrlViscVal = new QLabel;





    m_pctrlTipLoss = new QCheckBox(tr("Tip Loss"));
    m_pctrlTipLoss->setEnabled(false);

    m_pctrlRootLoss = new QCheckBox(tr("Root Loss"));
    m_pctrlRootLoss->setEnabled(false);

    m_pctrl3DCorrection = new QCheckBox(tr("3D Correction"));
    m_pctrl3DCorrection->setEnabled(false);

    m_pctrl3DEquilibrium = new QCheckBox(tr("3D Equilibrium"));
    m_pctrl3DEquilibrium->setEnabled(false);

    m_pctrlInterpolation = new QCheckBox(tr("Foil Interpolation"));
    m_pctrlInterpolation->setEnabled(false);

    m_pctrlNewTipLoss = new QCheckBox(tr("New Tip Loss"));
    m_pctrlNewTipLoss->setEnabled(false);

    m_pctrlNewRootLoss = new QCheckBox(tr("New Root Loss"));
    m_pctrlNewRootLoss->setEnabled(false);

    QGridLayout *SimuShow = new QGridLayout;

    SimuShow->addWidget(m_pctrlTipLoss,1,1);
    SimuShow->addWidget(m_pctrlNewTipLoss,2,1);
    SimuShow->addWidget(m_pctrlRootLoss,3,1);
    SimuShow->addWidget(m_pctrlNewRootLoss,4,1);
    SimuShow->addWidget(m_pctrlInterpolation,6,1);
    SimuShow->addWidget(m_pctrl3DCorrection,5,1);
    SimuShow->addWidget(m_pctrl3DEquilibrium,7,1);
    SimuShow->addWidget(m_pctrlRho,1,2);
    SimuShow->addWidget(m_pctrlRhoVal,1,3);
    SimuShow->addWidget(m_pctrlVisc,2,2);
    SimuShow->addWidget(m_pctrlViscVal,2,3);
    SimuShow->addWidget(m_pctrlElements,3,2);
    SimuShow->addWidget(m_pctrlElementsVal,3,3);
    SimuShow->addWidget(m_pctrlIteration,4,2);
    SimuShow->addWidget(m_pctrlIterationVal,4,3);
    SimuShow->addWidget(m_pctrlEpsilon,5,2);
    SimuShow->addWidget(m_pctrlEpsilonVal,5,3);
    SimuShow->addWidget(m_pctrlRelax,6,2);
    SimuShow->addWidget(m_pctrlRelaxVal,6,3);

    QGroupBox *SimuGroup = new QGroupBox(tr("Simulation Parameters"));
    SimuGroup->setLayout(SimuShow);

    //---------------Wing Simulation Control Layout (bottom)------------------//
    QGridLayout *SequenceLayout = new QGridLayout;

    m_pctrlCreateBEM = new QPushButton(tr("Define Blade Simulation"));
    m_pctrlLSLabel = new QLabel(tr("Tip Speed Ratio Start ="));
    m_pctrlLSLabel->setAlignment(Qt::AlignLeft);
    m_pctrlLSLineEdit = new FloatEdit;
    m_pctrlLSLineEdit->setAlignment(Qt::AlignRight);
    m_pctrlLSLineEdit->SetMin(double(0.01));
    m_pctrlLELabel = new QLabel(tr("Tip Speed Ratio End ="));
    m_pctrlLELabel->setAlignment(Qt::AlignLeft);
    m_pctrlLELineEdit = new FloatEdit;
    m_pctrlLELineEdit->setAlignment(Qt::AlignRight);
    m_pctrlLELineEdit->SetMin(double(0.01));
    m_pctrlLDLabel = new QLabel(tr("Tip Speed Ratio Delta ="));
    m_pctrlLDLabel->setAlignment(Qt::AlignLeft);
    m_pctrlLDLineEdit = new FloatEdit;
    m_pctrlLDLineEdit->setAlignment(Qt::AlignRight);
    m_pctrlLDLineEdit->SetMin(double(0.1));

    m_pctrlStartBEM = new QPushButton(tr("Start BEM"));

    SequenceLayout->addWidget(m_pctrlCreateBEM,1,2);
    SequenceLayout->addWidget(m_pctrlLSLabel,2,1);
    SequenceLayout->addWidget(m_pctrlLELabel,3,1);
    SequenceLayout->addWidget(m_pctrlLDLabel,4,1);
    SequenceLayout->addWidget(m_pctrlLSLineEdit,2,2);
    SequenceLayout->addWidget(m_pctrlLELineEdit,3,2);
    SequenceLayout->addWidget(m_pctrlLDLineEdit,4,2);
    SequenceLayout->addWidget(m_pctrlStartBEM,5,2);

    QGroupBox *AnalysisGroup = new QGroupBox(tr("Analysis Settings"));
    AnalysisGroup->setLayout(SequenceLayout);

    /////////-----------Turbine Simulation Control Layout (Bottom) ---------------//

    m_pctrlWind1 = new FloatEdit;
    m_pctrlWind1->SetMin(double(0.01));
    m_pctrlWind1Label = new QLabel(tr("Start = "));
    m_pctrlWind2 = new FloatEdit;
    m_pctrlWind2->SetMin(double(0.01));
    m_pctrlWind2Label = new QLabel(tr("End = "));
    m_pctrlWindDelta= new FloatEdit;
    m_pctrlWindDelta->SetMin(double(0.1));

    m_pctrlWindDeltaLabel = new QLabel(tr("Delta = "));
    m_pctrlDefineTurbineSim = new QPushButton(tr("Define Propeller Simulation"));
    m_pctrlStartTurbineSim = new QPushButton(tr("Start BEM"));

    speed1 = new QLabel;
    speed2 = new QLabel;
    speed3 = new QLabel;

    QGridLayout *WindLayout = new QGridLayout;
    WindLayout->addWidget(m_pctrlDefineTurbineSim,1,2);
    WindLayout->addWidget(m_pctrlWind1Label,2,1);
    WindLayout->addWidget(m_pctrlWind1,2,2);
    WindLayout->addWidget(speed1,2,3);
    WindLayout->addWidget(m_pctrlWind2Label,3,1);
    WindLayout->addWidget(m_pctrlWind2,3,2);
    WindLayout->addWidget(speed2,3,3);
    WindLayout->addWidget(m_pctrlWindDeltaLabel,4,1);
    WindLayout->addWidget(m_pctrlWindDelta,4,2);
    WindLayout->addWidget(speed3,4,3);
    WindLayout->addWidget(m_pctrlStartTurbineSim,5,2);


    QGroupBox *WindGroup = new QGroupBox(tr("Analysis Settings"));
    WindGroup->setLayout(WindLayout);
    //_______________________Curve Display______________________//

    QHBoxLayout *CurveDisplay = new QHBoxLayout;
    m_pctrlShowCurve  = new QCheckBox(tr("Curve"));
    m_pctrlShowPoints = new QCheckBox(tr("Points"));
    m_pctrlShowOpPoint= new QCheckBox(tr("Selected Op Point"));
    CurveDisplay->addWidget(m_pctrlShowCurve);
    CurveDisplay->addWidget(m_pctrlShowPoints);
    CurveDisplay->addWidget(m_pctrlShowOpPoint);

    QVBoxLayout *CurveGroup = new QVBoxLayout;
    m_pctrlCurveStyle = new LineCbBox();
    m_pctrlCurveWidth = new LineCbBox();
    m_pctrlCurveColor = new LineButton;
    for (int i=0; i<5; i++)
    {
            m_pctrlCurveStyle->addItem("item");
            m_pctrlCurveWidth->addItem("item");
    }
    m_pStyleDelegate = new LineDelegate;
    m_pWidthDelegate = new LineDelegate;
    m_pctrlCurveStyle->setItemDelegate(m_pStyleDelegate);
    m_pctrlCurveWidth->setItemDelegate(m_pWidthDelegate);

    QGridLayout *CurveStyleLayout = new QGridLayout;
    QLabel *lab200 = new QLabel(tr("Style"));
    QLabel *lab201 = new QLabel(tr("Width"));
    QLabel *lab202 = new QLabel(tr("Color"));
    lab200->setAlignment(Qt::AlignRight |Qt::AlignVCenter);
    lab201->setAlignment(Qt::AlignRight |Qt::AlignVCenter);
    lab202->setAlignment(Qt::AlignRight |Qt::AlignVCenter);
    CurveStyleLayout->addWidget(lab200,1,1);
    CurveStyleLayout->addWidget(lab201,2,1);
    CurveStyleLayout->addWidget(lab202,3,1);
    CurveStyleLayout->addWidget(m_pctrlCurveStyle,1,2);
    CurveStyleLayout->addWidget(m_pctrlCurveWidth,2,2);
    CurveStyleLayout->addWidget(m_pctrlCurveColor,3,2);
    CurveStyleLayout->setColumnStretch(2,5);


    CurveGroup->addLayout(CurveDisplay);
    CurveGroup->addLayout(CurveStyleLayout);
    CurveGroup->addStretch(1);

    QGroupBox *CurveBox = new QGroupBox(tr("Graph Curve Settings"));
    CurveBox->setLayout(CurveGroup);

    //////////////final Layout//////////////

    middleControls = new QStackedWidget;
    middleControls->addWidget(AnalysisGroup);
    middleControls->addWidget(WindGroup);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(SimuGroup);
    mainLayout->addWidget(middleControls);
    mainLayout->addWidget(CurveBox);
    mainLayout->insertStretch(100000,100000);;
    setLayout(mainLayout);
}


void SimuWidget::Connect()
{

    connect(m_pctrlStartBEM, SIGNAL(clicked()), this,SLOT(OnStartBEM()));
    connect(m_pctrlCreateBEM, SIGNAL(clicked()), this,SLOT(OnCreateBEM()));    
    connect(m_pctrlStartTurbineSim, SIGNAL(clicked()), SLOT(OnStartTurbineSimulation()));
    connect(m_pctrlDefineTurbineSim, SIGNAL(clicked()), SLOT(OnSetTurbineSimulationParameters()));

    connect(m_pctrlCurveStyle, SIGNAL(activated(int)), this, SLOT(OnCurveStyle(int)));
    connect(m_pctrlCurveWidth, SIGNAL(activated(int)), this, SLOT(OnCurveWidth(int)));
    connect(m_pctrlCurveColor, SIGNAL(clicked()), this, SLOT(OnCurveColor()));
    connect(m_pctrlShowPoints, SIGNAL(clicked()), this, SLOT(OnShowPoints()));
    connect(m_pctrlShowCurve, SIGNAL(clicked()), this, SLOT(OnShowCurve()));
    connect(m_pctrlShowOpPoint, SIGNAL(clicked()), this, SLOT(OnShowOpPoint()));


}

void SimuWidget::OnStartBEM()
{
    QBEM *pBEM = (QBEM *) m_pBEM;

    pBEM->OnStartRotorSimulation();
}

void SimuWidget::OnCreateBEM()
{
    QBEM *pBEM = (QBEM *) m_pBEM;

    pBEM->OnCreateRotorSimulation();
}

void SimuWidget::OnStartTurbineSimulation()
{
    QBEM *pBEM = (QBEM *) m_pBEM;

    pBEM->OnStartTurbineSimulation();;
}

void SimuWidget::OnSetTurbineSimulationParameters()
{
    QBEM *pBEM = (QBEM *) m_pBEM;

    pBEM->OnCreateTurbineSimulation();
}

void SimuWidget::OnCurveStyle(int index)
{
    QBEM *pBEM = (QBEM *) m_pBEM;

    pBEM->OnCurveStyle(index);
}

void SimuWidget::OnCurveColor()
{
    QBEM *pBEM = (QBEM *) m_pBEM;

    pBEM->OnCurveColor();
}

void SimuWidget::OnCurveWidth(int index)
{
    QBEM *pBEM = (QBEM *) m_pBEM;

    pBEM->OnCurveWidth(index);
}

void SimuWidget::OnShowPoints()
{
    QBEM *pBEM = (QBEM *) m_pBEM;

    pBEM->OnShowPoints();
}

void SimuWidget::OnShowCurve()
{
    QBEM *pBEM = (QBEM *) m_pBEM;

    pBEM->OnShowCurve();
}

void SimuWidget::OnShowOpPoint()
{
    QBEM *pBEM = (QBEM *) m_pBEM;

    pBEM->OnShowOpPoint();
}


