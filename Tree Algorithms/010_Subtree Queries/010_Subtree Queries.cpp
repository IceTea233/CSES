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

int n,q;
vector<int> G[maxn];
int v[maxn] = {};
int in[maxn] = {};
int out[maxn] = {};
int anc[maxn][30] = {};

int id = 0;
void dfs(int x, int p) {
    in[x] = ++id;
    anc[x][0] = p;
    for (int i=0; anc[x][i]; i++)
        anc[x][i+1] = anc[anc[x][i]][i];
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

int bit[maxn*2] = {};
void add(int x, int d) {
    while(x <= n*2) {
        bit[x] += d;
        x += x & (-x);
    }
}

int query(int x) {
    int ret = 0;
    while(x) {
        ret += bit[x];
        x -= x & (-x);
    }
    return ret;
}

int sum(int l, int r) {
    return query(r) - query(l-1);
}

int32_t main() {
    int i,j;

    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        scanf("%lld", &v[i]);
    }
    for (int i=1; i<=n-1; i++) {
        int a,b;
        scanf("%lld %lld", &a, &b);
        G[a].PB(b);
        G[b].PB(a);
    }
    dfs(1, 0);
    for (int i=1; i<=n; i++) {
        add(in[i], v[i]);
    }

    while(q--) {
        int type;
        scanf("%lld", &type);
        if (type == 1) {
            int s, x;
            scanf("%lld %lld", &s, &x);
            int d = x - v[s];
            add(in[s], d);
            v[s] = x;
        } else {
            int s;
            scanf("%lld", &s);
            int ans = sum(in[s], out[s]);
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
