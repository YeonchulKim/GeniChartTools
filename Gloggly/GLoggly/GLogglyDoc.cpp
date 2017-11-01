
// GLogglyDoc.cpp : implementation of the CGLogglyDoc class
//

#include "stdafx.h"
#include "GLoggly.h"
#include "MainFrm.h"
#include "HeaderInfo.h"
#include "ProcessData.h"
#include "GLogglyDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGLogglyDoc

IMPLEMENT_DYNCREATE(CGLogglyDoc, CDocument)

BEGIN_MESSAGE_MAP(CGLogglyDoc, CDocument)
END_MESSAGE_MAP()


// CGLogglyDoc construction/destruction

CGLogglyDoc::CGLogglyDoc(): m_pBuf(0),m_pHeader(0),m_pProcData(0)
{
	// TODO: add one-time construction code here

}

CGLogglyDoc::~CGLogglyDoc()
{
	if(m_pBuf != NULL) delete m_pBuf;
	if(m_pHeader != NULL) delete m_pHeader;
	if(m_pProcData != NULL) delete m_pProcData;
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

BOOL CGLogglyDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  Add your specialized creation code here
	int llLength = 0;
	CFile file;
	if(file.Open(lpszPathName, CFile::modeRead))
	{
		llLength = (int)file.GetLength();
		if(m_pBuf != NULL) 
		{
			delete[] m_pBuf;	
			m_pBuf = NULL;
		}
		m_pBuf = new char[llLength+10];

		file.Read(m_pBuf, llLength);
		file.Close();
		m_pBuf[llLength]=0;	

		if(m_pHeader != NULL)
		{
			delete m_pHeader; m_pHeader = NULL;
			delete m_pProcData; m_pProcData = NULL;
		}
		m_pHeader = new CHeaderInfo();
		m_pProcData = new CProcessData();
		Parsing();
		UpdateAllViews(NULL);
	}

	return TRUE;
}

void CGLogglyDoc::Parsing()
{
	using namespace std;
	vector<string> lines; 
	vector<string> header;
	vector<string> items;
	
	
	char seps[] = "\r\n";
	Split(m_pBuf,seps,lines);//split line	
	std::vector<std::string> *pHeader = m_pHeader->GetHeader();
	pHeader->clear();
	pHeader->assign(CHeaderInfo::COUNT,"");
	for(size_t i = 0; i != CHeaderInfo::COUNT; i++)
	{
		m_pHeader->GetHeader()->at(i) = lines.at(i);		
		((CMainFrame*)AfxGetApp()->GetMainWnd())->GetOutputWnd()->FillBuildWindow(lines.at(i));
	}
	
	char seps1[] = ",";
	Split(lines[12],seps1,items);

	//assign tables
	int header_row = CHeaderInfo::COUNT+1;
	int rows = lines.size() - header_row;

	std::vector<std::vector<float>> *pTable = m_pProcData->GetTables();
	pTable->clear();
	//pTable->assign(rows,std::vector<float>(CProcessData::LAST,0.0));
	pTable->assign(CProcessData::LAST,std::vector<float>(rows,0.0));//[74][total lines]

	for(size_t i=13 ; i != lines.size(); i++)
	{
		vector<string> data;
		Split(lines[i],seps1,data);

		for ( int j = CProcessData::FIRST; j != CProcessData::LAST;j++ )
		{
			//(*pTable)[i-header_row][j] = static_cast<float>(atof(data[j].c_str()));
			if(j==CProcessData::FIRST)
			{
				(*pTable)[j][i-header_row] = static_cast<float>(5.0*i);//
			}
			else
				(*pTable)[j][i-header_row] = static_cast<float>(atof(data[j].c_str()));//
		}
		data.clear();
	}

}
void CGLogglyDoc::Split(std::string str,char* seps, std::vector<std::string>& v)
{
	using namespace std;
	char *token = 0;
	char *context = 0;

	token = strtok_s(const_cast<char  *>(str.c_str()), seps,&context );
	int i = 0;
	while( token != NULL )
	{	  
		v.push_back(string(token));
		token = strtok_s( NULL, seps,&context );
	}
}