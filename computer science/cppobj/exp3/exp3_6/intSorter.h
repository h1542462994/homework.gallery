class intSorter
{
public:
	intSorter(int *arr, int length, int flag);

	void sort();

	void print();

private:

	int *arr;
	int length;
	int flag;
};