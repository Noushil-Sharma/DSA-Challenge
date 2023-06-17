#include <bits/stdc++.h>
using namespace std;
#define Noushil ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 


void solve(int n,vector<int>&v,vector<vector<int>>&res,vector<int>&temp,vector<int>&vis){
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }
        for(int i =0; i<n; i++){
            if(!vis[i]){
            vis[i]=1;
            temp.push_back(v[i]);
            solve(n,v,res,temp,vis);
            temp.pop_back();
            vis[i]=0;
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        int n = nums.size();
        vector<int>vis(n,0);
        solve(n,nums,res,temp,vis);
        set<vector<int>>s1;
        for(auto it: res){
            s1.insert(it);
        }
        vector<vector<int>>ans;
        for(auto it: s1){
            ans.push_back(it);
        }

        return ans;

    }
int main() {
  Noushil
  
  

  
    
    return 0;
}