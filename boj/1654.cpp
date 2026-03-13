#include <bits/stdc++.h>
using namespace std;
int n;
long long l,r,m;
long long a[10004];

int check(long long len){
    int ret = 0;
    for(int i=0; i<n; i++) ret += a[i] / len;
    return ((ret >= m) ? 1 : 0);
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
        r = max(r, a[i]);
    }
    while(l < r){
        long long m = (l + r) / 2 + 1;
        if(check(m)) l = m;
        else r = m - 1;
    }
    cout << l;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}