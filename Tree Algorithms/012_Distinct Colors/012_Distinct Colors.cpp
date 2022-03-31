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

struct info {
    int type;
    int num;
};

int n;
int c[maxn] = {};
vector<int> G[maxn];
int in[maxn*2] = {};
int out[maxn*2] = {};
info info[maxn*2] = {};
map<int, int> last;
int ans[maxn] = {};

int id = 0;
void dfs(int x, int p) {
    in[x] = ++id;
    info[id] = {1, x};
    for (auto y : G[x]) {
        if (y == p)
            continue;
        dfs(y, x);
    }
    out[x] = ++id;
    info[id] = {2, x};
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

    cin >> n;
    for (int i=1; i<=n; i++) {
        scanf("%lld", &c[i]);
    }
    for (int i=1; i<=n-1; i++) {
        int a, b;
        scanf("%lld %lld", &a, &b);
        G[a].PB(b);
        G[b].PB(a);
    }
    dfs(1, 0);

    for (int i=1; i<=n*2; i++) {
        if (info[i].type == 1) {
            int x = info[i].num;
            if (last[c[x]]) {
                add(last[c[x]], -1);
            }
            add(i, 1);
            last[c[x]] = i;
        } else {
            int x = info[i].num;
            ans[x] = sum(in[x], out[x]);
        }
    }

    for (int i=1; i<=n; i++)
        printf("%lld ", ans[i]);
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
