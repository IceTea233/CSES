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
const int maxn = 1e5 + 7;
const int MOD = 1e9 + 7;

int pwr(int a, int b) {
    int ret = 1;
    while(b) {
        if (b&1)
            ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

int sum(int l, int r) {
    return (l + r) % MOD * ((r-l+1) % MOD) % MOD * pwr(2, MOD-2) % MOD;
}

int32_t main() {
    int i,j,k;
    int n;

    cin >> n;
    int ans = 0;
    for (int i=1, j=1; i<=n; i=j) {
        for (k=0; n / (j + (1LL<<k)) == n / j; k++);
        for (; k>=0; k--) {
            if (n / (j + (1LL<<k)) == n / j)
                j += (1LL<<k);
        }
        // printf(">>> %lld\n", j-i+1);
        // printf("(%lld, %lld)\n", i, j);
        // printf("+ %lld\n", (n / i) * (j-i+1) * sum(i, j));
        ans += (n / i)  * sum(i, j) % MOD;
        ans %= MOD;
        j++;
    }
    printf("%lld\n", ans);

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
