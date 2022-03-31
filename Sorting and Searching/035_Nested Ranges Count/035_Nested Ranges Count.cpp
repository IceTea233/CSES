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
const int maxm = 1e6;

struct info {
    int id;
    pii val;
};

int n;
int x[maxn] = {};
int y[maxn] = {};
int ans1[maxn] = {};
int ans2[maxn] = {};

bool cmp1(info a, info b) {
    if (a.val.F == b.val.F)
        return a.val.S > b.val.S;
    return a.val.F < b.val.F;
}
bool cmp2(info a, info b) {
    if (a.val.S == b.val.S)
        return a.val.F > b.val.F;
    return a.val.S < b.val.S;
}

int bit[maxm] = {};
void upd(int x, int d) {
    while(x <= maxn*2) {
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
int sum(int l, int r) {
    return query(r) - query(l-1);
}

int32_t main() {
    int i,j;

    cin >> n;

    for (int i=1; i<=n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    vector<int> tmp;
    for (int i=1; i<=n; i++) {
        tmp.PB(x[i]);
        tmp.PB(y[i]);
    }
    sort(all(tmp));
    tmp.resize(unique(all(tmp)) - begin(tmp));
    for (int i=1; i<=n; i++) {
        x[i] = lower_bound(all(tmp), x[i]) - begin(tmp) + 1;
        y[i] = lower_bound(all(tmp), y[i]) - begin(tmp) + 1;
    }

    vector<info> keep;
    for (int i=1; i<=n; i++) {
        keep.PB({i, {x[i], y[i]}});
    }

    sort(all(keep), cmp1);
    for (auto it : keep) {
        int id = it.id;
        ans1[id] = sum(it.val.S, maxn*2);
        upd(it.val.S, 1);
    }
    memset(bit, 0, sizeof(bit));
    sort(all(keep), cmp2);
    for (auto it : keep) {
        int id = it.id;
        ans2[id] = sum(it.val.F, it.val.S);
        upd(it.val.F, 1);
    }

    for (int i=1; i<=n; i++)
        printf("%lld ", ans2[i]);
    printf("\n");
    for (int i=1; i<=n; i++)
        printf("%lld ", ans1[i]);
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
