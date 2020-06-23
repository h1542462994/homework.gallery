

namespace cht 
{
	template <typename T>
	class node
	{
	public:
		node(T *item) 
		{
			this->item = item;
		}
		T *item;
		node<T> *next;
		~node() 
		{
			try
			{
				delete item;
			}
			catch (const std::exception&)
			{

			}
		}
	};

}

