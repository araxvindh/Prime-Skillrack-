#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++)
    {

        cin>>arr[i];
    }

    stack<int>st;

    for(int i=n-1;i>=0;i--)
    {
        if(!st.empty()&& arr[i]==st.top())
        {
            st.pop();
        }
        else
        {
            st.push(arr[i]);
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();

    }
}
/*
9
20 15 10 30 30 10 15 50 90

output: 20 50 90

*/
