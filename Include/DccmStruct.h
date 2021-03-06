#pragma once
#include <vector>
using namespace std;


typedef struct tagModuleInfo
{
	CString CameraNum;       //模组型号 ex CM9002
	CString Customer;        //客户名   ex BBK
	CString Lens;            //物料名字
	CString VCM;             //物料名字
	CString ImageSensorIC;     //物料名字
	CString DriverIC;        //物料名字
	CString EepromIC;		
	CString IRfilter;        //物料名字
	CString QualityLevel;    //品质等级 ex A+
}ModuleInfo;

#define DTPIN_MAX   45
typedef struct tagOSTab
{	
	BOOL    OS_en;
    DWORD   PinMask_L;
    DWORD   PinMask_H;
	struct OSPin
	{
		double  OpenLimit;
		double  ShortLimit;
		CString Name;
	}Pin[DTPIN_MAX];
}OSTab;


typedef struct tagCurrentTab
{
	// 待机电流测试
	BOOL StandbyCurrent_En;
	BOOL StandbyCurrentTotal_En;
	int StandbyLimit_Total;
	int StandbyLimit_AVDD;
	int StandbyLimit_DOVDD;
	int StandbyLimit_DVDD;
	int StandbyLimit_AFVDD;
	int StandbyLimit_VPP;
	int StandByStableTime;

	// 工作电流测试
	BOOL WorkingCurrent_En;
	int WorkingLimit_AVDD;
	int WorkingLimit_DOVDD;
	int WorkingLimit_DVDD;
	int WorkingLimit_AFVDD;
	int WorkingLimit_VPP;
}CurrentTab;

typedef struct tagDccmISP
{
	BOOL bSharpen;
	BOOL bSmooth;
	BOOL bDPC;
	BOOL bOB;
	int  DPC_th; //DPC阈值
}DccmISP;

const int RgnMax = 9; // max region number 九宫格
typedef struct tagGeneralSettingTab
{
	DccmISP ISP;
    BOOL AutoExpEnable;			// 软件自动调整曝光时间进行自动曝光
	BOOL AutoExpInfo;			// 曝光信息显示
	BOOL RecordDllExp;			// 测试项记忆曝光
	int AutoExpTarget;
	int AutoExpTolerance;
	int AutoExpROI_Length;
	int WorkStation;			// 岗位设置

	BOOL RegionShowEnable;		//九宫格显示开启
	CPoint RegionCenterPoint[9]; //九宫格



	//模组编号的方式
	enum
	{
		IDMODE_RANDOM,			//随机生成
		IDMODE_MANUAL_INPUT,	//手动输入
		IDMODE_SENSOR_CHIP_ID,	//芯片自己的唯一ID
		IDMODE_AUTO_INPUT,		//二维码等自动设备获取
	    IDMODE_FROM_CHIPID_DB, 	//根据CHIPID查找数据库关联的ID
		IDMODE_AUTO_INPUTUSB,	// 根据USB接口的二维码设备等自动获取
	};
	int IDMode;
	CString CommID; 
	BOOL Bind_CamID_ChipID_En; //绑定 CAMID 和 sensor chip id
	BOOL Check_CamID_ChipID_En; //检查本次得到的二维码ID和chipID和已绑定的是否一致

	BOOL AutoExecuteFirstItem;    // 自动进入第一项测试
	BOOL AutoStopAfterLastItem;	  // 测完最后一项时，自动关闭模组
	BOOL SocketPwdnProtected_En;  // 探针测试架开启自动断电保护
	BOOL AutoFullScreenWhenStart; // 启动时自动全屏，关闭时恢复

	BOOL NoCompression;
	BOOL ColorOnColor_En;
	BOOL ForcedShow_En;

	BOOL SamePosRun_En;
	BOOL PowerOnDebug_En;

	BOOL ShowFinalResult;
	BOOL InterruptMode;
	BOOL AFClearGlue_En;

}GeneralSettingTab;

typedef struct tagDataSavingTab
{
	BOOL SaveToSQL_En;			//是否开启数据库存储测试记录
	BOOL SaveToSQL_ItemData_En; //测试项目详细数据记录
	BOOL CheckData_En;			//显示结果确认

	BOOL LocalReport_En;			//存储测试记录
	BOOL CheckLastWorkStation_En;
	CString LocalReportPath;

	CString ModuleType;
	CString WorkStation;
	CString Remarks;
	CString LastWorkStaion; //列名表
}DataSavingTab;

typedef struct tagImageInfo //导出给DLL的信息
{
	int   width;
	int   height;
	BYTE*   Y_Buf;
	BYTE*   RGB24_Buf;
	USHORT* Raw_Buf;
	BYTE    RawBits;
	BYTE    RawFormat;
}ImageInfo;

typedef struct tagSensorRegister
{
	USHORT Exp_Length;
	USHORT Exp_Reg;
	DWORD  Exp_Mask;
	DWORD  Exp_Reserve;
	USHORT Exp_Limit_Reg;

	USHORT AGain_Length;
	USHORT AGain_Reg;
	USHORT AGain_Mask;
	USHORT AGain_Reserve;

	USHORT Gain_R_Reg;
	USHORT Gain_GR_Reg;
	USHORT Gain_GB_Reg;
	USHORT Gain_B_Reg;

	USHORT Gain_Color_Mask;
}SensorRegister;


typedef struct tagFontInfo
{
	CString str;
	int fontSize;
	COLORREF color;
}FontInfo;


typedef struct tagszKeyValuePair
{
	CString Name;
	CString Value;
}szKeyValuePair;

typedef struct tagSensorPowerOffSequence
{
	int Reset;
	int Pwdn;
	int Mclk;
	BOOL Reset_En;
	BOOL Pwdn_En;
}SensorPowerOffSequence;


typedef struct tagSensorPowerOnSequence
{
	int AVDD;
	int DVDD;
	int DOVDD;
	int AFVDD;
	int VPP;
	int Reset;
	int Pwdn;
	int Mclk;
}SensorPowerOnSequence;

typedef struct tagIniSection
{
	CString keyname;
	CString szData;
}IniSection;

// 20160127
typedef struct tagBootInfo
{
	CString loadFile;
	int		language;		// 中文、English
	CString szServerIP;		// TcpServer's IP
	CString szServerPort;	// TcpServer's Port

	CString szClientIP;
	CString szClientPort;

	// 只读字段
	CString loginMode;		// Operator、Engineer
	CString password;		// Operator的密码
	int		DisableUI;		// 

	// 启动时程序的长宽
	int		width;
	int		height;
	int		deviceID;
	CString devName;	// device name
	int		appNumber;	// #[n]

	// 全平台兼容
	int		AppDisplayType;
}BootInfo;

// 20160127
typedef struct tagStartup
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		deviceID;
	int		appNumber;	// #[n]

	BOOL bManualStartup;
	CString szServerIP;		// TcpServer's IP
	CString szServerPort;	// TcpServer's Port

}Startup;