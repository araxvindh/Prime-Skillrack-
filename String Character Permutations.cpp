#include<bits/stdc++.h>

using namespace std;
void swap1(string& str,int i,int j)
{
    char temp=str[i];
    str[i]=str[j];
    str[j]=temp;
}



void permutate(string&str , int left ,int right)
{
    if(left==right)
    {
        cout<<str<<endl;
        return;
    }
    for(int index=left;index<=right;index++)
    {
        swap1(str,left,index);
        permutate(str,left+1,right);
        swap1(str,left,index);
    }
}



int main()
{
    string a;
    cin>>a;
    int len=a.size();

    permutate(a,0,len-1);
}


/*

input:
abc

Output:
abc
acb
bac
bca
cba
cab


input:
rack

Output:
rack
rakc
rcak
rcka
rkca
rkac
arck
arkc
acrk
ackr
akcr
akrc
cark
cakr
crak
crka
ckra
ckar
kacr
karc
kcar
kcra
krca
krac

*/
