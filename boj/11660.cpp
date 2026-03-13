#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[1030][1030];
int n,m,a,b,c,d;

void solve(){
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> sum[i][j];
    for(int i=1; i<=n; i++) for(int j=2; j<=n; j++) sum[i][j] += sum[i][j-1];

    for(int i=0; i<m; i++){
        ll ret = 0;
        cin >> a >> b >> c >> d;

        for(int j=a; j<=c; j++) ret += sum[j][d] - sum[j][b-1];
        cout << ret << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    solve();
    return 0;
}