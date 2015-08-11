/*! \file  ProgramMainMenu.cpp
\brief    ���ܱ��������
\author   xsr
\version  1.0
\date     2010-7-28
*/

#include "CaMsgBox.h"
#include "CaProgressBar.h"
#include "MultiBtnCommonWin.h"

#include "CMainFrame.h"
#include "CGlobalArg.h"
#include "ProgramMainMenu.h"
#include "APIBase.h"


//����ת�����ӿڣ�
#if (TYPE_MODE == ZHQ_MODE)
CProgramCtrlMenu::CProgramCtrlMenu():CMultiBtnCommonWin(8, 2)
{
}
#else
CProgramCtrlMenu::CProgramCtrlMenu():CMultiBtnCommonWin(8, 2)
{
}
#endif

int CProgramCtrlMenu::Create(int iX,int iY,int iW,int iH)
{
	m_pFrame->RegsiterWin(this, PROGRAM_CTRL_MAIN_MENU);    
    
	CMultiBtnCommonWin::Adjustm_iH(1);
	CMultiBtnCommonWin::Create(iX, iY, iW, iH);

	SetTitle(1,  "A.��Ʒ����");
	SetTitle(2,  "B.��ƱԱ����");
	SetTitle(3,  "C.�ͻ�����");
	SetTitle(4,  "D.�������");
	SetTitle(5,  "E.���ݴ���");
	SetTitle(6,  "F.�������");
	SetTitle(7,  "G.�����޸�");
#if TYPE_MODE == ZHQ_MODE
	SetTitle(8,  "H.ת��������");
#elif	TYPE_MODE == SKJ_MODE
	SetTitle(8,  "H.�������");
#endif	
	return 1;
}

//------------------------------------------------------------------------------------
//��Ʒ��̣��ο�4000��PLU��̡�����ɾ����ԭ����DEPT_EDIT_WIN
//------------------------------------------------------------------------------------
void CProgramCtrlMenu::OnButton1(int iEvent, unsigned char * pEventData, int iDataLen)
{
	if (g_globalArg->m_initFlag == 0)
	{
		CaMsgBox::ShowMsg("����δ��ʼ��");
		return ;
	}
	ChangeWin(DEPT_EDIT_WIN);
}

//��ƱԱ����
void CProgramCtrlMenu::OnButton2(int iEvent, unsigned char * pEventData, int iDataLen)
{
	ChangeWin(OPERATOR_EDIT_WIN);
}

//�ͻ�����
void CProgramCtrlMenu::OnButton3(int iEvent, unsigned char * pEventData, int iDataLen)
{
	ChangeWin(CLIENT_EDIT_WIN);	
}

//��������
void CProgramCtrlMenu::OnButton4(int iEvent, unsigned char * pEventData, int iDataLen)
{
	// ������̲���δ��ʼ������
// 	if (g_globalArg->m_initFlag == 0)
// 	{
// 		CaMsgBox::ShowMsg("����δ��ʼ��");
// 		return ;
// 	}
	m_pFrame->GetWin(SYS_ARG_EDIT_WIN);
	ChangeWin(SYSTEM_ARG_MENU);
}


//���ݴ���
void CProgramCtrlMenu::OnButton5(int iEvent, unsigned char * pEventData, int iDataLen)
{
	//ChangeWin(TEMPLATE_TRANS_MENU);
	ChangeWin(DATA_IO_MENU);
}


//�������
void CProgramCtrlMenu::OnButton6(int iEvent, unsigned char * pEventData, int iDataLen)
{	
	ChangeWin(SYSTEM_UPGRADE_WIN);	
}


//�޸�����
void CProgramCtrlMenu::OnButton7(int iEvent, unsigned char * pEventData, int iDataLen)
	{
	ChangeWin(PASSWD_EDIT_WIN);	
}

#if TYPE_MODE == ZHQ_MODE
//ת������������
void CProgramCtrlMenu::OnButton8(int iEvent, unsigned char * pEventData, int iDataLen)
{	
	ChangeWin(ZHQ_MANAGE_MENU);	

	return ;
}
	
#elif TYPE_MODE == SKJ_MODE

//��������
void CProgramCtrlMenu::OnButton8(int iEvent, unsigned char * pEventData, int iDataLen)
{
	ChangeWin(NET_MANAGE_MENU);
}

#endif

int CProgramCtrlMenu::ProcEvent(int iEvent,unsigned char *pEventData, int iDataLen)
{
	if (RETURN_MAIN_MENU == iEvent)
	{
		ChangeWin(SYSTEM_MAIN_MENU);
		return SUCCESS;
	}
	return CMultiBtnCommonWin::ProcEvent(iEvent,pEventData,iDataLen);
}
