#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

char s[17];
int table[17][17] = {};

int ans = 0;

void display() {
    for( int i=1; i<=8; i++) {
        for( int j=1; j<=8; i++) {
            printf("%3d", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void draw( int id, int r, int c) {
    for( int i=1; i<=8; i++) {
        table[r][i] += id;
        table[i][c] += id;
    }

    for( int i=1; r-i > 0 && c-i > 0; i++)
        table[r-i][c-i] += id;
    for( int i=1; r-i > 0 && c+i < 9; i++)
        table[r-i][c+i] += id;
    for( int i=1; r+i < 9 && c-i > 0; i++)
        table[r+i][c-i] += id;
    for( int i=1; r+i < 9 && c+i < 9; i++)
        table[r+i][c+i] += id;
    table[r][c] -= id * 5;
}

void place( int r) {

    de(0) {
        for( int i=1; i<=8; i++) {
            for( int j=1; j<=8; j++) {
                printf("%d ", table[i][j]);
            }
        }
    }
    if( r > 8) {
        ans++;
        return;
    }

    for( int c=1; c<=8; c++) {
        if( table[r][c])
            continue;

        draw( 1, r, c);
        place( r+1);
        draw( -1, r, c);
    }
}

int main() {

    int i,j;

    for( i=1; i <= 8; i++) {
        scanf("%s", s+1);
        for( j=1; j<=8; j++) {
            table[i][j] = ( s[j] == '*');
        }
    }

    place(1);
    printf("%d\n", ans);


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
