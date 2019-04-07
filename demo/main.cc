/*
 * suzhengpeng<at>hotmail.com
 */
#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;

int main()
{
	int arr[] = {0, 2, 3, 1, 5, 1,10,8,44,6};
	vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
	Sort<int> B(nums);
	B.display();
	cout << "SIZE of B :"<<B.size() << endl;
	B.bublleSort();
	B.display();
}
