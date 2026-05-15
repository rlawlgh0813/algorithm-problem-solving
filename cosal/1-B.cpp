#include <bits/stdc++.h>
using namespace std;
int a[30];
string s;

void solve(){
    cin >> s;
    for(int i=0; i<s.size(); i++) a[s[i] - 'a']++;

    for(int i=0; i<26; i++) cout << a[i] << " ";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}