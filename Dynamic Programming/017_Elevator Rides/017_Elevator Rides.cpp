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
const int maxn = 2e6 + 7;

int w[maxn] = {};
pii dp[maxn] = {};

int32_t main() {
    int i,j;
    int n,x;

    cin >> n >> x;
    for (int i=0; i<n; i++)
        cin >> w[i];

    for (int i=1; i<(1<<n); i++) {
        dp[i] = {INF, INF};
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) {
                pii pre = dp[i^(1<<j)];
                pii now = pre.S + w[j] > x ? (pii){pre.F + 1, w[j]} : (pii){pre.F, pre.S + w[j]};
                dp[i] = min(dp[i], now);
                // printf("(%lld, %lld)\n", dp[i].F, dp[i].S);
            }
        }
    }
    // printf("(%lld, %lld)\n", dp[(1<<n)-1].F, dp[(1<<n)-1].S);
    int ans = dp[(1<<n)-1].F + (dp[(1<<n)-1].S > 0);
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
