#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int h[200007] = {};
int t[200007] = {};

int main() {

    int i,j;
    int n,m;

    scanf("%d %d", &n, &m);
    for( i=1; i<=n; i++) {
        scanf("%d", &h[i]);
    }
    for( i=1; i<=m; i++) {
        scanf("%d", &t[i]);
    }
    multiset< int, greater<int> > st;
    for( i=1; i<=n; i++) {
        st.insert( h[i]);
    }
    for( i=1; i<=m; i++) {
        auto it = st.lower_bound( t[i]);
        if( it == st.end())
            printf("-1\n");
        else {
            printf("%d\n", *it);
            st.erase(it);
        }
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
