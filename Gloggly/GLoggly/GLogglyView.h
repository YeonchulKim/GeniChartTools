
// GLogglyView.h : interface of the CGLogglyView class
//


#pragma once

#include "NiGraph.h"
class CGLogglyView : public CFormView
{
protected: // create from serialization only
	CGLogglyView();
	DECLARE_DYNCREATE(CGLogglyView)

public:
	enum{ IDD = IDD_GLOGGLY_FORM };

// Attributes
public:
	CGLogglyDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	

// Implementation
public:
	virtual ~CGLogglyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	NI::CNiGraph c_Graph;
// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // debug version in GLogglyView.cpp
inline CGLogglyDoc* CGLogglyView::GetDocument() const
   { return reinterpret_cast<CGLogglyDoc*>(m_pDocument); }
#endif

