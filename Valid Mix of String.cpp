#include<bits/stdc++.h>
using namespace std;

int isValid(string&str1,string&str2,string&str3,int len1,int len2,int mixlen,int ind1 ,int ind2,int indmix){
    if(mixlen==indmix){
        return true;
    }
    if(ind1<len1 && ind2<len2 && str3[indmix]==str1[ind1] &&str3[indmix]==str2[ind2]){
        int valid= isValid(str1,str2,str3,len1,len2,mixlen,ind1+1,ind2,indmix+1);
        if(valid){
            return true;
        }else{
            return isValid(str1,str2,str3,len1,len2,mixlen,ind1,ind2+1,indmix+1);
        }
    }else if (ind1<len1 && str3[indmix]==str1[ind1]){
        return isValid(str1,str2,str3,len1,len2,mixlen,ind1+1,ind2,indmix+1);
    }else if (ind2<len2 &&str3[indmix]==str2[ind2]){
        return isValid(str1,str2,str3,len1,len2,mixlen,ind1,ind2+1,indmix+1);
    }else{
        return false;
    }

}

int main(){
    string str1,str2,str3;
    cin>>str1>>str2>>str3;
    int len1 =str1.size();
    int len2 =str2.size();
    int mixlen =str3.size();
    if(mixlen!=len1+len2){
        cout<<"INVALID"<<endl;
        return 0;
    }
    int valid=(isValid(str1,str2,str3,len1,len2,mixlen,0,0,0));
    cout<<(valid ?"VALID":"INVALID") << endl;

return 0;
}
//nose
//neck
//nonseeck
