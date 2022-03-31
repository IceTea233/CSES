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

struct dinic {
    int n, m;
    int s, t;
    vector<int> G[maxn];
    int cp[maxn][maxn];
    int fl[maxn][maxn];
    int lev[maxn];
    bool vis[maxn];

    dinic() {
        memset(cp, -1, sizeof(cp));
        memset(fl, 0, sizeof(fl));
        for (int i=0; i<maxn; i++)
            G[i].clear();
    }
    void add_edge(int a, int b, int c) {
        if (cp[a][b] == -1) {
            G[a].PB(b);
            cp[a][b] = 0;
        }
        cp[a][b] += c;
        if (cp[b][a] == -1) {
            G[b].PB(a);
            cp[b][a] = 0;
        }
    }

    int bfs() {
        memset(lev, 0, sizeof(lev));
        queue<int> que;
        que.push(s);
        lev[s] = 1;
        while(!que.empty()) {
            int x = que.front();
            que.pop();
            for (auto y: G[x]) {
                if (!lev[y] && cp[x][y] > fl[x][y]) {
                    que.push(y);
                    lev[y] = lev[x] + 1;
                }
            }
        }
        return lev[t];
    }
    int dfs(int x, int mf) {
        if (x == t)
            return mf;
        int f = mf;
        for (auto y : G[x]) {
            if (lev[y] == lev[x] + 1 && cp[x][y] > fl[x][y]) {
                int t = dfs( y, min(f, cp[x][y] - fl[x][y]));
                fl[x][y] += t;
                fl[y][x] -= t;
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
        memset(fl, 0, sizeof(fl));
        int ret = 0;
        while(bfs()) {
            int add = 0;
            while((add = dfs(s, INF)))
                ret += add;
        }
        return ret;
    }

    void dfs2(int x) {
        vis[x] = 1;
        for (auto y: G[x]) {
            if (cp[x][y] > fl[x][y] && !vis[y])
                dfs2(y);
        }
    }

    vector<pii> min_cut(int _s, int _t) {
        memset(vis, 0, sizeof(vis));
        // printf("max flow = %lld\n",max_flow(_s, _t));
        int maxi = max_flow(_s, _t);
        dfs2(s);
        vector<pii> ret;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (cp[i][j] != -1 && vis[i] && !vis[j])
                    ret.PB({i, j});
            }
        }
        return ret;
    }

    void display(int x, int y) {
        printf("%lld / %lld\n", fl[x][y], cp[x][y]);
    }
};

dinic flow;

int32_t main() {
    int n,m;

    cin >> n >> m;
    flow.n = n;
    flow.m = m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        flow.add_edge(a, b, 1);
        flow.add_edge(b, a, 1);
    }
    vector<pii> ans = flow.min_cut(1, n);
    printf("%lu\n", ans.size());
    for (auto it: ans) {
        printf("%lld %lld\n", it.F, it.S);
    }

    // int x, y;
    // while(scanf("%lld %lld", &x, &y)) {
    //     flow.display(x, y);
    // }

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
