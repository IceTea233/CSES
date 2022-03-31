#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int a[200007] = {};

int main() {

    int i,j;
    int n,x;

    scanf("%d %d", &n, &x);
    for( i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    map<int,int> mp;
    for( i=1; i<=n; i++) {
        mp[ a[i] ] ++;
    }

    pii ans = { 0, 0};
    for( auto it:mp) {
        int d = x - it.fst;
        if( d == it.fst) {
            if( it.sec > 1) {
                ans = { d, d};
            }
        }
        else {
            if( mp.find(d) != mp.end())
                ans = { it.fst, d};
        }
    }

    if( ans.fst == 0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    int p1 = 0, p2 = 0;
    for( i=1; i<=n; i++) {
        if( !p1 && a[i] == ans.fst)
            p1 = i;
        if( a[i] == ans.sec && p1 != i)
            p2 = i;
    }

    printf("%d %d\n", p1, p2);

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
