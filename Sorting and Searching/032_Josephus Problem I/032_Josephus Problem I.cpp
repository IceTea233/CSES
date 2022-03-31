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

int nxt[maxn] = {};

int32_t main() {
    int i,j;
    int n;

    cin >> n;
    for (int i=1; i<=n; i++) {
        nxt[i] = i%n+1;
    }
    de(1) {
        for (int i=1; i<=n; i++) {
            printf("%lld ", nxt[i]);
        }
        printf("\n");
    }
    vector<int> ans;
    int now = 1;
    while(nxt[now] != now) {
        int tmp = now;
        now = nxt[now];
        ans.PB(now);
        now = nxt[now];
        nxt[tmp] = now;
    }
    ans.PB(now);
    for (auto it: ans) {
        printf("%lld ", it);
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
