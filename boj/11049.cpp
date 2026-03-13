#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int n, ret;
vector<pair<int,int>> v;

void solve(){
    cin >> n;
    for(int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }

    for(int i=0; i<n-1; i++){
        int mn = INF, s = -1, e = -1;
        for(int j=0; j<n-1; j++){
            if(!v[j].second) continue;
            for(int k=j+1; k<n; k++){
                if(!v[k].second) continue;
                if(mn > v[j].first * v[j].second * v[k].second){
                    mn = v[j].first * v[j].second * v[k].second;
                    s = j;
                    e = k;
                }
                break;
            }
        }
        ret += mn;
        v[s].second = v[e].second;
        v[e].second = 0;
    }
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}