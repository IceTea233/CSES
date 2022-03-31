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
int in[maxn] = {};

int id = 0;
void dfs(int x, int p) {
    in[x] = ++id;
    anc[x][0] = p;
    for (int i=0; anc[x][i]; i++)
        anc[x][i+1] = anc[anc[x][i]][i];
    for (auto y :G[x])
        dfs(y, x);
}

int lca(int a, int b) {
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
    int n,q;

    cin >> n >> q;
    for (int i=2; i<=n; i++) {
        int e;
        scanf("%lld", &e);
        G[e].PB(i);
    }
    dfs(1, 0);
    while(q--) {
        int a,b;
        scanf("%lld %lld", &a, &b);
        int ans = lca(a, b);
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
