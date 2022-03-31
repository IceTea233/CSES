#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

LLI a[1007] = {};

int main() {

    int i,j;
    int n,x;

    cin >> n >> x;
    for( i=1; i<=n; i++) {
        cin >> a[i];
    }

    multiset<LLI> st;
    vector<LLI> cht[1007];
    for( i=1; i<=n; i++) {
        for( j=i+1; j<=n; j++) {
            cht[i].push_back( a[i] + a[j]);
            st.insert( a[i] + a[j]);
        }
    }

    array< int, 4> ans = {};
    for( i=1; i<=n; i++) {
        for( auto it: cht[i]) {
            auto del = st.find( it);
            st.erase( del);
        }
        for( j=1; j<i; j++) {
            int sum1 = a[i] + a[j];
            if( st.find( x - sum1) != st.end() ) {
                for( int k = i+1; k<=n; k++) {
                    for( int h = k+1; h<=n; h++) {
                        if( sum1 + a[k] + a[h] == x) {
                            ans[0] = j;
                            ans[1] = i;
                            ans[2] = k;
                            ans[3] = h;
                        }
                    }
                }
            }

            if( ans[0])
                break;
        }

        if( ans[0])
            break;
    }

    if( ans[0]) {
        for( auto it:ans)
            cout << it << " ";
        cout << "\n";
    }
    else
        cout << "IMPOSSIBLE\n";

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
