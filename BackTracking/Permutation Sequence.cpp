#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string s,int k,int n,vector<string>&ans,vector<bool>&vis,int cnt,string &temp){
        if(temp.size()==n){
            ans.push_back(temp);
            cnt++;
            
            if(cnt==k) return;
        }

        for(int i =0; i<n; i++){
            if(!vis[i]){
                vis[i]=1;
                temp.push_back(s[i]);
                solve(s,k,n,ans,vis,cnt,temp);
                temp.pop_back();
                vis[i]=0;
            }

            if(cnt==k)  return;
        }
    }
    string getPermutation(int n, int k) {
        vector<string>ans;
        string s;
        for(int i =1; i<=n; i++){
            s+=to_string(i);
        }
        cout<<s<<" ";
        vector<bool>vis(n,0);
        string temp = "";
        solve(s,k,n,ans,vis,0,temp);
        return ans[k-1];

    }
};

int main(){

    return 0;
}