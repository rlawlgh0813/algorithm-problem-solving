#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<ll,ll> a[100004];
map<ll,ll> s,e;

int check(int len){

}

void solve(){
    cin >> n;
    for(int i=0; i<n; i++){
        ll p,q; cin >> p >> q;
        a[i] = {p+100000000,q+100000000};
        s[p+100000000]++;
        e[q+100000000]++;
    }

    ll l = 0, r = 200000000;
    while(l < r){
        ll m = (l + r) / 2;

    }
    cout << l;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}