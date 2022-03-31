#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define PP pop_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

int mask[8][4] = {
    { -2,  1},
    { -1,  2},
    {  1,  2},
    {  2,  1},
    {  2, -1},
    {  1, -2},
    { -1, -2},
    { -2, -1}
};

int v[10][10] = {};

bool ok(int x, int y) {
    return (1 <= x && x <= 8 && 1 <= y && y <= 8);
}

void display() {
    system("cls");
    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            printf("%3lld ", v[i][j]);
        }
        printf("\n");
    }
}

int cal(int x, int y) {
    int ret = 0;
    for (int i=0; i<8; i++) {
        int n_x = x + mask[i][0];
        int n_y = y + mask[i][1];
        if (ok(n_x, n_y) && !v[n_x][n_y])
            ret++;
    }
    return ret;
}

bool flag = 0;
void dfs(int step, int x, int y) {
    // display();
    // system("PAUSE");
    if (step > 64) {
        flag = 1;
        return;
    }
    // vector<pair<int, pii>> yee;
    // for (int i=0; i<8; i++) {
    //     int n_x = x + mask[i][0];
    //     int n_y = y + mask[i][1];
    //     if (ok(n_x, n_y) && !v[n_x][n_y])
    //         yee.PB({cal(n_x, n_y), {n_x, n_y}});
    // }
    vector<pii> yee;
    for (int i=0; i<8; i++) {
        int n_x = x + mask[i][0];
        int n_y = y + mask[i][1];
        if (ok(n_x, n_y) && !v[n_x][n_y])
            yee.PB({cal(n_x, n_y), i});
    }
    sort(all(yee));
    for (auto it: yee) {
        // int n_x = it.S.F;
        // int n_y = it.S.S;
        int n_x = x + mask[it.S][0];
        int n_y = y + mask[it.S][1];

        v[n_x][n_y] = step;
        dfs(step+1, n_x, n_y);
        if (flag)
            return;
        v[n_x][n_y] = 0;
    }
}

main() {
    int i,j;
    int x,y;

    cin >> x >> y;
    v[x][y] = 1;
    dfs(2, x, y);
    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            printf("%lld ", v[j][i]);
        }
        printf("\n");
    }

    return 0;
}

//
//          ___ ___  __________  __________
//         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
//        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
//       ////   \ \  \ \  \      \ \\\\\\\\\\\
//      ////__   \ \  \ \  \      \ \\\\_____/
//     ///////\   \ \  \ \  \______\ \\\\_______   ________
//    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
//   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
//                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
// ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
//   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
//                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
//                               \/__/    \/________/\/__/   \/__/
//
