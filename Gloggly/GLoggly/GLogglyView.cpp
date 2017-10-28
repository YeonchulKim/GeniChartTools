
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
