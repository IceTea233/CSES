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

int n, k;
vector<int> G[maxn] = {};
bool vis[maxn] = {};
int cnt[maxn] = {};
int w[maxn] = {};

void build_w(int x, int p=0) {
    w[x] = 1;
    for (auto &y : G[x]) {
        if (vis[y] || y == p)
            continue;
        build_w(y, x);
        w[x] += w[y];
    }
}

int centroid(int x, int p, int M) {
    for (auto &y : G[x]) {
        if (vis[y] || y == p)
            continue;
        if (w[y] > M / 2)
            return centroid(y, x, M);
    }
    return x;
}

int ans = 0;
void dfs1(int x, int p, int dep) {
    cnt[dep] ++;
    for (auto &y : G[x]) {
        if(vis[y] || y == p)
            continue;
        dfs1(y, x, dep+1);
    }
}
void dfs2(int x, int p, int dep) {
    if (k - dep >= 0)
        ans += cnt[k-dep];
    for (auto &y : G[x]) {
        if (vis[y] || y == p)
            continue;
        dfs2(y, x, dep+1);
    }
}

void cal(int x) {
    cnt[0] = 1;
    vis[x] = true;
    for (auto &y : G[x]) {
        if (vis[y])
            continue;
        dfs2(y, x, 1);
        dfs1(y, x, 1);
    }
}

void solve(int x) {
    build_w(x);
    memset(cnt, 0, sizeof(int) * (k + 1));
    int c = centroid(x, 0, w[x]);
    if (w[x] > k) {
        cal(c);
        for (auto &y : G[c]) {
            if (!vis[y])
                solve(y);
        }
    } else {
        vis[c] = true;
    }

}

int32_t main() {
    cin.tie(0);
    int i,j;


    cin >> n >> k;
    for (int i=1; i<=n-1; i++) {
        int a, b;
        scanf("%lld %lld", &a, &b);
        G[a].PB(b);
        G[b].PB(a);
    }

    solve(1);
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
