#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

char s[49] = {};
bool v[50][50] = {};
LLI key[50][50] = {};
LLI head[50][50] = {};
unordered_map< LLI, int> dp;

int ans = 0;
int total = 0;

int mask[4][2] =
{
    { 1, 0},
    { 0, 1},
    {-1, 0},
    { 0,-1}
};

int mask2[8][2] =
{
    {-1,-1}, {-1, 0}, {-1, 1},
    { 0, 1}, { 1, 1}, { 1, 0},
    { 1,-1}, { 0,-1}
};

LLI hashee( LLI k) {
    return ( k * 1000000007 + rand() ) % (1000000000000007);
}

void prepare() {
    LLI k = 1;
    for( int i=1; i<=7; i++) {
        for( int j=1; j<=7; j++) {
            k = hashee(k);
            key[i][j] = k;
            k = hashee(k);
            head[i][j] = k;
        }
    }
}

bool OK( int r, int c) {
    int cnt = 0;
    for( int i=0; i<8; i++) {
        int r1 = r + mask2[i][0];
        int c1 = c + mask2[i][1];
        int r2 = r + mask2[(i+1) % 8][0];
        int c2 = c + mask2[(i+1) % 8][1];

        if( !v[r1][c1] && v[r2][c2])
            cnt++;
    }

    if( cnt > 1)
        return 0;
    return 1;
}

int act( int step, int r, int c, LLI k) {

    total++;
    // if( v[r][c] || !OK( r, c) )
    //     return 0;
    if( v[r][c])
        return 0;

    de(0) {
        system("CLS");
        for( int i=1; i<=7; i++) {
            for( int j=1; j<=7; j++) {
                if( i == r && j == c)
                    printf("*");
                else
                    printf("%d", v[i][j]);
            }
            printf("\n");
        }
        printf("%d\n", ans);
    }
    if( step == 48) {
        ans++;
        de(1) printf("%d\n", ans);
        return 1;
    }

    if( r == 7 && c == 1)
        return 0;

    k ^= key[r][c];
    if( dp.find( k ^ head[r][c]) != dp.end() ) {
        int q = dp[ k ^ head[r][c] ];
        ans += q;
        return q;
    }

    v[r][c] = 1;
    int suc = 0;
    if( s[step] == '?') {
        for( int i=0; i<4; i++) {
            suc += act( step+1, r + mask[i][0], c + mask[i][1], k);
        }
    }
    else if( s[step] == 'D') {
        suc += act( step+1, r + 1, c, k);
    }
    else if( s[step] == 'U') {
        suc += act( step+1, r - 1, c, k);
    }
    else if( s[step] == 'L') {
        suc +=act( step+1, r, c - 1, k);
    }
    else if( s[step] == 'R') {
        suc += act( step+1, r, c + 1, k);
    }
    v[r][c] = 0;

    dp[ k ^ head[r][c] ] = suc;

    k ^= key[r][c];
    return suc;
}

int main() {

    int i,j;

    prepare();
    for( i=0; i<48; i++) {
        scanf("%c", &s[i]);
    }

    for( i=0; i<=8; i++) {
        v[0][i] = 1;
        v[i][0] = 1;
        v[8][i] = 1;
        v[i][8] = 1;
    }

    act( 0, 1, 1, 0);

    printf("%d\n", ans);
    de(1) printf("total run = %d\n", total);


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
