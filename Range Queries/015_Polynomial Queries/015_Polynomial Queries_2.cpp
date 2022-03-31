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
    int tag1[maxn*4];
    int tag2[maxn*4];

    SGT() {
        for (int i=0; i<maxn*4; i++) {
            tree[i] = 0;
            tag1[i] = 0;
            tag2[i] = 0;
        }
    }

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}
    int sum (int l, int m, int r) {
        int a = (1 + m-l) * (m-l) / 2;
        int b = (1 + r-l+1) * (r-l+1) / 2;
        de(1) printf("sum(%lld, %lld, %lld) = %lld\n", l, m, r, b-a);
        return b - a;
    }
    void push(int l, int r, int i) {
        int m = (l + r) / 2;
        tree[LC(i)] += tag1[i] * (m-l+1) + tag2[i] * sum(l, l, m);
        tree[RC(i)] += tag1[i] * (r - m) + tag2[i] * sum(l, m+1, r);
        tag1[LC(i)] += tag1[i];
        tag1[RC(i)] += tag1[i] + (m-l+1) * (tag2[i]);
        tag2[LC(i)] += tag2[i];
        tag2[RC(i)] += tag2[i];
        tag1[i] = 0;
        tag2[i] = 0;
    }
    void pull(int l, int r, int i) {
        tree[i] = tree[LC(i)] + tree[RC(i)];
    }
    void build(int arr[] ,int l, int r, int i=1) {
        if (l == r) {
            tree[i] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        build(arr, l, m, LC(i));
        build(arr, m+1, r, RC(i));
        pull(l, r, i);
    }
    void upd(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            tree[i] += sum(x1, l, r);
            tag1[i] += l - x1;
            tag2[i] += 1;
            return;
        }
        int m = (l+r) / 2;
        push(l, r, i);
        if (x1 <= m)
            upd(x1, x2, l, m, LC(i));
        if (m+1 <= x2)
            upd(x1, x2, m+1, r, RC(i));
        pull(l, r, i);
    }
    int query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        int m = (l+r) / 2;
        push(l, r, i);
        int ret = 0;
        if (x1 <= m)
            ret += query(x1, x2, l, m, LC(i));
        if (m+1 <= x2)
            ret += query(x1, x2, m+1, r, RC(i));
        return ret;
    }
}seg;

int t[maxn] = {};

int32_t main() {
    int i,j;
    int n,q;

    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    seg.build(t, 1, n);
    while (q--) {
        int type;
        scanf("%lld", &type);
        if (type == 1) {
            int a,b;
            scanf("%lld %lld", &a, &b);
            seg.upd(a, b, 1, n);
        } else {
            int a,b;
            scanf("%lld %lld", &a, &b);
            int ans = seg.query(a, b, 1, n);
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
