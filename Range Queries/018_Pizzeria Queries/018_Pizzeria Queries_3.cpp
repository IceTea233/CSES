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
        tree[i] =  min(tree[LC(i)], tree[RC(i)]);
    }
    void build(int *arr, int l, int r, int i=1) {
        if (l == r) {
            tree[i] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        build(arr, l, m, LC(i));
        build(arr, m+1, r, RC(i));
        pull(i);
    }
    void upd(int x, int d, int l, int r, int i=1) {
        if (l == r) {
            tree[i] += d;
            return;
        }
        int m = (l + r) / 2;
        if (x <= m)
            upd(x, d, l, m, LC(i));
        if (m+1 <= x) {
            upd(x, d, m+1, r, RC(i));
        }
        pull(i);
    }
    int query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        int m = (l + r) / 2;
        int ret = INF;
        if (x1 <= m)
            ret = min(ret, query(x1, x2, l, m, LC(i)));
        if (m+1 <= x2)
            ret = min(ret, query(x1, x2, m+1, r, RC(i)));
        return ret;
    }

} seg1, seg2;

int p[maxn] = {};
int a1[maxn] = {};
int a2[maxn] = {};
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
        a1[i] = p[i] + i;
        a2[i] = p[i] + (n - i);
    }
    seg1.build(a1, 1, n);
    seg2.build(a2, 1, n);
    while (q--) {
        int cmd;
        scanf("%lld", &cmd);
        if (cmd == 1) {
            int k, x;
            scanf("%lld %lld", &k, &x);
            int d = x - p[k];
            seg1.upd(k, d, 1, n);
            seg2.upd(k, d, 1, n);
            p[k] += d;
            a1[k] += d;
            a2[k] += d;
        } else if (cmd == 2) {
            int k;
            scanf("%lld", &k);
            int ans1 = seg1.query(k, n, 1, n) - k;
            int ans2 = seg2.query(1, k, 1, n) - (n - k);
            int ans = min(ans1, ans2);
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
