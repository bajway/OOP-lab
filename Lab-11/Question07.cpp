#include<iostream>
using namespace std ;
template <typename T>
class SmartArray
{
    public:
        int size ;
        T* array = new T[size] ;
        SmartArray(int size) : size(size)
        {
            for(int i=0 ; i<size ; i++)
            {
                cin>>array[i] ;
            }
        }
} ;
int main()
{
    SmartArray<int> array2(5) ;
    try
    {
        int index = 0 ;
        cin>>index ;
        if(index>array2.size)
        {
            throw "OutOfBoundsException" ;
        }
        else
        {
            cout<<array2.array[index] ;
        }   
    }
    catch(const char* exception)
    {
        cout<<"Invalid Access Attempted!!!"<<endl ;
    }
    return 0 ;
}