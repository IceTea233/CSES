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

struct SGT {
    struct node {
        int val;
        int tag;
        int lc = 0;
        int rc = 0;
    };
    int ptr;
    node tree[maxn] = {};

    SGT() {
        ptr = 0;
    }

    int LC(int i) {return tree[i].lc;}
    int RC(int i) {return tree[i].rc;}
    void pull(int i) {
        tree[i].val = min( tree[LC(i)].val, tree[RC(i)].val);
    }
    void push(int i) {
        tree[LC(i)].val += tree[i].tag;
        tree[RC(i)].val += tree[i].tag;
        tree[LC(i)].tag += tree[i].tag;
        tree[RC(i)].tag += tree[i].tag;
        tree[i].tag = 0;
    }
    void build(int *arr, int l, int r, int i=1) {
        if (l == r) {
            tree[i].val = arr[l];
            return;
        }
        int m = (l + r) / 2;
        build(arr, l , m, LC(i));
        build(arr, m+1, r, RC(i));
    }
    void upd(int x1, int x2, int d, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            tree[i].val += d;
            tree[i].tag += d;
            return;
        }
        int m = (l + r) / 2;
        push(i);
        if (x1 <= m)
            upd(x1, x2, d, l, m, LC(i));
        if (m+1 <= x2)
            upd(x1, x2, d, m+1, r, RC(i));
        pull(i);
    }
    int query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i].val;
        }
        int m = (l + r) / 2;
        int ret = INF;
        push(i);
        if (x1 <= m)
            ret = min(ret, query(x1, x2, l, m, LC(i)));
        if (m+1 <= x2)
            ret = min(ret, query(x1, x2, m+1, r, RC(i)));
        pull(i);
        return ret;
    }
} seg;

int p[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int n,q;

    cin >> n >> q;

    for (int i=1; i<=n; i++) {
        scanf("%lld", &p[i]);
    }
    seg.build(p, 1, n);
    for (int i=1; i<=n; i++) {
        seg.upd(i, i, i-1, 1, n);
    }
    int cur = 1;
    while (q--) {
        int cmd;
        scanf("%lld", &cmd);
        if (cmd == 1) {
            int k, x;
            scanf("%lld %lld", &k, &x);
            seg.upd(k, k, x-p[i], 1, n);
            p[i] = x;
        } else if (cmd == 2) {
            int k;
            scanf("%lld", &k);

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
