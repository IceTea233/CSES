#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int n,m;
vector<int> adj[100007] = {};
bool v[100007] = {};
int p[100007] = {};

int main() {

    int i,j;

    cin >> n >> m;

    for( i=1; i<=m; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> que;
    que.push( 1);
    v[1] = 1;
    while( !que.empty()) {
        int x = que.front();
        que.pop();
        for( auto y: adj[x] ) {
            if( v[y])
                continue;
            p[y] = x;
            v[y] = 1;
            que.push(y);
        }
    }

    if( !v[n])
        cout << "IMPOSSIBLE\n";
    else {
        int now = n;
        vector<int> ans;
        while( now != 0) {
            ans.push_back(now);
            now = p[now];
        }
        reverse( begin(ans), end(ans));
        cout << ans.size() << "\n";
        for( auto it:ans) {
            cout << it << " ";
        }
        cout << "\n";
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
