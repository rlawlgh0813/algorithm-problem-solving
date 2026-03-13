#include <bits/stdc++.h>
using namespace std;
int n;
int grade[54];
pair<int,int> a[54];

void solve(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i].first >> a[i].second;

    for(int i=0; i<n; i++){
        int cnt = 1;
        for(int j=0; j<n; j++) if(a[i].first < a[j].first && a[i].second < a[j].second) cnt++;
        cout << cnt << " ";
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}