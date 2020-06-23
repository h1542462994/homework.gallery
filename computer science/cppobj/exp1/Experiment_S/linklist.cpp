#include "linklist.h"
#include<vcruntime.h>
using namespace std;


linklist::linklist() {}

linklist::~linklist()
{
	node *_p = _first;
	while (_p != NULL)
	{
		node *_todelete = _p;
		_p = _p->next;
		delete _todelete;
	}
}

void linklist::add(stu * item) {
	if (!_iter)
	{
		node *p = new node(item);
		p->next = NULL;

		if (_first == NULL)
		{
			_first = p;
			_last = p;
		}
		else
		{
			_last->next = p;
			_last = p;
		}

		++_length;
	}
	else
	{

	}
}

//�Ƴ������е�һ��ƥ��ν�ʵ�Ԫ�ء�

bool linklist::removeFirst(stu * item, predicate_T1 predicate) {
	node *_p = _first;
	node *_prev = NULL;
	while (_p != NULL)
	{
		if (predicate(*item, *(_p->item)))
		{
			if (_p == _first)
			{
				if (_length == 1)
				{
					_first = NULL;
					_last = NULL;
				}
				else
				{
					_first = _p->next;
				}
			}
			else if (_p = _last)
			{
				_prev->next = NULL;
				_last = _prev;
			}
			else
			{
				_prev->next = _p->next;
			}
			--_length;
			//delete _p->item;
			delete _p;
			return true;
		}
		_prev = _p;
		_p = _p->next;
	}
	return false;
}

int linklist::removeAll(stu * item, predicate_T1 predicate) {
	int _matchcount = 0;
	while (removeFirst(item, predicate))
	{
		_matchcount++;
	}
	return _matchcount;
}

stu* linklist::elementAt(int index)
{
	if (index < 0)
	{
		return NULL;
	}
	int i = 0;
	node *_p = _first;
	while (_p != NULL)
	{
		if (index == i)
		{
			return _p->item;
			break;
		}
		_p = _p->next;
		i++;
	}
	return NULL;
}

//������ĵ�i������ǰ����Ԫ�ء�

bool linklist::insert(stu * item, int index)
{
	node *_insert = new node(item);
	node *_p = _first;
	node *_prev = NULL;
	int i = 0;
	while (_p != NULL)
	{
		if (i == index)
		{
			if (_p == _first)
			{
				_insert->next = _first;
				_first = _insert;
			}
			else
			{
				_prev->next = _insert;
				_insert->next = _p;
			}
			++_length;
			return true;
		}
		i++;
		_prev = _p;
		_p = _p->next;
	}
	return false;
}

//ʹ�õ������﷨���������е�����Ԫ��

void linklist::forEach(action_T action)
{
	_iter = true;
	node *_p = _first;
	while (_p != NULL)
	{
		action(*(_p->item));
		_p = _p->next;
	}
	_iter = false;
}

//��������ĳ���

int linklist::length() { return _length; }
