#include <bits/stdc++.h>
using namespace std;
int n,idx;
int a[11][11], d1[25], d2[25], ret[2];

void go(int x, int y, int cnt){
    if(y >= n){
        x++;
        y = ((y & 1) ? 0 : 1);
    }
    if(x >= n){
        ret[idx] = max(ret[idx], cnt);
        return;
    }

    if(a[x][y] && !d1[x+y] && !d2[x-y+n]){
        d1[x+y] = d2[x-y+n] = 1;
        go(x,y+2,cnt+1);
        d1[x+y] = d2[x-y+n] = 0;
    }
    go(x,y+2,cnt);
}

void solve(){
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> a[i][j];

    go(0,0,0);
    idx++;
    go(0,1,0);
    cout << ret[0] + ret[1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}