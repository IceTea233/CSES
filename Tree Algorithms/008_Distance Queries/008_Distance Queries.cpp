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
int anc[maxn][27] = {};
int dep[maxn] = {};
int rec[maxn] = {};

int id = 0;
void dfs(int x, int p) {
    rec[x] = ++id;
    anc[x][0] = p;
    dep[x] = dep[p] + 1;
    for (int i=0; anc[x][i]; i++)
        anc[x][i+1] = anc[anc[x][i]][i];
    for (auto y : G[x]) {
        if (y == p)
            continue;
        dfs(y, x);
    }
}

int lca(int a, int b) {
    if (a == b)
        return a;
    if (rec[a] > rec[b])
        swap(a, b);
    for (int i=20; i>=0; i--) {
        if (rec[a] < rec[anc[b][i]])
            b = anc[b][i];
    }
    return anc[b][0];
}

int dis(int a, int b) {
    int c = lca(a, b);
    return (dep[a] - dep[c]) + (dep[b] - dep[c]);
}

int32_t main() {
    int i,j;
    int n, q;

    cin >> n >> q;
    for (int i=2; i<=n; i++) {
        int a, b;
        scanf("%lld %lld", &a, &b);
        G[a].PB(b);
        G[b].PB(a);
    }
    dfs(1, 0);

    while(q--) {
        int a, b;
        scanf("%lld %lld", &a, &b);
        int ans = dis(a, b);
        printf("%lld\n", ans);
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
