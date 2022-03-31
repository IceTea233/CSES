#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

int world[1007][1007] = {};
int mask[4][2] = {
    { 1, 0},
    { 0, 1},
    {-1, 0},
    { 0,-1}
};

void DFS( int r, int c) {
    world[r][c] = 1;
    for( int i=0; i<4; i++) {
        int n_r = r + mask[i][0];
        int n_c = c + mask[i][1];

        if( !world[n_r][n_c]) {
            DFS( n_r, n_c);
        }
    }
}

int main() {

    int i,j;
    int n,m;

    cin >> n >> m;
    for( i=1; i<=n; i++) {
        char s[1007];
        scanf("%s", s+1);
        for( j=1; j<=m; j++) {
            if( s[j] == '#')
                world[i][j] = 1;
        }
    }
    for( i=0; i<=n+1; i++) {
        world[i][0] = 1;
        world[i][m+1] = 1;
    }
    for( i=0; i<=m+1; i++) {
        world[0][i] = 1;
        world[n+1][i] = 1;
    }

    int ans = 0;
    for( i=1; i<=n; i++) {
        for( j=1; j<=m; j++) {
            if( !world[i][j]) {
                DFS( i, j);
                ans++;
            }
        }
    }

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
