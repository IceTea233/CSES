#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

int t[200007][30] = {};
vector<int> p[200007] = {};
int d[200007] = {};
int c[200007] = {};
bool v[200007] = {};

int root( int x) {
    de(1) cout << ">>>" << x << "\n";
    int y = t[x][0];
    if( d[y] || v[y]) {
        return x;
    }
    v[x] = 1;
    int ret = root(y);
    v[x] = 0;
    return ret;
}

void DFS( int x, int dep) {
    de(1) cout << "DFS( " << x << ", " << dep << ")" << "\n";
    d[x] = dep;
    for( auto y: p[x]) {
        if( d[y])
            continue;
        DFS( y, dep+1);
    }
}

void move( int &now, int step) {
    for( int i=0; i<20; i++, step>>=1) {
        if( step&1)
            now = t[now][i];
    }
}

int solve( int a, int b) {
    int now = a;
    int dis;
    if( d[a] >= d[b]) {
        dis = d[a] - d[b];
        move( now, dis);

        if( now == b)
            return d[a] - d[b];
    }
    dis = d[now] - 1;
    move( now, dis);
    dis = ( d[ t[now][0] ] + 1 ) - d[b];
    if( dis <= 0 )
        return -1;
    move( now, dis);
    if( now == b)
        return ( d[a] - 1 ) + dis;
    else
        return -1;
}

int main() {

    int i,j;
    int n,q;

    cin >> n >> q;
    for( i=1; i<=n; i++) {
        cin >> t[i][0];
        p[ t[i][0] ].push_back(i);
    }

    for( i=1; i<=20; i++) {
        for( j=1; j<=n; j++) {
            t[j][i] = t[ t[j][i-1] ][i-1];
        }
    }

    for( i=1; i<=n; i++) {
        if( !d[i]) {
            int r = root(i);
            DFS( r, 1);
        }
    }

    de(1) {
        for( i=1; i<=n; i++) {
            printf("d[%d] = %d\n", i, d[i]);
        }
    }

    while( q--) {
        int a,b;
        cin >> a >> b;
        int ans = solve( a, b);
        cout << ans << "\n";
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
