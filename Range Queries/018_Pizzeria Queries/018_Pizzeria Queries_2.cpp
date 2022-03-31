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
        int val = 0;
        int tag = 0;
        int lc = 0;
        int rc = 0;
    };
    int ptr;
    node tree[maxn * 4];

    SGT() {
        ptr = 0;
    }

    int LC(int i) {
        if (!tree[i].lc)
            tree[i].lc = ++ptr;
        return tree[i].lc;
    }
    int RC(int i) {
        if (!tree[i].rc)
            tree[i].rc = ++ptr;
        return tree[i].rc;
    }
    int pull(int i) {
        node cur = tree[i];
        tree[++ptr].val = min( tree[LC(i)].val, tree[RC(i)].val);
        return ptr;
    }
    int push(int i) {
        node cur = tree[i];
        node lc = tree[LC(i)];
        node rc = tree[RC(i)];

        lc.val += tree[i].tag;
        rc.val += tree[i].tag;
        lc.tag += tree[i].tag;
        rc.tag += tree[i].tag;
        cur.tag = 0;
        tree[++ptr] = lc;
        cur.lc = ptr;
        tree[++ptr] = rc;
        cur.rc = ptr;
        tree[++ptr] = cur;
        return ptr;
    }
    int build(int *arr, int l, int r) {
        node cur;
        if (l == r) {
            tree[++ptr].val = arr[l];
            return ptr;
        }
        int m = (l + r) / 2;
        cur.lc = build(arr, l , m);
        cur.rc = build(arr, m+1, r);
        tree[++ptr] = cur;
        return pull(ptr);
    }
    int upd(int x1, int x2, int d, int l, int r, int i) {
        node cur = tree[i];
        if (x1 <= l && r <= x2) {
            ptr++;
            cur.val += d;
            cur.tag += d;
            tree[++ptr] = cur;
            return ptr;
        }
        int m = (l + r) / 2;
        i = push(i);
        cur = tree[i];
        if (x1 <= m)
            cur.lc = upd(x1, x2, d, l, m, LC(i));
        if (m+1 <= x2)
            cur.rc = upd(x1, x2, d, m+1, r, RC(i));
        return pull(i);
    }
    int query(int x1, int x2, int l, int r, int i) {
        if (x1 <= l && r <= x2) {
            return tree[i].val;
        }
        int m = (l + r) / 2;
        int ret = INF;
        i = push(i);
        if (x1 <= m)
            ret = min(ret, query(x1, x2, l, m, LC(i)));
        if (m+1 <= x2)
            ret = min(ret, query(x1, x2, m+1, r, RC(i)));
        return ret;
    }
} seg;

int p[maxn] = {};
int ver[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int n,q;

    cin >> n >> q;

    for (int i=1; i<=n; i++) {
        scanf("%lld", &p[i]);
    }
    for (int i=1; i<=n; i++) {
        p[i] += i - 1;
    }

    int cur = seg.build(p, 1, n);
    while (q--) {
        int cmd;
        scanf("%lld", &cmd);
        if (cmd == 1) {
            int k, x;
            scanf("%lld %lld", &k, &x);
            cur = seg.upd(k, k, x-p[i], 1, n, cur);
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
