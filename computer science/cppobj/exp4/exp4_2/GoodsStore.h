	class GoodsStore 
	{
	public:
		static void reset();

		static void addStore(int n, double price);
		static double getSum();
		static double getAveragePrice();
	private:
		static int _count;
		static double _price;
	};