#include<iostream>
using namespace std ;
template <typename T>
void swapValues(T &val1 , T &val2)
{
    T temp = val1 ;
    val1 = val2 ;
    val2 = temp ;
}
int main()
{
    int val1 , val2 ;
    cin>>val1>>val2 ;
    cout<<val1<<" "<<val2<<endl ;
    swapValues(val1,val2) ;
    cout<<val1<<" "<<val2<<endl ;
    float val3 , val4 ;
    cin>>val3>>val4 ;
    cout<<val3<<" "<<val4<<endl ;
    swapValues(val3,val4) ;
    cout<<val3<<" "<<val4<<endl ;
    char val5 , val6 ;
    cin>>val5>>val6 ;
    cout<<val5<<" "<<val6<<endl ;
    swapValues(val5,val6) ;
    cout<<val5<<" "<<val6<<endl ;
    return 0 ;
}