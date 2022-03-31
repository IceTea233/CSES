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

LLI dp[250007] = {};

LLI pwr( LLI a, LLI b) {
    LLI ret = 1;
    while(b) {
        if( b&1 )
            ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

int main() {

    int i,j;
    int n;

    cin >> n;

    dp[0] = 1;
    for( i=1; i<=n; i++) {
        for( j=n*n; j>=i; j--) {
            dp[j] += dp[j-i];
            dp[j] %= MOD;
        }
    }

    int sum = n * (n+1) / 2;
    if( sum % 2 == 0)
        cout << dp[ sum/2 ] * pwr( 2, MOD-2) % MOD << "\n";
    else
        cout << "0\n";

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
