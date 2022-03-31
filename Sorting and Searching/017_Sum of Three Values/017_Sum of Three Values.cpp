#include<bits/stdc++.h>
#define LLI long long int
#define pii pair< LLI, LLI>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

pii a[5007] = {};

int main() {

    int i,j;
    LLI n,x;

    cin >> n >> x;
    for( i=1; i<=n; i++) {
        int num;
        cin >> num;
        a[i] = { num, i};
    }
    sort( a+1, a+n+1);

    array< int, 3> ans = { 0, 0, 0};
    for( i=1; i<=n; i++) {
        int k = n;
        for( j=i+1; j<k; j++) {
            for( ; j<k && a[i].fst + a[j].fst + a[k].fst > x; k--);
            if( j >= k)
                break;
            if( a[i].fst + a[j].fst + a[k].fst == x ) {
                ans[0] = a[i].sec;
                ans[1] = a[j].sec;
                ans[2] = a[k].sec;
            }
        }
    }

    if( ans[0] == 0)
        cout << "IMPOSSIBLE\n";
    else {
        for( auto it:ans)
            cout << it << " ";
        cout << "\n";
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
