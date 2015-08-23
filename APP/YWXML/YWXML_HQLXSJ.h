/*! \file    YWXML_HQLXSJ.h
   \brief    ������õ��м���ӿ� ҵ�� 2.28.��ȡ�����������
   \author   myf
   \version  1.0
   \date     2015 
*/

#ifndef YWXML_HQLXSJ_H
#define YWXML_HQLXSJ_H


#include "IncludeMe.h"
#include "YWXmlBase.h"



/**
 *@class CGetOffLineData
 *@brief ��ȡ�����������
 */
class CGetOffLineData : public CYWXmlBase
{
public:
	/*!
	@brief ��ȡ�����������
	@param[in] ywlx 		ҵ������
	*/

	CGetOffLineData(CYWXML_GY &ywxml_gy, string &wscfpzs, string &wscfpsj, string &wscfpljje);
	~CGetOffLineData();
	
	INT32 XmlBuild();
	INT32 XmlParse();

	string &m_wscfpzs;
	string &m_wscfpsj;
	string &m_wscfpljje;

private:
	
};


#endif












































