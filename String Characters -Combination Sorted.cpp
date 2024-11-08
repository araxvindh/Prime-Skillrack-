#include<bits/stdc++.h>

using namespace std;

int main()
{

    string a;
    cin>>a ;

    int n=a.size();
    vector<string>c;
    for(int ctr=0;ctr<(1<<n);ctr++)
    {
        string b;
        for(int bin=0;bin<n;bin++)
        {
            if((ctr&1<<bin)!=0)
            {
                b+=a[bin];
            }
        }
        c.push_back(b);
    }

    for(auto it :c)
    {
        cout<<it<<endl;
    }
}

/*
abc

a
b
ab
c
ac
bc
abc

*/
