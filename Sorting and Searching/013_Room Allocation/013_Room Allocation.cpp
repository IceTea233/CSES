#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

struct event {
    int id;
    int type;
    int time;

    bool operator<( event b) {
        if( time == b.time)
            return type < b.type;
        return time < b.time;
    }
};

int main() {

    int i,j;
    int n;

    cin >> n;
    vector<event> keep;
    for( i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        keep.push_back( { i, 1, a});
        keep.push_back( { i, 2, b});
    }
    sort( begin( keep), end( keep));

    vector<int> room(n+1);
    vector<int> roomer(n+1);
    priority_queue<int, vector<int>, greater<int> > pq;
    for( i=1; i<=n; i++)
        pq.push(i);
    int ans = 0;
    for( auto it:keep) {
        if( it.type == 1) {
            int n_t = pq.top();
            pq.pop();
            room[it.id] = n_t;
            ans = max( ans, n_t);
        }
        else {
            pq.push( room[it.id]);
        }
    }

    cout << ans << "\n";
    for( i=1; i<=n; i++) {
        cout << room[i] << " ";
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
