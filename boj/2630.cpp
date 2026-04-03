#include <bits/stdc++.h>
using namespace std;
int n;
int a[130][130], ret[2];

void go(int x, int y, int n){
    int cnt = 0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(a[x+i][y+j]) cnt++;
    
    if(cnt == n*n) ret[1]++;
    else if(cnt == 0) ret[0]++;
    else{
        go(x,y,n/2);
        go(x,y+n/2,n/2);
        go(x+n/2,y,n/2);
        go(x+n/2,y+n/2,n/2);
    }
}

void solve(){
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> a[i][j];
    go(0,0,n);
    cout << ret[0] << '\n' << ret[1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}