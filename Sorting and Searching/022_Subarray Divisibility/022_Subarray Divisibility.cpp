#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int a[200007] = {};
LLI pre[200007] = {};

int main() {

    int i,j;
    int n;

    cin >> n;
    for( i=1; i<=n; i++) {
        cin >> a[i];
    }

    map< LLI, int> mp;
    for( i=1; i<=n; i++) {
        pre[i] = ( ( pre[i-1] + a[i] ) % n + n ) % n;
        mp[ pre[i] ] ++;
    }


    LLI ans = 0;
    LLI fix = 0;
    for( i=1; i<=n; i++) {
        ans += mp[ fix ];
        fix = ( ( fix + a[i] ) % n + n ) % n;
        mp[ pre[i] ]--;
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
