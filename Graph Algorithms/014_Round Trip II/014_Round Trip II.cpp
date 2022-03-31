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

vector<int> G[maxn];
int color[maxn] = {};
int ans = 0;
vector<int> keep;

void dfs(int x) {
    // printf("dfs %lld\n", x);
    color[x] = 1;
    for (auto &y : G[x]) {
        if (color[y] == 0) {
            dfs(y);
        } else if (color[y] == 1) {
            keep.PB(y);
            ans = 1;
        }

        if (ans)
            break;
    }
    if (ans && ( keep.size() < 2 || keep.front() != keep.back())) {
        keep.PB(x);
    }
    color[x] = 2;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int n,m;

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        scanf("%lld %lld", &a, &b);
        G[a].PB(b);
    }

    for (int i=1; i<=n; i++) {
        if (!color[i] & !ans) {
            dfs(i);
        }
    }

    if (ans) {
        reverse(all(keep));
        printf("%d\n", keep.size());
        for (auto &it : keep)
            printf("%lld ", it);
        printf("\n");
    } else {
        printf("IMPOSSIBLE\n");
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
