#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int x,y,dir;
}node;
int n,k,ret;
int a[13][13], dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
vector<int> v[13][13];
vector<node> stat;

void go(int x, int y, int dir, int num){
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] == 2){
        stat[num].dir ^= 1;
        nx = x + dx[stat[num].dir];
        ny = y + dy[stat[num].dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] == 2) return;
    }

    auto pos = find(v[x][y].begin(), v[x][y].end(), num);
    if(a[nx][ny] == 1) reverse(pos,v[x][y].end());
    for(auto iter = pos; iter != v[x][y].end(); iter++){
        v[nx][ny].push_back(*iter);
        stat[*iter].x = nx; stat[*iter].y = ny;
    }
    v[x][y].erase(pos,v[x][y].end());
}

void solve(){
    cin >> n >> k;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> a[i][j];
    for(int i=0; i<k; i++){
        int x,y,dir; cin >> x >> y >> dir; x--; y--; dir--;
        v[x][y].push_back(i);
        stat.push_back({x,y,dir});
    }

    for(ret=1; ret<=1000; ret++){
        int flag = 0;
        for(int i=0; i<stat.size(); i++){
            go(stat[i].x,stat[i].y,stat[i].dir,i);
            for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(v[i][j].size() >= 4) flag = 1;
        }
        if(flag) break;
    }
    cout << ((ret > 1000) ? -1 : ret);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}