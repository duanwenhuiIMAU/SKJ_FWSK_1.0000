/*! \file   PrintDriver.h
   \brief   ��ӡ����
   \author  Yin Chuntian
 */
#ifndef PRINT_DRIVER_H
#define PRINT_DRIVER_H

#include "comdatatype.h"

#ifdef __cplusplus
extern "C"
{
#endif


#define PRINTER_INTERRUPT 		0
#define SIDA_PRINTER			1


/*!
@brief	    �򿪴�ӡ���豸�ļ�
@details	��ʼ�����ݰ���:�����ӡ���������ָ�Ĭ��ֵ��ѡ���ַ���1��ɾ���û������ַ�
@others		����(HEX)��1B  40  
*/
void OpenPrinterDEV();

#if (POS_TYPE != POS_APE4000RG)

/*!
@brief		���ӡ�����ͳ�ʼ������
@details	��ʼ�����ݰ���:�����ӡ���������ָ�Ĭ��ֵ��ѡ���ַ���1��ɾ���û������ַ�
@param[in]  bidirectionalPrint ��ӡ����  
@others		����(HEX)��1B  40 
*/
void PrinterIni(UINT8 bidirectionalPrint);

/*!
@brief		���뺺�ִ�ӡ����
@details	��ӡ�����յ���������󣬽���5��7����ASCII�ַ���ӡ״̬ת����16��16����ĺ��ִ�ӡ״̬�����ִ�����2�ֽڶ�Ӧһ�����ֵı�׼������
@others		����(HEX)��1C  26 
*/
void SetChineseMode(void);


/*!
@brief		�˳����ִ�ӡ����
@details	��ӡ��������������󣬽��Ӻ��ִ�ӡ״̬�л���5��7����ASCII�ַ���ӡ״̬����ʵ��16��16��������5��7����ASCII�ַ�ͬ�л�ϴ�ӡ 
@others		����(HEX)��1C  2E 
*/
void SetAsciiMode(void);


/*!
@brief		ִ��n������ֽ
@details	��ӡ�����յ������������ǰ��n���У�n��ֵ��1-255��Χ�ڡ������������س����У�Ҳ��Ӱ�����Ļ������
@param[in]	N ��ֽ�ĵ���
@others		����(HEX)��1B  4A  n
*/
void ForwardNPoint(UINT16 N);


/*!
@brief     ����N��
@param[in] N ���� 
*/
void ForwardNLine(UINT8 N);

/*!
@brief    ִ�к��ֱ����ӡ
@details  ��ӡ���ڽ��յ�������󣬴�ӡ�ĺ��ֽ��ں���Ŵ�һ�������򲻸ı䡣������FS DC4��CR��LF��������Զ�����֮�����˳����ֱ����ӡ����ÿ������ʽ��ִ����ౣ��һ�� 
@others   ����(HEX)��1C  0E 
*/
void SetDoubleChineseMode(void);


/*!
@brief    ȡ�����ֱ����ӡ
@details  ȡ����FS SO����ִ�еĺ��ֱ����ӡ��ʽ���ָ���׼���ִ�ӡ����ʵ�ֲ�ͬ��ȵĺ���ͬ�л�ϴ�ӡ
@oters    ����(HEX)��1C  0E 
*/
void CancelDoubleChineseMode(void);


/*!
@brief       ���� n���м��
@details     Ϊ����Ļ�����������n���м�࣬n��ֵ��0-255֮�䣬��ʹ��ESC K�����ӡ����ͼ��ʱ��ͨ������n=0���ı���ӡʱͨ������n=3
@param[in]   N  �м�����
@others      ����(HEX)��1B  31  n 
*/
void SetLineSpace(UINT8 N);


/*!
@brief      �س�
@details    ������һ��CR�����ӡ��ʱ���ڻ������е������ַ����ֶ�������ӡ����������ֽ��ǰ��һ�� 
@others     ����(HEX)��0D
*/
void CarriageReturn(void);


/*!
@brief     ����
@details   ��ӡ����ǰ��һ���ַ���
@others    ����(HEX)��0A  
*/
void LineFormard(void);


/*!
@brief     ���ڱ�ǰ��
@details   ���ӡ���յ����������ǰ��ֽ��ֱ����⵽�ڱ��ǰ��ʱֹͣ��ֽ 
@others    ����(HEX)��16
*/
void SeekForntBorderBlackMark(void);


/*!
@brief    ���ڱ����
@details  ��ӡ���յ����������ǰ��ֽ��ֱ����⵽�ڱ�ĺ���ʱֹͣ��ֽ������⵽�ڱ�ǰ��ʱ����ֹͣ��ֽ
@others   ����(HEX)��17  
*/
void SeekBackBorderBlackMark(void);


/*!
@brief      ����ˮƽ���ֵ
@details    ����ˮƽ���λ��,n1 n2�ȵȣ�������Щ��Ӧ�ڸ��ͺŴ�ӡ����ͷ���п�֮�ڣ����磺n1=3,��ִ��ˮƽ���ʱ���ӵ������ַ�����ʼ��ӡ���ַ�
		    NUL������󣬱�ʾ������Ľ��������������ˮƽ�������,�������ø�������ESC D NUL��ʽ���
@others     ����(HEX)��1B  44  n1 n2 n3 �� 00
*/
void SetHT(void);

/*!
@brief      ִ��ˮƽ���
@details    ��ӡλ�ý��е���ESC D�������õ���һˮƽ���λ�á����û������ˮƽ���ֵ���ߵ�ǰ��ӡλ�õ��ڻ򳬹����һ��ˮƽ���ֵ��HT�����ִ��
@others     ����(HEX)��09 
*/
void ExecuteHT(void);


/*!
@brief    ���ִ�ӡһ���ַ�
@details  ��ӡλ�ý��е���ESC D�������õ���һˮƽ���λ�á����û������ˮƽ���ֵ���ߵ�ǰ��ӡλ�õ��ڻ򳬹����һ��ˮƽ���ֵ��HT�����ִ�� 
*/
void PrintChineseLine(INT8 *LineBuff, UINT8 BuffLen);

/*!
@brief       �����ӡһ���ַ�
@details     ��ӡλ�ý��е���ESC D�������õ���һˮƽ���λ�á����û������ˮƽ
		     ���ֵ���ߵ�ǰ��ӡλ�õ��ڻ򳬹����һ��ˮƽ���ֵ��HT�����ִ��
@param[in]   LineBuff ��ӡ������   BuffLen ��ӡ���ݵĳ���  
*/
void PrintDoubleChineseLine(INT8 *LineBuff, UINT8 BuffLen);


/*!
@brief      Ascii��ӡһ���ַ�
@details    ��ӡλ�ý��е���ESC D�������õ���һˮƽ���λ�á����û������ˮƽ
		    ���ֵ���ߵ�ǰ��ӡλ�õ��ڻ򳬹����һ��ˮƽ���ֵ��HT�����ִ��
@param[in]  LineBuff ��ӡ������   BuffLen ��ӡ���ݵĳ��� 
*/
void PrintAsciiLine(INT8 *LineBuff, UINT8 BuffLen);


/*!
@brief       �����ӡһ���ַ�
@details     ��ӡλ�ý��е���ESC D�������õ���һˮƽ���λ�á����û������ˮƽ
		     ���ֵ���ߵ�ǰ��ӡλ�õ��ڻ򳬹����һ��ˮƽ���ֵ��HT�����ִ��
@param[in]   LineBuff ��ӡ������   BuffLen ��ӡ���ݵĳ��� 
*/
void PrintReportLine(INT8 *LineBuff, UINT8 BuffLen);

/*!
@brief  ��ӡ���з�  
*/
void PrintSeparateLine(void);

#if SIDA_PRINTER == 1

/*!
@brief       ִ��n������ֽ
@details     ��ӡ�����յ������������ǰ��n���У�n��ֵ��1-255��Χ�ڡ������������س����У�Ҳ��Ӱ�����Ļ�������
@param[in]   N��ֽ�еĵ��� 
@others      ����(HEX)��1B  49  n
*/
void BackwardNPoint(UINT16 N);

/*!
@brief     ���� n���ּ��
@details   Ϊ����Ļ�����������n���м�࣬n��ֵ��0-255֮�䣬��ʹ��ESC K�����ӡ����ͼ��ʱ��ͨ������n=0���ı���ӡʱͨ������n=3
@param[in] N �ּ��ĵ���
@others    ����(HEX)��1B  32  n
*/
void SetWordSpace(UINT8 N);

/*!
@brief      ����˫���ӡ����
@details    Ϊ����Ļ�����������n���м�࣬n��ֵ��0-255֮�䣬��ʹ��ESC K���� ��ӡ����ͼ��ʱ��ͨ������n=0���ı���ӡʱͨ������n=3
@param[in]  N ˫���ӡ����  
@others     ����(HEX)��1B  33  n
*/
void SetBidirectionalPara(UINT8 N);

/*!
@brief     ��ѯ����״̬ 
@return    ���ػ���״̬
@others    ����(HEX)��1B  23
*/
UINT8 GetPrinterStatus(void);

/*!
@brief      ��ѯ������ʹ������
@return     ��ѯ������ʹ������
@others     ����(HEX)��1B  21
*/
UINT8 GetUsedLines(void);


/*!
@brief     ��ѯ������ʹ���ֽ���
@return    ��ѯ������ʹ������
@others    ����(HEX)��1B  24
*/
UINT16 GetUsedBytes(void);

void Code128Return(int n, int cmd);
void CodeTwo(int n, int cmd1, int cmd2);

/*!
@brief    ��ӡ��ά����
*/
int PrintBiznfo(unsigned char *input1,int VerticalNum,int HorizontalNum, int leftMargin);

int PrintBiznfo2(unsigned char *input1,unsigned char *input2,int VerticalNum,int HorizontalNum,int index);

#endif

#else

/*!
@brief		�������ʼ����ӡ��
@details	��ʼ�����ݰ���:�����ӡ������б༭���桢�ָ�ȱʡֵ�������ַ����ִ�ӡ��ʽ��ɾ���Զ����ַ�
@param[in]  bidirectionalPrint ��ӡ����  
@others		����(HEX)��1B  40 (ESC @)
*/
void PrinterIni(void);

/*!
@brief		���뺺�ִ�ӡ����
@details	��ӡ�����յ���������󣬽���5��7����ASCII�ַ���ӡ״̬ת����16��16����ĺ��ִ�ӡ״̬�����ִ�����2

�ֽڶ�Ӧһ�����ֵı�׼������
@others		����(HEX)��1C  26

@brief		ѡ�����ķ�ʽ�µĴ�ӡģʽ
@details	n��bit2(0������Ч,1������Ч),bit3(0������Ч,1������Ч),bit7(0�»�����Ч,1�»�����Ч)
@others		����(HEX)��1C  21 n
*/
void SetChineseMode(void);


/*!
@brief		�˳����ִ�ӡ����
@details	��ӡ��������������󣬽��Ӻ��ִ�ӡ״̬�л���5��7��7��7����ASCII�ַ���ӡ״̬����ʵ��16��16����

����5��7����ASCII�ַ�ͬ�л�ϴ�ӡ 
@details	n��bit0(��ģѡ��0:5��7,1:7��7),bit5(0������Ч,1������Ч),bit4(0������Ч,1������Ч),bit7(0�»���

��Ч,1�»�����Ч)
@others		����(HEX)��1B  21 n
*/
void SetAsciiMode(void);


/*!
@brief		��ӡ����ֽ
@details	��ӡ����ֽn/144Ӣ�磬�绺���������ݿɴ���ֱ����ֽ
@param[in]	N ��ֽ�Ĳ���,һ��Ϊ1/144Ӣ��,0.176mm
@others		����(HEX)��1B  4A  n
*/
void ForwardNPoint(UINT16 N);


/*!
@brief		��ӡ����ֽn�ַ���
@details	��ӡ�л�����������ݲ���ǰ��ֽn�ַ���, n=0~255, �����������س����У�Ҳ��Ӱ�����Ļ������ 
@param[in]	N ����
@others		����(HEX)��1B  64  n 
*/
void ForwardNLine(UINT8 N);

/*!
@brief		ִ�к��ֱ����ӡ,ѡ�����ķ�ʽ�µĴ�ӡģʽ
@details	��ӡ���ڽ��յ�������󣬴�ӡ�ĺ��ֽ��ں���Ŵ�һ�������򲻸ı䡣������FS DC4��CR��LF��������Զ�

����֮�����˳����ֱ����ӡ����ÿ������ʽ��ִ����ౣ��һ�� 
@details	n��bit2(0������Ч,1������Ч),bit3(0������Ч,1������Ч),bit7(0�»�����Ч,1�»�����Ч)
@others		����(HEX)��1C  21 n
*/
void SetDoubleChineseMode(void);


/*!
@brief		ȡ�����ֱ����ӡ,ѡ�����ķ�ʽ�µĴ�ӡģʽ
@details	ȡ�����ֱ����ӡ��ʽ���ָ���׼���ִ�ӡ����ʵ�ֲ�ͬ��ȵĺ���ͬ�л�ϴ�ӡ
@details	n��bit2(0������Ч,1������Ч),bit3(0������Ч,1������Ч),bit7(0�»�����Ч,1�»�����Ч)
@others		����(HEX)��1C  21 n
*/
void CancelDoubleChineseMode(void);


/*!
@brief       �趨�ַ��о�Ϊ n/144 Ӣ��
@details     �����м��Ϊ n/144Ӣ��, n��ֵ��0-255֮��, Ĭ��ֵ��n=24
@details     ��ֽ�������м��ĵ�λ����1/144 Ӣ��,��ӡ���ĵ����2/144 Ӣ��,���9���ӡ��һ���ַ��ĸ߶�������

16/144 Ӣ��
@details     Ϊ����������,nֵӦ����16
@param[in]   N  �м�ಽ��
@others      ����(HEX)��1B  33  n 
*/
void SetLineSpace(UINT8 N);


/*!
@brief      ��ӡ���س�,ע������ʵ�ֻ�������
@details    ��ӡ������б༭�����е�һ�����ݣ���ӡͷ�Զ��˻���߱�λ
@others     ����(HEX)��0D
*/
void CarriageReturn(void);


/*!
@brief      ��ӡ������
@details	��ӡ������б༭�����е�һ�����ݣ�������ǰ�趨���о���ǰ��ֽһ�С�����б༭����գ���ֻ��
@details	��ǰ�趨���о���ǰ��ֽһ��
@others		����(HEX)��0A  
*/
void LineFormard(void);


/*!
@brief     ִ�кڱ��� 
@details   ִ�кڱ��⣬�쵽�ڱ�����ֹͣ��ֽ���ڴ��ڷ���ֵAAH����첻���ڱ�������ҳ������ֹͣ��ֽ��
@details   �ڴ��ڷ���ֵ55H 
@others    ����(HEX)��1D 0C
*/
void SeekForntBorderBlackMark(void);


/*!
@brief    ִ�кڱ��� 
@details   ִ�кڱ��⣬�쵽�ڱ�����ֹͣ��ֽ���ڴ��ڷ���ֵAAH����첻���ڱ�������ҳ������ֹͣ��ֽ��
@details   �ڴ��ڷ���ֵ55H 
@others   ����(HEX)��1D 0C  
*/
void SeekBackBorderBlackMark(void);


/*!
@brief      ����ˮƽ�Ʊ�ֵ
@details    ����ˮƽ���λ��,n1 n2�ȵȣ�������Щ��Ӧ�ڸ��ͺŴ�ӡ����ͷ���п�֮�ڣ����磺n1=3,��ִ��ˮƽ���ʱ��

�ӵ������ַ�����ʼ��ӡ���ַ�
@details    NUL������󣬱�ʾ������Ľ��������������ˮƽ�������,�������ø�������ESC D NUL��ʽ���
@others     ����(HEX)��1B  44  n1 n2 n3 �� 00
*/
void SetHT(void);

/*!
@brief      ˮƽ�Ʊ�
@details    ��ӡλ�ý��е���һˮƽ�Ʊ�λ��, ���û������ˮƽ���ֵ���ߵ�ǰ��ӡλ�õ��ڻ򳬹����һ��ˮƽ���ֵ��

HT�����ִ��
@others     ����(HEX)��09 
*/
void ExecuteHT(void);


/*!
@brief    ���ִ�ӡһ���ַ�
@details  ��ӡλ�ý��е���ESC D�������õ���һˮƽ���λ�á����û������ˮƽ���ֵ���ߵ�ǰ��ӡλ�õ��ڻ򳬹����

һ��ˮƽ���ֵ��HT�����ִ�� 
*/
void PrintChineseLine(INT8 *LineBuff, UINT8 BuffLen);

/*!
@brief       �����ӡһ���ַ�
@details     ��ӡλ�ý��е���ESC D�������õ���һˮƽ���λ�á����û������ˮƽ
		     ���ֵ���ߵ�ǰ��ӡλ�õ��ڻ򳬹����һ��ˮƽ���ֵ��HT�����ִ��
@param[in]   LineBuff ��ӡ������   BuffLen ��ӡ���ݵĳ���  
*/
void PrintDoubleChineseLine(INT8 *LineBuff, UINT8 BuffLen);


/*!
@brief      Ascii��ӡһ���ַ�
@details    ��ӡλ�ý��е���ESC D�������õ���һˮƽ���λ�á����û������ˮƽ
		    ���ֵ���ߵ�ǰ��ӡλ�õ��ڻ򳬹����һ��ˮƽ���ֵ��HT�����ִ��
@param[in]  LineBuff ��ӡ������   BuffLen ��ӡ���ݵĳ��� 
*/
void PrintAsciiLine(INT8 *LineBuff, UINT8 BuffLen);


/*!
@brief       �����ӡһ���ַ�
@details     ��ӡλ�ý��е���ESC D�������õ���һˮƽ���λ�á����û������ˮƽ
		     ���ֵ���ߵ�ǰ��ӡλ�õ��ڻ򳬹����һ��ˮƽ���ֵ��HT�����ִ��
@param[in]   LineBuff ��ӡ������   BuffLen ��ӡ���ݵĳ��� 
*/
void PrintReportLine(INT8 *LineBuff, UINT8 BuffLen);

/*!
@brief  ��ӡ���з�  
*/
void PrintSeparateLine(void);

#if SIDA_PRINTER == 1

/*!
@brief       ��ӡ��������ֽ 
@details     ��ӡ����ӡ�����������ݲ�������ֽn*1/144Ӣ�磬n=0~48
@param[in]   N��ֽ�еĵ��� 
@others      ����(HEX)��1B  4B  n
*/
void BackwardNPoint(UINT16 N);

/*!
@brief     �����ַ��Ҽ�� 
@details   �԰��Ϊ�趨��λ��1/144Ӣ�磩�������ַ��ұ߼��Ϊn������,n=0~32,Ĭ��ֵn=0 
@param[in] N �ּ��ĵ���
@others    ����(HEX)��1B  20  n
*/
void SetWordSpace(UINT8 N);

/*!
@brief      ����˫���ӡ����
@details    ���������ñ�����Flash оƬ��ֱ���´��޸�
@param[in]  N ˫���ӡ����  
@others     ����(HEX)��1B 10 03 00 07 N CHK 
*/
void SetBidirectionalPara(UINT8 N);

/*!
@brief      ˫���ӡ(BID)��������
@details    �Ѵ�0 ��9�ĸ���BID ֵ�Ĵ�ӡЧ����ӡ�����ţ�����*����Ϊ��ǰ��ѡ��ֵ
@others     ����(HEX)��1B 10 02 00 07 00 34
*/
void BidirectionalParaTest(void);

/*!
@brief     ��ѯ����״̬ 
@return    ���ػ���״̬,�������ڴ�����Ч����ӡ���յ���ָ��󽫵�ǰ��ӡ��ֽ��״����һ���ֽڵ���ʽ������λ��������

�ڵ�
@return    �������£�����ӡ����ֽʱ�����ֽ�bit2=1;��ֽʱ��bit2=0;
@return    �ںڱ���Чʱ�����ֽ�bit7=1 ��ʾ��ǰ���ںڱ�λ�ã�bit7=0 ���ʾ��ǰ���Ǵ��ںڱ�λ�ã����ڱ���
@return    Ч���λ�޶���
@others    ����(HEX)��1B  76
*/
UINT8 GetPrinterStatus(void);

/*!
@brief      ��ѯ������ʹ������
@return     ���ػ���������δ��ӡ������
@others     ����(HEX)��1B  21
@others     ӳ����ӡ���޴�����,�仺���������Ƚ��ȳ����ڴ�������,��˸ú���һֱ����0
*/
UINT8 GetUsedLines(void);

/*!
@brief     ��ѯ������ʹ���ֽ���
@return    ��ѯ������ʹ������
@others    ����(HEX)��1B  24
*/
UINT16 GetUsedBytes(void);

void Code128Return(int n, int cmd);
void CodeTwo(int n, int cmd1, int cmd2);

/*!
@brief    ��ӡ��ά����
*/
int PrintBiznfo(unsigned char *input1,int VerticalNum,int HorizontalNum, int leftMargin);

int PrintBiznfo2(unsigned char *input1,unsigned char *input2,int VerticalNum,int HorizontalNum,int index);
#endif
#endif



#ifdef __cplusplus
}
#endif

#endif
