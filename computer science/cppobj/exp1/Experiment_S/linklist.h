#include "node.h"
#include "stu.h"
using namespace std;

//����һ����Ԫν��
typedef bool(*predicate_T1)(stu &, stu &);
//����һ���޷���ֵ�ĺ���
typedef void(*action_T)(stu &);

class linklist
{
public:
	//��ʼ��
	linklist();
	~linklist();
	void add(stu *item);
	//�Ƴ������е�һ��ƥ��ν�ʵ�Ԫ�ء�
	bool removeFirst(stu * item, predicate_T1 predicate);
	int removeAll(stu *item, predicate_T1 predicate);
	stu *elementAt(int index);
	//������ĵ�i������ǰ����Ԫ�ء�
	bool insert(stu * item, int index);

	//ʹ�õ������﷨���������е�����Ԫ��
	void forEach(action_T action);
	//��������ĳ���
	int length();
private:

	bool _iter = false;
	int _length = 0;
	node *_first = NULL;
	node *_last = NULL;
};


