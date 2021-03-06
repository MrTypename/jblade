/****************************************************************************

    CBody Class
	Copyright (C) 2007-2008 Andre Deperrois adeperrois@xflr5.com

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

#ifndef CBODY_H
#define CBODY_H

#include "Panel.h"
#include "Frame.h"
#include "../Params.h"

#include <QTextStream>
#include <QColor>

class CBody
{
public:
	CBody();

	CFrame* GetFrame(int iSelect);
	
	bool Gauss(double *A, int n, double *B, int m);
	bool IsInNURBSBody(CVector Pt);
	bool Intersect(CVector A, CVector B, CVector &I, bool bRight);
	bool IntersectPanels(CVector A, CVector B, CVector &I);
	bool IntersectNURBS(CVector A, CVector B, CVector &I, bool bRight);
	bool SerializeBody(QDataStream &ar, bool bIsStoring, int ProjectFormat);
//	bool SetModified();
	bool ImportDefinition() ;
	bool ExportDefinition() ;


	int InsertFrame(CVector Real);
	int InsertPoint(CVector Real);
	int IsFramePos(CVector Real, double ZoomFactor);
	int RemoveFrame(int n);
	int ReadFrame(QTextStream &in, int &Line, CFrame *pFrame, double const &Unit);

	double Length();
	double Getu(double x);
	double Getv(double u, CVector r, bool bRight);
	double GetSectionArcLength(double x);
	double SplineBlend(int const &index, int const &p, double const &t, double *knots);
	double TotalMass();
	double DistToNURBSBody(CVector Pt);

	CVector LeadingPoint();

	void ComputeAero(double *Cp, double &XCP, double &YCP,
					 double &GCm, double &GRm, double &GYm, double &Alpha, CVector &CoG);
	void ComputeCenterLine();
	void ComputeBodyAxisInertia();
	void ComputeVolumeInertia(CVector &CoG, double &CoGIxx, double &CoGIyy, double &CoGIzz, double &CoGIxz);
	void Duplicate(CBody *pBody);
	void ExportGeometry(int nx, int nh);
	void GetPoint(double u, double v, bool bRight, CVector &Pt);
	void InsertSideLine(int SideLine);
	void InterpolateCurve(CVector *D, CVector *P, double *v, double *knots, int degree, int Size);
	void InterpolateSurface();
	void RemoveActiveFrame();
	void RemoveSideLine(int SideLine);
	void Scale(double XFactor, double YFactor, double ZFactor, bool bFrameOnly=false, int FrameID=0);
	void Translate(double XTrans, double YTrans, double ZTrans, bool bFrameOnly=false, int FrameID=0);
	void Translate(CVector T, bool bFrameOnly=false, int FrameID=0);
	void SetKnots();
	void SetPanelPos();
	void UpdateFramePos(int iFrame);

//____________________VARIABLES_____________________________________________

	static void* s_pMainFrame;

	bool m_bClosedSurface;

	int m_NSideLines;
	int m_NStations;			// the number of stations along x-axis where frames are defined
	int m_iActiveFrame;		// the currently selected frame for display
	int m_iHighlight;		// the currently selected frame for display
	int m_LineType; //1=lines  2=B-Splines
	int m_iRes; //for splines
	int m_NElements;// = m_nxPanels * m_nhPanels *2
	int m_nxPanels, m_nhPanels;
	int m_nxDegree, m_nhDegree, m_nxKnots, m_nhKnots;
	int m_BodyStyle, m_BodyWidth;

	double m_Bunch;

	double m_VolumeMass, m_TotalMass;	    //for inertia calculations
	double m_MassValue[MAXMASSES];
	int m_NMass; //number of point mass values
	CVector m_MassPosition[MAXMASSES];
	QString m_MassTag[MAXMASSES];
	CVector m_CoG;
	double m_CoGIxx,m_CoGIyy,m_CoGIzz,m_CoGIxz;

	int m_np;
	double  m_x[IBX], m_y[IBX];	// the point coordinates of the overlayed body

	QString m_BodyName;
	QString m_BodyDescription;

	QColor m_BodyColor;

	CVector m_FramePosition[MAXBODYFRAMES];
	CFrame m_Frame[MAXBODYFRAMES];	// the frames at the stations

	int m_xPanels[MAXBODYFRAMES];
	int m_hPanels[MAXSIDELINES];

	CPanel *m_pPanel;

	//allocate temporary variables to
	//avoid lengthy memory allocation times on the stack
	double value, eps, bs, cs;
	CVector t_R, t_Prod, t_Q, t_r, t_N;
//	CVector P0, P1, P2, PI;
	static double s_xKnots[MAXBODYFRAMES*2];
	static double s_hKnots[MAXSIDELINES*2];
	static double s_XPanelPos[300];

};
#endif

