#include <bits/stdc++.h>
using namespace std;
int n,ret;
int a[16][16];

int check(int x, int y){
    for(int i=0; i<n; i++){
        if(a[i][y]) return 1;
        if((x-i >= 0) && (y-i >= 0)) if(a[x-i][y-i]) return 1;
        if((x-i >= 0) && (y+i < n)) if(a[x-i][y+i]) return 1;
    }
    return 0;
}

void go(int x, int num){
    if(num == n){
        ret++;
        return;
    }

    for(int i=0; i<n; i++){
        if(a[x][i] || check(x,i)) continue;
        a[x][i] = 1;
        go(x+1,num+1);
        a[x][i] = 0;
    }
}

void solve(){
    cin >> n;
    
    go(0,0);
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}