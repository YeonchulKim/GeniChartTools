#include "StdAfx.h"
#include "HeaderInfo.h"

CHeaderInfo::CHeaderInfo(void)
{
	m_Header.resize(COUNT);
}

CHeaderInfo::~CHeaderInfo(void)
{
	m_Header.clear();
}
