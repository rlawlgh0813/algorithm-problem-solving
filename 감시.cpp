// BOJ 15683
// bf

#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[9][9];
int mn = 64;

vector<pair<int,int>> v;

void color(int x, int y, int l, int r, int u, int d){
    for(int i=1; i<8; i++){
        if(l && (y-i >= 0) && a[x][y-i] != 6)
    }
}

void go(){
    for(int i=0; i<4; i++){
        
    }
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

    go();
    cout << mn;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}