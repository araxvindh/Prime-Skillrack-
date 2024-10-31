#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int>chocdp(n+1);
    vector<int>icedp(n+1);

    chocdp[1]=icedp[1]=1;

    for(int days =2;days<=n;days++)
    {
        chocdp[days]=chocdp[days-1]+icedp[days-1];

        icedp[days]=chocdp[days-1];
    }
    cout<<chocdp[n]+icedp[n];

}
/*
input : 3
OutPut: 5

explaination :
C C C
C C I
C I C
I C I
I C C

icecream is not allowed on the consecutive days

*/
