#include<iostream>
using namespace std;
class FunArray{
    int* pa, size;
public:
    FunArray(int a[], int thesize) : pa(a),size(thesize){ }
    int Size(){ return size; }
    int& operator[](int index)  
    {
        if(index >= size)
            throw index; 
        return pa[index];
    }
};
int main()
{
    int s[]={ 3, 5, 2, 0, 7, 4 };
    int len = sizeof(s)/sizeof(int);  	
    try
    {							
        FunArray ma(s, len);		
        ma[3] = 1;				
        for(int i=0; i<len; i++)
            cout<<' '<<ma[s[i]];  
    }
    catch(int err)					
    {							
        cout<<"\nInvalid index: "<<err<<"\n"; 
    }
    return 0;
} 
