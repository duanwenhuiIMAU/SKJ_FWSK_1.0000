#ifndef __CINV_UP_FAIL_INFO_H
#define __CINV_UP_FAIL_INFO_H

 #include "CTable.h"
 #include "CDB.h"

/**
 *@class CInvUpFailInfo 
 *@brief ���˷�Ʊ��Ϣ��
 *@brief 
 */
class CInvUpFailInfo
{
public:
    
	/*!
	@brief ���캯��	
	@attention   ���ע��
	*/ 
	CInvUpFailInfo();

    /*!
	@brief ��������	
	*/
	~CInvUpFailInfo();
	

	string m_fpdm;		/**< ��Ʊ���� */
	UINT32 m_fphm;		/**< ��Ʊ���� */
	string m_ErrInfo;	/**<��������*/
};

#endif
