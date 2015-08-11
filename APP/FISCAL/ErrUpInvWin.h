/*! \file    ErrUpInvWin.h
   \brief    awe4000r��ȡ�ϴ�����Ʊ��Ϣ����
   \author   Yu Yan
   \version  1.0
   \date     2008-2-22
 */

#ifndef ERR_UP_INV_WIN_H
#define ERR_UP_INV_WIN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifdef WIN32
#include <conio.h>
#endif

#include "IncludeMe.h"
#include "CaWindow.h"
#include "LOGCTRL.h"
#include "pos_debug.h"
#include "g_def.h"
#include "CaLabel.h"
#include "CMainFrame.h"
#include "CaInput.h"
#include "CaButton.h"
#include "CaMsgBox.h"
#include "TDateTime.h"
#include "InvManageFunc.h"
#include "YWXmlBase.h"
#include "CInvServ.h"

#include "SysMacDef.h"
#include "CGlobalArg.h"
#include "SaleData.h"


/**
 *@class CInvDistQueryWin 
 *@brief ��ȡ�ϴ�����Ʊ��Ϣ����
 */
class CErrInvUpWin : public CaWindow
{
public:
	char title_array[6][OBJ_TITLE_MAX_LEN + 1];	/**< ��ǩ�ı���*/

	CaLabel *label[5];							/**< ָ���ǩ��ָ�� */
	        	
	int m_iBtnW;								/**< ����ʱ���ؼ��Ŀ�� */  
	int m_iColW;								/**< ����ʱ���ڶ��еĺ����� */  

	UINT32 m_pageIndex;							/**< ��ǰҳ��*/
	UINT32 m_pageNum;							/**< ��ҳ����*/
	CDataInvServ m_InvUpFailInfo[MAX_ERR_INV_COUNT];	/**< ��Ʊ������Ϣ*/
	UINT32 m_recordIndex;						/**< ��¼�ڱ��е����*/

	/*!
	@brief ��������	
	@param iX ���ϽǺ�����
	@param iY ���Ͻ�������
	@param iW ���
	@param iH �߶�
	@return 1 ���ɹ���������ʧ��
	*/
	int Create(int iX,int iY,int iW,int iH);

	/*!
	@brief �����¼�	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	@return   1  �Ѵ��� 0 �޷�����
	*/
	int ProcEvent(int iEvent,unsigned char *pEventData, int iDataLen);

	/*!
	@brief ˢ�´�����ʾ	
	@return 1: SUCCESS
	*/
	virtual int ReFresh();

	/*!
	@brief ���캯��	
	*/
	CErrInvUpWin();

	/*!
	@brief ��������	
	*/
	virtual ~CErrInvUpWin();
    
	/*!
	@brief ������Ϣ��ʾ��	
	@param[in] ret   ����� 
	@return  FAILURE
	*/
    UINT8 ErrMsgBox(UINT8 ret);
    
	  
	/*!
	@brief ������ʾ���ݵľ�̬����	 
	*/
	static void S_OnActive(CaWindow *obj);
    
	/*!
	@brief ������ʾ���ݵĺ���	 
	*/
	void DoActive(); 

	
	/*!
	@brief �ı�Label��������titleֵ	
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 ChangeTitle();

	/*!
	@brief ��ȡδ���뷢Ʊ����Ϣ�����޸���Ļ��ʾ
	@param[in] pInvVol ��Ʊ���¼��ָ��
	@param[in] nPageIndex  ������Ļ��ʾ��ҳ���
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 QueryShow(CDataInvServ *pInvUpFailInfo, UINT32 nPageIndex);

};

#endif
