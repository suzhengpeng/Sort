/*
 * suzhengpeng<at>hotmail.com
 */
#include <iostream>
#include <vector>

typedef int Rank;

using namespace std;

template <typename T> class Sort
{
	protected:
		T * _elem; // store a arry for sort
		Rank _elemSize; // size of _elem[]
	public:
		Sort(int size); // Constructor functions: create object by size
		Sort(vector<T> arr); // Constructor functions: create object from a vector
		~Sort(){delete[] _elem;}
		Rank size(); // return the size of _elem[]
		void display(); // print _elem[] by element-wise
		void bublleSort(); // sort _elem[] by Bubble
	private:
		bool bubble(Rank lo,Rank hi);
};
template <typename T> Sort<T>::Sort(Rank size)
{
	_elem = new T[size];
	for(Rank i = 0;i < size;i ++)
	{
		_elem[i] = 0;
	}
	_elemSize = size;
}
template <typename T> Sort<T>::Sort(vector<T> arr)
{
	_elem = new T[arr.size()];
	for(Rank i = 0;i < arr.size();i ++)
	{
		_elem[i] = arr[i];
	}
	_elemSize = arr.size();
}
template <typename T> Rank Sort<T>::size()
{
	return _elemSize;
}
template <typename T> void Sort<T>::display()
{
	for(Rank i = 0;i < _elemSize;i ++)
	{
		cout << _elem[i] << endl;
	}
}
template <typename T> void Sort<T>::bublleSort()
{
	Rank lo = 0,hi = _elemSize;
	while(!bubble(lo,hi--));
}
template <typename T> bool Sort<T>::bubble(Rank lo,Rank hi)
{
	bool sorted = true;
	while(++lo < hi)
	{
		if(_elem[lo - 1] > _elem[lo])
		{
			sorted = false;
			swap(_elem[lo - 1],_elem[lo]);
		}
	}
	return sorted;
}
