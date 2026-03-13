#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
int n,m,k;
ll a[1000004];
vector<ll> v(1000004 * 4);

ll build(int s, int e, int node){
    if(s == e) return v[node] = a[s];

    int m = (s + e) / 2;
    return v[node] = (build(s,m,node*2) * build(m+1,e,node*2+1)) % MOD;
}

void update(int s, int e, int target, int val, int node){
    if(s == e && s == target){
        a[target] = v[node] = val;
        return;
    }

    int m = (s + e) / 2;
    if(target <= m) update(s,m,target,val,node*2);
    else update(m+1,e,target,val,node*2+1);
    v[node] = (v[node*2] * v[node*2+1]) % MOD;
}

ll val(int s, int e, int l, int r, int node){
    if(e < l || r < s) return 1;
    if(l <= s && e <= r) return v[node];

    int m = (s + e) / 2;
    return (val(s,m,l,r,node*2) * val(m+1,e,l,r,node*2+1)) % MOD;
} 

void solve(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) cin >> a[i];
    build(0,n-1,1);

    for(int i=0; i<(m+k); i++){
        int type,p,q; cin >> type >> p >> q;
        if(type == 1) update(0,n-1,p-1,q,1);
        else cout << val(0,n-1,p-1,q-1,1) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}