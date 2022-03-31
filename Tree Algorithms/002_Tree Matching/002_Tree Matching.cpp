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
const int maxn = 2e5 + 7;

vector<int> G[maxn];
int dp[maxn][2] = {};

void dfs(int x, int p) {
    dp[x][0] = 0;
    dp[x][1] = 1;
    if (G[x].size() == 1 && G[x][0] == p)
        return;
    bool flag = 0;
    for (auto y : G[x]) {
        if (y == p)
            continue;
        dfs(y, x);
        dp[x][0] += dp[y][1];
        dp[x][1] += min(dp[y][0], dp[y][1]);
    }
}

int32_t main() {
    int i,j;
    int n;

    cin >> n;
    for (int i=1; i<=n-1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].PB(b);
        G[b].PB(a);
    }
    dfs(1, 0);
    int ans = min(dp[1][0], dp[1][1]);
    // for (int i=1; i<=n; i++) {
    //     printf("dp[%lld] = %lld %lld\n", i, dp[i][0], dp[i][1]);
    // }
    printf("%lld\n", ans);

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
