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
    int type;
    int time;
    bool operator<( event b) {
        return time < b.time;
    }
};

int main() {

    int i,j;
    int n;

    scanf("%d", &n);
    vector<event> keep;
    for( i=1; i<=n; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        keep.push_back( { 1, a});
        keep.push_back( { 2, b});
    }
    sort( begin(keep), end(keep));

    int cnt = 0;
    int ans = 0;
    for( auto it:keep) {
        if( it.type == 1)
            cnt++;
        else
            cnt--;
        ans = max( ans, cnt);
    }

    printf("%d\n", ans);

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
