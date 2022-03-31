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
const int maxn = 1e5 + 7;

vector<int> G[maxn] = {};
set<int> G2[maxn] = {};
int k[maxn] = {};
int val[maxn] = {};
int maxi[maxn] = {};

int tag[maxn] = {};
int low[maxn] = {};
int scc[maxn] = {};
int instk[maxn] = {};
vector<int> stk = {};
vector<int> keep;
int id = 0;
void tarjan(int x) {
    stk.PB(x);
    instk[x] = 1;
    low[x] = tag[x] = ++id;
    for (auto y: G[x]) {
        if (!tag[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (instk[y]) {
            low[x] = min(low[x], tag[y]);
        }
    }

    if (low[x] == tag[x]) {
        int now;
        do {
            now = stk.back();
            stk.PP();
            instk[now] = 0;
            scc[now] = x;
            val[x] += k[now];
        } while (now != x);
        keep.push_back(x);
    }
}

main() {
    int i,j;
    int n,m;

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> k[i];
    }
    for (int i=1; i<=m; i++) {
        int a,b;
        cin >> a >> b;
        G[a].PB(b);
    }
    for (int i=1; i<=n; i++) {
        if (!tag[i])
            tarjan(i);
    }
    reverse(all(keep));
    for (int i=1; i<=n; i++) {
        for (auto y: G[i]) {
            if (scc[y] != scc[i])
                G2[scc[i]].insert(scc[y]);
        }
    }

    int ans = 0;
    for (auto it: keep)
        maxi[it] = val[it];
    for (auto it: keep) {
        ans = max(ans, maxi[it]);
        for (auto y: G2[it]) {
            // printf("%lld -> %lld\n", it, y);
            maxi[y] = max( maxi[y], maxi[it] + val[y]);
        }
    }
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
