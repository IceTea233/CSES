#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

struct DS {
    int p[100007] = {};

    DS() {
        for( int i=1; i<=100000; i++) {
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
        p[y] = x;
    }
}ds;

int main() {

    int i,j;
    int n,m;

    cin >> n >> m;

    for( i=1; i<=m; i++) {
        int a,b;
        cin >> a >> b;
        ds.join( a, b);
    }

    vector<int> final;
    for( i=1; i<=n; i++) {
        final.push_back( ds.clan(i) );
    }
    sort( begin(final), end(final));
    final.resize( unique( begin(final), end(final)) - begin(final));
    de(1) {
        cout << ">>> ";
        for( auto it:final) {
            cout << it << " ";
        }
        cout << "\n";
    }

    vector<pii> ans;
    for( i=1; i<final.size(); i++) {
        ans.push_back( { final[i], final[i-1]});
    }
    cout << ans.size() << "\n";
    for( auto it:ans) {
        cout << it.fst << " " << it.sec << "\n";
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
