#include "node.h"
#include "stu.h"
using namespace std;

//定义一个二元谓词
typedef bool(*predicate_T1)(stu &, stu &);
//定义一个无返回值的函数
typedef void(*action_T)(stu &);

class linklist
{
public:
	//初始化
	linklist();
	~linklist();
	void add(stu *item);
	//移除链表中第一个匹配谓词的元素。
	bool removeFirst(stu * item, predicate_T1 predicate);
	int removeAll(stu *item, predicate_T1 predicate);
	stu *elementAt(int index);
	//在链表的第i个索引前插入元素。
	bool insert(stu * item, int index);

	//使用迭代器语法迭代链表中的所有元素
	void forEach(action_T action);
	//返回链表的长度
	int length();
private:

	bool _iter = false;
	int _length = 0;
	node *_first = NULL;
	node *_last = NULL;
};


