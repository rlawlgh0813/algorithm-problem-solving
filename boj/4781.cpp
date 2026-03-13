#include <bits/stdc++.h>
using namespace std;
int flag=1;
int a[10004];

void solve(){
    int n,m,u,t; scanf("%d %d.%d",&n,&u,&t); m = u*100 + t;
    if(n == 0 || m == 0){ flag = 0; return; }

    memset(a,0,sizeof(a));
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        int c,p,t,u; scanf("%d %d.%d",&c,&t,&u); p = t*100 + u;
        v.push_back({c,p});
    }

    for(int i=0; i<m; i++){
        for(auto x : v){
            if(i + x.second > m) continue;
            a[i + x.second] = max(a[i+x.second], a[i] + x.first);
        }
    }

    int ret = 0;
    for(int i=0; i<=m; i++) ret = max(ret, a[i]);
    cout << ret << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    while(flag) solve();
    return 0;
}