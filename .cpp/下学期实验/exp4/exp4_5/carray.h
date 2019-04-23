#pragma once
#include<iostream>
#include<cstdlib>
#include<cstdarg>
#include<initializer_list>

using namespace std;

template<typename T>
class carray
{
public:
	carray(initializer_list<T> list) 
	{
		_length = list.size();
		_container = new T[_length];
		int index = 0;
		for (auto p = list.begin(); p != list.end(); p++)
		{
			_container[index++] = *p;
		}
	}
	carray(T* container, int length)
	{
		this->_container = container;
		this->_length = length;
	}
	explicit carray(int length) 
	{
		this->_container = new T[length];
		this->_length;
	}
	//返回数组的长度
	int length() const
	{
		return _length;
	}
	//获取位于索引处的元素
	T& elementAt(int index) const
	{
		return _container[index];
	}
	//indexer.
	T& operator[] (int index) const{
		if (index < 0 || index >= _length)
		{
			cerr << "下标越界" << endl;
			throw exception("下标越界");
		}
		return _container[index];
	}

	void Print() 
	{
		for (int i = 0; i < _length; i++)
		{
			cout << _container[i] << endl;
		}
	}
	//int SearchRef(const T& key,T** result) 
	//{
	//	int _count = 0;
	//	for (int i = 0; i < _length; i++)
	//	{
	//		if (&_container[i] == &key)
	//		{
	//			result[_count++] = &(_container[i]);
	//		}
	//	}

	//	return _count;
	//}
	int Search(T key,int* result) 
	{
		int _count = 0;
		for (int i = 0; i < _length; i++)
		{
			if (_container[i] == key)
			{
				result[_count++] = i;
			}
		}

		return _count;
	}


private:
	//T* pointer = NULL;
	T* _container;
	int _length;
};
