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
    int tree[maxn*4];
    queue<pii> tag[maxn*4];

    SGT() {
        memset(tree, 0, sizeof(tree));
    }

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}

    void push(int l, int r, int i) {
        while(!tag[i].empty()) {
            pii now = tag[i].front();
            tag[i].pop();
            int m = (l + r) / 2;
            if (now.F == 1) {
                tree[LC(i)] += now.S * (m-l+1);
                tree[RC(i)] += now.S * (r-m);
            } else if (now.F == 2) {
                tree[LC(i)] = now.S * (m-l+1);
                tree[RC(i)] = now.S * (r-m);
            }
            tag[LC(i)].push(now);
            tag[RC(i)].push(now);
        }
    }
    void pull(int l, int r, int i) {
        tree[i] = tree[LC(i)] + tree[RC(i)];
    }
    void build(int arr[], int l, int r, int i=1) {
        if (l == r) {
            tree[i] = arr[l];
            return;
        }
        int m = (l+r) / 2;
        build(arr, l, m, LC(i));
        build(arr, m+1, r, RC(i));
        pull(l, r, i);
    }
    void upd(int type, int x1, int x2, int d, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            if (type == 1) {
                tree[i] += d * (r-l+1);
                tag[i].push({1, d});
            } else if (type == 2) {
                tree[i] = d * (r-l+1);
                tag[i].push({2, d});
            }
            return;
        }
        int m = (l + r) / 2;
        push(l, r, i);
        if (x1 <= m)
            upd(type, x1, x2, d, l, m, LC(i));
        if (m+1 <= x2)
            upd(type, x1, x2, d, m+1, r, RC(i));
        pull(l, r, i);
    }
    int query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        int m = (l + r) / 2;

        int ret = 0;
        push(l, r, i);
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
        scanf("%lld", &t[i]);
    }
    seg.build(t, 1, n);
    while(q--) {
        int type;
        scanf("%lld", &type);
        if (type == 1) {
            int a, b, x;
            scanf("%lld %lld %lld", &a, &b, &x);
            seg.upd(type, a, b, x, 1, n);
        } else if (type == 2) {
            int a, b, x;
            scanf("%lld %lld %lld", &a, &b, &x);
            seg.upd(type, a, b, x, 1, n);
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
