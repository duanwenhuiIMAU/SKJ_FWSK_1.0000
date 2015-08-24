/*! \file    ErrUpInvWin.CPP
   \brief    awe4000r��ȡ�ϴ�����Ʊ��Ϣ����
   \author   Yu Yan
   \version  1.0
   \date     2008-2-22
 */


#include "ErrUpInvWin.h"
#include "APIBase.h"
#include "TemplateGeneralFuc.h"

#include "LOGCTRL.h"
//#define NO_POS_DEBUG
#include "pos_debug.h"
#include <string>

#define  ERR_MES_MAX_LEN	54	//������Ϣ��������ֽ���
#define	 LINE_ERR_MES_LEN	22	//��������ʾ������ֽ���


CErrInvUpWin::CErrInvUpWin():CaWindow()
{
	m_pageIndex = 1;
	m_pageNum = 0;
}

CErrInvUpWin::~CErrInvUpWin()
{

}

int CErrInvUpWin::Create(int iX,int iY,int iW,int iH)
{
	int curH;
	char title[OBJ_TITLE_MAX_LEN + 1];
    int titleLen=0;
	

    m_iBtnW = (SCREEN_W/2 - 0) ; //�ؼ��Ŀ��
	m_iColW = m_iBtnW + 0;        //�ؼ����п�
  
	m_pFrame->RegsiterWin(this,ERR_UP_INV_WIN);
  
	CaWindow::Create(iX,iY,iW,iH); // creat a window

	//����һ����ǩ  ��һ��	
	label[0] = new CaLabel(false,CaObject::ALIGN_RIGHT);
	curH = SCREEN_TOP_OFFSET;
	label[0]->Create(0,curH, SCREEN_W, CHAR_H); //����������
	label[0]->SetTitle(title_array[0], strlen(title_array[0]));
  
	//����һ����ǩ  �ڶ���
	label[1] = new CaLabel(false,CaObject::ALIGN_LEFT);
	curH += LINE_H;
	label[1]->Create(0,curH, SCREEN_W, CHAR_H); //����������
	label[1]->SetTitle(title_array[1], strlen(title_array[1]));

	//����һ����ǩ  ������
	label[2] = new CaLabel(false,CaObject::ALIGN_LEFT);
	curH += LINE_H;
	label[2]->Create(0,curH, SCREEN_W, CHAR_H);
	label[2]->SetTitle(title_array[2], strlen(title_array[2]));

	//����һ����ǩ ������
	label[3] = new CaLabel(false,CaObject::ALIGN_LEFT);
	curH += LINE_H;
	label[3]->Create(0,curH, SCREEN_W, CHAR_H);
	label[3]->SetTitle(title_array[3], strlen(title_array[3]));
	
	//����һ����ǩ  ������
	label[4] = new CaLabel(false,CaObject::ALIGN_LEFT);
	curH += LINE_H;
	label[4]->Create(0,curH, SCREEN_W, CHAR_H);
	label[4]->SetTitle(title_array[4], strlen(title_array[4]));

	OnActive = S_OnActive;
	
	this->End();  
	return 0;
}

int CErrInvUpWin::ProcEvent(int iEvent,unsigned char *pEventData, int iDataLen)
{
    UINT8 ret = 0;
	UINT32 ii;
	char *content;

	switch(iEvent)
	{	   
	case RETURN_MAIN_MENU:  //return to SYSTEMMENU
			 ChangeWin(FISCAL_MAIN_MENU);			
	
		 return SUCCESS;
	 	 break;

	case PAGEUP_KEY:

		 DBG_PRINT(("PAGEUP_KEY"));
		 if ((m_pageIndex-1)<1)
		 {
			 return FAILURE;
		 }
		 m_pageIndex--;
		 QueryShow(m_InvUpFailInfo, m_pageIndex);
		 ChangeTitle();
	     ReFresh();	
		 DBG_PRINT(("PAGEUP_KEY"));
		 return SUCCESS;
		 break;

	case PAGEDOWN_KEY:
		 if ((m_pageIndex+1)>m_pageNum)
		 {
			 return FAILURE;
		 }
		 m_pageIndex++;
		 QueryShow(m_InvUpFailInfo, m_pageIndex);
		 ChangeTitle();
	     ReFresh();	
		 return SUCCESS;
		 break;

	default: break;		
	}
 	  
	return CaWindow::ProcEvent(iEvent,pEventData,iDataLen);
}

int CErrInvUpWin::ReFresh()
{
	ReFreshTitle();
	CaGroup::ReFresh();
	if(m_pCurObj != NULL )
	{
 		m_pCurObj->SetFocusIn();
	}
	LCDRedraw();

	return 1;
}

UINT8 CErrInvUpWin::ErrMsgBox(UINT8 ret)
{
	string pText;
	switch(ret)
	{
		case PRE_INV_ERROR:
		    pText = "��ѯ�ϱʽ���ʧ��";
			break;
		case NO_DIST_INV:
		    pText = "��ǰ0��Ʊδ����";
			break;
		case QUERY_ERROR:
		    pText = "��ѯʧ��";
			break;
		default:;
	}  

	CaMsgBox::ShowMsg(pText);
	return FAILURE;	
}




void CErrInvUpWin::S_OnActive(CaWindow *obj)
{
	((CErrInvUpWin *)obj)->DoActive();
}


void CErrInvUpWin::DoActive()
{
	DBG_PRINT((" CErrInvUpWin::DoActive()!"));
	m_pageIndex = 1;
	string StrErr = "";
	INT32 ret;
	ret = g_pAPIBase->InvUpFailInfo_API(*g_YwXmlArg, m_InvUpFailInfo, m_pageNum, StrErr);//���δ����ķ�Ʊ����
 	DBG_PRINT((" m_pageNum = %u!", m_pageNum));
	if (SUCCESS != ret)
 	{
		m_pageIndex = 1;
		m_pageNum = 0;
		CaMsgBox::ShowMsg(StrErr);
		ChangeWin(FISCAL_MAIN_MENU);
	}
	else
	{
		if(m_pageNum <= 0)
		{
			CaMsgBox::ShowMsg("���ϴ���־��Ϣ");
			ChangeWin(FISCAL_MAIN_MENU);
			return;
		}
		QueryShow(m_InvUpFailInfo, m_pageIndex);//��֯��Ļ��ʾ��Ϣ
		ChangeTitle();
		ReFresh();	
	}	
}

UINT8 CErrInvUpWin::ChangeTitle()
{
	label[0]->SetTitle(title_array[0], strlen(title_array[0]));
	label[1]->SetTitle(title_array[1], strlen(title_array[1]));
	label[2]->SetTitle(title_array[2], strlen(title_array[2]));
	label[3]->SetTitle(title_array[3], strlen(title_array[3]));
    label[4]->SetTitle(title_array[4], strlen(title_array[4]));  
	return SUCCESS;
}

//--------------------------------------------------------------------------------------------------------------------
//��ȡδ���뷢Ʊ����Ϣ�����޸���Ļ��ʾ
//--------------------------------------------------------------------------------------------------------------------
UINT8 CErrInvUpWin::QueryShow(CDataInvServ *pInvUpFailInfo, UINT32 nPageIndex)
{
	DBG_ASSERT_EXIT((pInvUpFailInfo != NULL), (" pInvUpFailInfo == NULL!"));
	
	UINT8 ret = SUCCESS;
	UINT8 MesLen = 0;
	string TempErr = "";
	UINT8 buff[LINE_ERR_MES_LEN+1];

	DBG_PRINT((" nPageIndex == %u", nPageIndex));
	//ҳ����ų���
	if( (nPageIndex<1) || (nPageIndex>m_pageNum) )
	{
		return FAILURE;
	}
	
 	sprintf(title_array[0], "ESC������      [ҳ%u/%u]", nPageIndex, m_pageNum);
 	sprintf(title_array[1], "��Ʊ����: %s", pInvUpFailInfo[nPageIndex-1].m_fpdm.c_str());
 	sprintf(title_array[2], "��Ʊ����: %08u", pInvUpFailInfo[nPageIndex-1].m_fphm);

	DBG_PRINT((" pInvUpFailInfo[%u].m_ErrInfo.length() == %u", nPageIndex-1, pInvUpFailInfo[nPageIndex-1].m_errMsg.length()));
	MesLen = pInvUpFailInfo[nPageIndex-1].m_errMsg.length();
	if (MesLen > ERR_MES_MAX_LEN)
	{
			MesLen = ERR_MES_MAX_LEN;
	}

	if (MesLen <= LINE_ERR_MES_LEN)
 	{
		sprintf(title_array[3], "��������: %s", pInvUpFailInfo[nPageIndex-1].m_errMsg.c_str());
 	}
 	else
 	{	
		TempErr = pInvUpFailInfo[nPageIndex-1].m_errMsg.substr(0, LINE_ERR_MES_LEN);
		DBG_PRINT(("��ȡ���ַ���Ϊ�� %s", TempErr.c_str()));

		memset(buff, 0, sizeof(buff));
		sprintf((char *)buff, "%s", TempErr.c_str());
		if( GetHalfHZCount(buff, LINE_ERR_MES_LEN)%2 == 0 )
		{
			sprintf(title_array[3], "��������: %s",TempErr.c_str());
			TempErr = pInvUpFailInfo[nPageIndex-1].m_errMsg.substr(LINE_ERR_MES_LEN, MesLen - LINE_ERR_MES_LEN);
			sprintf(title_array[4], "%s", TempErr.c_str());
		}
		else
		{
			TempErr = pInvUpFailInfo[nPageIndex-1].m_errMsg.substr(0, LINE_ERR_MES_LEN - 1);
			DBG_PRINT(("��ȡ���ַ���Ϊ�� %s", TempErr.c_str()));
			sprintf(title_array[3], "��������: %s",TempErr.c_str());

			if (MesLen ==  ERR_MES_MAX_LEN)
			{
				MesLen -= 1;
				TempErr = pInvUpFailInfo[nPageIndex-1].m_errMsg.substr(LINE_ERR_MES_LEN - 1, MesLen - LINE_ERR_MES_LEN);
			}

			TempErr = pInvUpFailInfo[nPageIndex-1].m_errMsg.substr(LINE_ERR_MES_LEN - 1, MesLen - LINE_ERR_MES_LEN + 1);
			
			sprintf(title_array[4], "%s", TempErr.c_str());
		}

 	}

	return ret;
}











