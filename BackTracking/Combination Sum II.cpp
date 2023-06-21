#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void f(int i,vector<vector<int>>&res, vector<int>& can,vector<int>& temp, int tar){
            if(tar==0){
                res.push_back(temp);
                return;
            } 
        for(int j=i;j<can.size();j++){
            if(j>i && (can[j]==can[j-1])) continue;
            if(can[j]>tar) break;
            temp.push_back(can[j]);
            f(j+1,res,can,temp,tar-can[j]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        sort(can.begin(),can.end());
        vector<vector<int>>res;
        vector<int>temp;
        f(0,res,can,temp,tar);
        return res;
        
        
    }
};


int main(){
    
}