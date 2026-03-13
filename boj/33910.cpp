#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[500004];
ll ret;

void solve(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    int cur = a[n-1];
    ret += a[n-1];
    for(int i=n-2; i>=0; i--){
        if(cur > a[i]) cur = a[i];
        ret += cur;   
    }
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}