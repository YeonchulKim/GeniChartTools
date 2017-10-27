
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

IMPLEMENT_DYNCREATE(CGLogglyView, CView)

BEGIN_MESSAGE_MAP(CGLogglyView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGLogglyView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CGLogglyView construction/destruction

CGLogglyView::CGLogglyView()
{
	// TODO: add construction code here

}

CGLogglyView::~CGLogglyView()
{
}

BOOL CGLogglyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGLogglyView drawing

void CGLogglyView::OnDraw(CDC* /*pDC*/)
{
	CGLogglyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CGLogglyView printing


void CGLogglyView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CGLogglyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGLogglyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGLogglyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
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
	CView::AssertValid();
}

void CGLogglyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGLogglyDoc* CGLogglyView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGLogglyDoc)));
	return (CGLogglyDoc*)m_pDocument;
}
#endif //_DEBUG


// CGLogglyView message handlers
