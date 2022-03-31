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
    int tag[maxn*4] = {};

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}
    void pull(int i) {
        tree[i] = tree[LC(i)] + tree[RC(i)];
    }
    void push(int l, int r, int i) {
        if (!tag[i])
            return;
        int m = (l + r) / 2;
        tree[LC(i)] = tag[i] * (m - l + 1);
        tree[RC(i)] = tag[i] * (r - m);
        tag[LC(i)] = tag[i];
        tag[RC(i)] = tag[i];
        tag[i] = 0;
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
    void upd(int x1, int x2, int d, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            tree[i] = d * (r - l + 1);
            tag[i] = d;
            // printf("UPD(%lld, %lld) = %lld\n", l, r, tree[i]);
            return;
        }
        int m = (l + r) / 2;
        push(l, r, i);
        if (x1 <= m)
            upd(x1, x2, d, l, m, LC(i));
        if (m+1 <= x2)
            upd(x1, x2, d, m+1, r, RC(i));
        pull(i);
        // printf("UPD(%lld, %lld) = %lld\n", l, r, tree[i]);
    }
    int query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        int m = (l + r) / 2;
        push(l, r, i);
        int ret = 0;
        if (x1 <= m)
            ret += query(x1, x2, l, m, LC(i));
        if (m+1 <= x2)
            ret += query(x1, x2, m+1, r, RC(i));
        return ret;
    }
} seg;

int x[maxn] = {};
int ans[maxn] = {};

struct BIT {
    int arr[maxn] = {};
    void add(int x, int d) {
        while (x < maxn) {
            arr[x] += d;
            x += (x & -x);
        }
    }
    int query(int x) {
        int ret = 0;
        while (x) {
            ret += arr[x];
            x -= (x & -x);
        }
        return ret;
    }
    int sum(int l, int r) {
        return query(r) - query(l-1);
    }
} bit;

struct SPT {
    int table[maxn][31];

    void build(int *arr, int n) {
        for (int i=1; i<=n; i++) {
            table[i][0] = arr[i];
        }
        for (int i=0; i<30; i++) {
            for (int j=1; j<=n; j++) {
                table[j][i+1] = max(table[j][i], table[min(n, j + (1 << i))][i]);
            }
        }
    }
    int query(int x, int k, int n) {
        for (int i=30; i>=0; i--) {
            if (x <= n && table[x][i] <= k)
                x = min(n+1, x + (1 << i));
        }
        return x-1;
    }
} spt;
vector< array<int, 3> > op;

int32_t main() {
    cin.tie(0);
    int i,j;
    int n,q;

    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        scanf("%lld", &x[i]);
    }

    for (int i=1; i<=q; i++) {
        int a, b;
        scanf("%lld %lld", &a, &b);
        op.PB({a, b, i});
    }
    sort(all(op), greater<array<int,3>>());
    spt.build(x, n);
    // for (int i=0; i<10; i++) {
    //     for (int j=1; j<=n; j++) {
    //         printf("%2lld ", spt.table[j][i]);
    //     }
    //     printf("\n");
    // }
    int cur = n;
    for (auto it : op) {
        // printf(">>> %lld %lld\n", it[0], it[1]);
        while (cur >= it[0]) {
            // printf("cur = %lld\n", cur);
            int r = spt.query(cur, x[cur], n);
            // printf("set [%lld, %lld] = %lld\n", cur, r, x[cur]);
            seg.upd(cur, r, x[cur], 1, n);
            bit.add(cur, x[cur]);
            cur--;
        }
        // printf("OK\n");
        int a = bit.sum(it[0], it[1]);
        int b = seg.query(it[0], it[1], 1, n);
        // printf("a = %lld, b = %lld\n", a, b);
        ans[it[2]] = b - a;
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
