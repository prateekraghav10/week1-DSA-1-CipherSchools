#include "bits/stdc++.h"
using namespace std;

//1st Question
void generate(string &genstr,int open,int close,vector<string> &result){
    if(open>close){
        return;
    }
    if(open <0 || close < 0){
        return;
    }
    if(open ==0 && close == 0){
        result.push_back(genstr);
        return;
    }

    genstr.push_back('(');
    generate(genstr,open-1,close,result);
    genstr.pop_back();

    genstr.push_back(')');
    generate(genstr,open,close-1,result);
    genstr.pop_back();


}
vector<string> generateParenthesis(int n) {
    vector<string> result;
    int open = n;
    int close = n;
    string genstr = "";

    generate(genstr,open,close,result);
    return result;
}


//2nd Question
vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void letterComb(string &digits,int start,string curr,vector<string> &res){
    if(start>=digits.size()){
        res.push_back(curr);
        return;
    }
    int digit = digits[start]-'0';
    string comb = mp[digit];
    for(char ch:comb){
        curr.push_back(ch);
        letterComb(digits,start+1,curr,res);
        curr.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if(digits.empty()){
        return {};
    }
    vector<string> res;
    letterComb(digits,0,"",res);
    return res;
}


//3rd Question
void allarrangement(vector<int> &nums,int start,int end, vector<vector<int>> &result){
    if(start>end){
        result.push_back(nums);
        return;
    }
    for(int j=start;j<nums.size();j++){
        swap(nums[start],nums[j]);
        allarrangement(nums,start+1,end,result);
        swap(nums[start],nums[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    int start = 0;
    int end = nums.size()-1;

    allarrangement(nums,start,end,result);
    return result;
}



//4th Question
void allsubset(vector<int> &nums,int start,vector<int> &temp,vector<vector<int>> &result){
    if(start>=nums.size()){
        result.push_back(temp);
        return;
    }
    temp.push_back(nums[start]);
    allsubset(nums,start+1,temp,result);
    temp.pop_back();
    allsubset(nums,start+1,temp,result);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> temp;
    allsubset(nums,0,temp,result);
    return result;
}


int main(){
    cout<<"Lecture 10"<<endl;
    return 0;
}