#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s , key ;
    cin>>s>>key;

    int slen=s.size();
    int keyLen=key.size();

    vector<int>lps(keyLen);
    lps[0]=0;
    int len=0;
    for(int i=1;i<keyLen;)
    {
        if(key[i]==key[len])
        {
            lps[i]=len;
            i++;
            len++;

        }
        else
        {
            if(len==0)
            {
                lps[i]=len;
                i++;
            }else
            {
                len=lps[len-1];
            }
        }

    }

    int cnt=0;
    int lpsInd=0;
    for(int ind=0;ind<slen;)
    {
        if(s[ind]==key[lpsInd])
        {
            ind++;
            lpsInd++;
            if(lpsInd==keyLen)
            {
                cnt++;
                lpsInd=0;
            }
        }
        else
        {
            if(lpsInd==0)
            {
                ind++;
            }
            else
            {
                lpsInd=lps[lpsInd-1];
            }
        }

    }
   cout<<cnt;
}

/*
KMP ALGORITHM
string: aaaabaaaabaa

      01234
key : aabaa
lps : 01012

Now lps with string
0-0
1-1
2-2
2-1
3-2
3-1
4-2
5-3
6-4 count++
7-0
8-1
9-2
10-3
11-4  count++

code:https://youtu.be/S50mCVovRwQ
logic : https://youtu.be/A6qCbbaoO84

input:
XyzzxxXyZzyxXyzzxXzz
xXyzz

output:
1


*/
