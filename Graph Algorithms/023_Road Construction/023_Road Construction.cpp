#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

struct ds {
    int p[100007];
    int s[100007];
    int maxi = 0;
    ds( int n) {
        for( int i=1; i<=n; i++) {
            p[i] = i;
            s[i] = 1;
        }
    }

    int clan( int x) {
        return x == p[x] ? x : ( p[x] = clan( p[x] ));
    }

    void join( int x, int y) {
        x = clan(x);
        y = clan(y);
        if( x == y)
            return;
        s[y] += s[x];
        p[x] = y;
    }

    int size( int x) {
        x = clan(x);
        return s[x];
    }
}ds(100007);

vector<pii> keep;

int main() {

    int i,j;
    int n, m;

    cin >> n >> m;
    for( i=1; i<=m; i++) {
        int a,b;
        cin >> a >> b;
        keep.push_back( { a, b});
    }

    int maxi = 1;
    int num = n;
    for( auto it: keep) {
        if( ds.clan(it.fst) != ds.clan(it.sec)) {
            ds.join( it.fst, it.sec);
            maxi = max( maxi, ds.size(it.fst));
            num--;
        }
        cout << num << " " << maxi << "\n";
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
