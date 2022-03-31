#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int k[200007] = {};

int main() {

    int i,j;
    int n;

    scanf("%d", &n);
    for( i=1; i<=n; i++) {
        cin >> k[i];
    }

    map<int,int> mp;
    int ans = 0;
    for( int i=1, j=0; i<=n; i++) {
        mp[ k[i] ]++;
        while ( mp[ k[i] ] > 1) {
            mp[ k[++j] ]--;
        }
        ans = max( ans, i-j);
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
