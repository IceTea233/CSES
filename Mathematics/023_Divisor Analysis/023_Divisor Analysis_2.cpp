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

int num = 1;
int sum = 1;
int prod = 1;
int x[maxn] = {};
int k[maxn] = {};
int pre[maxn] = {};
int suf[maxn] = {};

int pwr(int x, int k) {
    int ret = 1;
    while (k) {
        if (k & 1)
            ret = ret * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return ret;
}

int pwr2(int x, int k) {
    int ret = 1;
    while (k) {
        if (k & 1)
            ret = ret * x % (MOD - 1);
        x = x * x % (MOD - 1);
        k >>= 1;
    }
    return ret;
}

int Series(int r, int n) {
    return (pwr(r, n + 1) - 1) * pwr(r - 1, MOD - 2) % MOD;
}

int cmpl(int x) {
    return pwr(x, MOD - 2);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int n;

    cin >> n;
    int tt = 0;
    for (int i=1; i<=n; i++) {
        scanf("%lld %lld", &x[i], &k[i]);
        num = num * (k[i] + 1) % MOD;
    }

    pre[0] = 1;
    for (int i=1; i<=n; i++) {
        pre[i] = pre[i-1] * (k[i] + 1) % (MOD - 1);
    }
    suf[n+1] = 1;
    for (int i=n; i>=1; i--) {
        suf[i] = suf[i+1] * (k[i] + 1) % (MOD - 1);
    }

    for (int i=1; i<=n; i++) {
        // printf("%lld %lld %lld\n", num, sum, prod);
        sum = sum * Series(x[i], k[i]) % MOD;
        int mul = pre[i-1] * suf[i+1] % (MOD - 1);
        // printf("mul = %lld\n", mul);
        int base = pwr(x[i], k[i] * (k[i] + 1) / 2 % (MOD - 1));
        // printf("base = %lld\n", base);
        prod = prod * pwr(base, mul) % MOD;
    }
    printf("%lld %lld %lld\n", num, sum, prod);


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
