
// GLogglyDoc.h : interface of the CGLogglyDoc class
//


#pragma once
#include <string>
#include <vector>

class CHeaderInfo;
class CProcessData;
class CGLogglyDoc : public CDocument
{
protected: // create from serialization only
	CGLogglyDoc();
	DECLARE_DYNCREATE(CGLogglyDoc)

// Attributes
public:

// Operations
public:
	char * const GetBuffer(void){return m_pBuf;}
	

private:
	void Parsing();
	void Split(std::string str,char* seps, std::vector<std::string>& v);

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

private:
	char* m_pBuf;
	CHeaderInfo *m_pHeader;
	CProcessData *m_pProcData;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};


