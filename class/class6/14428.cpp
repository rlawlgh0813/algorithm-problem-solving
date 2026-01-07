#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
typedef pair<int,int> pii;
int n,m;
int a[100004];
pii t[400020];

pii init(int s, int e, int here){
    if(s == e) return t[here] = make_pair(a[s],s);
    int m = (s + e) / 2;
    pii lhs = init(s,m,here*2);
    pii rhs = init(m+1,e,here*2+1);
    if(lhs.first == rhs.first) return t[here] = make_pair(lhs.first,min(lhs.second,rhs.second));
    else return t[here] = (lhs.first < rhs.first) ? lhs : rhs;
}

void update(int s, int e, int here, int idx, int val){
    if(idx < s || e < idx) return;
    if(s == e){
        t[here] = {val, idx};
        return;
    }

    int m = (s + e) / 2;
    update(s,m,here*2,idx,val);
    update(m+1,e,here*2+1,idx,val);
    if(t[here*2].first == t[here*2+1].first) t[here] = make_pair(t[here*2].first,min(t[here*2].second,t[here*2+1].second));
    else t[here] = (t[here*2].first < t[here*2+1].first) ? t[here*2] : t[here*2+1];
}

pii get(int s, int e, int l, int r, int here){
    if(l > e || r < s) return make_pair(INF,-1);
    if(l <= s && e <= r) return t[here];

    int m = (s + e) / 2;
    pii lhs = get(s,m,l,r,here*2);
    pii rhs = get(m+1,e,l,r,here*2+1);
    if(lhs.first == rhs.first) return (lhs.second < rhs.second) ? lhs : rhs;
    else return (lhs.first < rhs.first) ? lhs : rhs;
}

void solve(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    init(0,n-1,1);

    cin >> m;
    while(m--){
        int mode,p,q;
        cin >> mode >> p >> q;

        if(mode == 1){
            a[p-1] = q;
            update(0,n-1,1,p-1,q);
        }else if(mode == 2){
            pii ret = get(0, n-1, p-1, q-1, 1);
            cout << ret.second+1 << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}