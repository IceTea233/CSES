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

int n, q;
vector<int> G[maxn] = {};
int v[maxn] = {};
int sz[maxn] = {};
int heavy[maxn] = {};
int head[maxn] = {};
int par[maxn] = {};
int anc[maxn][31] = {};
int pos[maxn] = {};
int in[maxn] = {};

int chain[maxn] = {};

int id = 0;
void dfs(int x, int p) {
    in[x] = ++id;
    anc[x][0] = p;
    for (int i=0; anc[x][i]; i++) {
        anc[x][i+1]  = anc[anc[x][i]][i];
    }

    par[x] = p;
    sz[x] = 1;
    for (auto &y : G[x]) {
        if (y == p)
            continue;
        dfs(y, x);
        if (sz[y] > sz[heavy[x]])
            heavy[x] = y;
        sz[x] += sz[y];
    }
}

int LCA(int a, int b) {
    if (a == b)
        return a;
    if (in[a] > in[b])
        swap(a, b);
    for (int i=20; i>=0; i--) {
        if (in[a] < in[anc[b][i]])
            b = anc[b][i];
    }
    return anc[b][0];
}

void build() {
    id = 0;
    for (int i=1; i<=n; i++) {
        if (heavy[par[i]] != i) {
            int x = i;
            while (x) {
                head[x] = i;
                pos[x] = ++id;
                chain[id] = x;
                x = heavy[x];
            }
        }
    }
}

struct SGT {
    int tree[maxn*4];
    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}
    void pull(int i) {
        tree[i] = max(tree[LC(i)], tree[RC(i)]);
    }
    void build(int *arr, int l, int r, int i=1) {
        if (l == r) {
            tree[i] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        build(arr, l, m, LC(i));
        build(arr, m+1, r, RC(i));
        pull(i);
    }
    void upd(int x, int d, int l, int r, int i=1) {
        if (l == r) {
            tree[i] = d;
            return;
        }
        int m = (l + r) / 2;
        if (x <= m)
            upd(x, d, l, m, LC(i));
        if (m+1 <= x)
            upd(x, d, m+1, r, RC(i));
        pull(i);
    }
    int query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        int m = (l + r) / 2;
        int ret = 0;
        if (x1 <= m)
            ret = max(ret, query(x1, x2, l, m, LC(i)));
        if (m+1 <= x2)
            ret = max(ret, query(x1, x2, m+1, r, RC(i)));
        return ret;
    }
} seg;

int chain_query(int u, int d) {
    de(1) printf("chain query(%lld, %lld)\n", u, d);
    int ret = 0;
    while (in[u] < in[head[d]]) {
        de(1) printf("query[%lld, %lld]\n", head[d], d);
        ret = max(ret, seg.query(pos[head[d]], pos[d], 1, n));
        d = par[head[d]];
    }
    de(1) printf("query[%lld, %lld]\n", u, d);
    ret = max(ret, seg.query(pos[u], pos[d], 1, n));
    return ret;
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> n >> q;
    for (int i=1; i<=n; i++)
        scanf("%lld", &v[i]);
    for (int i=1; i<=n-1; i++) {
        int a, b;
        scanf("%lld %lld", &a, &b);
        G[a].PB(b);
        G[b].PB(a);
    }
    dfs(1, 0);
    build();
    de(1) {
        printf("tree chain: ");
        for (int i=1; i<=n; i++) {
            printf("%lld ", chain[i]);
        }
        printf("\n");
    }
    for (int i=1; i<=n; i++) {
        seg.upd(pos[i], v[i], 1, n);
    }
    while (q--) {
        int cmd;
        scanf("%lld", &cmd);
        if (cmd == 1) {
            int s, x;
            scanf("%lld %lld", &s, &x);
            seg.upd(pos[s], x, 1, n);
        } else if (cmd == 2) {
            int a, b;
            scanf("%lld %lld", &a, &b);
            int lca = LCA(a, b);
            de(1) printf("LCA = %lld\n", lca);
            int ans = max(chain_query(lca, a), chain_query(lca, b));
            printf("%lld\n", ans);
        }
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
