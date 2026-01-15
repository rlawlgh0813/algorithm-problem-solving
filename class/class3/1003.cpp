#include <bits/stdc++.h>
using namespace std;
int m,a,b;

int fibonacci(int n){
    if(n==0){
        a++;
        return 0;
    }else if(n==1){
        b++;
        return 1;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void solve(){
    cin >> m;
    while(m--){
        a = b = 0;
        int t; cin >> t;
        fibonacci(t);
        cout << a << " " << b << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}