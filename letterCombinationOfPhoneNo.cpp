#include<bits/stdc++.h>
using namespace std;

unordered_map<char,string> mpp={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

void letterCom(const string & digits,int index,vector<string> &result, string &comb){
    if(index==digits.size())
    {
        result.push_back(comb);
        return;
    }
    string letters = mpp[digits[index]];
    for(char letter: letters){
        comb.push_back(letter);
        letterCom(digits,index+1,result,comb);
        comb.pop_back();
    }

}
 vector<string> letterCombinations(string digits) {
     vector<string>result;
     string comb;
     if(digits.empty()){
        return result;
     }
     letterCom(digits,0,result,comb);
     return result;

 }

int main()
{

    string digits;
    cin>> digits;

   vector<string> combinations = letterCombinations(digits);

    for (const string &s : combinations) {
        cout << s << " ";
    }
    return 0;
}

/*
23
ad ae af bd be bf cd ce cf
*/
