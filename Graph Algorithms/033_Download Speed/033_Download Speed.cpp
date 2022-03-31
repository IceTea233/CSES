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
const int maxn = 5e2 + 7;
const int maxm = 1e3 + 7;

struct dinic {
    int n, m;
    int s, t;
    vector<int> G[maxn];
    int cap[maxn][maxn];
    int flow[maxn][maxn];
    int lev[maxn];
    bool v[maxn];

    dinic(int _n, int _m) {
        n = _n;
        m = _m;
        memset(cap, -1, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        for (int i=0; i<=n; i++) {
            G[i].clear();
        }
    }

    void add_edge(int u, int v, int c) {
        if (cap[u][v] == -1) {
            G[u].PB(v);
            cap[u][v] = 0;
        }
        if (cap[v][u] == -1) {
            G[v].PB(u);
            cap[v][u] = 0;
        }
        cap[u][v] += c;
    }

    int bfs() {
        memset(lev, 0, sizeof(lev));
        queue<int> que;
        lev[s] = 1;
        que.push(s);
        while(!que.empty()) {
            int x = que.front();
            que.pop();
            for (auto y: G[x]) {
                if (!lev[y] && cap[x][y] > flow[x][y]) {
                    lev[y] = lev[x] + 1;
                    que.push(y);
                }
            }
        }
        return lev[t];
    }

    int dfs(int x, int mf) {
        int f = mf;
        if (x == t)
            return mf;
        for (auto y: G[x]) {
            if (lev[y] == lev[x] + 1 && cap[x][y] > flow[x][y]) {
                int t = dfs(y, min(f, cap[x][y] - flow[x][y]));
                flow[x][y] += t;
                flow[y][x] -= t;
                f -= t;
            }
            if (f == 0)
                break;
        }
        return mf - f;
    }

    int max_flow(int _s, int _t) {
        s = _s;
        t = _t;
        int ret = 0;

        while(bfs()) {
            int add;
            while(add = dfs(s, INF)) {
                ret += add;
            }
        }
        return ret;
    }
};

dinic F(maxn, maxm);

main() {
    int i,j;
    int n,m;

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        F.add_edge(a, b, c);
    }
    int ans = F.max_flow(1, n);
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
