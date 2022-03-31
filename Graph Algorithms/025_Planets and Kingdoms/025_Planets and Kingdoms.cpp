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
bool v[100007] = {};
int  t[100007] = {};
int low[100007] = {};
int clan[100007] = {};

int id = 0;
int cl = 0;
vector<int> stk;
void dfs( int x) {
    stk.push_back(x);
    t[x] = ++id;
    low[x] = id;

    for( auto y: adj[x]) {
        if( v[y])
            continue;
        if( !t[y]) {
            dfs(y);
        }
        low[x] = min( low[x], low[y]);
    }
    if( t[x] == low[x]) {
        cl++;
        while( stk.back() != x) {
            v[ stk.back() ] = 1;
            clan[ stk.back() ] = cl;
            stk.pop_back();
        }
        v[x] = 1;
        clan[x] = cl;
        stk.pop_back();
    }
}

int main() {

    int i,j;
    int n,m;

    cin >> n >> m;
    for( i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for( i=1; i<=n; i++) {
        if( !v[i]) {
            dfs(i);
        }
    }
    cout << cl << "\n";
    for( i=1; i<=n; i++) {
        cout << clan[i] << " ";
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
