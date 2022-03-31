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
const int maxn = 27;
const int MOD = 1e9 + 7;

int G[maxn][maxn] = {};
int dp[20][1<<20] = {};

main() {
    int i,j;
    int n,m;

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        G[a-1][b-1]++;
    }

    dp[0][1] = 1;
    for (int i=1; i<(1<<n); i++) {
        for (int j=0; (1<<j) <= i; j++) {
            if ( !(i&(1<<j)) )
                continue;

            for (int k=0; k<n; k++) {
                if (!G[j][k] || (i&(1<<k)))
                    continue;
                dp[k][i|(1<<k)] += dp[j][i] * G[j][k] % MOD;
                dp[k][i|(1<<k)] %= MOD;
            }
        }
    }

    printf("%lld\n", dp[n-1][(1<<n)-1]);

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
