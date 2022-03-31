#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

LLI dp[507][507] = {};

int main() {

    int i,j;
    int a,b;

    cin >> a >> b;
    for( i=1; i<=a; i++) {
        for( j=1; j<=b; j++) {
            dp[i][j] = (LLI) ULTRA * ULTRA;
        }
    }
    for( i=1; i<=a; i++)
        dp[i][1] = i-1;
    for( i=1; i<=b; i++)
        dp[1][i] = i-1;
    for( i=1; i <= min( a, b); i++)
        dp[i][i] = 0;

    for( i=2; i<=a; i++) {
        for( j=2; j<=b; j++) {
            for( int k=1; k<i; k++) {
                dp[i][j] = min( dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }
            for( int k=1; k<j; k++) {
                dp[i][j] = min( dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }

    de(1) {
        for( i=1; i<=a; i++) {
            for( j=1; j<=b; j++) {
                printf("%3d", dp[i][j]);
            }
            printf("\n");
        }
    }

    cout << dp[a][b] << "\n";

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
