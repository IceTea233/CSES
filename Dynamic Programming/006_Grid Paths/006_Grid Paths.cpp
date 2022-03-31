#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define MOD 1000000007
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int n;
char world[1007][1007] = {};
LLI dp[1007][1007] = {};

int main() {

    int i,j;
    int n;

    cin >> n;
    for( i=1; i<=n; i++) {
        scanf("%s", world[i]+1);
    }

    if( world[1][1] == '.')
        dp[1][1] = 1;
    for( i=1; i<=n; i++) {
        for( j=1; j<=n; j++) {
            if( world[i][j] == '*')
                continue;
            dp[i][j] += dp[i][j-1] + dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][n] << "\n";

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
