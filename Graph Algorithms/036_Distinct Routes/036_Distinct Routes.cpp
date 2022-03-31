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
const int maxn = 500 + 7;

struct dinic {
    int n;
    int s,t;
    vector<int> G[maxn];
    int cp[maxn][maxn];
    int fl[maxn][maxn];
    int lev[maxn];

    dinic() {
        memset(cp, -1, sizeof(cp));
        memset(fl, 0, sizeof(fl));
        for (int i=0; i<maxn; i++)
            G[i].clear();
    }

    void add_edge(int a, int b, int c) {
        if (cp[a][b] == -1) {
            cp[a][b] = 0;
            G[a].PB(b);
        }
        if (cp[b][a] == -1) {
            cp[b][a] = 0;
            G[b].PB(a);
        }
        cp[a][b] += c;
    }

    int bfs() {
        memset(lev, 0, sizeof(lev));
        queue<int> que;
        lev[s] = 1;
        que.push(s);
        while(!que.empty()) {
            int x = que.front();
            que.pop();
            for (auto y : G[x]) {
                if (!lev[y] && cp[x][y] > fl[x][y]) {
                    lev[y] = lev[x] + 1;
                    que.push(y);
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
            if (lev[y] == lev[x]+1 && cp[x][y] > fl[x][y]) {
                int t = dfs(y, min(f, cp[x][y] - fl[x][y]));
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
            int add;
            while((add = dfs(s, INF))) {
                ret += add;
            }
        }
        return ret;
    }

    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (cp[i][j] > 0)
                    printf("%lld -> %lld ( %lld / %lld )\n", i, j, fl[i][j], cp[i][j]);
            }
        }
    }
}F;

int n,m;
vector<int> G[maxn];
vector<vector<int>> ans;
vector<int> keep;
bool dfs(int x) {
    if (x == n+1) {
        ans.PB(keep);
        ans.back().PP();
        return 1;
    }

    if (!G[x].empty()) {
        int y = G[x].back();
        G[x].PP();
        keep.PB(y);
        bool flag = dfs(y);
        keep.PP();
        return flag;
    }
    return 0;
}

main() {
    int i,j;

    cin >> n >> m;
    F.n = n+1;
    for (int i=1; i<=m; i++) {
        int a,b;
        cin >> a >> b;
        F.add_edge(a, b, 1);
    }
    F.add_edge(n, n+1, INF);
    F.max_flow(1, n+1);
    // printf(">>> %lld\n", F.max_flow(1, n+1));
    // F.display();
    for (int i=1; i<=n+1; i++) {
        for (int j=1; j<=n+1; j++) {
            for (int k=1; k<=F.fl[i][j]; k++)
                G[i].PB(j);
        }
    }
    keep.PB(1);
    while(dfs(1));

    printf("%d\n", ans.size());
    for (auto it: ans) {
        printf("%d\n", it.size());
        for (auto it2: it) {
            printf("%lld ", it2);
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
