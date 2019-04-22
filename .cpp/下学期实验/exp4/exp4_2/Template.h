template<typename T>
void sort(T* array_T, int length,int direction=1) 
{
    for (int i = 0; i < length - 1; i++)
    {
        int lindex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (direction == 1)
            {
                if (array_T[j] < array_T[lindex])
                {
                    lindex = j;
                }
            }
            else 
            {
                if (array_T[j] > array_T[lindex])
                {
                    lindex = j;
                }
            }
        }
        if (lindex != i)
        {
            T t = array_T[lindex];
            array_T[lindex] = array_T[i];
            array_T[i] = t;
        }
    }
}

template<typename T>
void print(T* array_T, int length ) 
{
    for (int i = 0; i < length; i++)
    {
        cout << array_T[i] << endl;
    }
}