// BOJ 15683
// bf

#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[9][9];
int mn = 987654321;

vector<pair<int,int>> v;

void color(int x, int y, int l, int r, int u, int d){

}

void go(int x, int y){

}

void solve(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j] == 6 || a[i][j] == 0) continue;
            else if(a[i][j] == 5) color(i,j,1,1,1,1);
            else v.push_back({i,j});
        }
    }

    for(auto here : v){

    }

    cout << (mn ==)
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}