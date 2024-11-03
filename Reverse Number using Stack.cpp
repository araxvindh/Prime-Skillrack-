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

    for(int i=0;i<n;i++)
    {
        st.push(arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

/*

5
10 20 30 50 40

output :
40 50 30 20 10
*/
