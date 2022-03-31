#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

int dp[200007][2] = {};

bool comp( pii a, pii b) {
    return a.sec < b.sec;
}

bool comp2( pii a, pii b) {
    return a.sec <= b.fst;
}

int main() {

    int i,j;
    int n;

    scanf("%d", &n);
    vector<pii> keep;
    for( i=1; i<=n; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        keep.push_back( { a, b});
    }
    keep.push_back( { 0, 0});
    sort( begin(keep), end(keep), comp);
    de(1) {
        for( auto it:keep) {
            printf("( %d, %d)\n", it.fst, it.sec);
        }
    }

    int ans = 0;
    for( i=1; i<=n; i++) {
        auto it = lower_bound( begin(keep), end(keep), keep[i], comp2)-1;
        int idx = it - begin(keep);
        // if( it == keep.end() ) {
        //     printf("null\n");
        //     continue;
        // }
        dp[i][0] = max( dp[i-1][0], dp[i-1][1]);
        dp[i][1] = max( dp[idx][0], dp[idx][1]) + 1;
        ans = max( { ans, dp[i][0], dp[i][1]});
        de(1) printf(">>> ( %d, %d)\n", it->fst, it->sec);
    }

    printf("%d\n", ans);

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
