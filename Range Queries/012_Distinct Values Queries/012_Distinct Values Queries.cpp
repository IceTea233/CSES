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
const int maxn = 2e5 + 7;

struct SGT {
    int tree[maxn*4];

    SGT() {
        memset(tree, 0, sizeof(tree));
    }

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}

    void pull(int i) {
        tree[i] = tree[LC(i)] + tree[RC(i)];
    }
    void upd(int x, int d, int l, int r, int i=1) {
        if (l == r) {
            tree[i] = d;
            return;
        }
        int m = (l + r) / 2;
        if (x <= m)
            upd(x, d, l, m, LC(i));
        if (m+1 <= x)
            upd(x, d, m+1, r, RC(i));
        pull(i);
    }
    int query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        int m = (l + r) / 2;
        int ret = 0;
        if (x1 <= m)
            ret += query(x1, x2, l, m, LC(i));
        if (m+1 <= x2)
            ret += query(x1, x2, m+1, r, RC(i));
        return ret;
    }
}seg;

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
    int n,q;

    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        scanf("%lld", &x[i]);
    }

    vector<info> Q;
    for (int i=1; i<=q; i++) {
        int a,b;
        scanf("%lld %lld", &a, &b);
        Q.PB({i, a, b});
    }
    sort(begin(Q), end(Q));
    int now = 1;

    for (auto it: Q) {
        for (; now <= it.r; now++) {
            seg.upd(mp[x[now]], 0, 0, n);
            seg.upd(now, 1, 0, n);
            mp[x[now]] = now;
        }
        ans[it.id] = seg.query(it.l, it.r, 0, n);
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
