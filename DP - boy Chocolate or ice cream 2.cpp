#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n,k;
    cin >>n,k;

    vector<int>choc(n+1);
    vector<int>ice(n+1);

    choc[1]=ice[1]=1;

    for(int days =2;days<=n;days++)
    {
        choc[days]=choc[days-1]+ice[days-1];
        ice[days]=choc[days-1];
        if(days%k==0)
        {
            ice[days]+=ice[days-1];
        }
    }
    cout<< choc[n]+ice[n];
}
/*
consective days icecream is not allowed but relaxation given on the k days

input : 3 2
output : 6

explanation :
C C C
C C I
C I C
I C C
I C I
I I C

implementation:
n=6 , k =3
day  : 1 2 3 4 5 6
choc : 1 2 3 6 9 15
ice  : 1 1 3 3 6 15
total: 2 3 6 9 15 30


logic :https://youtu.be/j7dsrZ0a9fs
code :https://youtu.be/1bMFUJcigRw


*/
