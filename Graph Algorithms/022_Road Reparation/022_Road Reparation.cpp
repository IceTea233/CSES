#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

struct edge {
    int p1;
    int p2;
    int val;

    bool operator< ( edge b) {
        return val < b.val;
    }
};

struct ds {
    int p[100007];

    ds( int n) {
        for( int i=1; i<=n; i++) {
            p[i] = i;
        }
    }
    int clan( int x) {
        return x == p[x] ? x : ( p[x] = clan(p[x]));
    }
    void join( int x, int y) {
        x = clan(x);
        y = clan(y);
        if( x == y)
            return;
        p[x] = y;
    }

}ds(100007);

vector<edge> keep;

int main() {

    int i,j;
    int n,m;

    cin >> n >> m;
    for( i=1; i<=m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        keep.push_back( { a, b, c});
    }
    sort( begin(keep), end(keep));
    LLI ans = 0;
    for( auto it: keep) {
        if( ds.clan(it.p1) == ds.clan(it.p2))
            continue;
        ans += it.val;
        ds.join( it.p1, it.p2);
    }

    bool flag = 0;
    for( i=1; i<=n; i++) {
        if( ds.clan(i) != ds.clan(1))
            flag = 1;
    }

    if( flag)
        cout << "IMPOSSIBLE\n";
    else
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
