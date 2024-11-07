#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,s,t;
    cin>>n>>s>>t;

    vector<int>steps(s);
    for(int i=0;i<s;i++)
    {
        cin>>steps[i];
    }

    vector<int>dam(t);
    for(int j=0;j<t;j++)
    {
        cin>>dam[j];
    }

    vector<int>ways(n+1);

    ways[0]=1;

    for(int i=1;i<=n;i++)
    {
        if(find(dam.begin(),dam.end(),i)!=dam.begin())
        for(int j=0;j<s;j++)
        {
            if(i>=steps[j])
            {
                 ways[i]+=ways[i-steps[j]];
            }
        }
    }
    cout<<ways[n];
}
/*
input:
5 2 1
2 3
2

output:
1

input:
10 2 3
2 3
2 4 6
code and logic : https://youtu.be/xXn-rTWzpHs


*/
