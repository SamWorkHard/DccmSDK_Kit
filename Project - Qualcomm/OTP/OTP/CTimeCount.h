#pragma once

// 精确获得算法处理时间的类(毫秒量级)
class CTimeCount
{
public:
	// 计时开始
	CTimeCount();
	void Start(void);
	// 计时结束
	void End(void);
	// 获得算法处理时间(单位:秒)
	double GetUseTime(void);
    // 通过afxmessagebox提示时间
	void MessageBoxTip(void);

private:
	double use_time;// 算法处理时间 (单位: ms)
	LARGE_INTEGER new_time, old_time, frequency;// 计数值
};
