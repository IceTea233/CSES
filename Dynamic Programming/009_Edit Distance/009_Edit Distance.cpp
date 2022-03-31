#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

char s[5007] = {};
char t[5007] = {};
int dp[5007][5007] = {};

int main() {

    int i,j;

    scanf("%s", s+1);
    scanf("%s", t+1);

    int n = strlen(s+1);
    int m = strlen(t+1);
    for( i=1; i<=n; i++)
        dp[i][0] = i;
    for( i=1; i<=m; i++)
        dp[0][i] = i;
    for( i=1; i<=n; i++) {
        for( j=1; j<=m; j++) {
            dp[i][j] = min( dp[i][j-1]+1, dp[i-1][j]+1);
            if( s[i] == t[j]) {
                dp[i][j] = min( dp[i][j], dp[i-1][j-1]);
            }
            else {
                dp[i][j] = min( dp[i][j], dp[i-1][j-1]+1);
            }
        }
    }

    de(1) {
        for( i=1; i<=n; i++) {
            for( j=1; j<=m; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
    }

    cout << dp[n][m] << "\n";

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
