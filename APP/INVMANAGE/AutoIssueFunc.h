/*! \file    AutoIssueFunc.h
   \brief    awe4000r��Ʊ������Զ���Ʊ����
   \author   Yu Yan 
   \version  1.0
   \date     2008-5-21 
 */

#ifndef AUTO_ISSUE_FUNC_H
#define AUTO_ISSUE_FUNC_H

#include "IncludeMe.h"
#include "SysMacDef.h"
#include "SaleData.h"
#include "CRtInv.h"
#include "CaMsgBox.h"
#include "CInvVol.h"

/*!
@brief �ڲ���������
@param[out] nIfInvSum  �Ƿ�ִ���˾���ܲ�����1���ǣ�0����
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 SimpleAutoIssue(UINT8 &nIfInvSum);

/*!
@brief ��һ����Ʊ	
@param[in] tmpSaleData  ��������������
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 SimpleMakeNormalInv(SaleData &tmpSaleData,string &strErr);

/*!
@brief ��һ�ź�Ʊ	
@param[in] tmpSaleData  ��������������
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 SimpleMakeReturnInv(SaleData &tmpSaleData);

/*!
@brief ��һ�ŷ�Ʊ
@param[in] tmpSaleData  ��������������	
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 SimpleMakeWasteInv(SaleData &tmpSaleData);

/*!
@brief ��ȡ��ǰ��Ʊ���루����ǰ�޷�Ʊ�����Զ������ѷַ��ķ�Ʊ��	
@param[out] invNo      ��ǰ��Ʊ���� 
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 GetInvNo(SaleData &tmpSaleData, UINT32 &invNo);

/*!
@brief ��鰴�����ж��Ƿ��˳��Զ���Ʊ����	
@param[out] nKeyTime      ������ȷ�ϼ��Ĵ��� 
@return  1 ��(SUCCESS)�� 0 ��(FAILURE)
*/
UINT8 CheckKey2(UINT8 &nKeyTime);

/*!
@brief ���㿪Ʊ���	
@param[in] date    ����
@param[in] No      ˰Ŀ��� 
@return  ��������100������λ����Ӧ���֡���
*/
UINT32 ComputerMoney(UINT32 date, UINT8 No);

/*!
@brief ������걨��ʼ������X���º���걨��ֹ����	
@param[in] BeginDate    �걨��ʼ����
@param[in] nMonths      �·��� 
@return  �걨��ֹ����
*/
UINT32 ThreeMonthsEndDay(UINT32 BeginDate, UINT8 nMonths);

/*!
@brief �ж�ĳ�����Ƿ������һ��	
@param[in] nDate     ���жϵ�����
@return  1 ��(SUCCESS)�� 0 ��(FAILURE)
*/
UINT8 IsLastDay(UINT32 nDate);

/*!
@brief 15����������	
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 ComplexAutoIssue();


/*!
@brief ��һ����Ʊ	
@param[in] tmpSaleData  ��������������
@param[in] nTaxId  ˰Ŀ��
@param[in] nInvNo  ��Ʊ����
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 MakeNormalInv(SaleData &tmpSaleData, UINT8 nTaxId, UINT32 nInvNo);

/*!
@brief ��һ�ź�Ʊ	
@param[in] tmpSaleData  ��������������
@param[in] nTaxId  ˰Ŀ��
@param[in] nInvNo  ��Ʊ����
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 MakeReturnInv(SaleData &tmpSaleData, UINT8 nTaxId, UINT32 nInvNo);


/*!
@brief ��һ�ŷ�Ʊ	
@param[in] tmpSaleData  ��������������
@param[in] nTaxId  ˰Ŀ��
@param[in] nInvNo  ��Ʊ����
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 MakeWasteInv(SaleData &tmpSaleData);

/*!
@brief ����һ��Ŀ�Ʊ����	
@param[in] tmpSaleData  ��������������
@param[in] nInvNum  ����һ�쿪�ķ�Ʊ������
@param[in] IssuedNum  �����Ѿ������ķ�Ʊ����
@param[out] nKeyTime  ����ȷ�ϡ����Ĵ���
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 NormalDayIssue(SaleData &tmpSaleData, UINT32 nInvNum, UINT32 IssuedNum, UINT8 &nKeyTime);


/*!
@brief ��ĩһ��Ŀ�Ʊ����	
@param[in] tmpSaleData  ��������������
@param[in] nInvNum  ����һ�쿪�ķ�Ʊ������
@param[in] IssuedNum  �����Ѿ������ķ�Ʊ����
@param[out] nKeyTime  ����ȷ�ϡ����Ĵ���
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 LastDayIssue(SaleData &tmpSaleData, UINT32 nInvNum, UINT32 IssuedNum, UINT8 &nKeyTime);


/*!
@brief ���������ܽӿ�	
@param[out] nIfInvSum  �Ƿ�ִ���˾���ܲ�����1���ǣ�0����
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 AutoIssue(UINT8 &nIfInvSum);

/*!
@brief �жϷ�Ʊ������INV_HEAD���Ƿ�Ҫ����������ʾ��Ϣ��	
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 IfInvHeadRoll();

/*!
@brief �жϾ���ܣ�INV_SUM���Ƿ�Ҫ����������ʾ��Ϣ��	
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 IfInvSumRoll();

/*!
@brief �жϾ���ܣ�RT_INV���Ƿ�Ҫ����������ʾ��Ϣ��	
@return  1 SUCCESS�� 0 FAILURE
*/
UINT8 IfRtInvRoll();

/*!
@brief ���PLU���¼��ֱ��������ɼ�¼�������ޣ�	
@return  1 SUCCESS�� 0 FAILURE
*/
//UINT8 WritePlu(void);

/*!
@brief ���PLU���¼��ֱ��������ɼ�¼�������ޣ�	
@return  1 SUCCESS�� 0 FAILURE
*/
//UINT8 WriteSysLog(void);

//--------------------bx
UINT8 NetMakeNormalInv(SaleData &tmpSaleData, CDept *pDept);
UINT8 NetAutoIssue(UINT8 &nIfInvSum);

#endif
