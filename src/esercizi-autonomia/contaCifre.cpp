#include <iostream>
using namespace std;

int main()
{
    int n=0, frequenza[10] = {0,0,0,0,0,0,0,0,0,0};
    cout<<"inserisci un numero intero: ";
    cin>>n;

    for ( int i=n%10; n>0; i=(n/=10)%10)
    {
        frequenza [i] = frequenza[i]+1;
    }
    for ( int i=0; i<=9; ++i)
    {
        cout<<"la frequenza di " <<i <<" è: " <<frequenza[i] <<endl;
    }
    return 0;
}