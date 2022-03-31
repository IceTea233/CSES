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

vector<int> Gx[maxn];
int mx[maxn] = {};
int my[maxn] = {};
bool vy[maxn] = {};

int dfs(int x) {
    for (auto y : Gx[x]) {
        if (vy[y])
            continue;
        vy[y] = 1;
        if (!my[y] || dfs(my[y])) {
            mx[x] = y;
            my[y] = x;
            return 1;
        }
    }
    return 0;
}

main() {
    int i,j;
    int n, m, k;

    cin >> n >> m >> k;
    for (int i=1; i<=k; i++) {
        int a, b;
        cin >> a >> b;
        Gx[a].PB(b);
    }

    for (int i=1; i<=n; i++) {
        if (!mx[i]) {
            memset(vy, 0, sizeof(vy));
            dfs(i);
        }
    }

    vector<pii> ans;
    for (int i=1; i<=n; i++) {
        if (mx[i]) {
            ans.PB({i, mx[i]});
        }
    }
    printf("%d\n", ans.size());
    for (auto it: ans) {
        printf("%lld %lld\n", it.F, it.S);
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
