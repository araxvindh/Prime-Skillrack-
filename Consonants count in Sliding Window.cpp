#include<bits/stdc++.h>

using namespace std;

bool isVowel(char a)
{
    a=tolower(a);

    return a=='a' || a=='e' || a=='i' || a=='o' || a=='u' ;
}


int main()
{
    int n ,k;
    cin>>n>>k;
    string word;
    cin>> word;
    int cnt=0;

    for(int i=0;i<k;i++)
    {
        if(!isVowel(word[i]))
        {
            cnt++;
        }
    }
    cout<< cnt<<" ";

    for(int i=1;i<=n-k;i++)
    {
        if((!isVowel(word[i-1])))
        {
            cnt--;
        }
        if((!isVowel(word[i+k-1])))
        {
            cnt++;
        }
        cout << cnt <<" ";
    }
}


/*
3
pineapple


*/
