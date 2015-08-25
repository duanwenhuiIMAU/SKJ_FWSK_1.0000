/**
 @file  ZhqParaSetMenu.cpp
 @brief �����ļ���ת���������������˵�
 @author  lzh
 @date  20150608
*/
#include "APIBase.h"
#include "ZhqParaSetMenu.h"
#include "CMainFrame.h"
#include "CaMsgBox.h"
#include "CaProgressBar.h"
#include "CGlobalArg.h"


CZhqParaSetMenu::CZhqParaSetMenu():CMultiBtnCommonWin(4)
{
	m_ComNetpara = &m_Netpara;
}
CZhqParaSetMenu::~CZhqParaSetMenu()
{
}

int CZhqParaSetMenu::Create(int iX,int iY,int iW,int iH)
{
	m_pFrame->RegsiterWin(this, ZHQ_MANAGE_MENU);    
    
	CMultiBtnCommonWin::Adjustm_iH(1);
	CMultiBtnCommonWin::Create(iX, iY, iW, iH);

	SetTitle(1,  "A.��������");
	SetTitle(2,  "B.��������");
	SetTitle(3,  "C.��������");
	SetTitle(4,  "D.�������");

	return 1;
}

void CZhqParaSetMenu::OnButton1(int iEvent, unsigned char * pEventData, int iDataLen)
{
	if (TYPE_MODE != ZHQ_MODE)
	{
		CaMsgBox::ShowMsg("��ת��������ģʽ");
		return;
	}
	ChangeWin(ZHQ_BTL_SET_WIN);
}

//��������
void CZhqParaSetMenu::OnButton2(int iEvent, unsigned char * pEventData, int iDataLen)
{	
	INT32 ret;
	string strErr = "";
	ret = g_globalArg->OnLineTest(strErr);
	if (SUCCESS == ret)
	{
		CaMsgBox::ShowMsg("�������Գɹ�");
	}
	else
	{
		CaMsgBox::ShowMsg(strErr);
		DBG_PRINT(("strErr : %s", strErr.c_str()));
		//CaMsgBox::ShowMsg("��������ʧ��");
	}
}

void CZhqParaSetMenu::OnButton3(int iEvent, unsigned char * pEventData, int iDataLen)
{
	if (g_globalArg->m_initFlag == 0)
	{
		DBG_PRINT(("����δ��ʼ��"));
		CaMsgBox::ShowMsg("����δ��ʼ��");
		return ;
	}

	INT32 errorcode = 0;
	m_ComNetpara->Requery();
	errorcode = m_ComNetpara->LoadOneRecord();
	DBG_PRINT(("errorcode = %d", errorcode));
	if ((errorcode!=SQLITE_DONE)&&(errorcode!=SQLITE_OK))
	{
		CaMsgBox::ShowMsg("���ݿ��ѯ����");
}
	DBG_PRINT(("m_ComNetpara: m_IDDHCP = %u", m_ComNetpara->m_IsDhcp));
	DBG_PRINT(("m_ComNetpara: m_LocalIP = %s", m_ComNetpara->m_LocalIP.c_str()));
	DBG_PRINT(("m_ComNetpara: m_ServIP = %s", m_ComNetpara->m_ServIP.c_str()));

	ChangeWin(ZHQ_IPADDR_SET_WIN);
}

void CZhqParaSetMenu::OnButton4(int iEvent, unsigned char * pEventData, int iDataLen)
{
	if (g_globalArg->m_initFlag == 0)
	{
		DBG_PRINT(("����δ��ʼ��"));
		CaMsgBox::ShowMsg("����δ��ʼ��");
		return ;
	}


	BAR_DEF();
	BAR_SHOW("�������Ӳ���...");

	INT32 ret = SUCCESS;
	string strErr = "";

	ret = g_pAPIBase->LXXXUpdatePro_API(*g_YwXmlArg, strErr);
	if(ret == SUCCESS)
	{
		CaMsgBox::ShowMsg("�������Ӳ��Գɹ�!");	
	}
	else
	{
		CaMsgBox::ShowMsg(strErr);
	}
}


int CZhqParaSetMenu::ProcEvent(int iEvent,unsigned char *pEventData, int iDataLen)
{
	if (RETURN_MAIN_MENU == iEvent)
	{
		ChangeWin(PROGRAM_CTRL_MAIN_MENU);
		return SUCCESS;
	}

	return CMultiBtnCommonWin::ProcEvent(iEvent,pEventData,iDataLen);
}
