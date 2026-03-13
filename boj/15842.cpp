#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
int n;
ll mn,mx;
ll a[300004], pow2[300004];

void solve(){
    cin >> n;

    pow2[0] = 1;
    for(int i=1; i<n; i++) pow2[i] = (pow2[i-1] * 2) % MOD;

    for(int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);

    for(int i=0; i<n; i++){
        mx = (mx + a[i]*pow2[i]) % MOD;
        mn = (mn + a[i]*pow2[n-i-1]) % MOD;
    }
    cout << ((mx - mn) % MOD + MOD) % MOD;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}