#include <bits/stdc++.h>
using namespace std;
int n,m,ret;
int a[604][604],vis[604][604];
int dx[] = {0,0,1,-1}, dy[] = {-1,1,0,0};
queue<pair<int,int>> q;

void solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++){
            a[i][j] = s[j];
            if(s[j] == 'I') q.push({i,j});
        }
    }

    while(q.size()){
        pair<int,int> here = q.front(); q.pop();
        if(a[here.first][here.second] == 'P') ret++;
        for(int i=0; i<4; i++){
            int nx = here.first + dx[i];
            int ny = here.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || a[nx][ny] == 'X') continue;
            q.push({nx,ny});
            vis[nx][ny] = 1;
        }
    }

    if(ret) cout << ret;
    else cout << "TT";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}