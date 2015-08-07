/*! \file    ErrUpInvWin.CPP
   \brief    awe4000r��ȡ�ϴ�����Ʊ��Ϣ����
   \author   Yu Yan
   \version  1.0
   \date     2008-2-22
 */


#include "ErrUpInvWin.h"
#include "APIBase.h"

#include "LOGCTRL.h"
//#define NO_POS_DEBUG
#include "pos_debug.h"
#include <string>

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
	label[2]->Create(0,curH, m_iBtnW, CHAR_H);
	label[2]->SetTitle(title_array[2], strlen(title_array[2]));

	//����һ����ǩ ������
	label[3] = new CaLabel(false,CaObject::ALIGN_LEFT);
	label[3]->Create(m_iColW,curH, m_iBtnW, CHAR_H);
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
	g_pAPIBase->InvUpFailInfo_API(*g_YwXmlArg, m_pageNum, m_InvUpFailInfo, StrErr);//���δ����ķ�Ʊ����
	QueryShow(m_InvUpFailInfo, m_pageIndex);//��֯��Ļ��ʾ��Ϣ
	ChangeTitle();
	ReFresh();	
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
UINT8 CErrInvUpWin::QueryShow(CInvUpFailInfo *pInvUpFailInfo, UINT32 nPageIndex)
{
	DBG_ASSERT_EXIT((pInvUpFailInfo != NULL), (" pInvUpFailInfo == NULL!"));
	
	UINT8 ret = SUCCESS;

	DBG_PRINT((" nPageIndex == %u", nPageIndex));
	//ҳ����ų���
	if( (nPageIndex<1) || (nPageIndex>m_pageNum) )
	{
		return FAILURE;
	}
	
 	sprintf(title_array[0], "[ҳ%u/%u]", nPageIndex, m_pageNum);
 	sprintf(title_array[1], "��Ʊ����: %s", pInvUpFailInfo[nPageIndex-1].m_fpdm.c_str());
 	sprintf(title_array[2], "��Ʊ����: %08u", pInvUpFailInfo[nPageIndex-1].m_fphm);
 	sprintf(title_array[3], "��������: %s", pInvUpFailInfo[nPageIndex-1].m_ErrInfo.c_str());
	//sprintf(title_array[4], "��������: %u", pInvVol->m_date); 

	return ret;
}











