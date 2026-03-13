#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
int n;
double ret;
vector<pll> v;

ll go(pll a, pll b, pll c){
    return (ll)(a.first * b.second) + (b.first * c.second) + (a.second * c.first) - (b.first *a.second) - (c.first *b.second) - (a.first * c.second);
}

void solve(){
    cin >> n;
    for(int i=0; i<n; i++){
        ll a,b; cin >> a >> b;
        v.push_back({a,b});
    }

    for(int i=1; i<n-1; i++) ret += go(v[0], v[i], v[i+1]) / (double)2;
    cout << fixed;
    cout.precision(1);
    cout << abs(ret);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}