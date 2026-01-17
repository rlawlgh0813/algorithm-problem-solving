#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<ll,ll> a[100004];
map<ll,ll> s,e;

int check(int len){
    int ret = 0;
    for()
}

void solve(){
    cin >> n;
    for(int i=0; i<n; i++){
        ll p,q; cin >> p >> q;
        a[i] = {p+100000000,q+100000000};
        s[p+100000000]++;
        e[q+100000000]++;
    }

    for(int i=0; i<n; i++){
        
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}