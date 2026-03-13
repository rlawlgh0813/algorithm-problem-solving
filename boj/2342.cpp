#include <bits/stdc++.h>
using namespace std;
int ret = 1e9;
int a[100004];

void go(int l, int r, int cur, int cnt){
    if(a[cur] == 0){
        ret = min(ret, cnt);
        return;
    }

    if(l == a[cur] || r == a[cur]) go(l,r,cur+1,cnt+1);

    if(l == -1 && r != a[cur]) go(a[cur],r,cur+1,cnt+2);
    if(r == -1 && l != a[cur]) go(l,a[cur],cur+1,cnt+2);

    if((l+1)%4 == a[cur] && r != a[cur]) go(a[cur],r,cur+1,cnt+3);
    if((r+1)%4 == a[cur] && l != a[cur]) go(l,a[cur],cur+1,cnt+3);
    if((l+3)%4 == a[cur] && r != a[cur]) go(a[cur],r,cur+1,cnt+3);
    if((r+3)%4 == a[cur] && l != a[cur]) go(l,a[cur],cur+1,cnt+3);

    if((l+2)%4 == a[cur] && r != a[cur]) go(a[cur],r,cur+1,cnt+4);
    if((r+2)%4 == a[cur] && l != a[cur]) go(l,a[cur],cur+1,cnt+4);
}

void solve(){
    for(int i=0; i<100004; i++){
        int n; cin >> a[i];
        if(n == 0) break;
        else a[i]--;
    }
    go(-1,-1,0,0);
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}