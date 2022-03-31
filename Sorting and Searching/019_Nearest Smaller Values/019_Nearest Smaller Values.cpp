#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int x[200007] = {};

struct info {
    int val;
    int pos;

    bool operator<( info b) {
        if( val == b.val) {
            return pos > b.pos;
        }
        return val < b.val;
    }
};

int main() {

    int i,j;
    int n;

    cin >> n;
    for( i=1; i<=n; i++) {
        cin >> x[i];
    }

    vector< info > keep;
    for( i=1; i<=n; i++) {
        keep.push_back( { x[i], i});
    }
    sort( begin(keep), end(keep));

    set< int, greater<int> > st;
    st.insert(0);
    vector<int> ans(n+1);
    for( auto it:keep) {
        int now = it.pos;
        auto q = st.upper_bound( now);
        ans[it.pos] = *q;
        st.insert(it.pos);
    }

    for( i=1; i<=n; i++)
        cout << ans[i] << " ";
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
