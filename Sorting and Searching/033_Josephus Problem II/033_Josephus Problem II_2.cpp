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

int n, k;
int bit[maxn] = {};

void add(int x, int d) {
    while (x <= n) {
        bit[x] += d;
        x += x & (-x);
    }
}

int query(int x) {
    int ret = 0;
    while (x) {
        ret += bit[x];
        x -= x & (-x);
    }
    return ret;
}

int sum(int l, int r) {
    if (l > r)
        return 0;
    return query(r) - query(l-1);
}

bool chk(int x, int now, int num) {
    int a = num * (x / n);
    x %= n;
    int b = 0;
    if (x <= n-now) {
        b += sum(now+1, now+x);
    } else {
        b += sum(now+1, n);
        x -= n-now;
        b += sum(1, x);
    }
    return (a+b) >= k + 1;
}

int bs(int l, int r, int now, int num) {
    if (l == r)
        return l;
    int m = (l + r) / 2;
    if (chk(m, now, num))
        return bs(l, m, now, num);
    else
        return bs(m+1, r, now, num);
}

int32_t main() {
    int i,j;

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        add(i, 1);
    }

    vector<int> ans;
    int now = 0;
    for (int i=n; i>=1; i--) {
        int step = bs(1, 1e18, now, i);
        // printf("step = %lld\n", step);
        now = ( now + step - 1 ) % n + 1;
        add(now, -1);
        ans.PB(now);
    }

    for (auto it : ans) {
        printf("%lld ", it);
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
