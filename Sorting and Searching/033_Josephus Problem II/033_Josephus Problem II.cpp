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

int32_t main() {
    int i,j;

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        add(i, 1);
    }

    vector<int> ans;
    int now = 1;
    for (int i=n; i>=1; i--) {
        now = (now-1 + k) % i + 1;
        printf("now = %lld\n", now);
        ans.PB(query(now));
        add(now, 1);
        de(1) {
            for (int j=1; j<i; j++) {
                printf("%lld ", query(j));
            }
            printf("\n");
        }
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
