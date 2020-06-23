	#include"Compare.h"

    template<typename TNum>
	Compare<TNum>::Compare(TNum a,TNum b)
	{
		x = a; y = b;
	}

	template<typename TNum>
	TNum Compare<TNum>::max() 
	{
		return (x > y) ? x : y;
	}

	template<typename TNum>
	TNum Compare<TNum>::min()
	{
		return (x < y) ? x : y;
	}