// 0108Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <vector>
using namespace std;

#include "Array.h"
#include "maxdiff.h"


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> array1;

	array1.push_back(1);
	array1.push_back(2);
	array1.push_back(3);
	array1.push_back(4);
	array1.push_back(5);

	vector<int>array2;
	array2.resize(array1.size());

	multiply(array1, array2);


	int array[] = {2, 4, 1, 16/*, 7, 5, 11, 9, 4*/};
	std::cout<<maxDiff_Solution1(array, sizeof(array) / sizeof(int))<<endl;

	cout<<maxDiff_Solution2(array, sizeof(array) / sizeof(int))<<endl;

	cout<<maxDiff_Solution3(array, sizeof(array) / sizeof(int))<<endl;

	KBig(array, 0, sizeof(array) / sizeof(int) - 1, 2);

	cout<<"**************************************************************"<<endl;
	cout<<"numberOfOne: "<<numberOfOne(9)<<endl;
	system("pause");
	return 0;
}

