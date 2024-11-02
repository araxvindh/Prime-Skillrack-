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

    int majElm=arr[0];
    int counter=1;

    for(int i=1;i<n;i++)
    {
        if(arr[i]==majElm)
        {
            counter++;
        }
        else{
            counter--;

            if(counter==0)
        {
            majElm=arr[i];
            counter++;
        }
        }


    }
 int cnt=0;
    if(counter>0)
    {

        for(int i=0;i<n;i++)
        {

            if(arr[i]==majElm)
            {
                cnt++;
            }
        }
    }

    if(cnt>(n/2))
    {
        cout<<majElm;
    }
    else
    {
        cout<<"Not Majority";
    }
}



/*
5
2 1 2 4 7


maj 2 1 2

Counter 1 0 1 0 1


8
10 20 10 5 10 10 5 10
output:
10

*/
