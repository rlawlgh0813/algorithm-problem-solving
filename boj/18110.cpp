#include <bits/stdc++.h>
using namespace std;
int n;
double sum;
vector<int> v;

void solve(){
    cin >> n;

    int amt = round(n*0.15);
    for(int i=0; i<n; i++){
        int t; cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for(int i=amt; i<(n-amt); i++) sum += v[i];

    if(n == 0) cout << 0;
    else cout << round(sum / (n - amt*2));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}