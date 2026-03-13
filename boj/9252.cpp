#include <bits/stdc++.h>
using namespace std;
int dp[1004][1004];
string a,b;
vector<char> v;

void solve(){
    cin >> a >> b;

    for(int i=1; i<=a.length(); i++){
        for(int j=1; j<=b.length(); j++){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i = a.length(), j = b.length();
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            v.push_back(a[--i]);
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    cout << v.size() << '\n';
    reverse(v.begin(), v.end());
    if(v.size()) for(auto x : v) cout << x;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}