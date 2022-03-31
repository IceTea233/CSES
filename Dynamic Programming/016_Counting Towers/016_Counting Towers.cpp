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
const int MOD = 1e9 + 7;

int dp[maxn][2] = {};

void prepare(int n) {
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i=2; i<=n; i++) {
        dp[i][0] = ( dp[i-1][0] * 2 % MOD + dp[i-1][1] ) % MOD;
        dp[i][1] = ( dp[i-1][0] + dp[i-1][1] * 4 % MOD ) % MOD;
    }
}

int32_t main() {
    int i,j;
    int t;

    prepare(1000000);

    cin >> t;
    while(t--) {
        int n;
        scanf("%lld", &n);
        int ans = ( dp[n][0] + dp[n][1] ) % MOD;
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
