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
bool vis[maxn] = {};
int w[maxn] = {};
int n, k1, k2;

void cal_w(int x, int p = 0) {
    w[x] = 1;
    for (auto &y : G[x]) {
        if (vis[y] || y == p)
            continue;
        cal_w(y, x);
        w[x] += w[y];
    }
}

int centroid(int m, int x, int p = 0) {
    for (auto &y : G[x]) {
        if (vis[y] || y == p)
            continue;
        if (w[y] > m/2)
            return centroid(m, y, x);
    }
    return x;
}

struct BIT {
    int arr[maxn];
    vector<int> keep;
    void reset(int n) {
        while (!keep.empty()) {
            arr[keep.back()] = 0;
            keep.pop_back();
        }
    }
    void add(int x, int d) {
        x ++;
        while (x < maxn) {
            keep.PB(x);
            arr[x] += d;
            x += (x & -x);
        }
    }
    int query(int x) {
        x ++;
        int ret = 0;
        while (x) {
            ret += arr[x];
            x -= (x & -x);
        }
        return ret;
    }
    int sum(int l, int r) {
        return query(r) - query(l-1);
    }
} bit;

int ans = 0;
void dfs_upd(int x, int p=0, int dep=1) {
    if (k2 - dep < 0)
        return;
    bit.add(dep, 1);
    for (auto &y : G[x]) {
        if (vis[y] || y == p)
            continue;
        dfs_upd(y, x, dep+1);
    }
}
void dfs_add(int x, int p=0, int dep=1) {
    if (k2 - dep < 0)
        return;
    ans += bit.sum(max(0LL, k1-dep), k2-dep);
    de(1) printf("dep = %lld, ans += sum(%lld, %lld) -> %lld\n", dep, k1-dep, k2-dep, bit.sum(max(0LL, k1-dep), k2-dep));
    for (auto &y : G[x]) {
        if (vis[y] || y == p)
            continue;
        dfs_add(y, x, dep+1);
    }
}
void cnt(int m, int x) {
    bit.reset(m);
    bit.add(0, 1);
    for (auto &y : G[x]) {
        if (vis[y])
            continue;
        de(1) printf("calculate subtree %lld\n", y);
        dfs_add(y);
        dfs_upd(y);
    }
}
void solve(int x) {
    cal_w(x);
    if (w[x] < k1)
        return;
    int c = centroid(w[x], x);
    vis[c] = true;
    de(1) printf("solve %lld, size = %lld\n", c, w[x]);
    cnt(w[x], c);
    de(1) printf("ans = %lld\n", ans);
    for (auto &y : G[c]) {
        if (vis[y])
            continue;
        solve(y);
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> n >> k1 >> k2;
    for (int i=1; i<=n-1; i++) {
        int a,b;
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
