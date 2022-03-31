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

vector<pii> fac;
int num = 1;
int sum = 1;
int prod = 1;

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
        int x, k;
        scanf("%lld %lld", &x, &k);
        fac.PB({x, k});
        num = num * (k + 1) % MOD;
    }

    for (auto it : fac) {
        // printf("%lld %lld %lld\n", num, sum, prod);
        sum = sum * Series(it.F, it.S) % MOD;
        int mul = num * cmpl(it.S + 1) % MOD;
        // printf("mul = %lld\n", mul);
        int base = pwr(it.F, it.S * (it.S + 1) % MOD * cmpl(2) % MOD);
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
