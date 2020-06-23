#include "stu.h"

class node
{
public:
	node(stu *item);
	stu *item;
	node* next;
	~node();
};


