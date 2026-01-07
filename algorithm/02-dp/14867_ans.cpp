#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
queue<pair<int,int>> q;
map<pair<int,int>,int> mp;

void go(int x, int y, int cnt){
    if(mp[{x,y}]) return;
    mp[{x,y}] = cnt+1;
    q.push({x,y});
}

void bfs(int x, int y){
    mp[{0,0}] = 1;
    q.push({0,0});
    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        go(x,0,mp[{x,y}]);
        go(0,y,mp[{x,y}]);
        go(a,y,mp[{x,y}]);
        go(x,b,mp[{x,y}]);
        go(min(x+y,a),max(0,y-(a-x)),mp[{x,y}]);
        go(max(0,x-(b-y)),min(x+y,b),mp[{x,y}]);
    }
}

void solve(){
    cin >> a >> b >> c >> d;
    bfs(0,0);
    cout << (mp[{c,d}] ? mp[{c,d}]-1 : -1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}