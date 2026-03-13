#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int,int> pii;
int n,m;
int a[100004];
vector<pii> v(4 * 100004);

pii init(int s, int e, int node){
    if(s == e){
        v[node] = a[s];
        return v[node];
    }
    int m = (s + e) / 2;
    pii left = init(s, m, 2*node);
    pii right = init(m+1, e, 2*node+1);
    v[node].first = min(left.first, right.first);
    v[node].second = max(left.second, right.second);
    return v[node];
}

pii init(int s, int e, int node){
    if(s == e){
        v[node].first = v[node].second = a[s];
        return v[node];
    }
    int m = (s + e) / 2;
    pii left = init(s, m, 2*node);
    pii right = init(m+1, e, 2*node+1);
    v[node].first = min(left.first, right.first);
    v[node].second = max(left.second, right.second);
    return v[node];
}

pii val(int s, int e, int l, int r, int node){
    if(r < s || l > e) return make_pair(INF,-INF);
    if(l <= s && e <= r) return v[node];
    int m = (s + e) / 2;
    pii left = val(s,m,l,r,node*2);
    pii right = val(m+1,e,l,r,node*2+1);
    return make_pair(min(left.first, right.first), max(left.second, right.second));
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    init(0,n-1,1);

    while(m--){
        int p,q; cin >> p >> q;
        pii ret = val(0,n-1,p-1,q-1,1);
        cout << ret.first << " " << ret.second << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}