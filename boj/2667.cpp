#include <bits/stdc++.h>
using namespace std;
int n;
int a[30][30], vis[30][30];
int dx[] = {0,0,1,-1}, dy[] = {-1,1,0,0};
vector<int> v;

int dfs(int x, int y){
    int ret = 0;
    vis[x][y] = 1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny] || !a[nx][ny]) continue;
        ret++;
        ret += dfs(nx,ny);
    }
    return ret;
}

void solve(){
    cin >> n;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<n; j++) a[i][j] = s[j] - '0';
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(vis[i][j] || !a[i][j]) continue;
            v.push_back(dfs(i,j)+1);
        }
    }
    sort(v.begin(), v.end());

    cout << v.size() << '\n';
    for(auto x : v) cout << x << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}