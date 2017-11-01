#pragma once
#include <string>
#include <vector>
class CHeaderInfo
{
public:
	CHeaderInfo(void);
	~CHeaderInfo(void);

	enum ITEMS{
		TOOLNAME,
		USERNAME,
		CTRLTYPE,
		PRECIPE,
		LDRECIPE,		
		PLOG,
		N2LOG,
		O2LOG,
		LDLOG,
		N2LL_USE,
		USE_DUALSP,
		ITEM_TITLE,
		COUNT
	};

	std::vector<std::string>* GetHeader(){return &m_Header;}
private:
	std::vector<std::string> m_Header;
};
