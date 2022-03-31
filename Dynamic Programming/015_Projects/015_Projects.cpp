#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

struct info {
    int a;
    int b;
    int p;

    bool operator< ( info info2) {
        return b < info2.b;
    }
};

bool comp( info info1, info info2) {
    return info1.b < info2.a;
}

int main() {

    int i,j;
    int n;

    cin >> n;

    vector<info> keep;
    for( i=1; i<=n; i++) {
        int a,b,p;
        cin >> a >> b >> p;
        keep.push_back( { a, b, p});
    }
    keep.push_back( { 0, 0, 0});
    sort( begin(keep), end(keep));

    map< int, LLI> dp[2];
    dp[0][0] = 0;
    dp[1][0] = 0;

    LLI ans = 0;
    for( i=1; i<=n; i++) {
        info now = keep[i];
        int prev1 = prev( lower_bound( begin(keep), end(keep), now, comp) )->b;
        int prev2 = keep[i-1].b;

        dp[0][now.b] = max( dp[0][prev2], dp[1][prev2]);
        dp[1][now.b] = max( dp[0][prev1], dp[1][prev1]) + now.p;
        ans = max( { ans, dp[0][now.b], dp[1][now.b]});
    }

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
