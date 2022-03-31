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
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 2e5 + 7;

vector<int> G[maxn];
int dp[maxn][2] = {};
int up[maxn] = {};
int ans[maxn] = {};

void dfs(int x, int p) {
    // printf("dfs(%lld, %lld)\n", x, p);
    dp[x][0] = 0;
    dp[x][1] = 0;
    for (auto y: G[x]) {
        if (y == p)
            continue;
        dfs(y, x);
        if (dp[y][0] + 1 >= dp[x][0]) {
            dp[x][1] = dp[x][0];
            dp[x][0] = dp[y][0] + 1;
        } else if (dp[y][0] + 1 >= dp[x][1]) {
            dp[x][1] = dp[y][0] + 1;
        }
    }
}

void dfs2(int x, int p) {
    for (auto y: G[x]) {
        if (y == p)
            continue;
        if (dp[y][0] + 1 == dp[x][0])
            up[y] = max( up[x], dp[x][1]) + 1;
        else
            up[y] = max( up[x], dp[x][0]) + 1;
        dfs2(y, x);
    }
    ans[x] = max(dp[x][0], up[x]);
}

int32_t main() {
    int i,j;
    int n;

    cin >> n;
    for (int i=1; i<=n-1; i++) {
        int a,b;
        scanf("%lld %lld", &a, &b);
        G[a].PB(b);
        G[b].PB(a);
    }
    dfs(1, 0);
    dfs2(1, 0);
    de(1) {
        for (int i=1; i<=n; i++) {
            printf("%lld >>> %lld %lld %lld\n", i, dp[i][0], dp[i][1], up[i]);
        }
    }
    for (int i=1; i<=n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");

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
