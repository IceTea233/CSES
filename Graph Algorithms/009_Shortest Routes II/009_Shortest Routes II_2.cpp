#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 1e18
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

struct edge {
    int des;
    int val;
};

vector<edge> adj[507];
LLI dp[507][507] = {};

int main() {

    int i,j;
    int n,m,q;

    cin >> n >> m >> q;
    for( i=1; i<=m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back( { b, c});
        adj[b].push_back( { a, c});
    }

    for( i=1; i<=n; i++) {
        for( j=1; j<=n; j++) {
            if( i != j)
                dp[i][j] = ULTRA;
        }
    }
    for( i=1; i<=n; i++) {
        for( auto it:adj[i]) {
            dp[i][it.des] = min( dp[i][it.des], (LLI) it.val);
        }
    }

    for( i=1; i<=n; i++) {
        for( j=1; j<=n; j++) {
            for( int k=1; k<=n; k++) {
                if( dp[j][i] + dp[i][k] < dp[j][k])
                    dp[j][k] = dp[j][i] + dp[i][k];
            }
        }
    }

    while(q--) {
        int a,b;
        cin >> a >> b;
        if( dp[a][b] == ULTRA)
            cout << "-1\n";
        else
            cout << dp[a][b] << "\n";
    }

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
