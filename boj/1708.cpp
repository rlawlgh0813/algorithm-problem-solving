#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
int n;
vector<pair<ll,ll>> v;

ll go(pll a, pll b, pll c){
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

bool cmp(pll a, pll b){
    ll ret = go(v[0], a, b);
    if(ret) return ret > 0;
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

void solve(){
    cin >> n;

    int idx = 0;
    for(int i=0; i<n; i++){
        ll a,b; cin >> a >> b;
        v.push_back({a,b});
        if(v[idx].second > b || (v[idx].second == b && v[idx].first > a)) idx = i;
    }
    swap(v[idx],v[0]);
    sort(v.begin()+1, v.end(), cmp);

    vector<pll> vv;
    for(int i=0; i<n; i++){
        while(vv.size() > 1 && go(vv[vv.size() - 2], vv.back(), v[i]) <= 0) vv.pop_back();
        vv.push_back(v[i]);
    }
    cout << vv.size();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}