#include "node.h"

node::node(stu * item)
{
	this->item = item;
}

node::~node()
{
	try
	{
		delete item;
	}
	catch (const std::exception&)
	{

	}
}
