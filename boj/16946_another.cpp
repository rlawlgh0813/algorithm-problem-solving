#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1004][1004], val[1000004], parent[1000004];
int dx[] = {0,1,0,-1}, dy[] = {-1,0,1,0};

int Find(int n){
    if(parent[n] == n) return n;
    return parent[n] = Find(parent[n]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    parent[b] = a;
    val[a] += val[b];
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++){
            a[i][j] = s[j] - '0';
            parent[i*m + j] = i*m + j;
            val[i*m + j] = 1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]) continue;
            for(int k=0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny]) continue;
                Union(i*m + j, nx*m + ny);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 0){
                cout << 0;
                continue;
            }
            set<int> s;
            int cnt = 1;
            for(int k=0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny]) continue;
                s.insert(Find(nx*m + ny));
            }
            for(auto x : s) cnt += val[x];
            cout << cnt % 10;
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}