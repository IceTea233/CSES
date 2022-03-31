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
const int maxn = 1e2 + 7;

double dp[maxn][maxn] = {};

int32_t main() {
    int i,j;
    int n,K;

    cin >> n >> K;
    for (int i=1; i<=K; i++) {
        dp[1][i] = (double) 1 / K;
    }
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=K; j++) {
            for (int k=1; k<j; k++) {
                dp[i][j] += dp[i-1][k] / K;
            }
            dp[i][j] += dp[i-1][j] * j / K;
        }
    }

    // for (int i=1; i<=n; i++) {
    //     for (int j=1; j<=K; j++) {
    //         printf("%.6f ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    double ans = 0;
    for (int i=1; i<=K; i++) {
        ans += i * dp[n][i];
    }
    printf("%.6f\n", ans);

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
