#include<bits/stdc++.h>
using namespace std;

int isValid(string&s1,string&s2,string&s3,int l1,int l2,int l3){
    if(l3==0) return true;
    if(l1>=0 && l2>=0 && s3[l3-1]==s1[l1] &&s3[l3-1]==s2[l2]){
        int valid=isValid(s1,s2,s3,l1-1,l2,l3-1);
        if(valid){
            return true;
        }else{
            return isValid(s1,s2,s3,l1,l2-1,l3-1);
        }
    }else if(l1>=0 && s3[l3-1]==s1[l1]){
        return isValid(s1,s2,s3,l1-1,l2,l3-1);
    }else if (l2>=0 && s3[l3-1]==s2[l2]){
        return isValid(s1,s2,s3,l1,l2-1,l3-1);
    }else{
        return false;
    }
}
int main(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int len1=s1.size();
    int len2=s2.size();
    int mixlen=s3.size();

    if(mixlen!=len1+len2){
        cout<<"NO";
        return 0;
    }
    int valid=isValid(s1,s2,s3,len1-1,len2-1,mixlen);

    cout<< (valid?"YES":"NO");
    return 0;
}
//yummy
//tasty
//ytymmusaty
//NO

