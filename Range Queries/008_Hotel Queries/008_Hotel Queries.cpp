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
    int tree[maxn*4] = {};

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}
    void pull(int i) {
        tree[i] = max(tree[LC(i)], tree[RC(i)]);
    }
    void build(int arr[], int l, int r, int i=1) {
        if (l == r) {
            tree[i] = arr[l];
            return;
        }
        int m = (l+r) / 2;
        build(arr, l, m, LC(i));
        build(arr, m+1, r, RC(i));
        pull(i);
    }
    void upd(int x, int d, int l, int r, int i=1) {
        if (l == r) {
            tree[i] += d;
            return;
        }
        int m = (l+r) / 2;
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
        int m = (l+r) / 2;
        int ret = 0;
        if (x1 <= m)
            ret = max(ret, query(x1, x2, l, m, LC(i)));
        if (m+1 <= x2)
            ret = max(ret, query(x1, x2, m+1, r, RC(i)));
        return ret;
    }
}seg;

int n,m;

bool chk(int m, int x) {
    return seg.query(1, m, 1, n+1) >= x;
}

int bs(int l, int r, int x) {
    if (l == r)
        return l;
    int m = (l+r) / 2;
    if (chk(m,x))
        return bs(l, m, x);
    else
        return bs(m+1, r, x);
}

int h[maxn] = {};
int r[maxn] = {};

int32_t main() {
    int i,j;

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> h[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> r[i];
    }
    h[n+1] = INF;
    seg.build(h, 1, n+1);

    for (int i=1; i<=m; i++) {
        int idx = bs(1, n+1, r[i]);
        if (idx > n)
            printf("0 ");
        else {
            printf("%lld ", idx);
            seg.upd(idx, -r[i], 1, n+1);
        }
    }
    printf("\n");

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
