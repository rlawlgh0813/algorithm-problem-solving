#include <bits/stdc++.h>
using namespace std;

void solve(){
    for(int i=3; i>0; i--){
        string s; cin >> s;
        if(s == "Fizz" || s == "Buzz" || s == "FizzBuzz") continue;
        int n = stoi(s) + i;
        if(n % 3 == 0){
            if(n % 5 == 0) cout << "FizzBuzz" << '\n';
            else cout << "Fizz" << '\n';
        }else if(n % 5 == 0){
            cout << "Buzz" << '\n';
        }else{
            cout << n << '\n';
        }
        return;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}