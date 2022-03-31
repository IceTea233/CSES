#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

struct event {
    int type;
    int id;
    int time;

    bool operator<( event b) {
        if( time == b.time)
            return type > b.type;
        return time < b.time;
    }
};

bool take[200007] = {};
int a[200007] = {};
int b[200007] = {};

int main() {

    int i,j;
    int n,k;

    cin >> n >> k;

    vector<event> keep;
    for( i=1; i<=n; i++) {
        cin >> a[i] >> b[i];
        keep.push_back( { 1, i, a[i]});
        keep.push_back( { 2, i, b[i]});
    }

    sort( begin(keep), end(keep));

    int ans = 0;
    multiset< pii, greater<pii> > st;
    for( auto it:keep) {
        de(1) cout << ">>> " << it.type << " " << it.id << " " << it.time << "\n";
        if( it.type == 1) {
            int now = it.id;
            take[now] = 1;
            st.insert( { b[now], now});
            ans ++;

            if( st.size() > k) {
                take[ st.begin()->sec ] = 0;
                ans--;
                st.erase( st.begin());
            }
        }
        else if ( it.type == 2) {
            if( take[ it.id ] == 1) {
                st.erase( { it.time, it.id});
            }
        }

        de(1) cout << "ans = " << ans << "\n";
    }

    de(1) {
        cout << "take:";
        for( i=1; i<=n; i++) {
            if( take[i])
                cout << " " << i;
        }
        cout << "\n";
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
