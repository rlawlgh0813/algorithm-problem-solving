#include <bits/stdc++.h>
using namespace std;
int n,m,ret;
char a[1004][1004];
int vis[1004][1004];

void go(int x, int y){
    if(vis[x][y]) return;
    vis[x][y] = 1;
    
    if(a[x][y] == 'U') go(x-1,y);
    else if(a[x][y] == 'D') go(x+1,y);
    else if(a[x][y] == 'L') go(x,y-1);
    else if(a[x][y] == 'R') go(x,y+1);

    if(x > 0 && a[x-1][y] == 'D') go(x-1,y);
    if(x < n-1 && a[x+1][y] == 'U') go(x+1,y);
    if(y > 0 && a[x][y-1] == 'R') go(x,y-1);
    if(y < m-1 && a[x][y+1] == 'L') go(x,y+1);
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++) a[i][j] = s[j];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]) continue;
            go(i,j);
            ret++;
        }
    }
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}