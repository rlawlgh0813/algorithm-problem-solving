#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t,p;
ll T[7];
ll ret1;
pair<ll,ll> ret2;

void solve(){
    cin >> n;
    for(int i=0; i<6; i++) cin >> T[i];
    cin >> t >> p;

    for(int i=0; i<6; i++){
        ret1 += T[i] / t;
        if(T[i] % t) ret1++;
    }
    ret2.first = n / p;
    ret2.second = n % p;

    cout << ret1 << '\n';
    cout << ret2.first << " " << ret2.second << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}