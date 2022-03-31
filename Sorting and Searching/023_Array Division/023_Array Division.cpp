#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 1e18
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int x[200007] = {};
int n,k;

bool check( LLI m) {
    LLI sum = 0;
    int cnt = 1;
    for( int i=1; i <= n; i++) {
        if( x[i] > m)
            return 0;

        sum += x[i];
        if( sum > m) {
            cnt++;
            sum = x[i];
        }
    }

    return cnt <= k;
}

LLI BS( LLI l, LLI r) {
    if( l == r)
        return l;
    LLI m = ( l + r) / 2;
    if( check(m))
        return BS( l, m);
    else
        return BS( m+1, r);
}

int main() {

    int i,j;

    cin >> n >> k;
    for( i=1; i<=n; i++) {
        cin >> x[i];
    }

    LLI ans = BS( 1, ULTRA);

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
