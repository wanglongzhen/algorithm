#ifndef MAXDIFF_H_H_01
#define MAXDIFF_H_H_01


/************************************************************************/
/* 在数组中，数字减去它右边的数字得到一个数对之差。求所有数对之差的最大值。
例如在数组{2, 4, 1, 16, 7, 5, 11, 9}中，数对之差的最大值是11，是16减去5的结果。                                                                     */
/************************************************************************/
int maxDiff_Solution1(int number[], int length);
int maxDiffCore(int *start, int *end, int &max, int &min);

int maxDiff_Solution2(int numbers[], int length);
int maxDiff_Solution3(int numbers[], int length);

/************************************************************************/
/* 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

例如：如果输入如下矩阵：

1              2              3              4
5              6              7              8
9              10             11             12
13             14             15             16   
则依次打印出数字1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10。*/
/************************************************************************/



/************************************************************************/
/* 编程之美的题目：2.5寻找最大的K个数
解法二：*/
/************************************************************************/

template<class Item>
void swap1(Item &rhs, Item &lhs)
{
	Item tmp = rhs;
	rhs = lhs;
	lhs = tmp;
}

/*
*快速排序的分割算法
*/
template<class Item>
int partition(Item a[], int l, int r)
{
	int compare = a[l];

	int left = l, right = r;
	while(left < right)
	{
		while(left < right && a[right] >= compare) right--;

		swap1(a[right], a[left]);

		while(left < right && a[left] <= compare) left++;

		swap1(a[right], a[left]);
	}

	return left;
}

template<class ElemType>
void QucikSortHelp(ElemType elem[], int low, int high)
{
	if(low < high)
	{
		int pivotLoc = partition(elem, low, high);
		QucikSortHelp(elem, low, pivotLoc - 1);
		QucikSortHelp(elem, pivotLoc + 1, high);
	}
}

template<class Item>
int KBig(Item a[], int l, int r, const int k)
{
	if((r - l) < k || k <= 0) return -1;

	int p = partition(a, l, r);    

	if((p - l) > k) return KBig(a, l, p, k);
	else if((p - l) <= k) return KBig(a, p + 1, r, k - (p - l));
}

/************************************************************************/
/*编程之美的题目：2.5寻找最大的K个数
解法四：假如数据量很大，可以先把创建K的数组，来存储，每次新扫描一个数字，就
和数组K中的数字比较，这样的时间复杂度是O(n*k）。如果K创建为一个小顶堆那没每次的
操作为logN,这样的话，时间复杂度就为O(n*logN)。*/
/************************************************************************/

//创建堆
// void HeapAjust(int *pNumber, int length)
// {
// 	int *p = pNumber;
// 	for(int i = (length - 1) / 2 - 1; i >= 0; --i)
// 	{
// 
// 	}
// }


/************************************************************************/
/* 编程之美2.4 1的数目，第一个问题，给定一个整数，求从1到这个整数1出现的次数
自己想的解法*/
/************************************************************************/
int numberOfOne(int n);
int numberOfOne2(int n);

#endif