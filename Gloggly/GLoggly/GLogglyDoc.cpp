
// GLogglyDoc.cpp : implementation of the CGLogglyDoc class
//

#include "stdafx.h"
#include "GLoggly.h"

#include "GLogglyDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGLogglyDoc

IMPLEMENT_DYNCREATE(CGLogglyDoc, CDocument)

BEGIN_MESSAGE_MAP(CGLogglyDoc, CDocument)
END_MESSAGE_MAP()


// CGLogglyDoc construction/destruction

CGLogglyDoc::CGLogglyDoc()
{
	// TODO: add one-time construction code here

}

CGLogglyDoc::~CGLogglyDoc()
{
}

BOOL CGLogglyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CGLogglyDoc serialization

void CGLogglyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CGLogglyDoc diagnostics

#ifdef _DEBUG
void CGLogglyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGLogglyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGLogglyDoc commands
