#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int t[200007] = {};
int ans[200007] = {};
int d[200007] = {};
bool v[200007] = {};

int k;
void dfs( int x, int dep) {
    v[x] = 1;
    d[x] = dep;
    int y = t[x];
    if( v[y]) {
        k = d[y];
        ans[x] = d[x] - d[y] + 1;
        v[x] = 0;
        return;
    }
    else if( ans[y]) {
        ans[x] = ans[y] + 1;
        v[x] = 0;
        k = dep;
        return;
    }
    else {
        dfs( y, dep+1);
        if( dep >= k)
            ans[x] = ans[y];
        else
            ans[x] = ans[y] + 1;
        v[x] = 0;
    }
}

int main() {

    int i,j;
    int n;

    cin >> n;
    for( i=1; i<=n; i++) {
        cin >> t[i];
    }

    for( i=1; i<=n; i++) {
        if( !ans[i]) {
            dfs( i, 1);
        }
    }

    for( i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

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
