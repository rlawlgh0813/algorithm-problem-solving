#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1004][1004], vis[1004][1004], val[1000004];
int dx[] = {0,1,0,-1}, dy[] = {-1,0,1,0};

int go(int x, int y, int idx){
    int cnt = 0;

    vis[x][y] = idx;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] || vis[nx][ny]) continue;
        cnt += go(nx,ny,idx) + 1;
    }
    return cnt;
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++) a[i][j] = s[j] - '0';
    }

    int cnt = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 0 && vis[i][j] == 0){
                val[cnt] = go(i,j,cnt) + 1;
                cnt++;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 0) continue;
            set<int> s;
            s.clear();
            for(int k=0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny]) continue;
                s.insert(vis[nx][ny]);
            }
            if(s.size()) for(auto x : s) a[i][j] += val[x];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cout << a[i][j] % 10;
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}