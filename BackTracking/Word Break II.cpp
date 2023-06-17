#include<bits/stdc++.h>
using namespace std;

void solve(int i,int sz,string s1,string s2,unordered_map<string,int>&mp,vector<string>&ans,string s){

        if(i==sz){
            if(mp[s1]>0){
                s2 = s2 + s1;
                ans.push_back(s2);
            }
            return;
        }
        string ss = "";
        if(mp[s1]>0){
            solve(i+1,sz,ss+s[i],s2+s1+" ",mp,ans,s);
        }
        solve(i+1,sz,ss+s1+s[i],s2,mp,ans,s);

    }


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        unordered_map<string,int>mp;
        for(auto it:wordDict){
            mp[it]++;
        }
        int sz = s.size();

        
        solve(0,sz,"","",mp,ans,s);
        return ans;
    }

int main(){

    return 0;
}