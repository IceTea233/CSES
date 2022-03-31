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
        int l;
        int r;
    };

    int id;
    node tree[maxn*10];

    SGT() {
        id = 0;
        memset(tree, 0, sizeof(tree));
    };
    int LC(int i) {return tree[i].l;}
    int RC(int i) {return tree[i].r;}

    int pull(int i) {
        tree[i].val = tree[LC(i)].val + tree[RC(i)].val;
        return i;
    }
    int build(int arr[], int l, int r) {
        node now;
        if (l == r) {
            tree[++id].val = arr[l];
            return id;
        }
        int m = (l+r) / 2;
        now.l = build(arr, l, m);
        now.r = build(arr, m+1, r);
        tree[++id] = now;
        return pull(id);
    }
    int upd(int x, int d, int l, int r, int i) {
        node now = tree[i];
        if (l == r) {
            now.val = d;
            tree[++id] = now;
            return id;
        }
        int m = (l+r) / 2;
        if (x <= m)
            now.l = upd(x, d, l, m, LC(i));
        if (m+1 <= x)
            now.r = upd(x, d, m+1, r, RC(i));
        tree[++id] = now;
        return pull(id);
    }
    int query(int x1, int x2, int l, int r, int i) {
        if (x1 <= l && r <= x2) {
            return tree[i].val;
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

int t[maxn] = {};
vector<int> ver(1, 0);
vector<int> arr(1, 0);

int32_t main() {
    int i,j;
    int n,q;

    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    ver.PB( seg.build(t, 1, n) );
    arr.PB(1);
    while(q--) {
        int type;
        scanf("%lld", &type);
        if (type == 1) {
            int k,a,x;
            scanf("%lld %lld %lld", &k, &a, &x);
            ver.PB( seg.upd(a, x, 1, n, ver[arr[k]]) );
            arr[k] = ver.size()-1;
        } else if (type == 2) {
            int k, a, b;
            scanf("%lld %lld %lld", &k, &a, &b);
            int ans = seg.query(a, b, 1, n, ver[arr[k]]);
            printf("%lld\n", ans);
        } else if (type == 3) {
            int k;
            scanf("%lld", &k);
            arr.PB(arr[k]);
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
