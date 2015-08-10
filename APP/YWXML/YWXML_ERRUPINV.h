/*! \file    YWXML_ERRUPINV.h
   \brief    ������õ��м���ӿ� ҵ�� ��ȡ�ϴ�����ķ�Ʊ��Ϣ
   \author   myf
   \version  1.0
   \date     2015 
*/

#ifndef YWXML_ERRUPINV_H
#define YWXML_ERRUPINV_H


#include "IncludeMe.h"
#include "YWXmlBase.h"
#include "CInvServ.h"


class CErrInvInfo
{
public:
	CDataInvServ InvUpFailInfo[MAX_ERR_INV_COUNT];
	UINT32 m_ErrUpNum;
	
	CErrInvInfo();
	~CErrInvInfo();
};



/**
 *@class CErrUpInv
 *@brief ��ȡ�ϴ�����ķ�Ʊ��Ϣ
 */
class CErrUpInv : public CYWXmlBase
{
public:
	/*!
	@brief ��ȡ�ϴ�����ķ�Ʊ��Ϣ
	@param[in] ywlx 		ҵ������
	*/

	CErrUpInv(CYWXML_GY &ywxml_gy, CErrInvInfo &ErrInvInfo);
	~CErrUpInv();
	
	INT32 XmlBuild();
	INT32 XmlParse();

	CErrInvInfo &m_ErrInvInfo;


private:
	
};


#endif













































