#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

LLI a[6] = { 0, 0, 6, 28, 96, 252};

int main() {

    LLI i,j;
    int n;

    scanf("%d", &n);
    for( i=1; i <= n; i++) {
        LLI ans = 0;
        if( i <= 4)
            ans = a[i];
        else {
            LLI a = 4; // 2
            LLI b = 8; // 3
            LLI c = (i-4) * 4 + 4; // 4
            LLI d = (i-4) * 4; // 6
            LLI e = (i-4) * (i-4); // 8

            de(1) printf(">>> %lld %lld %lld %lld %lld\n", a, b, c, d, e);
            ans = ( ( i * i ) * ( i * i - 1)
                  - a * 2
                  - b * 3
                  - c * 4
                  - d * 6
                  - e * 8 ) / 2;
        }
        printf("%lld\n", ans);
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
