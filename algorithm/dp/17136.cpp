#include <bits/stdc++.h>
using namespace std;

int board[10][10];
int paper[6];              // 각 크기별 사용 수
int best_ans = 1e9;

bool canPlace(int x, int y, int sz) {
    if (x + sz > 10 || y + sz > 10) return false;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (board[x + i][y + j] == 0) return false;
        }
    }
    return true;
}

void place(int x, int y, int sz, int val) {
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            board[x + i][y + j] = val;
        }
    }
}

void dfs(int used) {
    if (used >= best_ans) return;  // 현재 최선보다 많으면 중단

    int sx = -1, sy = -1;
    for (int i = 0; i < 10 && sx == -1; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j]) {
                sx = i; sy = j;
                break;
            }
        }
    }

    if (sx == -1) {                // 덮을 곳 없음 = 완료
        best_ans = min(best_ans, used);
        return;
    }

    for (int sz = 5; sz >= 1; sz--) {
        if (paper[sz] >= 5) continue;
        if (!canPlace(sx, sy, sz)) continue;

        place(sx, sy, sz, 0);
        paper[sz]++;
        dfs(used + 1);
        paper[sz]--;
        place(sx, sy, sz, 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) cin >> board[i][j];
    }

    dfs(0);
    cout << (best_ans == 1e9 ? -1 : best_ans);
    return 0;
}
