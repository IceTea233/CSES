#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int x[5007] = {};
LLI dp[5007][5007] = {};

int main() {

    int i,j;
    int n;

    cin >> n;
    LLI tt = 0;
    for( i=1; i<=n; i++) {
        cin >> x[i];
        tt += x[i];
    }

    for( i=1; i<=n; i++) {
        dp[i][i] = x[i];
    }

    for( i=2; i<=n; i++) {
        for( j=1; j+i-1 <= n; j++) {
            if( i % 2 == 0) {
                dp[j][j+i-1] = min( dp[j][j+i-2], dp[j+1][j+i-1]);
            }
            else {
                dp[j][j+i-1] = max( dp[j][j+i-2] + x[j+i-1], dp[j+1][j+i-1] + x[j]);
            }
        }
    }

    LLI ans;
    if( n % 2 == 0) {
        ans = tt - dp[1][n];
    }
    else {
        ans = dp[1][n];
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
