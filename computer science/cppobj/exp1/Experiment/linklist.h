#include "node.h"
#include<vcruntime.h>
using namespace std;

namespace cht 
{
	template <typename T>
	class linklist
	{
	public:
		//����һ����Ԫν��
		typedef bool(*predicate_T1)(T &, T &);
		//����һ���޷���ֵ�ĺ���
		typedef void(*action_T)(T &);

		//��ʼ��
		linklist() {}
		~linklist()
		{
			node<T> *_p = _first;
			while (_p != NULL)
			{
				node<T> *_todelete = _p;
				_p = _p->next;
				delete _todelete;
			}
		}
		//��һ�������ʼ������ȼ���create(T *array_T)
		linklist(T *array_T, int length)
		{
			for (int i = 0; i < length; i++)
			{
				node<T> *_p = new node<T>(array_T[i]);
				_p->next = NULL;
				if (_first == NULL)
				{
					_first = _p;
					_last = _p;

				}
				else
				{
					_last->next = _p;
					_last = _p;
				}
			}
		}
		void add(T *item) {
			if (!_iter)
			{
				node<T> *p = new node<T>(item);
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
		bool removeFirst(T * item, predicate_T1 predicate) {
			node<T> *_p = _first;
			node<T> *_prev = NULL;
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
		int removeAll(T *item, predicate_T1 predicate) {
			int _matchcount = 0;
			while (removeFirst(item,predicate))
			{
				_matchcount++;
			}
			return _matchcount;
		}
		//�Ƴ������е�һ��ƥ��ν�ʵ�Ԫ�أ�ʹ��Ĭ�ϵıȽ�����
		bool removeFirst(T item)
		{
			node<T> *_p = _first;
			node<T> *_prev = NULL;
			while (_p != NULL)
			{
				if (item == *(_p->item))
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
		//��ȡ������������Ԫ�ص�ָ�룬����Ԫ�ز����ڣ��򷵻�NULL.
		T *elementAt(int index)
		{
			if (index < 0)
			{
				return NULL;
			}
			int i = 0;
			node<T> *_p = _first;
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
		bool insert(T * item, int index)
		{
			node<T> *_insert = new node<T>(item);
			node<T> *_p = _first;
			node<T> *_prev = NULL;
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
		void forEach(action_T action)
		{
			_iter = true;
			node<T> *_p = _first;
			while (_p != NULL)
			{
				action(*(_p->item));
				_p = _p->next;
			}
			_iter = false;
		}
		//��������ĳ���
		int length() { return _length; }
	private:

		bool _iter = false;
		int _length = 0;
		node<T> *_first = NULL;
		node<T> *_last = NULL;
	};
}

