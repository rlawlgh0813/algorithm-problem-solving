#include <bits/stdc++.h>
using namespace std;
int n;
long long a[104];

void solve(){
    a[0] = a[1] = a[2] = 1;
    for(int i=3; i<101; i++) a[i] = a[i-2] + a[i-3];

    cin >> n;
    while(n--){
        int t; cin >> t;
        cout << a[t-1] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}