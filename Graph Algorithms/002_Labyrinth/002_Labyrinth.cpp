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

pos src, des;
char world[1007][1007] = {};
char dir[1007][1007] = {};
int mask[4][2] = {
    { 1, 0},
    { 0, 1},
    {-1, 0},
    { 0,-1}
};
char mask2[] = "ULDR";

int main() {

    int i,j;
    int n,m;

    cin >> n >> m;
    for( i=1; i<=n; i++) {
        scanf("%s", world[i]+1);
    }

    for( i=1; i<=n; i++) {
        for( j=1; j<=m; j++) {
            if( world[i][j] == 'A')
                src = { i, j};
            if( world[i][j] == 'B')
                des = { i, j};
        }
    }

    queue<pii> que;
    que.push( des);
    while( !que.empty() ) {
        pii now = que.front();
        que.pop();
        de(1) {
            printf("( %d, %d)\n", now.r, now.c);
        }
        if( now == src)
            break;
        for( i=0; i<4; i++) {
            int n_r = now.r + mask[i][0];
            int n_c = now.c + mask[i][1];
            if( world[n_r][n_c] == '.' || world[n_r][n_c] == 'A') {
                world[n_r][n_c] = mask2[i];
                que.push( { n_r, n_c});
            }
        }
    }

    string ans;
    pii now = src;
    while( now != des) {
        char c = world[now.r][now.c];
        ans.push_back(c);
        if( c == 'D')
            now.r++;
        else if( c == 'R')
            now.c++;
        else if( c == 'U')
            now.r--;
        else if( c == 'L')
            now.c--;
        else
            break;
        de(1) printf("( %d, %d)\n", now.r, now.c);
    }

    if( ans == "A")
        cout << "NO\n";
    else {
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
