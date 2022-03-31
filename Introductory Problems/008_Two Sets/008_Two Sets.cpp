#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int clan[1000007] = {};

int main() {

    int i,j;
    int n;

    scanf("%d", &n);
    if( n % 4 == 1 || n % 4 == 2) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
        LLI h = (LLI) n * ( n + 1 ) / 2 / 2;
        for( i=n; i>=1; i--) {
            if( h < i) {
                clan[h] = 1;
                break;
            }
            h -= i;
            clan[i] = 1;
        }

        vector<int> s1;
        vector<int> s2;
        for( i=1; i<=n; i++) {
            if( clan[i])
                s1.push_back(i);
            else
                s2.push_back(i);
        }
        printf("%d\n", s1.size());
        for( auto it:s1) {
            printf("%d ", it);
        }
        printf("\n");

        printf("%d\n", s2.size());
        for( auto it:s2) {
            printf("%d ", it);
        }
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
