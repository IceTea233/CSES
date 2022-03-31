#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 1e15
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

struct edge {
    int src;
    int des;
    int val;
};

vector<edge> keep;
LLI d[2507] = {};
bool v[2507] = {};

int main() {

    int i,j;
    int n,m;

    cin >> n >> m;
    for( i=1; i<=m; i++) {
        int a,b,x;
        cin >> a >> b >> x;
        keep.push_back( { a, b, x});
    }


    for( i=1; i<=n; i++) {
        d[i] = -ULTRA;
    }
    d[1] = 0;
    v[1] = 1;
    for( i=1; i<=n-1; i++) {
        for( auto it: keep) {
            if( v[it.src]) {
                v[it.des] = 1;
                d[it.des] = max( d[it.des], d[it.src] + it.val);
            }
        }
    }
    LLI ans = d[n];
    for( i=1; i<=n; i++) {
        for( auto it: keep) {
            if( v[it.src] && d[it.src] + it.val > d[it.des])
                d[it.des] = ULTRA;
        }
    }

    if( d[n] != ans)
        cout << "-1\n";
    else
        cout << d[n] << "\n";

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
