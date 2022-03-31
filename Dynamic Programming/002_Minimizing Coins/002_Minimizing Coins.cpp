#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int c[107] = {};
int dp[1000007] = {};

int main() {

    int i,j;
    int n,x;

    cin >> n >> x;
    for( i=1; i<=n; i++)
        cin >> c[i];
    for( i=1; i<=x; i++)
        dp[i] = ULTRA;

    for( i=1; i<=x; i++) {
        for( j=1; j<=n; j++) {
            if( i-c[j] >=0)
                dp[i] = min( dp[i], dp[ i - c[j] ] + 1);
        }
    }

    if( dp[x] == ULTRA)
        cout << "-1\n";
    else
        cout << dp[x] << "\n";



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
