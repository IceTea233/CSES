#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define PP pop_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 2e5 + 7;

int n,q;
int x[maxn] = {};
int bit[maxn] = {};

void add(int x, int d) {
    while(x <= n) {
        bit[x] += d;
        x += x&(-x);
    }
}
int query(int x) {
    int ret = 0;
    while(x) {
        ret += bit[x];
        x -= x&(-x);
    }
    return ret;
}

main() {
    int i,j;

    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> x[i];
    }
    for (int i=1; i<=n; i++) {
        add(i, x[i]-x[i-1]);
    }
    while(q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            add(a, u);
            add(b+1, -u);
        } else {
            int k;
            cin >> k;
            int ans = query(k);
            printf("%lld\n", ans);
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
