#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int x = 0;

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
void dfs(unordered_map<int,vector<int>>&adj,int node,vector<int>&vis){
    vis[node]=1;
    x++;
    
    for(auto nbr: adj[node]){
        if(!vis[nbr]){
            dfs(adj,nbr,vis);
        }
    }
    return;
}

int journeyToMoon(int n, vector<vector<int>> v) {
    unordered_map<int,vector<int>> adj;
    for(int i = 0; i<v.size();i++){
        adj[v[i][0]].push_back(v[i][1]);
        adj[v[i][1]].push_back(v[i][0]);
    }
    vector<int>vis(n,0);
    
    vector<int>vv;
    for(int i =0; i<n;i++){
        if(!vis[i]){
            dfs(adj,i,vis);
            vv.push_back(x);
            x=0;
        }
        
    }
    if(vv.size()==1){
        return 0;
    }
    int ans = 0;
    int sum = vv[0];
    int m = vv.size();
    for(int i = 1; i<m;i++){
        ans = ans + sum*vv[i];
        sum = sum + vv[i];
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
