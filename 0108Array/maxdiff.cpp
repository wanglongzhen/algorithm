#include "stdafx.h"
#include "maxdiff.h"

/************************************************************************/
/* 采用分治算法查找最大差值:
假设我们把数组分成两个子数组，我们其实没有必要拿左边的子数组中较小的数字去
和右边的子数组中较大的数字作减法。我们可以想象，数对之差的最大值只有可能是下面三种情况之一：
（1）被减数和减数都在第一个子数组中，即第一个子数组中的数对之差的最大值；
（2）被减数和减数都在第二个子数组中，即第二个子数组中数对之差的最大值；
（3）被减数在第一个子数组中，是第一个子数组的最大值。
减数在第二个子数组中，是第二个子数组的最小值。这三个差值的最大者就是整个数组中数对之差的最大值。*/
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
/* 转化成求解子数组的最大和问题:如果输入一个长度为n的数组numbers，
我们先构建一个长度为n-1的辅助数组diff，并且diff[i]等于numbers[i]-numbers[i+1]（0<=i<n-1）。
如果我们从数组diff中的第i个数字一直累加到第j个数字（j > i），
也就是diff[i] + diff[i+1] + … + diff[j] = (numbers[i]-numbers[i+1]) + 
(numbers[i + 1]-numbers[i+2]) + ... + (numbers[j] – numbers[j + 1]) = numbers[i] – numbers[j + 1]。

分析到这里，我们发现原始数组中最大的数对之差（即numbers[i] – numbers[j + 1]）
其实是辅助数组diff中最大的连续子数组之和。
我们在本系列的博客的第3篇《求子数组的最大和》中已经详细讨论过这个问题的解决方法。                                                                     */
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
/* 转化成求解子数组的最大和问题:

10000（被减数） —（减号） 6000（减数） =（等于号） 4000（差）

既然我们可以把求最大的数对之差转换成求子数组的最大和，而子数组的最大和可以通过动态规划求解，
那我们是不是可以通过动态规划直接求解呢？下面我们试着用动态规划法直接求数对之差的最大值。

我们定义diff[i]是以数组中第i个数字为减数的所有数对之差的最大值。
也就是说对于任意h（h < i），diff[i]≥number[h]-number[i]。diff[i]（0≤i<n）的最大值就是整个数组最大的数对之差。

假设我们已经求得了diff[i]，我们该怎么求得diff[i+1]呢？
对于diff[i]，肯定存在一个h（h < i），满足number[h]减去number[i]之差是最大的，
也就是number[h]应该是number[i]之前的所有数字的最大值。当我们求diff[i+1]的时候，
我们需要找到第i+1个数字之前的最大值。第i+1个数字之前的最大值有两种可能：
这个最大值可能是第i个数字之前的最大值，也有可能这个最大值就是第i个数字。
第i+1个数字之前的最大值肯定是这两者的较大者。
我们只要拿第i+1个数字之前的最大值减去number[i+1]，就得到了diff[i+1]。*/
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
/* 编程之美2.4 1的数目，第一个问题，给定一个整数，求从1到这个整数1出现的次数
自己想的解法*/
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