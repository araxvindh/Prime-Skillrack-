
#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>&arr,vector<vector<int>>&dp,int left,int right)
{
    if(left>right){
        return 0;
    }
    if(dp[left][right]!=-1){
        return dp[left][right];
    }
    int maxPts=-1;

    for(int i=left;i<right;i++){
        int maxPts =max(solve(arr,dp,left,i-1),solve(arr,dp,i+1,right),arr[left-1]*arr[i]*arr[right+1]);
    }
    dp[left][right]=maxPts;
    return maxPts;
}


int main()
{
    int n;
    vector<int>arr(n+2);
    int len=arr.size();
    arr[0]=1;
    arr[len-1]=1;
   vector<vector<int>>dp(n+1,vector<int>(n+1));
    for(int i=1;i<len-1;i++){
        cin>> arr[i];
    }
    cout<< solve(arr,dp,1,n-1);
    return 0;
}

// 3 1 5 8
