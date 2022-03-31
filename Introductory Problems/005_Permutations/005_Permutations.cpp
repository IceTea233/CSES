#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int ans[1000007] = {};

int main() {

    int i,j;
    int n;

    scanf("%d", &n);
    if( n == 1) {
        printf("1\n");
    }
    else if( n == 2 || n == 3) {
        printf("NO SOLUTION\n");
    }
    else if( n == 4) {
        printf("2 4 1 3\n");
    }
    else {
        for( i=1; i*2-1 <= n; i++) {
            ans[i*2-1] = i;
        }
        for( j=1; j*2 <= n; i++, j++) {
            ans[j*2] = i;
        }
        for( i=1; i<=n; i++)
            printf("%d ", ans[i]);
        printf("\n");
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
