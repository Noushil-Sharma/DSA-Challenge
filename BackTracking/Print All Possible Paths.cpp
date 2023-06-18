#include <bits/stdc++.h> 
using namespace std;

void solve(vector<vector<int>>&mat,int i,int j,vector<int>&curr,
vector<vector<int>>&ans) {
    curr.push_back(mat[i][j]);
    if(i==mat.size()-1 && j==mat[0].size()-1) {
        ans.push_back(curr);
        curr.pop_back();
        return;
    }
    if(i+1<mat.size()&&j<mat[0].size()) {
        solve(mat,i+1,j,curr,ans);
    }
    if(j+1<mat[0].size()&&i<mat.size()) {
        solve(mat,i,j+1,curr,ans);
    }
    curr.pop_back();
}

vector<vector<int>> printAllpaths(vector<vector<int>>&mat,int m,int n) {
    vector<int>curr;
    vector<vector<int>> ans;
    solve(mat,0,0,curr,ans);
    return ans;
}

int main(){

    return 0;
}