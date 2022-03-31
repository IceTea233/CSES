#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int p[200007] = {};

int main() {

    int i,j;
    int n,x;

    cin >> x >> n;
    for( i=1; i<=n; i++) {
        cin >> p[i];
    }

    set<int> st1;
    multiset<int> st2;

    st1.insert( 0 );
    st1.insert( x );
    st2.insert( x );
    for( i=1; i<=n; i++) {
        auto it = st1.upper_bound( p[i] );
        int dis = *it - *prev(it);

        st2.erase( st2.find( dis ) );
        st2.insert( *it - p[i]);
        st2.insert( p[i] - *prev(it));
        st1.insert( p[i] );
        cout << *prev( st2.end() ) << " ";
    }
    cout << "\n";

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
