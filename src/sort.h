/*
 * suzhengpeng<at>hotmail.com
 */
#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <vector>

typedef int Idx;

using namespace std;

template <typename T> class Sort
{
	protected:
		T * _elem; // store a arry for sort
		Idx _elemSize; // size of _elem[]
	  public:
		Sort(int size); // Constructor functions: create object by size
		Sort(vector<T> arr); // Constructor functions: create object from a vector
		~Sort(){delete[] _elem;}
		Idx size();		// return the size of _elem[]
		void display(); // print _elem[] by element-wise
		void bublleSort(); // sort _elem[] by Bubble
		void selectionSort(); // sort _elem[] by Selection
		void insertionSort(); // sort _elem[] by Insertion
		void quickSort(); // sort _elem[] by Quick
	private:
		bool bubble(Idx key);
		Idx select(Idx key);
		void insert(Idx key);
		void quick(Idx left, Idx right);
};
#endif


template <typename T> Sort<T>::Sort(Idx size)
{
	_elem = new T[size];
	for (Idx i = 0; i < size; i++)
	{
		_elem[i] = 0;
	}
	_elemSize = size;
}
template <typename T> Sort<T>::Sort(vector<T> arr)
{
	_elem = new T[arr.size()];
	for (Idx i = 0; i < arr.size(); i++)
	{
		_elem[i] = arr[i];
	}
	_elemSize = arr.size();
}
template <typename T> Idx Sort<T>::size()
{
	return _elemSize;
}
template <typename T> void Sort<T>::display()
{
	for (Idx i = 0; i < _elemSize; i++)
	{
		cout << _elem[i] << endl;
	}
}
/*Bubble Sort*/
template <typename T> void Sort<T>::bublleSort()
{
	Idx key = 0;
	while(!bubble(key));
}
template <typename T> bool Sort<T>::bubble(Idx key)
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
	Idx key = 0;
	for (Idx i = 0; i < _elemSize; i++)
	{
		Idx min = select(key++);
		swap(_elem[min],_elem[i]);
	}
}
template <typename T> Idx Sort<T>::select(Idx key)
{
	Idx select = key;
	for (Idx i = key; i < _elemSize; i++)
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
	Idx key = 1;
	while (key < _elemSize)
	{
		insert(key);
		key++;
	}
}
template <typename T> void Sort<T>::insert(Idx key)
{
	T val = _elem[key];
	Idx i = 0;
	while(val > _elem[i])
	{
		i++;
	}
	for (Idx j = key; j > i; j--)
	{
		//cout << "SWAP" << endl;
		swap(_elem[j],_elem[j-1]);
	}
}
template <typename T> void Sort<T>::quickSort()
{
	Idx l = 0, r = _elemSize - 1;
	quick(l,r);
}
template <typename T> void Sort<T>::quick(Idx left,Idx right)
{
	if(left > right)
	{
		return;
	}
	Idx i = left, j = right;
	T base = _elem[i];
	while(i!=j){
		while(_elem[j] >= base && i < j){
			j--;
		}
		while(_elem[i] <= base && i < j){
			i++;
		}
		if(i < j)
		{
			swap(_elem[i],_elem[j]);
		}
	}
	_elem[left] = _elem[i];
	_elem[i] = base;
	quick(left,i - 1);
	quick(i + 1,right);
}