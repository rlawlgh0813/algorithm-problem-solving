#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n,m,ret = INF;
long long a[100004];

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    
    int s = 0, e = 1;
    while(s < e){
        long long cnt = a[e] - a[s];
        if(cnt >= m){
            ret = min(ret, e-s);
            s++;
        }else{
            e++;
            if(e > n) break;
        }
    }
    cout << (ret == INF) ? 0 : ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}