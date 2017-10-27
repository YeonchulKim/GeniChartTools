
// GLogglyDoc.h : interface of the CGLogglyDoc class
//


#pragma once


class CGLogglyDoc : public CDocument
{
protected: // create from serialization only
	CGLogglyDoc();
	DECLARE_DYNCREATE(CGLogglyDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CGLogglyDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


