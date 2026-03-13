#include <bits/stdc++.h>
using namespace std;
int n,m,ret;
int know[54];
vector<int> v[54];

void solve(){
    cin >> n >> m;

    int t; cin >> t;
    for(int i=0; i<t; i++){
        int temp; cin >> temp;
        know[temp] = 1;
    }

    for(int i=0; i<m; i++){
        int flag = 0;
        int temp; cin >> temp;
        for(int j=0; j<temp; j++){
            int t; cin >> t;
            v[i].push_back(t);
            if(know[t]) flag = 1;
        }
        if(flag){
            for(auto x : v[i]) know[x] = 1;
            v[i].clear();
        }
    }

    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}