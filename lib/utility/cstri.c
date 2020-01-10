/*
ģ�飺 cstri.c
���ܣ� ת��int����ֵΪ�ַ�����
������ val��Ҫת����int����ֵ��
	  out������ת������ַ�������int����ֵ�Ļ��棬���С������12*sizeof(tchar)���ֽڡ�
���أ� ָ��out��ָ�롣
˵���� c2stri()���׼����itoa������ͬ����ȥ���������ͬ����(2/8/10/16)�Ĺ��ܣ������ͬ�Ľ���Ӧ����printf/sprintf�����
�汾�� 2019-05-20 denglf ģ�鴴��
*/

#include "../typedef.h"
#include "../typecvt.h"

tchar* cstri(int32 val, tchar* out)
{
	tchar* left = out;	//���λ��
	tchar* p = out;		//��ǰλ��
	int32 n;			//��ǰ����
	tchar c;			//��ǰ�ַ�
	
	//������ת��������
	if (val < 0)
	{
		val = -val; //ת��������
		*p = __T('-'); //���������д�븺��
		left = ++p; //��ǰ�ƶ�һ��λ��
	}

	//������ת�����ַ�
	do
	{
		n = val % 10; //ȡ�ø�λ
		val /= 10; //ȥ����λ
		*p++ = _c_tochr(n);//ת����'0'-'9'֮����ַ�
	} while (val > 0);
	*p-- = NUL;//�������ӽ�����������ָ��

	//��ת'-'��'\0'֮�������Ϊ��ȷ��˳��
	do
	{
		c = *left;
		*left++ = *p;
		*p-- = c;
	} while (left < p); 

	//����
	return out;
}