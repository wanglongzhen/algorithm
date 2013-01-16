
#ifndef ARRAY_H_H_01
#define ARRAY_H_H_01

#include <vector>
using namespace std;


/************************************************************************/
/* ����һ������A[1,2,...n]��������B��ʹ������B�еĵ�i������B=A*A*...*A[i-1]*A[i+1]*...*A.
Ҫ�󲻵�ʹ�ó˷��������Ŀ�ܶ�΢��͹ȸ�����Թٶ���ϲ������˵�����Ѷ������ʵϰ��Ҳ��������һ��                                                                     */
/************************************************************************/
template<typename T>
void multiply(const vector<T> array1, vector<T> &array2)
{
	if(array1.size() != array2.size() || array1.size() <= 1) return;

	const T *p1 = array1.data();
	T *p2 = array2.data();

	//array2�е�ֵ�൱��C��ֵ���������¼���ġ�
	*p2 = 1;
	for(int i = 1; i < array1.size(); ++i)
	{
		p2[i] = p1[i - 1] * p2[i - 1];
	}

	//temp��ֵ����D��ֵ���Ǵ������ϼ����
	int temp = 1;
	for(int i = array1.size() - 2; i >= 0; --i)
	{
		temp *= p1[i + 1];
		p2[i] *= temp;
	}
}

// void multiply(int array1[], int array2 [])
// {
// 	if(sizeof(array1) != sizeof(array2) || sizeof(array1) <= 0) return;
// 
// 	int *p2 = array2;
// 	*p2 = 1;
// 	int *p1 = array1;
// 	for(int i = 1; i < sizeof(array1) / sizeof(int); i++)
// 	{
// 		p2[i] = p1[i - 1] * p2[i - 1];
// 	}
// 
// 	int temp = 1;
// 	for(i = sizeof(array1) / sizeof(int) - 2; i >= 0; --i)
// 	{
// 		temp *= array1[i + 1];
// 		array2[i] *= temp;
// 	}
// }

#endif