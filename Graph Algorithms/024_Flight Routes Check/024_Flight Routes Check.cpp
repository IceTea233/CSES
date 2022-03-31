#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

vector<int> adj[100007];
int v[100007] = {};
int low[100007] = {};
int p[100007] = {};

int id = 0;
void dfs( int x) {
    v[x] = ++id;
    low[x] = id;
    for( auto y: adj[x]) {
        if( !v[y]) {
            dfs( y);
        }
        low[x] = min( low[x], low[y]);
    }
}

int main() {

    int i,j;
    int n,m;

    cin >> n >> m;
    for( i=1; i<=m; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs( 1);
    pii ans = { 0, 0};
    for( i=2; i<=n; i++) {
        if( !v[i]) {
            ans = { 1, i};
            break;
        }
        else if( low[i] == v[i])
            ans = { i, 1};
    }
    if( ans.fst) {
        cout << "NO\n";
        cout << ans.fst << " " << ans.sec << "\n";
    }
    else
        cout << "YES\n";

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
