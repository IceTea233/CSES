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

int n;
int x[maxn] = {};
int p[maxn] = {};

int bit[maxn] = {};
void add(int x, int d) {
    while(x <= n) {
        bit[x] += d;
        x += x & (-x);
    }
}
int query(int x) {
    int ret = 0;
    while(x) {
        ret += bit[x];
        x -= x & (-x);
    }
    return ret;
}

bool chk(int m, int x) {
    return query(m) >= x;
}

int bs(int l, int r, int x) {
    if (l == r)
        return l;
    int m = (l+r) / 2;
    if (chk(m, x))
        return bs(l, m, x);
    else
        return bs(m+1, r, x);
}

int32_t main() {
    int i,j;

    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> x[i];
    for (int i=1; i<=n; i++)
        cin >> p[i];
    for (int i=1; i<=n; i++) {
        add(i, 1);
    }

    for (int i=1; i<=n; i++) {
        int idx = bs(1, n, p[i]);
        printf("%lld ", x[idx]);
        add(idx, -1);
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
