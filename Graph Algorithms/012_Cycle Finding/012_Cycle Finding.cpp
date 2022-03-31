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
    int des;
    int val;
    bool operator< ( edge b) {
        return val < b.val;
    }
};

bool v[2507] = {};
vector<edge> adj[2507];
LLI d[2507] = {};
int n,m;

vector<int> keep;
bool ans = 0;

void SPFA( int x) {
    keep.push_back( x);
    if( v[x]) {
        ans = 1;
        return;
    }
    v[x] = 1;

    de(1) {
        cout << ">>> ";
        for( auto it: keep) {
            cout << it << " ";
        }
        cout << "\n";
    }
    for( auto y: adj[x]) {
        if( d[x] + y.val < d[y.des]) {
            d[y.des] = d[x] + y.val;
            SPFA( y.des);
        }
        if(ans)
            return;
    }

    v[x] = 0;
    keep.pop_back();
}

int main() {

    int i,j;

    cin >> n >> m;
    for( i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back( { b, c});
    }
    for( i=1; i<=n; i++) {
        adj[0].push_back( { i, 0});
        d[i] = ULTRA;
    }

    for( i=1; i<=n; i++) {
        for( j=0; j<=n; j++) {
            for( auto it:adj[j]) {
                if( d[j] + it.val < d[it.des])
                    d[it.des] = d[j] + it.val;
            }
        }
    }

    for( i=1; i<=n; i++) {
        for( auto it: adj[i]) {
            if( d[i] + it.val < d[it.des]) {
                 ans = 1;
            }
        }
    }
    if( ans) {
        cout << "YES\n";
        for( i=1; i<=n; i++)
            d[i] = ULTRA;
        ans = 0;
        SPFA(0);
        reverse( begin(keep), end(keep));
        while( keep.back() != keep.front())
            keep.pop_back();
        reverse( begin(keep), end(keep));
        for( auto it: keep) {
            cout << it << " ";
        }
        cout << "\n";
    }
    else
        cout << "NO\n";

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
