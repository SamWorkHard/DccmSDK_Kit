#pragma once
#include "OtpCheckBase.h"

class OtpCheck_HLT7014 :public OtpCheckBase
{
public:
	OtpCheck_HLT7014(void);
	~OtpCheck_HLT7014(void);

private:

	int CheckGroup(BYTE flag);
	int CheckSum(BOOL flag,int flagaddr, int sumaddr, int datasize,  int gap,  CString str, int validgroup);	//��һ��checksum�����޷���������checksum��������������������checksum����
	void SaveOTPData();	

};
