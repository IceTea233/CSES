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
int sum(int l, int r) {
    return query(r) - query(l-1);
}

main() {
    int i,j;

    cin >> n >> q;
    for (int i=1; i<=n; i++)
        cin >> x[i];
    for (int i=1; i<=n; i++)
        add(i, x[i]);
    while(q--) {
        int type;
        scanf("%lld", &type);
        if (type == 1) {
            int k, u;
            scanf("%lld %lld", &k, &u);
            add(k, u - x[k]);
            x[k] = u;
        } else if (type == 2) {
            int a, b;
            scanf("%lld %lld", &a, &b);
            int ans = sum(a, b);
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
