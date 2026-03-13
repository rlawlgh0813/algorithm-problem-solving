#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
ll a[1000004];
vector<ll> v(1000004 * 4);

ll init(int s, int e, int node){
    if(s == e) return v[node] = a[s];
    
    int m = (s + e) / 2;
    return v[node] = init(s,m,node*2) + init(m+1,e,node*2+1);
}

ll val(int s, int e, int l, int r, int node){
    if(s > r || e < l) return 0;
    if(l <= s && e <= r) return v[node];

    int m = (s + e) / 2;
    return val(s,m,l,r,node*2) + val(m+1,e,l,r,node*2+1);
}

void modify(int s, int e, int target, int node, ll amt){
    if(s == e){
        v[node] = a[target] = amt;
        return;
    }

    int m = (s + e) / 2;
    v[node] -= a[target];
    v[node] += amt;
    if(target <= m) modify(s,m,target,node*2,amt);
    else modify(m+1,e,target,node*2+1,amt);
}

void solve(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) cin >> a[i];
    init(0,n-1,1);

    for(int i=0; i<(m+k); i++){
        ll mode,p,q; cin >> mode >> p >> q;
        if(mode == 1) modify(0,n-1,p-1,1,q);
        else cout << val(0,n-1,p-1,q-1,1) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}