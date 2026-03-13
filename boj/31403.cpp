#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int ret1, ret2;

void solve(){
    cin >> a >> b >> c;

    ret1 = a + b - c;

    int n=0, temp = b;
    while(temp > 0){
        n++;
        temp /= 10;
    }
    for(int i=0; i<n; i++) a *= 10;
    ret2 = a + b - c;

    cout << ret1 << '\n' << ret2 << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}