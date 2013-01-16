#ifndef MAXDIFF_H_H_01
#define MAXDIFF_H_H_01


/************************************************************************/
/* �������У����ּ�ȥ���ұߵ����ֵõ�һ������֮�����������֮������ֵ��
����������{2, 4, 1, 16, 7, 5, 11, 9}�У�����֮������ֵ��11����16��ȥ5�Ľ����                                                                     */
/************************************************************************/
int maxDiff_Solution1(int number[], int length);
int maxDiffCore(int *start, int *end, int &max, int &min);

int maxDiff_Solution2(int numbers[], int length);
int maxDiff_Solution3(int numbers[], int length);

/************************************************************************/
/* ����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�

���磺����������¾���

1              2              3              4
5              6              7              8
9              10             11             12
13             14             15             16   
�����δ�ӡ������1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10��*/
/************************************************************************/



/************************************************************************/
/* ���֮������Ŀ��2.5Ѱ������K����
�ⷨ����*/
/************************************************************************/

template<class Item>
void swap1(Item &rhs, Item &lhs)
{
	Item tmp = rhs;
	rhs = lhs;
	lhs = tmp;
}

/*
*��������ķָ��㷨
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
/*���֮������Ŀ��2.5Ѱ������K����
�ⷨ�ģ������������ܴ󣬿����ȰѴ���K�����飬���洢��ÿ����ɨ��һ�����֣���
������K�е����ֱȽϣ�������ʱ�临�Ӷ���O(n*k�������K����Ϊһ��С������ûÿ�ε�
����ΪlogN,�����Ļ���ʱ�临�ӶȾ�ΪO(n*logN)��*/
/************************************************************************/

//������
// void HeapAjust(int *pNumber, int length)
// {
// 	int *p = pNumber;
// 	for(int i = (length - 1) / 2 - 1; i >= 0; --i)
// 	{
// 
// 	}
// }


/************************************************************************/
/* ���֮��2.4 1����Ŀ����һ�����⣬����һ�����������1���������1���ֵĴ���
�Լ���Ľⷨ*/
/************************************************************************/
int numberOfOne(int n);
int numberOfOne2(int n);

#endif