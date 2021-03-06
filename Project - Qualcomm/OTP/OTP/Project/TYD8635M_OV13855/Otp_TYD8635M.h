#pragma once

#include <vector>
#include <Windows.h>
#include "OtpDefine_TYD8635M.h"

class COtpTYD8635M : public COtpdefineTYD8635M
{
public:
	COtpTYD8635M(void);
	~COtpTYD8635M(void);

	////////////////////////////////Init Otp//////////////////////////////////////
	BOOL EraseAllData(void);
	void   SetWBDefaultGain(void);
	/////////////////////////////////LSC///////////////////////////////////////

	////////////////////////////////AWB////////////////////////////////////
	BOOL GetAWB(void);
	BOOL CheckOTPAWB(void);
    BOOL GetAWBInfo(tagAwbRatio* wb);
	BOOL TYD8635M_GetAWBData(TYD8635MOTPDataSpec &awbdata);
	BOOL TYD8635M_GetCurrentAWB(tagAwbRatio* wb);
	BOOL TYD8635M_CheckAWB(tagAwbRatio wb,int type);

	/////////////////////////////Burning/////////////////////////////////////////
	void   CreateBurningData(void);
	void   TYD8635M_GetBasicData(void);
	void   TYD8635M_GetAFData(void);
	void   TYD8635M_CalcAllCheckSum(void);
	BOOL TYD8635M_OtpWrite(void);
	BOOL WriteOTP(void);
	BOOL WriteOTP(vector<double>& vData);
	BOOL ProgrammingBasic(void);
	void Programming_3L8Basic(void);
	BOOL ProgrammingAWB(void);
	void Programming_3L8AWB(void);
	BOOL ProgrammingLSC(void);
	BOOL Programming_3L8LSC(void);
	void TYD8635M_WriteLSCFlagSum(void);
	BOOL ProgrammingAF(void);
	void Programming_3L8AF(void);
	BOOL ProgrammingPDAF(void);

	void SaveOTPData();	
	void SaveOTPData(vector<double>& vData);
	/////////////////////////////////Verify/////////////////////////////////////
	BOOL CheckOTP(void);
	BOOL TYD8635M_OTPVerify(void);
	BOOL TYD8635M_CheckOTPReadWrite(void);
	BOOL Sensor3L8_CheckReadWrite(void);
	BOOL Sensor3L8_CheckLSCReadWrite(void);
	BOOL TYD8635M_VerifyLSC();
	BOOL TYD8635M_VerifyAWB();
	BOOL VerifyLSC(void);
	BOOL VerifyPreWB(void);
	BOOL VerifyAWB(void);
	BOOL GetOTPRGBG(void);

	//////////////////////////////////////////////////////////////////////////
//	BOOL InitProgram(void);
	BOOL StartProgram(void);
//	BOOL EndProgram(void);



protected:
	void PreSubclassOtp(void);
	void SetOtpSensorParams(void);
private:
    OtpGroup Data_Write,Data_Read;
	tagAwbRatio m_wbCurrent;
	TYD8635MOTPDataSpec  OTP_Data_Write,OTP_Data_Read;

public:
	CString info;

	typedef struct tagAddressFlag
	{// Flag的Address
		WORD moduleInfo;
		WORD awb;
		WORD lsc;
		WORD af;
		WORD pdaf;
		WORD pdaf2;

	}AddressFlag;

	typedef struct tagAddressSum
	{// Sum的Address
		WORD moduleInfo;
		WORD awb;
		WORD lsc;
		WORD af;
		WORD pdaf;

	}AddressSum;

	typedef struct tagOtpSize
	{// 每个块占用的空间
		int moduleInfo;
		int awb;
		int lsc;
		int af;
		int pdaf;
	}OtpSize;

	typedef struct tagOtpPage
	{// 有Page类型的空间所在Page
		WORD moduleInfo;
		WORD awb;
		WORD lsc;
		WORD af;
		WORD pdaf;
		WORD pdaf_coef_k;

	}OtpPage;

	typedef struct tagAddressCode
	{// AF Code的Address
		WORD stcL;
		WORD stcH;
		WORD infL;
		WORD infH;
		WORD macL;
		WORD macH;

	}AddressCode;

	AddressFlag m_addrFlag;
	AddressSum	m_addrSum;
	OtpSize		m_otpSize;
	OtpPage		m_otpPage;
	AddressCode	m_addrCode;

	// slave addr
	WORD	m_slaveSensor;
	WORD	m_slaveEeprom;
	BYTE	m_modeSensor;//iic mode
	BYTE	m_modeEeprom;//iic mode
	BYTE	m_regSize;	// used for multiple read

	// valid flag val
	WORD m_flagEmpty;
	WORD m_flagValid;
// 	WORD m_flagGroup1;
// 	WORD m_flagGroup2;
// 	WORD m_flagGroup3;
	
	int proc1sum;

	BYTE TYD8635M_LSCWriteData[1868];
	BYTE TYD8635M_LSCReadData[1868];
	int TYD8635M_LSCchecksum;
};