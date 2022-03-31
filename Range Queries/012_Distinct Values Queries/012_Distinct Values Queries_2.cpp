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
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e6 + 7;

int n,q;
int bit[maxn] = {};
void add(int x, int d) {
    while(x <= n) {
        bit[x] += d;
        x += x & (-x);
    }
}
int query(int x) {
    int ret = 0;
    while(x) {
        ret += bit[x];
        x -= x & (-x);
    }
    return ret;
}
int sum(int l, int r) {
    return query(r) - query(l-1);
}

struct info {
    int id;
    int l;
    int r;
    bool operator<(info b) {
        return r < b.r;
    }
};
int x[maxn] = {};
int ans[maxn] = {};

unordered_map<int,int> mp;

int32_t main() {
    int i,j;

    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        scanf("%lld", &x[i]);
    }

    vector<info> Q;
    for (int i=1; i<=q; i++) {
        int a,b;
        scanf("%lld%lld", &a, &b);
        Q.PB({i, a, b});
    }
    sort(begin(Q), end(Q));
    int now = 1;

    for (auto it: Q) {
        for (; now <= it.r; now++) {
            assert(now <= n+1);
            if (mp[x[now]] != 0)
                add(mp[x[now]], -1);
            add(now, 1);
            mp[x[now]] = now;
        }
        ans[it.id] = sum(it.l, it.r);
        // ans[it.id] = seg.query(it.l, it.r, 0, n);
    }
    for (int i=1; i<=q; i++) {
        printf("%lld\n", ans[i]);
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
