#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

vector<int> adj[100007];
int pre[100007] = {};
int s = 0, t = 0;

void DFS( int x, int p) {
    for( auto y: adj[x]) {
        if( y == p)
            continue;
        if( !pre[y]) {
            pre[y] = x;
            DFS( y, x);
        }
        else {
            s = x;
            t = y;
        }
        if( s != 0)
            return;
    }
}

int main() {

    int i,j;
    int n, m;

    cin >> n >> m;
    for( i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for( i=1; i<=n; i++) {
        de(1) cout << "i = " << i << "\n";
        if( !pre[i]) {
            pre[i] = i;
            DFS( i, i);
        }
        if( s != 0)
            break;
    }

    de(1) {
        for( i=1; i<=n; i++) {
            printf("%d <<< %d\n", i, pre[i]);
        }
    }

    if( s == 0)
        cout << "IMPOSSIBLE\n";
    else {
        vector<int> ans;
        int now = s;
        while( now != t) {
            de(1) cout << "now = " << now << "\n";
            de(1) system("PAUSE");
            ans.push_back(now);
            now = pre[now];
        }
        ans.push_back(t);
        ans.push_back(s);
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
