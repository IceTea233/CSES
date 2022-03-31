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

int n;
vector<int> G[maxn];
int sz[maxn] = {};
int cnt[maxn] = {};
int ans[maxn] = {};

void dfs(int x, int p) {
    sz[x] = 1;
    for (auto y : G[x]) {
        if (y == p)
            continue;
        dfs(y, x);
        sz[x] += sz[y];
        cnt[x] += cnt[y] + sz[y];
    }
}

void dfs2(int x, int p) {
    for (auto y : G[x]) {
        if (y == p)
            continue;
        ans[y] = ans[x] - sz[y] + (n-sz[y]);
        dfs2(y, x);
    }
}

int32_t main() {
    int i,j;

    cin >> n;
    for (int i=1; i<=n-1; i++) {
        int a, b;
        scanf("%lld %lld", &a, &b);
        G[a].PB(b);
        G[b].PB(a);
    }
    dfs(1, 0);
    ans[1] = cnt[1];
    dfs2(1, 0);

    // printf("\n");
    // for (int i=1; i<=n; i++) {
    //     printf("%lld %lld\n", sz[i], cnt[i]);
    // }
    // printf("\n");

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
