
// GLogglyView.cpp : implementation of the CGLogglyView class
//

#include "stdafx.h"
#include "GLoggly.h"

#include "GLogglyDoc.h"
#include "GLogglyView.h"
#include "ProcessData.h"

#include <algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGLogglyView

IMPLEMENT_DYNCREATE(CGLogglyView, CFormView)

BEGIN_MESSAGE_MAP(CGLogglyView, CFormView)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CGLogglyView construction/destruction

CGLogglyView::CGLogglyView()
	: CFormView(CGLogglyView::IDD)
{
	// TODO: add construction code here

}

CGLogglyView::~CGLogglyView()
{
}

void CGLogglyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MAIN_GRAPH, c_Graph);
}

BOOL CGLogglyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CGLogglyView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
}

void CGLogglyView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGLogglyView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}

void CGLogglyView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here	
	if(IsWindow(c_Graph.GetSafeHwnd()))//please check chart control activation.
		c_Graph.SetWindowPos(NULL, 0, 0, cx-10, cy-10, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
}
// CGLogglyView diagnostics

#ifdef _DEBUG
void CGLogglyView::AssertValid() const
{
	CFormView::AssertValid();
}

void CGLogglyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CGLogglyDoc* CGLogglyView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGLogglyDoc)));
	return (CGLogglyDoc*)m_pDocument;
}
#endif //_DEBUG


// CGLogglyView message handlers

void CGLogglyView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: Add your specialized code here and/or call the base class
	std::vector<std::vector<float>> * const pTables = GetDocument()->GetProcessData()->GetTables();
	if(GetDocument()->GetBuffer() != NULL)
	{		
		c_Graph.ClearData();
		c_Graph.GetPlots().RemoveAll();
		
		float *pData = NULL;
		
		for(int i= 0 ; i != 74 ; i++)
		{	
			int plot = i+1;
			std::vector<float> tmp = (*pTables)[i];
			const int sz = tmp.size();
			CNiReal32Vector set(sz);

			pData = &tmp[0]; 
			::CopyMemory( (float*)set,pData,sizeof(float) * sz);		
			c_Graph.GetPlots().Add();
			c_Graph.GetPlots().Item(plot).SetAutoScale(TRUE);

			/*std::vector<float>::iterator max,min;			
			max = std::max_element(tmp.begin(),tmp.end());
			min = std::min_element(tmp.begin(),tmp.end());
			TRACE("Min=%lf / Max=%lf \n",*min,*max);*/

			c_Graph.GetPlots().Item(plot).PlotY(set, 0, 5);	
			c_Graph.GetPlots().Item(plot).SetLineColor(CNiColor(RGB(10+i*5,i*3,i*7)));

		}
	}
	
}
