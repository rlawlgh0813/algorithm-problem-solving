#include <bits/stdc++.h>
using namespace std;
int n,l,r,ret;
int a[200004],num[10];

int check(){
    int cnt=0;
    for(int i=1; i<10; i++) if(num[i]) cnt++;
    return cnt;
}

void solve(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    while(r < n){
        num[a[r]]++;
        while(check() > 2){
            num[a[l]]--;
            l++;
        }
        ret = max(ret, r-l+1);
        r++;
    }
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}