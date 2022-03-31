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
const int maxn = 1e6 + 7;

multiset<pii> G[maxn];
vector<int> stk;
vector<int> ans;
void dfs(int x) {
    while(!G[x].empty()) {
        auto now = *begin(G[x]);
        G[x].erase(now);
        dfs(now.F);
        ans.PB(now.S);
    }
}

main() {
    int i,j;
    int n;

    cin >> n;
    if (n==1) {
        printf("01\n");
        return 0;
    }

    for (int i=0; i<(1<<(n-1)); i++) {
        G[i].insert({  (i&( (1<<(n-2)) - 1))<<1    , 0});
        G[i].insert({ ((i&( (1<<(n-2)) - 1))<<1) + 1, 1});
    }

    // for (int i=0; i<(1<<(n-1)); i++) {
    //     printf("%lld >> ", i);
    //     for (auto it: G[i]) {
    //         printf("%lld ", it.F);
    //     }
    //     printf("\n");
    // }
    dfs(0);
    // printf("OK\n");
    for (int i=0; i<n-1; i++)
        ans.PB(0);
    reverse(begin(ans), end(ans));
    for (auto it: ans)
        printf("%lld", it);
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
