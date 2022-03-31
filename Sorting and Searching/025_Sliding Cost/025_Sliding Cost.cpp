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

int main() {

    int i,j;
    int n,k;

    cin >> n >> k;
    for( i=1; i<=n; i++)
        cin >> x[i];

    set<pii> st;
    for( i=1; i<=k; i++) {
        st.insert( { x[i], i});
    }

    auto now = st.begin();
    for( i=1; i<=(k-1)/2; i ++) {
        now = next(now);
    }
    LLI cost = 0;
    for( auto it: st)
        cost += abs( now->fst - it.fst);
    vector<LLI> ans;
    ans.push_back(cost);

    for( i=k+1; i<=n; i++) {
        pii kick = { x[i-k], i-k};
        pii add = { x[i], i};

        st.insert( add);

        if( kick >= *now && add < *now) {
            LLI d = now->fst - prev(now)->fst;
            if( k % 2) {
                cost += d;
            }
            else {
                cost += d*2;
            }
            now = prev(now);
        }
        else if( kick <= *now && add > *now) {
            LLI d = next(now)->fst - now->fst;
            if( k % 2) {
                cost += d;
            }
            else {
                cost += 0;
            }
            now = next(now);
        }

        cost -= abs( now->fst - kick.fst);
        cost += abs( now->fst - add.fst);
        ans.push_back(cost);
        st.erase(kick);
    }

    for( auto it:ans) {
        cout << it << " ";
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
