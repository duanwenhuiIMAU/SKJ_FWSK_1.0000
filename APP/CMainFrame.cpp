/* Generated by Together */
#include "APIBase.h"
#include "CMainFrame.h"
#include "LOGCTRL.h"
#include "pos_debug.h"
#include "CaWindow.h"
#include "SysMainMenu.h"

#include "LoginWin.h"

//要不断添加：销售档
#include "SaleData.h"
#include "SaleFunc.h"
#include "ProductSaleMainMenu.h"
#include "ProductSaleWin.h"

//要不断添加：功能编程档
#include "ProgramMainMenu.h"
#include "DeptEditWin.h"
#include "ClientEditWin.h"
#include "OperatorEditWin.h"
#include "SysArgMenu.h"
#include "SysArgEditWin.h"
//#include "NetManageMenu.h"
//#include "NetworkingSetWin.h"
//#include "NetServerSetWin.h"
#include "PswEditWin.h"
//#include "TemplateTransMenu.h"
//#include "WirelessViewWin.h"
//#include "WirelessInfoWin.h"
#include "SelDefWin.h"
#include "DataIOMenu.h"
//#include "NetModelEditWin.h"
//#include "ADSLInfoSetWin.h"
//#include "NetWlenCardWin.h"


//要不断添加：发票管理档
#include "InvManageMainMenu.h"
//#include "InvImportWin.h"
//#include "InvAssignWin.h"
#include "InvWasteWin.h"
#include "InvManageFunc.h"
#include "InvRetQueryWin.h"
#include "InvReturnWin.h"
#include "InvDistQueryWin.h"
//#include "InvImportFun.h"
#include "InvStubWin.h"
#include "InvStubPrnWin.h"
//#include "CurInvWin.h"
#include "InvWasteMenu.h"
#include "InvWstQueryWin.h"
#include "InvWstWin.h"
//#include "InvRetServerWin.h"
#include "InvSegMenu.h"
#include "InvDownloadMenu.h"
#include "InvDownloadNOWin.h"
#include "InvDownloadDateWin.h"
//#include "ReInvMenu.h"
#include "HostToInvWin.h"
#include "RetToInvWin.h"
#include "InvWllqfpWin.h"
#include "InvWllqfpjgqrWin.h"

//要不断添加：报表档
#include "ReportMainMenu.h"
#include "BasicReportMenu.h"
#include "MachineInfoWin.h"
#include "FiscalReportMenu.h"
#include "CommerceReportMenu.h"
#include "CorpInfoWin.h"
#include "MonthSaleSumWin.h"
#include "MonthSaleShowWin.h"
#include "DaySaleSumWin.h"
#include "SysLogDateWin.h"
#include "IssueSumDateWin.h"
#include "InvKindInfoWin.h"
#include "TaxInfoWin.h"
#include "TimeSumDateWin.h"
#include "TimeSumInfoWin.h"

//网络相关的窗口文件
#include "ADSLInfoSetWin.h"
#include "ApnAccPointSetWin.h"
#include "LocalNetworkMenu.h"
#include "M2MManageMenu.h"
#include "Net3GWlenMenu.h"
#include "Net3GWlenSetWin.h"
#include "NetIPModelWin.h"
#include "NetManageMenu.h"
#include "NetModelEditWin.h"
#include "NetModeSetMenu.h"
#include "NetServerSetWin.h"
#include "NetServMenu.h"
#include "NetWlenCardWin.h"
#include "NetworkingSetWin.h"
#include "NetworkingShowWin.h"
#include "NetworkSetMenu.h"
#include "VPNInfoSetWin.h"
#include "WirelessViewWin.h"
#include "WirelessInfoWin.h"
#include "NetAutoDialSetWin.h"
#include "ZhqParaSetMenu.h"
#include "ZhqBtlSetWin.h"
#include "ZhqIpaddrSetWin.h"
#include "ZhqServerSetWin.h"
#include "ZhqFtpSetWin.h"

//要不断添加：
#include "MaintenanceMenu.h"
#include "ClearDepotWin.h"
#include "ChangeDateTimeWin.h"
#include "SelfTestMenu.h"
#include "SelfTestFunc.h"
#include "SystemUpgrade.h"
#include "NetServMenu.h"
#include "DownLoadMacWin.h"
#include "UpdateMachineInfoWin.h"

//税务管理
#include "FiscalMainMenu.h"
#include "InfoUpdateMenu.h"
#include "MediumDeclareMenu.h"
#include "NetDeclareMenu.h"
#include "InitEditWin.h"
#include "ChangeDiskPswWin.h"
#include "FpblWin.h"
#include "HqlxsjWin.h"

CMainFrame::~CMainFrame(){}
CMainFrame::CMainFrame(){}
const char* CMainFrame::GetWinName(int id)
{
	DBG_ASSERT_EXIT( id >= 0 && id < WIN_MAX_NUM ,(" id=%d is invalid!",id));
// 	switch(id) {
// 	
// 	default:
// 		break;
// 	}
	return NULL;
}

int CMainFrame::ProcEvent(int iEvent, unsigned char *pEventData, int iDataLen)
{
	return CPosFrame::ProcEvent(iEvent,pEventData,iDataLen);
}

CaWindow *CMainFrame::GetWin(int id)
{
	CaWindow *win=CPosFrame::GetWin(id);
	win = (win != NULL) ? win :CreateWin(id);

	return win;
}

CaWindow *CMainFrame::IsWinExist(int id)
{
	return CPosFrame::GetWin(id);
}

void CMainFrame::ChangeWin( int id)
{
	if (GetWin(id) != NULL)
	{
		CPosFrame::ChangeWin(id);
	}
}

bool CMainFrame::Create()
{
   return true;
}

CaWindow *CMainFrame::CreateWin(int id)
{
	CaWindow *pWin = NULL;
	switch(id) {

//	case DIS_INVOICE_WIN:
//		{
//			pWin = new CInvoiceDistWin;
//			pWin->Create(0,0,SCREEN_W,SCREEN_H);
//		}
//		break;
	//发票录入
//	case INV_IMPORT_WIN:
//		{
//			pWin = new CInvImportWin;
//			pWin->Create(0,0,SCREEN_W,SCREEN_H);
//		}
//		break;
		//票号指定
//	case INV_ASSIGN_WIN:
//		{
//			pWin = new CInvAssignWin;
//			pWin->Create(0,0,SCREEN_W,SCREEN_H);
//		}
//		break;
	case INV_WLLQFP_WIN:
		{
			pWin = new CInvWllqfpWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
		/*
	case INV_WLLQFPJGQR_WIN:
		{
			pWin = new CInvWllqfpjgqrWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
		*/
	case HOST_TO_INV_WIN:
		{
			pWin = new CHostToInvWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
	case RET_TO_INV_WIN:
		{
			pWin = new CRetToInvWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
	case INV_MANAGE_MENU:
		{
			pWin = new CInvManageMenu;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
// 	case INITIALIZATION_WIN:
// 		{
// 			pWin = new CSysSetInitTime;
// 			pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 		}
// 		break;	
	case SYSTEM_MAIN_MENU:
		{
			pWin = new CSysMainMenu;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
	
	case PRODUCT_SALE_MAIN_MENU:
		{
			pWin = new CProductSaleMainMenu;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;

	case PRODUCT_SALE_WIN:
		{
			pWin = new CProductSaleWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
/*
//	case DECLARE_WIN:
//		{
//			pWin = new CDeclareWin();
//			pWin->Create(0,0,SCREEN_W,SCREEN_H);
//		}
//		break;
//	case DECLARE_DATE_SET:
//		{
//			pWin = new CDeclareSetDate();
//			pWin->Create(0,0,SCREEN_W,SCREEN_H);
//		}
//		break;
	case DETAIL_DATE_SET:
		{
			pWin = new CFDecDateSetWin();
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
//	case FISCAL_CHECK_WIN:
//		{
//			pWin = new CFiscalCheckWin();
//			pWin->Create(0,0,SCREEN_W, SCREEN_H);
//		}
//		break;
	case SERIAL_COMMUNICATION_WIN:
		{
			pWin = new CSerialCommunicationWin();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);

		}
		break;	*/	
	case INV_WASTE_WIN:
		{
			pWin = new CInvWasteWin();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case INV_RETURN_WIN:
		{
			pWin = new CInvReturnWin();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case INV_DIST_QUERY_WIN:
		{
			pWin = new CInvDistQueryWin();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
//	case CUR_INV_WIN:
//		{
//			pWin = new CCurInvWin();
//			pWin->Create(0,0,SCREEN_W, SCREEN_H);
//		}
//		break;
	case INV_STUB_WIN:
		{
			pWin = new CInvStubWin();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case INV_STUB_PRN_WIN:
		{
			pWin = new CInvStubPrnWin();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case INV_WASTE_MENU:
		{
			pWin = new CInvWasteMenu();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case INV_WST_QUERY_WIN:
		{
			pWin = new CInvWstQueryWin();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case INV_WST_WIN:
		{
			pWin = new CInvWstWin();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case MAINTENANCE_MENU:
		{
			pWin = new CMaintenanceMenu();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case CLEAR_DEPOT_WIN:
		{
			pWin = new CClearDepotWin();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case SELF_TEST_MENU:
		{
			pWin = new CSelfTestMenu();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case DOWNLOAD_MAC_WIN:
		{
			pWin = new CDownLoadMacWin();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case UPDATE_MACHINE_INFO_WIN:
		{
			pWin = new CUpdateMachindInfoWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	
	case PROGRAM_CTRL_MAIN_MENU:
		{
			pWin = new CProgramCtrlMenu;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
		
	case DEPT_EDIT_WIN:
		{
			pWin = new CDeptEditWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;

	case OPERATOR_EDIT_WIN:
		{
			pWin = new COperatorEditWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;

	case LOGIN_WIN:
		{
			pWin = new CLoginWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;

	case SYSTEM_ARG_MENU:
		{
			pWin = new CSysArgMenu;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;

	case SYS_ARG_EDIT_WIN:
		{
			pWin = new CSysArgEditWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
/*
	case DATA_TRANS_WIN:
		{
			pWin = new CDataTransWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
	case APDU_TEST_WIN:
		{
			pWin = new CAPDUTestWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;*/
	case CLIENT_EDIT_WIN:
		{
			pWin = new CClientEditWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
	case SYSTEM_UPGRADE_WIN:
		{
			pWin = new CSystemUpgradeWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
	case CHANGE_DATETIME_WIN:
		{
			pWin = new CChangeDateTime;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
 	case INV_SEG_MENU:
 		{
 			pWin = new CInvSegMenu;
 			pWin->Create(0,0,SCREEN_W,SCREEN_H);
 		}
 		break;
	case INV_DOWNLOAD_MENU:
		{
			pWin = new CInvDownloadMenu;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
			case INV_DOWNLOAD_NO_WIN:
		{
			pWin = new CInvDownloadNOWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
			case INV_DOWNLOAD_DATE_WIN:
		{
			pWin = new CInvDownloadDateWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
//	case RE_INV_MENU:
//		{
//			pWin = new CReInvMenu;
//			pWin->Create(0,0,SCREEN_W,SCREEN_H);
//		}
//		break;
// 	case NET_MANAGE_MENU:
// 		{
// 			pWin = new CNetManageMenu;
// 			pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 		}
// 		break;
// 	case NETWORKING_SET_WIN:
// 		{
// 			pWin = new CNetworkingSetWin;
// 			pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 		}
// 		break;
// 	case NET_SERVER_SET_WIN:
// 		{
// 			pWin = new CNetServerSetWin;
// 			pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 		}
// 		break;
	case PASSWD_EDIT_WIN:
		{
			pWin = new CPswEditWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;

 	case REPORT_MAIN_MENU:
 		{
 			pWin = new CReportMainMenu;
 			pWin->Create(0,0,SCREEN_W,SCREEN_H);
 		}
 		break;
 	case BASIC_REPORT_MENU:
 		{
 			pWin = new CBasicReportMenu;
 			pWin->Create(0,0,SCREEN_W,SCREEN_H);
 		}
 		break;
	case FISCAL_REPORT_MENU:
		{
			pWin = new CFiscalReportMenu;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
 	case MACHINE_INFO_WIN:
 		{
 			pWin = new CMachineInfoWin;
 			pWin->Create(0,0,SCREEN_W,SCREEN_H);
 		}
 		break;
// 	case SELF_DEF_WIN:
// 		{
// 			pWin = new CSelDefWin;
//  			pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 		}
// 		break;
//	case INV_RET_TO_SERVER_WIN:
//		{
//			pWin = new CInvRetServerWin;
// 			pWin->Create(0,0,SCREEN_W,SCREEN_H);
//		}
//		break;
// 		//	case TAX_ITEM_INFO_WIN:
// 		//		{
// 		//			pWin = new CTaxItemInfoWin;
// 		//			pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 		//		}
// 		//		break;
			case CORP_INFO_WIN:
				{
					pWin = new CCorpInfoWin;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
				// 增加票种信息
			case INV_KIND_INFO_WIN:
				{
					pWin = new CInvKindInfoWin;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
			case TAX_INFO_WIN:
				{
					pWin = new CTaxInfoWin;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
			
// 			case DAY_SUM_DATE_WIN:
// 				{
// 					pWin = new CDaySumDateWin;
// 					pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 				}
// 				break;
// 			case DAY_SUM_INFO_WIN:
// 				{
// 					pWin = new CDaySumInfoWin;
// 					pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 				}
// 				break;
			case TIME_SUM_DATE_WIN:
				{
					pWin = new CTimeSumDateWin;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
			case TIME_SUM_INFO_WIN:
				{
					pWin = new CTimeSumInfoWin;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
// 		//	case DECLARE_DATE_WIN:
// 		//		{
// 		//			pWin = new CDeclareDateWin;
// 		//			pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 		//		}
// 		//		break;
// 		//	case DECLARE_INFO_WIN:
// 		//		{
// 		//			pWin = new CDeclareInfoWin;
// 		//			pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 		//		}
// 		//		break;
// 			case AUTO_ISSUE_WIN:
// 				{
// 					pWin = new CAutoIssueWin;
// 					pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 				}
// 				break;
			case INV_RET_QUERY_WIN:
				{
					pWin = new CInvRetQueryWin;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
			case SYS_LOG_DATE_WIN:
				{
					pWin = new CSysLogDateWin;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
			case DATA_IO_MENU:
				{
					pWin = new CDataIOMenu;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
// 			case NETMODEL_EDIT_WIN:
// 				{
// 					pWin = new CNetModelEditWin;
// 					pWin->Create(0,0,SCREEN_W, SCREEN_H);
// 				}
// 				break;
// 			case ADSLINFO_SET_WIN:
// 				{
// 					pWin = new CADSLInfoSetWin;
// 					pWin->Create(0,0,SCREEN_W, SCREEN_H);
// 				}
// 				break;
			case COMMERCE_REPORT_MENU:
				{
					pWin = new CCommerceReportMenu;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
// 			case SALER_SUM_DATE_WIN:
// 				{
// 					pWin = new CSalerSumDateWin;
// 					pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 				}
// 				break;
			case DAY_SALE_SUM_WIN:
				{
					pWin = new CDaySaleSumWin;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
			case MONTH_SALE_SUM_WIN:
				{
					pWin = new CMonthSaleSumWIn;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
			case MONTH_SALE_SHOW_WIN:
				{
					pWin = new CMonthSaleShowWIn;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
			case FISCAL_MAIN_MENU:
				{
					pWin = new CFiscalMenu;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
			case INFO_UPDATE_MENU:
				{
					pWin = new CInfoUpdateMenu;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break; 	
			case MEDIUM_DECLARE_MENU:
				{
					pWin = new CMedDeclMenu;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break; 	
			case NET_DECLARE_MENU:
				{
					pWin = new CNetDeclMenu;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
			case CHANGE_DISK_PSW_WIN:
				{
					pWin = new CChangeDiskPswWin;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
// 		//	case UPDATA_TAXINFO_WIN:
// 		//		{
// 		//			pWin = new CUpdateTaxInfoWin;
// 		//			pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 		//		}
// 		//		break;
// 		//	case DECLARE_VIEW_WIN:
// 		//		{
// 		//			pWin = new CDeclareViewWin;
// 		//			pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 		//		}
// 		//		break;
			case ISSUE_SUM_DATE_WIN:
				{
					pWin = new CIssueSumDateWin;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);
				}
				break;
// 			case MONEY_INFO_WIN:
// 				{
// 					pWin = new CMoneyInfoWin;
// 					pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 				}
// 				break;
// 			case MAX_MONEY_EDIT_WIN:
// 				{
// 					pWin = new CMaxMoneyEditWin;
// 					pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 				}
// 				break;
// 			case INV_SALE_SUM_WIN:
// 				{
// 					pWin = new CInvSaleSumWin;
// 					pWin->Create(0,0,SCREEN_W,SCREEN_H);
// 				}
// 	case NET_WLEN_CARD_WIN:
// 			{
// 				pWin = new CNetWlenCardWin;
// 				pWin->Create(0,0,SCREEN_W, SCREEN_H);
// 			}
// 			break;
			case INIT_EDIT_WIN:
				{
					pWin=new CInitEditWin;
					pWin->Create(0,0,SCREEN_W,SCREEN_H);

				}
				break;
//////////////////////////////////////////////////////////////////////////
// 网络相关的窗口
//////////////////////////////////////////////////////////////////////////
	case ADSLINFO_SET_WIN:
		{
			pWin = new CADSLInfoSetWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;		
	case APN_ACCPOINT_SET_WIN:
		{
			pWin = new CApnAccPointSetWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case LOCAL_NETWORK_MENU:
		{
			pWin = new CLocalNetworkMenu;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case M2M_MANAGE_MENU:
		{
			pWin = new CM2MManageMenu;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case NET_3G_WLEN_MENU:
		{
			pWin = new CNet3GWlenMenu;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case NET_3GWLEN_SET_WIN:
		{
			pWin = new CNet3GWlenSetWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case NET_IP_MODEL_WIN:
		{
			pWin = new CNetIPModelWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case NET_MANAGE_MENU:
		{
			pWin = new CNetManageMenu;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
	case NETMODEL_EDIT_WIN:
		{
			pWin = new CNetModelEditWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case NET_MODE_SET_MENU:
		{
			pWin = new CNetModeSetMenu;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case NET_SERVER_SET_WIN:
		{
			pWin = new CNetServerSetWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
	case NET_SERV_MENU:
		{
			pWin = new CNetServMenu();
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case NET_WLEN_CARD_WIN:
		{
			pWin = new CNetWlenCardWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case NETWORKING_SET_WIN:
		{
			pWin = new CNetworkingSetWin;
			pWin->Create(0,0,SCREEN_W,SCREEN_H);
		}
		break;
	case NETWORKING_SHOW_WIN:
		{
			pWin = new CNetworkingShowWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case NETWORK_SET_MENU:
		{
			pWin = new CNetworkSetMenu;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case VPN_INFO_SET_WIN:
		{
			pWin = new CVPNInfoSetWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case WIRELESS_VIEW_WIN:
		{
			pWin = new CWirelessViewWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case WIRELESS_INFO_WIN:
		{
			pWin = new CWirelessInfoWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case NET_AUTO_DIAL_SET_WIN:
		{
			pWin = new CNetAutoDialSetWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;

#if TYPE_MODE == ZHQ_MODE
	case ZHQ_MANAGE_MENU:
		{
			pWin = new CZhqParaSetMenu;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case ZHQ_BTL_SET_WIN:
		{
			pWin = new CZhqBtlSetWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case ZHQ_IPADDR_SET_WIN:
		{
			pWin = new CZhqIpaddrSetWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;

	case ZHQ_FTP_SET_WIN:
		{
			pWin = new CZhqFtpSetWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;

	case ZHQ_SERVERIP_SET_WIN:
		{
			pWin = new CZhqServeripSetWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
#endif

	case FPBL_WIN:
		{
			pWin = new CFpblWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;
	case HQLXSJ_WIN:
		{
			pWin = new CHqlxsjWin;
			pWin->Create(0,0,SCREEN_W, SCREEN_H);
		}
		break;

//////////////////////////////////////////////////////////////////////////
// 网络相关的窗口(结束)
//////////////////////////////////////////////////////////////////////////
	default:
		break;
	}
	return pWin;
}

