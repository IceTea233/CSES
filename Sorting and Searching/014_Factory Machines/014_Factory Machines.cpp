#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int k[200007] = {};
LLI n,t;

bool check( LLI m) {
    LLI tt = 0;
    for( int i=1; i<=n; i++) {
        tt += m / k[i];
        if( tt >= t)
            return 1;
    }
    return 0;
}

LLI BS( LLI L, LLI R) {
    if( L == R)
        return L;
    LLI M = ( L + R ) / 2;
    if( check(M)) {
        return BS( L, M);
    }
    else {
        return BS( M+1, R);
    }
}

int main() {

    int i,j;

    cin >> n >> t;
    for( i=1; i<=n; i++) {
        cin >> k[i];
    }
    LLI ans = BS( 1, (LLI)1e18);

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
