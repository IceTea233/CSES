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
const int maxr = 1e9;

struct SGT {
    struct node {
        int val;
        int l;
        int r;
    };
    node tree[maxn*60] = {};
    int id = 1;

    SGT() {
        memset(tree, 0, sizeof(tree));
        id = 1;
    }

    int LC(int i) {
        if (tree[i].l == 0)
            tree[i].l = ++id;
        return tree[i].l;
    }
    int RC(int i) {
        if (tree[i].r == 0)
            tree[i].r = ++id;
        return tree[i].r;
    }

    void pull(int i) {
        tree[i].val = tree[LC(i)].val + tree[RC(i)].val;
    }
    void upd(int x, int d, int l, int r, int i=1) {
        if (l == r) {
            tree[i].val += d;
            return;
        }
        int m = ( l + r ) / 2;
        if (x <= m)
            upd(x, d, l, m, LC(i));
        if (m+1 <= x)
            upd(x, d, m+1, r, RC(i));
        pull(i);
    }
    int query(int x1, int x2, int l, int r, int i=1) {
        // printf("query(%lld, %lld)\n", l, r);
        if (x1 <= l && r <= x2) {
            return tree[i].val;
        }
        int m = ( l + r ) / 2;
        int ret = 0;
        if (x1 <= m)
            ret += query(x1, x2, l, m, LC(i));
        if (m+1 <= x2)
            ret += query(x1, x2, m+1, r, RC(i));
        return ret;
    }
}seg;

int p[maxn];
char trash[7] = {};

int32_t main() {
    int i,j;
    int n,q;

    scanf("%lld %lld", &n, &q);
    for (int i=1; i<=n; i++)
        scanf("%lld", &p[i]);
    for (int i=1; i<=n; i++) {
        seg.upd(p[i], 1, 1, maxr);
    }

    while(q--) {
        fgets(trash, 7, stdin);
        char c;
        scanf("%c", &c);
        if (c == '!') {
            int k, x;
            scanf("%lld %lld", &k, &x);
            seg.upd(p[k], -1, 1, maxr);
            seg.upd(x, 1, 1, maxr);
            p[k] = x;
        } else if (c == '?') {
            int a, b;
            scanf("%lld %lld", &a, &b);
            int ans = seg.query(a, b, 1, maxr);
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
