#include<bits/stdc++.h>

using namespace std;

bool isVowel(char a)
{
    a=tolower(a);
    return a=='a' || a=='e' || a=='i' || a=='o' || a=='u' ;
}



int main()
{

    string a;
    int k;
    cin>>a;
    cin>>k;
    int n=a.size();
    int bal=0;
    int cnt=0;
    for(int i=0;i<k;i++)
    {
        if(isVowel(a[i])){
            bal++;
        }
        else
        {
            bal--;
        }
    }
    if(bal==0)
    {
        cnt++;
    }

    for(int i=1;i<=n-k;i++)
    {
        bal=bal+ (isVowel(a[i-1])?-1:1);
        bal=bal+(isVowel(a[i+k-1])?1:-1);

        if(bal==0)
        {
            cnt++;
        }
    }
        cout<<cnt;
}

/*
havenhelljoysorrow
4

skillrack
2



*/
