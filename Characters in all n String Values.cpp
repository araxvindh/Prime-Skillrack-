#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<string>arr(n);
    int result=1;
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    map<int,int>mpp;
    for (int i = 0; i < 26; i++) {
        mpp[i] = 0;
    }
    for(int i=0;i<n;i++){
        for(char ch : arr[i]){
            if(mpp[ch-'a']==i){
                mpp[ch-'a']++;
            }
        }
    }
    for(int i=0;i<26;i++){
        if(mpp[i]==n){
            char ch =('a'+i);
            cout<<ch<<" ";
        }
    }
}

/*
5
giraffe
fishery
orangeisland
magnetism
engine

output e n



*/
