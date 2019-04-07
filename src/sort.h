/*
 * suzhengpeng<at>hotmail.com
 */
#ifndef SORT_H
#define SORT_H
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
		void selectionSort(); // sort _elem[] by Selection
		void insertionSort(); // sort _elem[] by Insertion
	private:
		bool bubble(Rank key);
		Rank select(Rank key);
		void insert(Rank key);
};
#endif


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
/*Bubble Sort*/
template <typename T> void Sort<T>::bublleSort()
{
	Rank key = 0;
	while(!bubble(key));
}
template <typename T> bool Sort<T>::bubble(Rank key)
{
	bool sorted = true;
	while(++key < _elemSize)
	{
		if(_elem[key - 1] > _elem[key])
		{
			sorted = false;
			swap(_elem[key - 1],_elem[key]);
		}
	}
	return sorted;
}
/*Selection Sort*/
template <typename T> void Sort<T>::selectionSort()
{
	Rank key = 0;
	for(Rank i = 0; i < _elemSize;i++)
	{
		Rank min = select(key++);
		swap(_elem[min],_elem[i]);
	}
}
template <typename T> Rank Sort<T>::select(Rank key)
{
	Rank select = key;
	for (Rank i = key; i < _elemSize; i++)
	{
		if(_elem[i] < _elem[select])
		{
			select = i;
		}
	}
	return select;
}
/*Insertion Sort*/
template <typename T> void Sort<T>::insertionSort()
{
	T *elemBuf = new T[_elemSize];
	Rank key = 1;
	while (key < _elemSize)
	{
		insert(key);
		key++;
	}
}
template <typename T> void Sort<T>::insert(Rank key)
{
	Rank val = _elem[key];
	Rank i = 0;
	while(val > _elem[i])
	{
		i++;
	}
	for(Rank j = key ; j > i ;j -- )
	{
		//cout << "SWAP" << endl;
		swap(_elem[j],_elem[j-1]);
	}
}