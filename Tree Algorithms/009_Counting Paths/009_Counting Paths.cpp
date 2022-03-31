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

struct SGT {
    int tree[maxn*2*4];
    int tag[maxn*2*4];

    SGT() {
        memset(tree, 0, sizeof(tree));
        memset(tag, 0, sizeof(tag));
    }

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}
    void push(int l, int r, int i) {
        int m = (l + r) / 2;
        tree[LC(i)] += tag[i] * (m-l+1);
        tree[RC(i)] += tag[i] * (r-m);
        tag[LC(i)] += tag[i];
        tag[RC(i)] += tag[i];
        tag[i] = 0;
    }
    void pull(int i) {
        tree[i] = tree[LC(i)] + tree[RC(i)];
    }
    void upd(int x1, int x2, int d, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            tree[i] += d * (r-l+1);
            tag[i] += d;
            return;
        }
        int m = (l + r) / 2;
        push(l, r, i);
        if (x1 <= m)
            upd(x1, x2, d, l, m, LC(i));
        if (m+1 <= x2)
            upd(x1, x2, d, m+1, r, RC(i));
        pull(i);
    }

    int query(int x, int l, int r, int i=1) {
        if (l == r) {
            return tree[i];
        }
        int m = (l + r) / 2;
        int ret = 0;
        push(l, r, i);
        if (x <= m)
            return query(x, l, m, LC(i));
        else
            return query(x, m+1, r, RC(i));
    }
}seg;

int n,m;
vector<int> G[maxn];
int in[maxn] = {};
int out[maxn] = {};
int anc[maxn][30] = {};

int id = 0;
void dfs(int x, int p) {
    anc[x][0] = p;
    for (int i=0; anc[x][i]; i++)
        anc[x][i+1] = anc[anc[x][i]][i];
    in[x] = ++id;
    for (auto y : G[x]) {
        if (y == p)
            continue;
        dfs(y, x);
    }
    out[x] = ++id;
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

int32_t main() {
    int i,j;

    cin >> n >> m;
    for (int i=2; i<=n; i++) {
        int a,b;
        scanf("%lld %lld", &a, &b);
        G[a].PB(b);
        G[b].PB(a);
    }
    dfs(1, 0);

    for (int i=1; i<=m; i++) {
        int a, b;
        scanf("%lld %lld", &a, &b);
        if (in[a] > in[b])
            swap(a, b);
        int lca = LCA(a, b);
        seg.upd(in[lca], in[a], 1, 1, n*2);
        seg.upd(in[lca], in[b], 1, 1, n*2);
        seg.upd(in[lca], in[lca], -1, 1, n*2);
    }

    // printf(">>> ");
    // for (int i=1; i<=n*2; i++) {
    //     printf("%lld ", seg.query(i, 1, n*2));
    // }
    // printf("\n");

    for (int i=1; i<=n; i++) {
        int ans = seg.query(in[i], 1, n*2) - seg.query(out[i], 1, n*2);
        printf("%lld ", ans);
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
