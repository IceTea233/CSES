#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define pos pii
#define r fst
#define c sec
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

char world[1007][1007] = {};
int v[1007][1007] = {};
int mask[4][2] = {
    { 1, 0},
    { 0, 1},
    {-1, 0},
    { 0,-1}
};

char mask2[] = "DRUL";

int main() {

    int i,j;
    int n,m;

    cin >> n >> m;
    for( i=1; i<=n; i++) {
        scanf("%s", world[i]+1);
    }
    for( i=0; i<=n+1; i++) {
        v[i][0] = 3;
        v[i][m+1] = 3;
    }
    for( i=0; i<=m+1; i++) {
        v[0][i] = 3;
        v[n+1][i] = 3;
    }

    pos src;
    queue<pos> que;
    for( i=1; i<=n; i++) {
        for( j=1; j<=m; j++) {
            if( world[i][j] == 'A') {
                src = { i, j};
            }
            else if( world[i][j] == 'M') {
                 que.push( { i, j});
                 v[i][j] = 2;
            }
            else if( world[i][j] == '#') {
                v[i][j] = 3;
            }
        }
    }
    que.push( src);
    v[src.r][src.c] = 1;
    while( !que.empty()) {
        pos x = que.front();
        que.pop();
        for( i=0; i<4; i++) {
            int n_r = x.r + mask[i][0];
            int n_c = x.c + mask[i][1];
            if( !v[n_r][n_c]) {
                if( v[x.r][x.c] == 1) {
                    world[n_r][n_c] = mask2[i];
                }
                v[n_r][n_c] = v[x.r][x.c];
                que.push( { n_r, n_c});
            }
        }
    }

    de(1) {
        for( i=1; i<=n; i++) {
            for( j=1; j<=m; j++) {
                cout << v[i][j];
            }
            cout << "\n";
        }
        for( i=1; i<=n; i++) {
            for( j=1; j<=m; j++) {
                cout << world[i][j];
            }
            cout << "\n";
        }
    }

    pos now = { 0, 0};
    for( i=1; i<=n; i++) {
        if( v[i][1] == 1)
            now = { i, 1};
        if( v[i][m] == 1)
            now = { i, m};
    }
    for( i=1; i<=m; i++) {
        if( v[1][i] == 1)
            now = { 1, i};
        if( v[n][i] == 1)
            now = { n, i};
    }

    if( now == (pii){ 0, 0})
        cout << "NO\n";
    else {
        string ans;
        while( now != src) {
            char dir = world[now.r][now.c];
            ans.push_back(dir);
            if( dir == 'D')
                now.r--;
            if( dir == 'U')
                now.r++;
            if( dir == 'L')
                now.c++;
            if( dir == 'R')
                now.c--;
        }
        reverse( begin(ans), end(ans));
        cout << "YES\n";
        cout << ans.size() << "\n";
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
