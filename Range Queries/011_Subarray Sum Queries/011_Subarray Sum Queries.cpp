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
        int lmax;
        int rmax;
        int sum;
        int max;
    };
    node tree[maxn*4];

    SGT() {
        memset(tree, 0, sizeof(SGT));
    }

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}

    void pull(int l, int r, int i) {
        tree[i].lmax = max(tree[LC(i)].lmax, tree[LC(i)].sum + tree[RC(i)].lmax);
        tree[i].rmax = max(tree[RC(i)].rmax, tree[RC(i)].sum + tree[LC(i)].rmax);
        tree[i].sum = tree[LC(i)].sum + tree[RC(i)].sum;
        tree[i].max = max({tree[LC(i)].max, tree[RC(i)].max, tree[LC(i)].rmax + tree[RC(i)].lmax});
    }
    void build(int arr[], int l, int r, int i=1) {
        if (l == r) {
            tree[i] = { max(arr[l], 0LL), max(arr[l], 0LL), arr[l], max(arr[l], 0LL)};
            // printf("(%lld, %lld) = (%lld, %lld, %lld, %lld)\n", l, r, tree[i].lmax, tree[i].rmax, tree[i].sum, tree[i].max);
            return;
        }
        int m = (l+r) / 2;
        build(arr, l, m, LC(i));
        build(arr, m+1, r, RC(i));
        pull(l, r, i);
        // printf("(%lld, %lld) = (%lld, %lld, %lld, %lld)\n", l, r, tree[i].lmax, tree[i].rmax, tree[i].sum, tree[i].max);
    }
    void upd(int x, int d, int l, int r, int i=1) {
        if (l == r) {
            tree[i] = { max(d, 0LL), max(d, 0LL), d, max(d, 0LL)};
            return;
        }
        int m = (l+r) / 2;
        if (x <= m)
            upd(x, d, l, m, LC(i));
        if (m+1 <= x)
            upd(x, d, m+1, r, RC(i));
        pull(l, r, i);
        // printf("(%lld, %lld) = (%lld, %lld, %lld, %lld)\n", l, r, tree[i].lmax, tree[i].rmax, tree[i].sum, tree[i].max);
    }
    int query() {
        return tree[1].max;
    }
}seg;

int x[maxn] = {};

int32_t main() {
    int i,j;
    int n,m;

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> x[i];
    }
    seg.build(x, 1, n);
    for (int i=1; i<=m; i++) {
        int k,x;
        scanf("%lld %lld", &k, &x);
        seg.upd(k, x, 1, n);
        int ans = seg.query();
        printf("%lld\n", ans);
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
