#include<bits/stdc++.h>
#define int long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int p[200007] = {};
int n,x;

bool OK( int m) {
    if( m * 2 > n)
        return 0;
    for( int i=0; i<m; i++) {
        if( p[ 1 + i ] + p[ m*2 - i ] > x)
            return 0;
    }
    return 1;
}

int BS( int l, int r) {
    if( l == r)
        return l;

    int m = ( l + r + 1) / 2;
    if( OK(m))
        return BS( m, r);
    else
        return BS( l, m-1);
}

main() {

    int i,j;

    scanf("%lld %lld", &n, &x);
    for( i=1; i<=n; i++) {
        scanf("%lld", &p[i]);
    }
    sort( p+1, p+n+1);

    int q= BS( 0, n);
    int ans = q + ( n - 2*q );

    printf("%lld\n", ans);

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
