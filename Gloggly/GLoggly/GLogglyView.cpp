
// GLogglyView.cpp : implementation of the CGLogglyView class
//

#include "stdafx.h"
#include "GLoggly.h"

#include "GLogglyDoc.h"
#include "GLogglyView.h"

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
	if(GetDocument()->GetBuffer() != NULL)
	{
		//CNiReal32Vector set(GetDocument()->GetTimes()->size());

		//float *pData = 0; 
		

		////Display
		/*c_Graph.ClearData();
		c_Graph.GetPlots().RemoveAll();

		float *pData = &GetDocument()->GetDiffPrs()->at(0);
		::CopyMemory( (float*)set,pData, sizeof(float) * GetDocument()->GetTimes()->size());		
		c_Graph.GetPlots().Add();
		c_Graph.GetPlots().Item(1).SetAutoScale(TRUE);
		c_Graph.GetPlots().Item(1).PlotY(set, 0, 15);
		c_Graph.GetPlots().Item(1).SetLineColor(CNiColor(RGB(255,0,0)));


		*pData = GetDocument()->GetShlPrs()->at(0);
		::CopyMemory( (float*)set,pData, sizeof(float) * GetDocument()->GetTimes()->size());
		c_Graph.GetPlots().Add();
		c_Graph.GetPlots().Item(2).SetAutoScale(TRUE);
		c_Graph.GetPlots().Item(2).PlotY(set, 0, 400);
		c_Graph.GetPlots().Item(2).SetLineColor(CNiColor(RGB(0,255,200)));*/

	}
}
