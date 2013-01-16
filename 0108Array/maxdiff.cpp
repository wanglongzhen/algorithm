#include "stdafx.h"
#include "maxdiff.h"

/************************************************************************/
/* ���÷����㷨��������ֵ:
�������ǰ�����ֳ����������飬������ʵû�б�Ҫ����ߵ��������н�С������ȥ
���ұߵ��������нϴ�����������������ǿ�����������֮������ֵֻ�п����������������֮һ��
��1���������ͼ������ڵ�һ���������У�����һ���������е�����֮������ֵ��
��2���������ͼ������ڵڶ����������У����ڶ���������������֮������ֵ��
��3���������ڵ�һ���������У��ǵ�һ������������ֵ��
�����ڵڶ����������У��ǵڶ������������Сֵ����������ֵ������߾�����������������֮������ֵ��*/
/************************************************************************/
int maxDiff_Solution1(int number[], int length)
{
	if(number == NULL || length < 2) return -1;

	int max = 0;
	int min = 0;
	return maxDiffCore(number, number + length - 1, max, min);
}


int maxDiffCore(int *start,int *end, int &max, int &min)
{
	if(start == end)
	{
		max = min = *start;
		return 0x80000000;
	}

	int *middle = start + (end - start) / 2;

	int leftMax, leftMin;
	int leftMaxDiff = maxDiffCore(start, middle, leftMax, leftMin);

	int rightMax, rightMin;
	int rightMaxdiff = maxDiffCore(middle + 1, end, rightMax, rightMin);

	max = leftMax > rightMax ? leftMax : rightMax;
	min = leftMin < rightMin ? leftMin : rightMin;

	int crossDiff = leftMax - rightMin;

	int MaxDiff = leftMaxDiff > rightMaxdiff ? leftMaxDiff : rightMaxdiff;
	MaxDiff = MaxDiff > crossDiff ? MaxDiff : crossDiff;

//	cout<<MaxDiff<<endl;

	return MaxDiff;
}

/************************************************************************/
/* ת����������������������:�������һ������Ϊn������numbers��
�����ȹ���һ������Ϊn-1�ĸ�������diff������diff[i]����numbers[i]-numbers[i+1]��0<=i<n-1����
������Ǵ�����diff�еĵ�i������һֱ�ۼӵ���j�����֣�j > i����
Ҳ����diff[i] + diff[i+1] + �� + diff[j] = (numbers[i]-numbers[i+1]) + 
(numbers[i + 1]-numbers[i+2]) + ... + (numbers[j] �C numbers[j + 1]) = numbers[i] �C numbers[j + 1]��

������������Ƿ���ԭʼ��������������֮���numbers[i] �C numbers[j + 1]��
��ʵ�Ǹ�������diff����������������֮�͡�
�����ڱ�ϵ�еĲ��͵ĵ�3ƪ��������������͡����Ѿ���ϸ���۹��������Ľ��������                                                                     */
/************************************************************************/
int maxDiff_Solution2(int numbers[], int length)
{
	int *diff = new int[length - 1];

	memset(diff, 0, length - 1);
#ifdef DEBUG
	cout<<"*********************"<<endl;
#endif
	for(int i = 0; i < length - 1; ++i)
	{
		diff[i] = numbers[i] - numbers[i + 1];
		cout<<diff[i]<<endl;
		
	}
#ifdef DEBUG
	cout<<"*************"<<endl;
#endif

	int maxDiff = 0;
	int currNumber = 0;
	for(int i = 0; i < length - 1; ++i)
	{
		if(currNumber <= 0)
			currNumber = diff[i];
		else
			currNumber += diff[i];

		if(currNumber > maxDiff) maxDiff = currNumber;
	}

	delete []diff;

	return maxDiff;
}

/************************************************************************/
/* ת����������������������:

10000���������� �������ţ� 6000�������� =�����ںţ� 4000���

��Ȼ���ǿ��԰�����������֮��ת����������������ͣ�������������Ϳ���ͨ����̬�滮��⣬
�������ǲ��ǿ���ͨ����̬�滮ֱ������أ��������������ö�̬�滮��ֱ��������֮������ֵ��

���Ƕ���diff[i]���������е�i������Ϊ��������������֮������ֵ��
Ҳ����˵��������h��h < i����diff[i]��number[h]-number[i]��diff[i]��0��i<n�������ֵ��������������������֮�

���������Ѿ������diff[i]�����Ǹ���ô���diff[i+1]�أ�
����diff[i]���϶�����һ��h��h < i��������number[h]��ȥnumber[i]֮�������ģ�
Ҳ����number[h]Ӧ����number[i]֮ǰ���������ֵ����ֵ����������diff[i+1]��ʱ��
������Ҫ�ҵ���i+1������֮ǰ�����ֵ����i+1������֮ǰ�����ֵ�����ֿ��ܣ�
������ֵ�����ǵ�i������֮ǰ�����ֵ��Ҳ�п���������ֵ���ǵ�i�����֡�
��i+1������֮ǰ�����ֵ�϶��������ߵĽϴ��ߡ�
����ֻҪ�õ�i+1������֮ǰ�����ֵ��ȥnumber[i+1]���͵õ���diff[i+1]��*/
/************************************************************************/
int maxDiff_Solution3(int numbers[], int length)
{
	if(numbers == NULL || length < 2) return - 1;

	int maxNumber = numbers[0];
	int maxDiff = maxNumber - numbers[1];
	
	for(int i = 2; i < length; ++i)
	{
		if(maxNumber < numbers[i - 1]) maxNumber = numbers[i - 1];

		int diff = maxNumber - numbers[i];
		if(diff > maxDiff) maxDiff = diff;
	}

	return maxDiff;
}


/************************************************************************/
/* ���֮��2.4 1����Ŀ����һ�����⣬����һ�����������1���������1���ֵĴ���
�Լ���Ľⷨ*/
/************************************************************************/
int numberOfOne(int n)
{
	if(n <= 0) return 0;

	int countOfOne = 0;
	for(int i = 1; i <= n; ++i)
	{
		int number = i;
		while(number)
		{
			if(number % 10 == 1) countOfOne++;
			number /= 10;
		}
	}

	return countOfOne;
}

int numberOfOne2(int n)
{
	if(n <= 0) return 0;

	int countOfOne = 0;
	while(n)
	{
		if(n % 10 == 1) countOfOne++;
		n /= 10;
	}
}