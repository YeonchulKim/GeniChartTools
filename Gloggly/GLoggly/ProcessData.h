#pragma once


class CProcessData
{
public:
	CProcessData(void);
	virtual ~CProcessData(void);

	enum COLUMN_HEADER
	{
		FIRST =0,
		DATE=FIRST,
		TIME,	
		DIFF_PRS,
		TUB_PRS,
		SHL_PRS,
		TB_PRESS_SET_PT,
		TUB_VENT_LCV,
		SHL_VENT_LCV,
		SHL_FILL_LCV,
		N2_SET_PT,
		N2_ACTUAL,
		H2_SET_PT,
		H2_ACTUAL,
		NH3_SET_PT,
		NH3_ACTUAL,
		OPT_SET_PT,
		OPT_ACTUAL,
		DI_SET_PT,
		D_VALVE,
		N2_DELIVERY,
		H2_DELIVERY,
		NH3_DELIVERY,
		OPT1_DELIVERY,
		SHELL_DELIV,
		SOLEN_DELIV,
		MTOP_SET_PT,
		MMID_SET_PT,
		MBOT_SET_PT,
		MBUF_SET_PT,
		PTOP_SET_PT,
		PSID_SET_PT,
		MTOP_PR_TMP,
		MMID_PR_TMP,
		MBOT_PR_TMP,
		MTOP_SP_TMP,
		MMID_SP_TMP,
		MBOT_SP_TMP,
		MBUF_TMP,
		PTOP_TMP,
		PSID_TMP,
		MAIN_TOP_S1,
		MAIN_TOP_S2,
		MAIN_MID_S1,
		MAIN_MID_S2,
		MAIN_BOT_S1,
		MAIN_BOT_S2,
		MAIN_BUF1,
		MAIN_BUF2,
		PLUG_TOP1,
		PLUG_TOP2,
		PLUG_SIDE1,
		PLUG_SIDE2,
		MAIN_TOP_P1,
		MAIN_TOP_P2,
		MAIN_MID_P1,
		MAIN_MID_P2,
		MAIN_BOT_P1,
		MAIN_BOT_P2,
		MTOP_POWER,
		MMID_POWER,
		MBOT_POWER,
		MBUF_POWER,
		PTOP_POWER,
		PSID_POWER,
		ENV_TOP_TEMP,
		ENV_BTM_TEMP,
		STM_OUT_TEMP,
		COOL_WAFER1,
		COOL_WAFER2,
		COOL_WAFER3,
		COOL_WAFER4,
		COOL_WAFER5,
		COOL_WAFER6,
		STEP,
		LAST
	};
public:
	std::vector<std::vector<float>>* GetTables(void){return &tables;}
private:
	std::vector<std::vector<float>> tables;
	
};
