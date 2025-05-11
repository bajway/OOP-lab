#include<iostream>
using namespace std ;
template <typename T>
void findMax(T* array , int size)
{
    T max = array[0] ;
    for(int i=0 ; i<size ; i++)
    {
        if(array[i]>max)
        {
            max = array[i] ;
        }
    }
    cout<<"Maximum Value:"<<max<<endl ;
}
int main()
{
    int* array = new int[5] ;
    for(int i=0 ; i<5 ; i++)
    {
        cin>>array[i] ;
    }
    findMax(array,5) ;
    delete array ;
    string* array2 = new string[4] ;
    for(int i=0 ; i<4 ; i++)
    {
        cin>>array2[i] ;
    }
    findMax(array2,4) ;
    return 0 ;
}