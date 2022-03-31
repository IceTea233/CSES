#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define MOD 1000000007
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

int a[100007] = {};
LLI dp[100007][107] = {};

int main() {

    int i,j;
    int n,m;

    cin >> n >> m;
    for( i=1; i<=n; i++)
        cin >> a[i];

    if( a[1] == 0) {
        for( i=1; i<=m; i++)
            dp[1][i] = 1;
    }
    else {
        dp[1][ a[1] ] = 1;
    }

    for( i=2; i<=n; i++) {
        if( a[i] == 0) {
            for( j=1; j<=m; j++) {
                dp[i][j] += dp[i-1][j+1] + dp[i-1][j] + dp[i-1][j-1];
                dp[i][j] %= MOD;
            }
        }
        else {
            dp[i][ a[i] ] = dp[i-1][ a[i]+1 ] + dp[i-1][ a[i] ] + dp[i-1][ a[i]-1 ];
            dp[i][ a[i] ] %= MOD;
        }
    }

    LLI ans = 0;
    for( i=1; i<=m; i++) {
        ans += dp[n][i];
        ans %= MOD;
    }

    de(1) {
        for( i=1; i<=n; i++) {
            cout << ">>> ";
            for( j=0; j<=m; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
    }

    cout << ans << "\n";

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
