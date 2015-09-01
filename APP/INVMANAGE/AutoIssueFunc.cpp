/*! \file    AutoIssueFunc.cpp
   \brief    awe4000r��Ʊ������Զ���Ʊ����
   \author   Yu Yan 
   \version  1.0
   \date     2008-5-21
 */

#include "AutoIssueFunc.h"
#include "CGlobalArg.h"
#include "PowerOffData.h"
#include "TDateTime.h"
#include "InvManageFunc.h"
#include "keypad.h"
#include "CaProgressBar.h"
//#include "CInvImportFun.h" 
#include "CGlobalArg.h"
#include "CSysLog.h"
#include "CInvSum.h"
//#include "JSKInvDownProc.h"

#include "SaleData.h"

#include "LOGCTRL.h"
//#define NO_POS_DEBUG
#include "pos_debug.h"

//#if AUTOISSUE

#define PRINT  0
#define SMALL_INV_NUM 		3			/**< ������ÿ�յĿ�Ʊ������ */
#define BIG_INV_NUM 		200			/**< 5719�ź�������ÿ�յĿ�Ʊ������ */
#define THREE_MONTH 			3
#define TAX_DIVISOR             4		/**< ����Ʊ����Ŀ������1 */
#define MAX_INV_NO 				5719    /**< �Զ�������Ʊ���ķ�Ʊ�� */
#define STOP_INV_NO				5700	/**< �Զ�������Ʊ��ͣ�ķ�Ʊ�� */

#if AUTOISSUE
UINT8 AutoIssue(UINT8 &nIfInvSum)
{
	DBG_PRINT(("AutoIssue()"));
	switch(ISSUE_TYPE) 
	{
		case 0:
			DBG_PRINT(("SimpleAutoIssue()"));
			SimpleAutoIssue(nIfInvSum);
			break;
// 		case 1:
// 			ComplexAutoIssue();
// 			break;
// 		case 2:
// 			NetAutoIssue(nIfInvSum);
		default: break;
	}
	
	return SUCCESS;
}

UINT8 SimpleAutoIssue(UINT8 &nIfInvSum)
{
//	INT32 nKey = 0x0;
	UINT8 nKeyTime = 0;
	UINT32 nDate;
    UINT8 nVolNum = 0;//��Ʊ����
	UINT32 nInvNo = 0;
	UINT32 nCurrentInvNo = 0;
	INT8 chValue[256];
	string strInfo;
	memset((void*)chValue, 0, sizeof(chValue));
	SaleData saleInfo;
	CaProgressBar proBar("");
	UINT8 ret;
	
	for(;;)
	{
		//������Ʊ��ֹ���ڣ�ֹͣ��Ʊ
		nDate = TDateTime::CurrentDateTime().FormatInt(YYYYMMDD);
		DBG_PRINT(("for�� nDate = %u", nDate));
		DBG_PRINT(("for�� g_globalArg->m_curInvVol->m_remain = %u", g_globalArg->m_curInvVol->m_remain));

//		if (nDate>g_globalArg->m_corpInfo->m_ieDate) 
//		{
//			CaMsgBox::ShowMsg("������Ʊ��ֹ����\n�������걨!");
//			return FAILURE;		
//		}
// 		if (1 == g_globalArg->m_declareLimitFlag)
// 		{
// 			CaMsgBox::ShowMsg("�걨�ڳ���,�������걨");
// 			return FAILURE;
// 		}
		
		//����������ȷ�ϼ������˳���Ʊ����
		if(CheckKey2(nKeyTime)==SUCCESS)
		{
			return SUCCESS;
		}

		DBG_PRINT(("��ʼ�Զ���Ʊ"));

//		if(g_globalArg->m_curInvVol->m_remain != 0)
//		{
//			nCurrentInvNo = g_globalArg->m_curInvVol->m_ieno + 1 - 
//					g_globalArg->m_curInvVol->m_remain;
			//�ж��Ƿ��������Ҫ��������ʾ��Ϣ��
// 			if(IfInvHeadRoll()!=SUCCESS)
// 			{
// 				return FAILURE; 			
// 			}
// 			if(IfInvSumRoll()!=SUCCESS) 
// 			{
// 				return FAILURE; 			
// 			}
// 			if(IfRtInvRoll()!=SUCCESS) 
// 			{
// 				return FAILURE; 			
// 			}

// 			if (g_globalArg->m_curInvVol->m_remain == 2)
// 			{
// 				DBG_PRINT(("�Զ�����Ʊ"));
// 				if ((ret = SimpleMakeReturnInv(saleInfo)) != SUCCESS)
// 				{
// 					if (ret==DB_FULL) 
// 					{
// 						CaMsgBox::ShowMsg("�洢�ռ��������޷���Ʊ �뾡���걨!");
// 					}
// 					else if (HAVE_ROLLED==ret)
// 					{
// 						CaMsgBox::ShowMsg("�������!");			
// 					}
// 					else
// 					{
// 						CaMsgBox::ShowMsg("����Ʊʧ��!");
// 					}					
// 					return FAILURE;
// 				}
// 			}
// 			else if (g_globalArg->m_curInvVol->m_remain == 1)
// 			{
// 				DBG_PRINT(("�Զ�����Ʊ"));
// 				if ((ret = SimpleMakeWasteInv(saleInfo)) != SUCCESS)
// 				{
// 					if (ret==DB_FULL) 
// 					{
// 						CaMsgBox::ShowMsg("�洢�ռ��������޷���Ʊ �뾡���걨!");
// 					}
// 					else if (HAVE_ROLLED==ret)
// 					{
// 						CaMsgBox::ShowMsg("�������!");			
// 					}
// 					else
// 					{
// 						CaMsgBox::ShowMsg("����Ʊʧ��!");
// 					}	
// 					return FAILURE;
// 				}
// 			}
// 			else
// 			{
// 			while (g_globalArg->m_InvServNum > 0)
// 			{
// 				CommonSleep(1000);
// 			}
			CommonSleep(1000);
				DBG_PRINT(("�Զ�����Ʊ"));
				string strErr("");
				if ((ret = SimpleMakeNormalInv(saleInfo,strErr))!= SUCCESS)
				{
					DBG_PRINT(("ret= %u",ret));
					if (ret==DB_FULL) 
					{
						CaMsgBox::ShowMsg("�洢�ռ��������޷���Ʊ �뾡���걨!");
					}
					else if (HAVE_ROLLED==ret)
					{
						CaMsgBox::ShowMsg("�������!");			
					}
					else if(INV_LIB_ERR == ret)
					{
						CaMsgBox::ShowMsg(g_globalArg->m_strMsg);
					}
					else
					{
						CaMsgBox::ShowMsg(strErr);
					}	
					return FAILURE;
				}
//			}
			//----������ر�����λ
			saleInfo.InitSaleData(1);	//������Ϣ��ʼ��
			saleInfo.InitInvHead();		//���ŷ�Ʊ��Ϣ��ʼ��
			
			//memset((void*)chValue, 0, sizeof(chValue));
			nCurrentInvNo++;
			sprintf(chValue, "�Զ���Ʊ: %u��",nCurrentInvNo);
			proBar.SetText(chValue);
			proBar.ReFresh();

			
			/*
		}
		else
		{
			//����ܣ���ѯ��Ʊ�������롣���޷�Ʊ���򱨴�����
			if (GetInvNo(saleInfo, nInvNo) != SUCCESS)
			{
				return FAILURE;
			}

			if(nVolNum < 1)
			{
				nVolNum++;
				continue;
			}
			nVolNum = 0;
			
			//�޸�ϵͳʱ�䵽�ڶ���	
// 			TDateTime dateTime(nDate, 80000);
// 			dateTime++;
// 			if (!TDateTime::SetCurrentDateTime(dateTime))
// 			{
// 				CaMsgBox::ShowMsg("�޸�����ʱ�����!");
// 				return FAILURE;			
// 			}
// 			UINT32 nTestDate = TDateTime::CurrentDateTime().FormatInt(YYYYMMDD);
// 			DBG_PRINT(("�ӳٺ� nTestDate = %u", nTestDate));
		
			//�ջ���
// 			INT32 errorcode = 0;
// 			INT8 charValue[128];
// 			memset((void*)charValue, 0, sizeof(charValue));
// 			if ((errorcode = g_globalArg->CheckDaySum(0)) != SUCCESS)
// 			{
// 				sprintf(charValue, "�ս��׻��ܴ���%02x", errorcode);
// 				CaMsgBox::ShowMsg(charValue);
// 				return FAILURE;	
// 			}

			
		}*/
	}
}


UINT8 SimpleMakeNormalInv(SaleData &tmpSaleData,string &strErr)
{
	UINT8 ret;
	CInvDet *invDet = NULL;
	CInvHead invHead;
	tmpSaleData.m_smallInvInfo = &invHead;
    UINT32 nCurDate = TDateTime::CurrentDateTime().FormatInt(YYYYMMDD);
	UINT32 nCurTime = TDateTime::CurrentDateTime().FormatInt(HHMMSS);

	INT64 tmpDJ=0;
	INT64 moneyTaxSum=0;
	//��װ��Ʊ
	//��װ��Ʊͷ
	//tmpSaleData.m_smallInvInfo->m_fphm = g_globalArg->m_curInvVol->m_ieno + 1 - 
	//	g_globalArg->m_curInvVol->m_remain;  /**< ��Ʊ���� */

	ret = SALE_GetCurInv(g_globalArg->m_curInvVol,strErr);
	DBG_PRINT(("strErr= %s",strErr.c_str()));

	if (ret ==FAILURE)
	{
		DBG_PRINT(("��ȡ��ǰ��Ʊ�������%s",strErr.c_str()));
		return ret;
	}


	tmpSaleData.m_smallInvInfo->m_fphm = g_globalArg->m_curInvVol->m_curInvNo;
    tmpSaleData.m_smallInvInfo->m_fpdm = g_globalArg->m_curInvVol->m_code;  /**< ��Ʊ������ */  	
	tmpSaleData.m_smallInvInfo->m_kplx = NORMAL_INV;		//��Ʊ����	

	tmpSaleData.m_smallInvInfo->m_yfphm = 0;		//ԭ��Ʊ����
	tmpSaleData.m_smallInvInfo->m_yfpdm = "";		//ԭ��Ʊ����	
    tmpSaleData.m_smallInvInfo->m_fplb = atoi(g_globalArg->m_invKind->m_pzCode.c_str()); //��Ʊ����
	
	tmpSaleData.m_smallInvInfo->m_fkdw = "����";			//����������
	tmpSaleData.m_smallInvInfo->m_fkdwsh = "012345678901234";
	tmpSaleData.m_smallInvInfo->m_sky = g_globalArg->m_operator->m_name;		//����Ա����
//	tmpSaleData.m_smallInvInfo->m_opId = g_globalArg->m_operator->m_opId;		//����Աid	
//	tmpSaleData.m_smallInvInfo->m_uID = 0;          //��˰������ID��
//	tmpSaleData.m_smallInvInfo->m_ptype = 0;		//���ʽ
	tmpSaleData.m_smallInvInfo->m_sphsl = 3;//��ǰ��Ʊ����Ʒ�м�1

	tmpSaleData.m_smallInvInfo->m_kphjje = (INT64)(3.00 * SUM_EXTENSION);//��ǰ��Ʊ�ܽ��
 	tmpSaleData.m_smallInvInfo->m_backup1 = "";		//�����ֶ�1

//	tmpSaleData.m_smallInvInfo->m_backup2 = "";		//�����ֶ�2 
//	tmpSaleData.m_smallInvInfo->m_backup3 = "";		//�����ֶ�3

	//��Ʊ��ϸ
	for(UINT8 i = 1; i<4; i++)
	{
//		invDet = new CInvDet;
		invDet = invDet->GetNewInvDet();//�Ӿ�̬�����ȡһ�����õ�CInvDet����
		DBG_ASSERT_EXIT((invDet != NULL), (" invDet == NULL!"));
		invDet->m_fpdm = tmpSaleData.m_smallInvInfo->m_fpdm; 
		invDet->m_fphm = tmpSaleData.m_smallInvInfo->m_fphm;
	//	invDet->m_sphxh = i; 
		invDet->m_kprq = nCurDate;
		invDet->m_kpsj = nCurTime;
		invDet->m_kplx = NORMAL_INV;
		invDet->m_sky = g_globalArg->m_operator->m_name;


		invDet->m_spbm = "0000000000001";
		invDet->m_sphxh = i;
		invDet->m_spmc = "������Ʒ1";
	//	invDet->m_taxId = 1; //��˰��ֻ����˰Ŀ1
		invDet->m_spsl = 1.0; //��������������ֵ
		invDet->m_dotNum = 0;
		invDet->m_spdj = (double)1.00;
		invDet->m_spje = (INT64)(1.00*SUM_EXTENSION);
		invDet->m_sl = 0.03;
		invDet->m_spse=tmpSaleData.CountTax(invDet->m_spje, (UINT32)(invDet->m_sl*SUM_EXTENSION)); //��Ʒ˰��
	    invDet->m_je= invDet->m_spje - invDet->m_spse; //��Ʒ���(����˰)
	
		invDet->m_spdw = "��";	//��Ʒ��λ
		
		tmpDJ = double2int(invDet->m_spdj*SUM_EXTENSION);
		DBG_PRINT(("tmpDJ==%lld ", tmpDJ));
		tmpDJ -=tmpSaleData.CountTax(double2int(invDet->m_spdj*SUM_EXTENSION), (UINT32)(invDet->m_sl*SUM_EXTENSION));
		DBG_PRINT(("tmpDJ==%lld ", tmpDJ));
		
		invDet->m_dj= (double)(tmpDJ*1.0)/SUM_EXTENSION; //��Ʒ����(����˰)
		
		invDet->m_je= invDet->m_spje-invDet->m_spse; //��Ʒ���(����˰)
		moneyTaxSum += invDet->m_spse;
		invDet->m_property = DETAIL_GENERAL_GOODS;
		invDet->m_backup = "";
		tmpSaleData.m_smallInvInfo->InsertNode(invDet);	//����ڵ�
		
	}

	//��ǰ��Ʊ�ۼ�˰������
	tmpSaleData.m_smallInvInfo->m_kpse = moneyTaxSum;
	DBG_PRINT(("��ǰ��Ʊ�ۼ�˰�� tmpSaleData.m_smallInvInfo->m_kpse = %lld", tmpSaleData.m_smallInvInfo->m_kpse));
	moneyTaxSum = 0;

	ret = tmpSaleData.MakeInvoiceHandle(PRINT, INV_ROLL_PROC);
	tmpSaleData.m_smallInvInfo->DelList();
	tmpSaleData.m_smallInvInfo = NULL;
	if (ret != SUCCESS)
	{
		if (ret==DB_FULL) 
		{
			DBG_RETURN(DB_FULL);
		}
		else if (ret==HAVE_ROLLED) 
		{
			DBG_RETURN(HAVE_ROLLED);
		}
		else
		{
			DBG_RETURN(ret);
		}	
	}	
	DBG_RETURN(SUCCESS);	
}


// UINT8 SimpleMakeReturnInv(SaleData &tmpSaleData)
// {
// 	UINT8 ret;
// 	CInvDet*invDet = NULL;
// 	CInvHead invHead;
// 	tmpSaleData.m_smallInvInfo = &invHead;
//     UINT32 nCurDate = TDateTime::CurrentDateTime().FormatInt(YYYYMMDD);
// 	UINT32 nCurTime = TDateTime::CurrentDateTime().FormatInt(HHMMSS);
// 
// 	//��װ��Ʊ
// 	//��װ��Ʊͷ
// 	tmpSaleData.m_smallInvInfo->m_InvNo = g_globalArg->m_curInvVol->m_InvEndNo + 1 - 
// 		g_globalArg->m_curInvVol->m_remain;  /**< ��Ʊ���� */
//     tmpSaleData.m_smallInvInfo->m_codeNo = g_globalArg->m_curInvVol->m_codeNo;  /**< ��Ʊ������ */  	
// 	DBG_PRINT(("m_smallInvInfo->m_InvNo =  %u", tmpSaleData.m_smallInvInfo->m_InvNo));
//     DBG_PRINT(("m_smallInvInfo->m_codeNo =  %u", tmpSaleData.m_smallInvInfo->m_codeNo));
// 
// 	tmpSaleData.m_smallInvInfo->m_issuetype = RETURN_INV;		//��Ʊ����	
// 	tmpSaleData.m_smallInvInfo->m_oldInv = tmpSaleData.m_smallInvInfo->m_InvNo - 1;		//ԭ��Ʊ����	
//     DBG_PRINT(("m_smallInvInfo->m_issuetype =  %u", tmpSaleData.m_smallInvInfo->m_issuetype));
//    
// 	tmpSaleData.m_smallInvInfo->m_payer = "����";			//����������
// 	tmpSaleData.m_smallInvInfo->m_operator = g_globalArg->m_operator->m_name;		//����Ա����
// 	tmpSaleData.m_smallInvInfo->m_opId = g_globalArg->m_operator->m_opId;		//����Աid	
// 	tmpSaleData.m_smallInvInfo->m_uID = 0;          //��˰������ID��
// 	tmpSaleData.m_smallInvInfo->m_payType = 0;		//���ʽ
// 	tmpSaleData.m_smallInvInfo->m_goodsCount = 3;//��ǰ��Ʊ����Ʒ�м�1
// 	tmpSaleData.m_smallInvInfo->m_moneySum = (INT64)(0.3 * SUM_EXTENSION);//��ǰ��Ʊ�ܽ��
// 
//  	tmpSaleData.m_smallInvInfo->m_backup1 = "";		//�����ֶ�1
// 	tmpSaleData.m_smallInvInfo->m_backup2 = "";		//�����ֶ�2 
// 	tmpSaleData.m_smallInvInfo->m_backup3 = "";		//�����ֶ�3
// 
// 	
// 	//��Ʊ��ϸ
// 	for(UINT8 i = 1; i<4; i++)
// 	{
// //		invDet = new CInvDet;
// 		invDet = invDet->GetNewInvDet();//�Ӿ�̬�����ȡһ�����õ�CInvDet����
// 		DBG_ASSERT_EXIT((invDet != NULL), (" invDet == NULL!"));
// 		invDet->m_codeNo = tmpSaleData.m_smallInvInfo->m_codeNo; 
// 		invDet->m_InvNo = tmpSaleData.m_smallInvInfo->m_InvNo;
// 		invDet->m_destriptionNo = 0; 
// 		invDet->m_issueDate = nCurDate;
// 		invDet->m_issueTime = nCurTime;
// 		invDet->m_issuetype = RETURN_INV;
// 
// 		invDet->m_code = "1000000000001";
// 		invDet->m_dpNo = i;
// 		invDet->m_name = "������Ʒ1";
// 		invDet->m_taxId = 1;
// 		invDet->m_quantity = 1.0; //��������������ֵ
// 		invDet->m_dotNum = 0;
// 		invDet->m_price = (double)0.1;
// 
// 		invDet->m_moneySum = (INT64)(0.1*SUM_EXTENSION);
// 		invDet->m_property = DETAIL_GENERAL_GOODS;
// 		invDet->m_backup = "";
// 		tmpSaleData.m_smallInvInfo->InsertNode(invDet);	//����ڵ�		
// 	}
// 
// 	ret = tmpSaleData.MakeInvoiceHandle(PRINT, INV_ROLL_PROC);
// 	tmpSaleData.m_smallInvInfo->DelList();
//     tmpSaleData.m_smallInvInfo = NULL;
// 	if (ret != SUCCESS)
// 	{
// 		if (ret==DB_FULL) 
// 		{
// 			DBG_RETURN(DB_FULL);
// 		}
// 		else if (ret==HAVE_ROLLED) 
// 		{
// 			DBG_RETURN(HAVE_ROLLED);
// 		}
// 		else
// 		{
// 			DBG_RETURN(FAILURE);
// 		}	
// 	}	
// 	DBG_RETURN(SUCCESS);
// 
// }
// 
// 
// UINT8 SimpleMakeWasteInv(SaleData &tmpSaleData)
// {
// 	UINT8 ret;
// 	//��Ʊ����
// 	ret = InvWasteHandle(&tmpSaleData);
// 	if(ret != SUCCESS)
// 	{
// 		DBG_PRINT(("InvWaste error !"));
// 		if (ret==DB_FULL) 
// 		{
// 			DBG_RETURN(DB_FULL);
// 		}
// 		else if (ret==HAVE_ROLLED) 
// 		{
// 			DBG_RETURN(HAVE_ROLLED);
// 		}
// 		else
// 		{
// 			DBG_RETURN(FAILURE);
// 		}	
// 	}
// 		DBG_RETURN(SUCCESS);
// }




UINT8 GetInvNo(SaleData &tmpSaleData,UINT32 &invNo)
{
//	UINT8 status;
	UINT8 errorcode;
	CInvVol invVol;
	UINT8 nIfInvSum;

	CaProgressBar proBar("");

	if (g_globalArg->m_curInvVol->m_remain == 0)
	{
		DBG_PRINT(("�������"));
		proBar.SetText("�������");
		proBar.ReFresh();

		POWOFF_DISABLE(); //���ε����ж�
// 		if(!tmpSaleData.InvSum(nIfInvSum))
// 		{
// 			DBG_PRINT(("Get volume Sum error !"));
// 			CaMsgBox::ShowMsg("�������ʧ��!");
// 			POWOFF_ENABLE(); //�������ж�
// 			return FAILURE;
// 		}
		POWOFF_ENABLE(); //�������ж�
		//�жϾ�����Ƿ�Ҫ����������������ʾ��Ϣ��
// 		if(IfInvSumRoll()!=SUCCESS) 
// 		{
// 			return FAILURE; 			
// 		}

		proBar.SetText("�����·�Ʊ��");
		proBar.ReFresh();

		//��ѯ�ɵ���ķ�Ʊ��		
		invVol.m_filter = "where USED_FLAG = 1 and OVER_FLAG = 1 order by NO limit 1";
		invVol.Requery();  //��ѯ
		errorcode = invVol.LoadOneRecord();
		if (errorcode != SQLITE_OK)
		{
			CaMsgBox::ShowMsg("��ѯ�ɵ��뷢Ʊ��ʧ��!");
			return FAILURE;
		}

		//���������ĵ������
		
// 		InvoiceInfoPer_u invoiceInfoPerData; /**< ��Ʊ�ַ���ʱ�ļ��ṹ��*/			  
// 		memset((void *)&invoiceInfoPerData, 0, sizeof(InvoiceInfoPer_u));
// 	
// 		//��ѯ��Ʊ����
// 		CInvcodeLink invcodeLink;
// 		string strCode; 
// 		errorcode = invcodeLink.CodeNo2Code(strCode, invVol.m_codeNo);
// 		DBG_PRINT(("********errocode = %u\n", errorcode));
// 		if (errorcode!=SUCCESS)
// 		{
// 			CaMsgBox::ShowMsg("��ѯ��Ʊ����ʧ��!");
// 			return FAILURE;
// 		}
// 		char2bin((UINT8 *)(invoiceInfoPerData.invoice_code), (INT8 *)(strCode.c_str()), INV_TYPE_CODE_LEN);

// 
// 		invoiceInfoPerData.InvStart_no = invVol.m_InvStartNo;
// 		invoiceInfoPerData.InvEnd_no = invVol.m_InvEndNo;


		//���뷢Ʊ��
		string strErr;
// 		CInvoiceImport invImport;
// 		POWOFF_DISABLE(); //���ε����ж�
// //		if ((invImport.ImportInvVolHandle(&invoiceInfoPerData, strErr)) != SUCCESS)
// 		if ((invImport.ImportInvoice((UINT8 *)(invVol.m_code.c_str()), invVol.m_isno, strErr, 1)) != SUCCESS)
// 		{
// 			CaMsgBox::ShowMsg("��Ʊ����ʧ��!");
// 			return FAILURE;
// 		}

// 		//���µ�ǰ����Ϣ(����Ʊ���þ���Ϣ����)
// 		char sqlbuf[512];
// 		string sqlstr;	
// 		memset((void*)sqlbuf,0,sizeof(sqlbuf));
// 
// 		sprintf(sqlbuf,"update INV_VOL set USED_FLAG = %u where IS_NO = %u and CODE = %u",0, invVol.m_InvStartNo, invVol.m_codeNo);
// 		sqlstr=sqlbuf;
// 		invVol.SetSQL(sqlstr);
// 		if (invVol.ExecuteSQL() != SQLITE_OK)
// 		{
// 			CaMsgBox::ShowMsg("���µ�ǰ����Ϣ����!");
// 			return FAILURE;
// 		}
		POWOFF_ENABLE();//�������ж�

		//��ǰ����Ϣ��ֵ
// 		INT8 value[256];
// 		memset((void *)value, 0, sizeof(value));
// 		sprintf(value," where USED_FLAG = %u and  OVER_FLAG = %u", 0 , 1);
// 		g_globalArg->m_curInvVol->m_filter = value;
// 		g_globalArg->m_curInvVol->Requery(); 
// 		errorcode = g_globalArg->m_curInvVol->LoadOneRecord(); 
// 		switch(errorcode)
// 		{
// 		case SQLITE_OK:
// 			break;
// 		default:
// 			CaMsgBox::ShowMsg("����ǰ����Ϣ����!");
// 			return FAILURE;
// 		}

	}
	//���㵱ǰ��Ʊ��
	invNo = g_globalArg->m_curInvVol->m_ieno + 1 - 
		g_globalArg->m_curInvVol->m_remain;

	return SUCCESS;
}


UINT8 CheckKey2(UINT8 &nKeyTime)
{
	INT32 nKey = 0x0;
	if((nKey = ReadKeypad())&&(RETURN_MAIN_MENU == nKey) )
   	{
		nKeyTime++;
		if (nKeyTime==2)
		{
			nKeyTime = 0;
			return SUCCESS;
		}		
   	}
	return FAILURE;
}


//----------15�� ��������------------------//

// UINT8 ComplexAutoIssue()
// {
// 	UINT32 i;
// //	UINT32 date;
// 	UINT8 status;
// 	UINT32 invNo;
// 	UINT8 nKeyTime = 0;
// 	SaleData saleDataInfo, *pSaleData;
// 	pSaleData = &saleDataInfo;
// 	CInvHead invHead;
// 	INT8 charValue[256];
// 	UINT8 ret = 0;
// 	INT32 nIssuedNum = 0; //�����ѿ���Ʊ��
// 	UINT32 nNormalInvNum = SMALL_INV_NUM; //������ÿ�쿪Ʊ����
// 	
// 	UINT32 nDate = TDateTime::CurrentDateTime().FormatInt(YYYYMMDD);
// 	UINT32 DeclareDay = ThreeMonthsEndDay(g_globalArg->m_startDecDate, THREE_MONTH);
// 	
// 	memset((void*)charValue, 0, sizeof(charValue));
// 	sprintf(charValue,"where I_DATE = %u",nDate);
// 	invHead.m_filter = charValue;
// 	nIssuedNum = invHead.GetRecordNum();//�����ѿ���Ʊ����ͳ��
// 	if (nIssuedNum<0) 
// 	{
// 		CaMsgBox::ShowMsg("ͳ�Ƶ����ѿ���Ʊ��ʧ��");
// 		return FAILURE;
// 	}
// 		
// 	while(1)//g_globalArg->m_invCount<MAX_INV_NO
// 	{
// 		//��Ʊ
// 		nDate = TDateTime::CurrentDateTime().FormatInt(YYYYMMDD);
// 		if (IsLastDay(nDate))//�������һ��
// 		{
// 			ret = LastDayIssue(saleDataInfo, nNormalInvNum, nIssuedNum, nKeyTime);
// 		}
// 		else
// 		{
// 			ret = NormalDayIssue(saleDataInfo, nNormalInvNum, nIssuedNum,nKeyTime);
// 		}
// 		if (ret!=SUCCESS) 
// 		{
// 			return FAILURE;	
// 		}
// 		nIssuedNum = 0; //�����ѿ�Ʊ����0;
// 		
// 
// 		if (nDate>=DeclareDay) 
// 		{
// 			CaMsgBox::ShowMsg("3���ѵ��������걨");
// 		 	return SUCCESS;			
// 		}
// 
// 		//�޸�ϵͳʱ�䵽�ڶ���	
// 		TDateTime dateTime(nDate, 80000);
// 		dateTime++;
// 		if (!TDateTime::SetCurrentDateTime(dateTime))
// 		{
// 			CaMsgBox::ShowMsg("�޸�����ʱ�����!");
// 			return FAILURE;			
// 		}
// 		UINT32 nTestDate = TDateTime::CurrentDateTime().FormatInt(YYYYMMDD);
// 		DBG_PRINT(("�޸�ϵͳʱ�䵽 nTestDate = %u", nTestDate));
// 	
// 		//�ջ���
// 		INT32 errorcode = 0;
// 		memset((void*)charValue, 0, sizeof(charValue));
// 		if ((errorcode = g_globalArg->CheckDaySum(0)) != SUCCESS)
// 		{
// 			sprintf(charValue, "�ս��׻��ܴ���%02x", errorcode);
// 			CaMsgBox::ShowMsg(charValue);
// 			return FAILURE;	
// 		}
// 
// 		//STOP_INV_NO���Ժ��Ʊ����һ�ž��˳���Ʊ����
// 		if (g_globalArg->m_invCount>=STOP_INV_NO) 
// 		{
// 			return SUCCESS;			
// 		}
// 	}
// 	return SUCCESS;
// }
// 
// UINT32 ComputerMoney(UINT32 date, UINT8 No)
// {
// 	UINT32 y;
// 	UINT32 mm;
// 	UINT32 dd;
// 
// 	y = (date / 10000) % 10;
// 	mm = (date / 100) % 100;
// 	dd = date % 100;
// 	return (y * 100000 + mm * 1000 + dd * 10 + No);
// }
// 
// 
// 
// UINT32 ThreeMonthsEndDay(UINT32 nBeginDate, UINT8 nMonths)
// {
// 	TDateTime sDate(nBeginDate, 0);//�걨��ʼ��
// 	TDateTime eDate;
// 	UINT32 nEndDay = 0;
// 	
// 	eDate = sDate.MonthAdd(sDate, nMonths); //nMonths���º������
// 	eDate--;  //��һ��
// 	nEndDay = eDate.FormatInt(YYYYMMDD); //�걨��ֹ��
// 	DBG_PRINT(("�걨��ֹ�� nEndDay=  %u", nEndDay));
// 
// 	return nEndDay;	
// }
// 
// 
// UINT8 IsLastDay(UINT32 nDate)
// {
// 	UINT32 nNextDate = 0;
// 	TDateTime curDate(nDate, 0);
// 
// 	curDate++;	//��һ��
// 	nNextDate = curDate.FormatInt(YYYYMMDD);
// 	if ((nNextDate % 100) == 1)
// 	{
// 		return SUCCESS; //�����Ǳ������һ��
// 	}
// 	else
// 	{
// 		return FAILURE; //���첻�Ǳ������һ��
// 	}
// }
// 
// 
// UINT8 MakeNormalInv(SaleData &tmpSaleData, UINT8 nTaxId, UINT32 nInvNo)
// {
// 	UINT8 ret;
// 	CInvDet *invDet = NULL;
// 	CInvHead invHead;
// 	tmpSaleData.m_smallInvInfo = &invHead;
//     UINT32 nCurDate = TDateTime::CurrentDateTime().FormatInt(YYYYMMDD);
// 	UINT32 nCurTime = TDateTime::CurrentDateTime().FormatInt(HHMMSS);
// 
// 	//��װ��Ʊ
// 	//��װ��Ʊͷ
// 	tmpSaleData.m_smallInvInfo->m_InvNo = nInvNo;  /**< ��Ʊ���� */
//     tmpSaleData.m_smallInvInfo->m_codeNo = g_globalArg->m_curInvVol->m_codeNo;  /**< ��Ʊ������ */  	
// 
// 	tmpSaleData.m_smallInvInfo->m_issuetype = NORMAL_INV;		//��Ʊ����	
// 	tmpSaleData.m_smallInvInfo->m_oldInv = 0;		//ԭ��Ʊ����	
//   
// 	tmpSaleData.m_smallInvInfo->m_payer = "����";			//����������
// 	tmpSaleData.m_smallInvInfo->m_operator = g_globalArg->m_operator->m_name;		//����Ա����
// 	tmpSaleData.m_smallInvInfo->m_opId = g_globalArg->m_operator->m_opId;		//����Աid	
// 	tmpSaleData.m_smallInvInfo->m_uID = 0;          //��˰������ID��
// 	tmpSaleData.m_smallInvInfo->m_payType = 0;		//���ʽ
// 	tmpSaleData.m_smallInvInfo->m_goodsCount = 1;//��ǰ��Ʊ����Ʒ�м�1
// 	tmpSaleData.m_smallInvInfo->m_moneySum = ComputerMoney(nCurDate, nTaxId);//��ǰ��Ʊ�ܽ��
// 
//  	tmpSaleData.m_smallInvInfo->m_backup1 = "";		//�����ֶ�1
// 	tmpSaleData.m_smallInvInfo->m_backup2 = "";		//�����ֶ�2 
// 	tmpSaleData.m_smallInvInfo->m_backup3 = "";		//�����ֶ�3
// 
// 	//��Ʊ��ϸ	
// //	invDet = new CInvDet;
// 	invDet = invDet->GetNewInvDet();//�Ӿ�̬�����ȡһ�����õ�CInvDet����
// 	DBG_ASSERT_EXIT((invDet != NULL), (" invDet == NULL!"));
// 	invDet->m_codeNo = tmpSaleData.m_smallInvInfo->m_codeNo; 
// 	invDet->m_InvNo = tmpSaleData.m_smallInvInfo->m_InvNo;
// 	invDet->m_destriptionNo = 0; 
// 	invDet->m_issueDate = nCurDate;
// 	invDet->m_issueTime = nCurTime;
// 	invDet->m_issuetype = NORMAL_INV;
// 
// 	invDet->m_code = "1000000000001";
// 	invDet->m_dpNo = nTaxId;
// 	invDet->m_name = "������Ʒ1";
// 	invDet->m_taxId = nTaxId;
// 	invDet->m_quantity = 1.0; //��������������ֵ
// 	invDet->m_dotNum = 0;
// 	invDet->m_price = ((double)(tmpSaleData.m_smallInvInfo->m_moneySum))/SUM_EXTENSION;
// 
// 	invDet->m_moneySum = tmpSaleData.m_smallInvInfo->m_moneySum;
// 	invDet->m_property = DETAIL_GENERAL_GOODS;
// 	invDet->m_backup = "";
// 	tmpSaleData.m_smallInvInfo->InsertNode(invDet);	//����ڵ�
// 		
// 
// 	ret = tmpSaleData.MakeInvoiceHandle(0, INV_ROLL_PROC);
// 	tmpSaleData.m_smallInvInfo->DelList();
// 	tmpSaleData.m_smallInvInfo = NULL;
// 	if (ret != SUCCESS)
// 	{
// 		if (ret==DB_FULL) 
// 		{
// 			DBG_RETURN(DB_FULL);
// 		}
// 		else if (ret==HAVE_ROLLED) 
// 		{
// 			DBG_RETURN(HAVE_ROLLED);
// 		}
// 		else
// 		{
// 			DBG_RETURN(FAILURE);
// 		}		
// 	}	
// 	DBG_RETURN(SUCCESS);	
// }
// 
// UINT8 MakeReturnInv(SaleData &tmpSaleData, UINT8 nTaxId, UINT32 nInvNo)
// {
// 	UINT8 ret;
// 	CInvDet*invDet = NULL;
// 	CInvHead invHead;
// 	tmpSaleData.m_smallInvInfo = &invHead;
//     UINT32 nCurDate = TDateTime::CurrentDateTime().FormatInt(YYYYMMDD);
// 	UINT32 nCurTime = TDateTime::CurrentDateTime().FormatInt(HHMMSS);
// 
// 	//��װ��Ʊ
// 	//��װ��Ʊͷ
// 	tmpSaleData.m_smallInvInfo->m_InvNo = nInvNo;  /**< ��Ʊ���� */
//     tmpSaleData.m_smallInvInfo->m_codeNo = g_globalArg->m_curInvVol->m_codeNo;  /**< ��Ʊ������ */  	
// 	DBG_PRINT(("m_smallInvInfo->m_InvNo =  %u", tmpSaleData.m_smallInvInfo->m_InvNo));
//     DBG_PRINT(("m_smallInvInfo->m_codeNo =  %u", tmpSaleData.m_smallInvInfo->m_codeNo));
// 
// 	tmpSaleData.m_smallInvInfo->m_issuetype = RETURN_INV;		//��Ʊ����	
// 	tmpSaleData.m_smallInvInfo->m_oldInv = tmpSaleData.m_smallInvInfo->m_InvNo - 3;		//ԭ��Ʊ����	
//     DBG_PRINT(("m_smallInvInfo->m_issuetype =  %u", tmpSaleData.m_smallInvInfo->m_issuetype));
//    
// 	tmpSaleData.m_smallInvInfo->m_payer = "����";			//����������
// 	tmpSaleData.m_smallInvInfo->m_operator = g_globalArg->m_operator->m_name;		//����Ա����
// 	tmpSaleData.m_smallInvInfo->m_opId = g_globalArg->m_operator->m_opId;		//����Աid	
// 	tmpSaleData.m_smallInvInfo->m_uID = 0;          //��˰������ID��
// 	tmpSaleData.m_smallInvInfo->m_payType = 0;		//���ʽ
// 	tmpSaleData.m_smallInvInfo->m_goodsCount = 1;//��ǰ��Ʊ����Ʒ�м�1
// 	tmpSaleData.m_smallInvInfo->m_moneySum = ComputerMoney(nCurDate, nTaxId);//��ǰ��Ʊ�ܽ��
// 
//  	tmpSaleData.m_smallInvInfo->m_backup1 = "";		//�����ֶ�1
// 	tmpSaleData.m_smallInvInfo->m_backup2 = "";		//�����ֶ�2 
// 	tmpSaleData.m_smallInvInfo->m_backup3 = "";		//�����ֶ�3
// 
// 	
// 	//��Ʊ��ϸ	
// 	// invDet = new CInvDet;
// 	invDet = invDet->GetNewInvDet();//�Ӿ�̬�����ȡһ�����õ�CInvDet����
// 	DBG_ASSERT_EXIT((invDet != NULL), (" invDet == NULL!"));
// 	invDet->m_codeNo = tmpSaleData.m_smallInvInfo->m_codeNo; 
// 	invDet->m_InvNo = tmpSaleData.m_smallInvInfo->m_InvNo;
// 	invDet->m_destriptionNo = 0; 
// 	invDet->m_issueDate = nCurDate;
// 	invDet->m_issueTime = nCurTime;
// 	invDet->m_issuetype = RETURN_INV;
// 
// 	invDet->m_code = "1000000000001";
// 	invDet->m_dpNo = nTaxId;
// 	invDet->m_name = "������Ʒ1";
// 	invDet->m_taxId = nTaxId;
// 	invDet->m_quantity = 1.0; //��������������ֵ
// 	invDet->m_dotNum = 0;
// 	invDet->m_price = ((double)(tmpSaleData.m_smallInvInfo->m_moneySum))/SUM_EXTENSION;
// 
// 	invDet->m_moneySum = tmpSaleData.m_smallInvInfo->m_moneySum;
// 	invDet->m_property = DETAIL_GENERAL_GOODS;
// 	invDet->m_backup = "";
// 	tmpSaleData.m_smallInvInfo->InsertNode(invDet);	//����ڵ�		
// 	
// 
// 	ret = tmpSaleData.MakeInvoiceHandle(0, INV_ROLL_PROC);
// 	tmpSaleData.m_smallInvInfo->DelList();
//     tmpSaleData.m_smallInvInfo = NULL;
// 	if (ret != SUCCESS)
// 	{
// 		if (ret==DB_FULL) 
// 		{
// 			DBG_RETURN(DB_FULL);
// 		}
// 		else if (ret==HAVE_ROLLED) 
// 		{
// 			DBG_RETURN(HAVE_ROLLED);
// 		}
// 		else
// 		{
// 			DBG_RETURN(FAILURE);
// 		}	
// 	}	
// 	DBG_RETURN(SUCCESS);
// 
// }
// 
// UINT8 MakeWasteInv(SaleData &tmpSaleData)
// {
// 	UINT8 ret;
// 	//��Ʊ����
// 	ret = InvWasteHandle(&tmpSaleData);
// 	if(ret != SUCCESS)
// 	{
// 		DBG_PRINT(("InvWaste error !"));
// 		if (ret==DB_FULL) 
// 		{
// 			DBG_RETURN(DB_FULL);
// 		}
// 		else if (ret==HAVE_ROLLED) 
// 		{
// 			DBG_RETURN(HAVE_ROLLED);
// 		}
// 		else
// 		{
// 			DBG_RETURN(FAILURE);
// 		}		
// 	}
// 	DBG_RETURN(SUCCESS);
// }
// 
// 
// UINT8 NormalDayIssue(SaleData &tmpSaleData, UINT32 nInvNum, UINT32 IssuedNum, UINT8 &nKeyTime)
// {
// 	UINT32 i;
// 	UINT8 ret;
// 	UINT32 nInvNo = 0;
// 	INT8 chValue[128];
// 	memset((void*)chValue, 0, sizeof(chValue));
// 	CaProgressBar proBar("");
// 	
// 	//������Ʊ
// 	for(i=IssuedNum+1; i<=nInvNum; i++)
// 	{
// 		//����ܣ���ѯ��Ʊ�������롣���޷�Ʊ���򱨴�����
// 		if (GetInvNo(tmpSaleData, nInvNo) != SUCCESS)
// 		{
// 			return FAILURE;
// 		}
// 		//���ΰ����˳�����,���˳�����
// 		if(CheckKey(nKeyTime)==SUCCESS)
// 		{
// 			return FAILURE; 
// 		}
// 		//�ж��Ƿ��������Ҫ��������ʾ��Ϣ��
// 		if(IfInvHeadRoll()!=SUCCESS)
// 		{
// 			return FAILURE; 			
// 		}
// 
// 		DBG_PRINT(("�Զ�����Ʊ"));
// 		if ((ret = MakeNormalInv(tmpSaleData, i%TAX_DIVISOR, nInvNo))!= SUCCESS)
// 		{
// 			if (ret==DB_FULL) 
// 			{
// 				CaMsgBox::ShowMsg("�洢�ռ��������޷���Ʊ �뾡���걨!");
// 			}
// 			else if (HAVE_ROLLED==ret)
// 			{
// 				CaMsgBox::ShowMsg("�������!");			
// 			}
// 			else
// 			{
// 				CaMsgBox::ShowMsg("��Ʊʧ��!");
// 			}	
// 			return FAILURE;
// 		}
// 		//----������ر�����λ
// 		tmpSaleData.InitSaleData(1);	//������Ϣ��ʼ��
// 		tmpSaleData.InitInvHead();		//���ŷ�Ʊ��Ϣ��ʼ��
// 		
// 		//memset((void*)chValue, 0, sizeof(chValue));
// 		sprintf(chValue, "�Զ���Ʊ: %u��",nInvNo);
// 		proBar.SetText(chValue);
// 		proBar.ReFresh();
// 	}
// 	
// 	return SUCCESS;
// 
// }
// 
// 
// UINT8 LastDayIssue(SaleData &tmpSaleData, UINT32 nInvNum, UINT32 IssuedNum, UINT8 &nKeyTime)
// {
// 	UINT32 i;
// 	UINT8 ret;
// 	UINT32 nInvNo = 0;
// 	INT8 chValue[256];
// 	UINT32 retIssuedNum = 0;
// 	memset((void*)chValue, 0, sizeof(chValue));
// 	CaProgressBar proBar("");
// 	
// 	if (IssuedNum<=nInvNum)
// 	{
// 		//������Ʊ
// 		if (NormalDayIssue(tmpSaleData, nInvNum, IssuedNum, nKeyTime)!=SUCCESS) 
// 		{
// 			return FAILURE;		
// 		}
// 		IssuedNum = 0;
// 	}
// 	else
// 	{
// 		retIssuedNum = IssuedNum - 3;//��Ʊ�ѿ�����		
// 	}
// 
// 	//���ź�Ʊ��һ�ŷ�Ʊ
// 	for(i=retIssuedNum+1; i<=nInvNum+1; i++)
// 	{
// 		//����ܣ���ѯ��Ʊ�������롣���޷�Ʊ���򱨴�����
// 		if (GetInvNo(tmpSaleData, nInvNo) != SUCCESS)
// 		{
// 			return FAILURE;
// 		}
// 		//���ΰ����˳�����,���˳�����
// 		if(CheckKey(nKeyTime)==SUCCESS)
// 		{
// 			return FAILURE; 
// 		}
// 		if(IfInvHeadRoll()!=SUCCESS)
// 		{
// 			return FAILURE; 			
// 		}
// 
// 		if (4 == i)
// 		{
// 			DBG_PRINT(("�Զ�����Ʊ"));
// 			ret = SimpleMakeWasteInv(tmpSaleData);			
// 		}
// 		else
// 		{
// 			DBG_PRINT(("�Զ�����Ʊ"));
// 			ret = MakeReturnInv(tmpSaleData, i%TAX_DIVISOR, nInvNo);
// 		}
// 
// 		if (ret!= SUCCESS)
// 		{
// 			if (ret==DB_FULL) 
// 			{
// 				CaMsgBox::ShowMsg("�洢�ռ��������޷���Ʊ �뾡���걨!");
// 			}
// 			else if (HAVE_ROLLED==ret)
// 			{
// 				CaMsgBox::ShowMsg("�������!");			
// 			}
// 			else
// 			{
// 				CaMsgBox::ShowMsg("��Ʊʧ��!");
// 			}	
// 			return FAILURE;
// 		}
// 		//----������ر�����λ
// 		tmpSaleData.InitSaleData(1);	//������Ϣ��ʼ��
// 		tmpSaleData.InitInvHead();		//���ŷ�Ʊ��Ϣ��ʼ��
// 		
// 		//memset((void*)chValue, 0, sizeof(chValue));
// 		sprintf(chValue, "�Զ���Ʊ: %u��",nInvNo);
// 		proBar.SetText(chValue);
// 		proBar.ReFresh();
// 	}	
// 	DBG_RETURN(SUCCESS);
// 
// }

UINT8 IfInvHeadRoll()
{
	CInvHead curInvHead;
	UINT8 ret = SUCCESS;
	UINT32 nInvDelDate = 0;
	
//	ret = CheckIfFull(g_globalArg->m_invCount, g_globalArg->m_invSumCount);
//	if (ret==SUCCESS) 
//	{
//		DBG_RETURN(DB_FULL);		
//	}

	TDateTime lastDate(g_globalArg->m_startDecDate, 000001);
	lastDate--;
	UINT32 nRefDate = lastDate.FormatInt(YYYYMMDD);//�ϴ��걨�Ľ�ֹ����

	//�ж��Ƿ���Ҫ������������������ļ�¼����
	ret = curInvHead.CheckRoll(g_globalArg->m_invCount, nRefDate,nInvDelDate);
	if (ret!=SUCCESS)
	{
		CaMsgBox::ShowMsg("��Ʊ���������ж�ʧ��!");
		DBG_RETURN(FAILURE);
	}

	//����
	if (nInvDelDate>0)
	{
		DBG_PRINT(("nInvDelDate = %u", nInvDelDate));
		CaMsgBox::ShowMsg("��Ʊ����Ҫ����!");
	}
	DBG_RETURN(SUCCESS);
}

UINT8 IfInvSumRoll()
{
	CInvSum curInvSum;
	UINT8 ret = SUCCESS;
	UINT32 nSumDelDate = 0;

	TDateTime lastDate(g_globalArg->m_startDecDate, 000001);
	lastDate--;
	UINT32 nRefDate = lastDate.FormatInt(YYYYMMDD);//�ϴ��걨�Ľ�ֹ����

	ret = curInvSum.CheckRoll(g_globalArg->m_invSumCount, nRefDate,nSumDelDate);
	if (ret!=SUCCESS)
	{
		CaMsgBox::ShowMsg("������ܹ����ж�ʧ��!");
		DBG_RETURN(FAILURE);
	}

	if (nSumDelDate>0)
	{
		DBG_PRINT(("nSumDelDate = %u", nSumDelDate));
		CaMsgBox::ShowMsg("�������Ҫ����!");		
	}
	
	DBG_RETURN(SUCCESS);

}

UINT8 IfRtInvRoll()
{
	CRtInv curRtInv;
	UINT8 ret = SUCCESS;
// 	UINT32 nSumDelDate = 0;
	UINT32 nRtDetNo = 0;

//	TDateTime lastDate(g_globalArg->m_startDecDate, 000001);
//	lastDate--;
//	UINT32 nRefDate = lastDate.FormatInt(YYYYMMDD);//�ϴ��걨�Ľ�ֹ����

	ret = curRtInv.CheckRoll(g_globalArg->m_rtInvCount, nRtDetNo);
	if (ret!=SUCCESS)
	{
		CaMsgBox::ShowMsg("��Ʊ��Ϣ�����ж�ʧ��!");
		DBG_RETURN(FAILURE);
	}

	if (nRtDetNo>0)
	{
		DBG_PRINT(("nRtDetNo = %u", nRtDetNo));
		CaMsgBox::ShowMsg("��Ʊ��ϢҪ����!");		
	}
	
	DBG_RETURN(SUCCESS);

}

//-----------15�� ��������----------------------//

/*
UINT8 WriteSysLog(void)
{
	CSysLog syslog;
	INT32 nCount = 0;
	INT32 nLeft = 0;
	UINT32 i;
	INT8 chMsg[128];
	CaProgressBar proBar("");
	UINT8 nKeyTime = 0;
	UINT8 ret;

	nCount = syslog.GetSysLogNum();
	DBG_PRINT(("nCount = %d", nCount));
	
	if (nCount<0)
	{
		nCount = 0;
		CaMsgBox::ShowMsg("ͳ��ϵͳ��־��ʧ��");
		DBG_RETURN(FAILURE);
	}

	nLeft =  SYSLOG_MAX - nCount;
	if (nLeft>0) 
	{
		for(i = 0; i<nLeft; i++)
		{
			//���ΰ����˳�����,���˳�����
			if(CheckKey(nKeyTime)==SUCCESS)
			{
				return FAILURE; 
			}
			ret = CGlobalArg::SysLog(EVENT_IMPORT_INVOICE, SUCCESS);//дϵͳ��־
			if (ret!=SUCCESS)
			{
				CaMsgBox::ShowMsg("дϵͳ��־��ʧ��");
				DBG_RETURN(FAILURE);
			}
			nCount++;
			sprintf(chMsg, "����SysLog��¼: %u��",nCount);
			proBar.SetText(chMsg);
			proBar.ReFresh();

//			for (UINT32 j = 0; j<0xAFFFFF; j++);
			FOR_DELAY(0xAFFFFF);
		}
	}
	DBG_RETURN(SUCCESS);
}*/



/*
UINT8 WritePlu(void)
{
//	CPlu plu;
	CDept plu;
	INT32 nCount = 0;
//	INT32 nLeft = 0;
	UINT32 i;
	CaProgressBar proBar("");
	INT8 chValue[128];
	INT8 chMsg[128];
	memset((void*)chValue, 0, sizeof(chValue));
	memset((void*)chMsg, 0, sizeof(chMsg));
	UINT8 nKeyTime = 0;
	UINT8 ret;

		for(i = g_globalArg->m_pluCount+1; i<=PLU_MAX; i++)
		{
			//���ΰ����˳�����,���˳�����
			if(CheckKey(nKeyTime)==SUCCESS)
			{
				return FAILURE; 
			}
	
			sprintf(chValue, "xx%u", i);
			plu.m_code = chValue;
//			plu.m_nameAbbr = "2";
			plu.m_name = "��ţ�����";
			plu.m_dept = 2;
			plu.m_taxId = 2;
			plu.m_price = 50.0;
			plu.m_rate = 100.0;
			plu.m_unit = "piece";
			ret = plu.AddNew();
			if (ret != SQLITE_OK)
			{
				if (SQLITE_ERROR==ret) {
				}
				DBG_PRINT(("дPLU��ʧ�� ret = %u", ret));
				CaMsgBox::ShowMsg("дPLU��ʧ��");
				DBG_RETURN(FAILURE);
			}

			g_globalArg->m_pluCount++;
			sprintf(chMsg, "����PLU��¼: %u��",g_globalArg->m_pluCount);
			proBar.SetText(chMsg);
			proBar.ReFresh();

//			for (UINT32 j = 0; j<0xAFFFFF; j++);
			FOR_DELAY(0xAFFFFF);

		}

	DBG_RETURN(SUCCESS);
}*/


// UINT8 NetAutoIssue(UINT8 &nIfInvSum)
// {
// //	INT32 nKey = 0x0;
// 	UINT8 nKeyTime = 0;
// 	UINT32 nDate;
//     UINT8 nVolNum = 0;//��Ʊ����
// 	UINT32 nInvNo = 0;
// 	UINT32 nCurrentInvNo = 0;
// 	INT8 chValue[256];
// 	string strInfo;
// 	memset((void*)chValue, 0, sizeof(chValue));
// 	SaleData saleInfo;
// 	CaProgressBar proBar("");
// 	UINT8 ret;
// 
// 	//----��ѯ��Ʒ��Ϣ
// 	CDept curDept;
// 	//��װ��ѯ����
// 	sprintf(chValue,"WHERE DP_NO = %d", 1);
// 	DBG_PRINT(("--------chValue = %s--------", chValue));
// 	curDept.m_filter = chValue;
// 	curDept.Requery();
// 	INT32 errorcode = curDept.LoadOneRecord();
// 
// 	if (errorcode != SQLITE_OK)
// 	{
// 		CaMsgBox::ShowMsg("c��ѯ������Ϣ��");
// 		DBG_PRINT((" Warning: No matched goods!  errorcode = %d", errorcode));
// 		ret = FAILURE;
// 		DBG_RETURN(ret);	
// 	}
// 	
//     DBG_PRINT(("m_dpNo : %d ", curDept.m_dept));
// 	DBG_PRINT(("m_name : %s ", curDept.m_name.c_str()));
// 	DBG_PRINT(("m_taxId : %d ", curDept.m_taxId));
// 	
// 	for(;;)
// 	{
// 		//������Ʊ��ֹ���ڣ�ֹͣ��Ʊ
// 		nDate = TDateTime::CurrentDateTime().FormatInt(YYYYMMDD);
// 		DBG_PRINT(("for�� nDate = %u", nDate));
// 		DBG_PRINT(("for�� g_globalArg->m_curInvVol->m_remain = %u", g_globalArg->m_curInvVol->m_remain));
// 
// //		if (nDate>g_globalArg->m_corpInfo->m_ieDate) 
// //		{
// //			CaMsgBox::ShowMsg("������Ʊ��ֹ����\n�������걨!");
// //			return FAILURE;		
// //		}
// //		if (1 == g_globalArg->m_declareLimitFlag)
// //		{
// //			CaMsgBox::ShowMsg("�걨�ڳ���,�������걨");
// //			return FAILURE;
// //		}
// 		
// 		//����������ȷ�ϼ������˳���Ʊ����
// 		if(CheckKey(nKeyTime)==SUCCESS)
// 		{
// 			return SUCCESS;
// 		}
// 
// 		DBG_PRINT(("��ʼ�Զ���Ʊ"));
// 
// 		if(g_globalArg->m_curInvVol->m_remain != 0)
// 		{
// 			nCurrentInvNo = g_globalArg->m_curInvVol->m_InvEndNo + 1 - 
// 					g_globalArg->m_curInvVol->m_remain;
// 			//�ж��Ƿ��������Ҫ��������ʾ��Ϣ��
// 			if(IfInvHeadRoll()!=SUCCESS)
// 			{
// 				return FAILURE; 			
// 			}
// 			if(IfInvSumRoll()!=SUCCESS) 
// 			{
// 				return FAILURE; 			
// 			}
// 			if(IfRtInvRoll()!=SUCCESS) 
// 			{
// 				return FAILURE; 			
// 			}
// 
// //			if (g_globalArg->m_curInvVol->m_remain == 2)
// //			{
// //				DBG_PRINT(("�Զ�����Ʊ"));
// //				if ((ret = SimpleMakeReturnInv(saleInfo)) != SUCCESS)
// //				{
// //					if (ret==DB_FULL) 
// //					{
// //						CaMsgBox::ShowMsg("�洢�ռ��������޷���Ʊ �뾡���걨!");
// //					}
// //					else if (HAVE_ROLLED==ret)
// //					{
// //						CaMsgBox::ShowMsg("�������!");			
// //					}
// //					else
// //					{
// //						CaMsgBox::ShowMsg("����Ʊʧ��!");
// //					}					
// //					return FAILURE;
// //				}
// //			}
// //			else if (g_globalArg->m_curInvVol->m_remain == 1)
// //			{
// //				DBG_PRINT(("�Զ�����Ʊ"));
// //				if ((ret = SimpleMakeWasteInv(saleInfo)) != SUCCESS)
// //				{
// //					if (ret==DB_FULL) 
// //					{
// //						CaMsgBox::ShowMsg("�洢�ռ��������޷���Ʊ �뾡���걨!");
// //					}
// //					else if (HAVE_ROLLED==ret)
// //					{
// //						CaMsgBox::ShowMsg("�������!");			
// //					}
// //					else
// //					{
// //						CaMsgBox::ShowMsg("����Ʊʧ��!");
// //					}	
// //					return FAILURE;
// //				}
// //			}
// //			else
// //			{
// 				DBG_PRINT(("�Զ�����Ʊ"));
// 				if ((ret = NetMakeNormalInv(saleInfo, &curDept))!= SUCCESS)
// 				{
// 					if (ret==DB_FULL) 
// 					{
// 						CaMsgBox::ShowMsg("�洢�ռ��������޷���Ʊ �뾡���걨!");
// 					}
// 					else if (HAVE_ROLLED==ret)
// 					{
// 						CaMsgBox::ShowMsg("�������!");			
// 					}
// 					else
// 					{
// 						CaMsgBox::ShowMsg("����Ʊʧ��!");
// 					}	
// 					return FAILURE;
// 				}
// //			}
// 			//----������ر�����λ
// 			saleInfo.InitSaleData(1);	//������Ϣ��ʼ��
// 			saleInfo.InitInvHead();		//���ŷ�Ʊ��Ϣ��ʼ��
// 			
// 			//memset((void*)chValue, 0, sizeof(chValue));
// 			sprintf(chValue, "�Զ���Ʊ: %u��",nCurrentInvNo);
// 			proBar.SetText(chValue);
// 			proBar.ReFresh();
// 		}
// 		else
// 		{
// 			//����ܣ���ѯ��Ʊ�������롣���޷�Ʊ���򱨴�����
// 			if (GetInvNo(saleInfo, nInvNo) != SUCCESS)
// 			{
// 				return FAILURE;
// 			}
// 
// 			if(nVolNum < 1)
// 			{
// 				nVolNum++;
// 				continue;
// 			}
// 			nVolNum = 0;
// 			
// 			//�޸�ϵͳʱ�䵽�ڶ���	
// 			TDateTime dateTime(nDate, 80000);
// 			dateTime++;
// 			if (!TDateTime::SetCurrentDateTime(dateTime))
// 			{
// 				CaMsgBox::ShowMsg("�޸�����ʱ�����!");
// 				return FAILURE;			
// 			}
// 			UINT32 nTestDate = TDateTime::CurrentDateTime().FormatInt(YYYYMMDD);
// 			DBG_PRINT(("�ӳٺ� nTestDate = %u", nTestDate));
// 		
// 			//�ջ���
// 			INT32 errorcode = 0;
// 			INT8 charValue[128];
// 			memset((void*)charValue, 0, sizeof(charValue));
// 			if ((errorcode = g_globalArg->CheckDaySum(0)) != SUCCESS)
// 			{
// 				sprintf(charValue, "�ս��׻��ܴ���%02x", errorcode);
// 				CaMsgBox::ShowMsg(charValue);
// 				return FAILURE;	
// 			}
// //			UINT32 nIndex = 0;
// //			while (nIndex<0xFFFFFF)
// //			{
// //				nIndex = nIndex + 1;
// //			}
// 			
// 		}
// 	}
// }
// 
// 
// UINT8 NetMakeNormalInv(SaleData &tmpSaleData, CDept *pDept)
// {
// 	UINT8 ret;
// 	CInvDet *invDet = NULL;
// 	CInvHead invHead;
// 	tmpSaleData.m_smallInvInfo = &invHead;
//     UINT32 nCurDate = TDateTime::CurrentDateTime().FormatInt(YYYYMMDD);
// 	UINT32 nCurTime = TDateTime::CurrentDateTime().FormatInt(HHMMSS);
// 
// 	//��װ��Ʊ
// 	//��װ��Ʊͷ
// 	tmpSaleData.m_smallInvInfo->m_InvNo = g_globalArg->m_curInvVol->m_InvEndNo + 1 - 
// 		g_globalArg->m_curInvVol->m_remain;  /**< ��Ʊ���� */
//     tmpSaleData.m_smallInvInfo->m_codeNo = g_globalArg->m_curInvVol->m_codeNo;  /**< ��Ʊ������ */  	
// 
// 	tmpSaleData.m_smallInvInfo->m_issuetype = NORMAL_INV;		//��Ʊ����	
// 	tmpSaleData.m_smallInvInfo->m_oldInv = 0;		//ԭ��Ʊ����	
//   
// 	tmpSaleData.m_smallInvInfo->m_payer = "����";			//����������
// 	tmpSaleData.m_smallInvInfo->m_operator = g_globalArg->m_operator->m_name;		//����Ա����
// 	tmpSaleData.m_smallInvInfo->m_opId = g_globalArg->m_operator->m_opId;		//����Աid	
// 	tmpSaleData.m_smallInvInfo->m_uID = 0;          //��˰������ID��
// 	tmpSaleData.m_smallInvInfo->m_payType = 0;		//���ʽ
// 	tmpSaleData.m_smallInvInfo->m_goodsCount = 3;//��ǰ��Ʊ����Ʒ�м�1
// 	tmpSaleData.m_smallInvInfo->m_moneySum = (INT64)(0.3 * SUM_EXTENSION);//��ǰ��Ʊ�ܽ��
// 
//  	tmpSaleData.m_smallInvInfo->m_backup1 = "";		//�����ֶ�1
// 	tmpSaleData.m_smallInvInfo->m_backup2 = "";		//�����ֶ�2 
// 	tmpSaleData.m_smallInvInfo->m_backup3 = "";		//�����ֶ�3
// 
// 
// 	//��Ʊ��ϸ
// 	for(UINT8 i = 1; i<4; i++)
// 	{
// //		invDet = new CInvDet;
// 		invDet = invDet->GetNewInvDet();//�Ӿ�̬�����ȡһ�����õ�CInvDet����
// 		DBG_ASSERT_EXIT((invDet != NULL), (" invDet == NULL!"));
// 		invDet->m_codeNo = tmpSaleData.m_smallInvInfo->m_codeNo; 
// 		invDet->m_InvNo = tmpSaleData.m_smallInvInfo->m_InvNo;
// 		invDet->m_destriptionNo = 0; 
// 		invDet->m_issueDate = nCurDate;
// 		invDet->m_issueTime = nCurTime;
// 		invDet->m_issuetype = NORMAL_INV;
// 
// 		invDet->m_code = pDept->m_code;
// 		invDet->m_dpNo = pDept->m_dept;
// 		invDet->m_name = pDept->m_name;
// 		invDet->m_taxId = pDept->m_taxId; //��˰��ֻ����˰Ŀ1
// 		invDet->m_quantity = 1.0; //��������������ֵ
// 		invDet->m_dotNum = 0;
// 		invDet->m_price = (double)0.1;
// 
// 		invDet->m_moneySum = (INT64)(0.1*SUM_EXTENSION);
// 		invDet->m_property = DETAIL_GENERAL_GOODS;
// 		invDet->m_backup = "";
// 		invDet->m_tradeName = pDept->m_tradeName;
// 		invDet->m_indusCode = pDept->m_indusCode;
// 		tmpSaleData.m_smallInvInfo->InsertNode(invDet);	//����ڵ�
// 		
// 	}
// 	
// 	tmpSaleData.m_smallInvInfo->m_tradeName = pDept->m_tradeName;
// 
// 	ret = tmpSaleData.MakeInvoiceHandle(PRINT, INV_ROLL_PROC);
// 	tmpSaleData.m_smallInvInfo->DelList();
// 	tmpSaleData.m_smallInvInfo = NULL;
// 	if (ret != SUCCESS)
// 	{
// 		if (ret==DB_FULL) 
// 		{
// 			DBG_RETURN(DB_FULL);
// 		}
// 		else if (ret==HAVE_ROLLED) 
// 		{
// 			DBG_RETURN(HAVE_ROLLED);
// 		}
// 		else
// 		{
// 			DBG_RETURN(FAILURE);
// 		}	
// 	}	
// 	DBG_RETURN(SUCCESS);	
// }




#endif


