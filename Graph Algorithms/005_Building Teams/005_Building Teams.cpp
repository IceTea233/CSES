#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

vector<int> adj[100007] = {};
int color[100007] = {};

bool ans = 1;
void DFS( int x) {
    for( auto y:adj[x]) {
        if( color[y]) {
            if( color[x] == color[y])
                ans = 0;
        }
        else {
            if( color[x] == 1)
                color[y] = 2;
            else if( color[x] == 2)
                color[y] = 1;
            DFS(y);
        }
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
        adj[b].push_back(a);
    }

    for( i=1; i<=n; i++) {
        if( !color[i]) {
            color[i] = 1;
            DFS(i);
        }
    }
    if( ans) {
        for( i=1; i<=n; i++) {
            cout << color[i] << " ";
        }
        cout << "\n";
    }
    else {
        cout << "IMPOSSIBLE\n";
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
