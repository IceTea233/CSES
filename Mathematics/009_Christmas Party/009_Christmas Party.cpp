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
const int maxn = 2e6 + 7;
const int MOD = 1e9 + 7;

int fac[maxn] = {};

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

void prepare() {
    fac[0] = 1;
    for (int i=1; i<maxn; i++)
        fac[i] = fac[i-1] * i % MOD;
}

int C(int a, int b) {
    return fac[a] * pwr(fac[b], MOD-2) % MOD * pwr(fac[a-b], MOD-2) % MOD;
}

int32_t main() {
    int i,j;
    int n;

    cin >> n;
    prepare();
    int ans = 0;
    for (int i=n; i>=0; i--) {
        int d = fac[i] * C(n, i) % MOD;
        // printf("d = %lld\n", d);
        if (i % 2 == n % 2) {
            ans = (ans + d) % MOD;
        } else {
            ans = ( (ans - d ) % MOD + MOD ) % MOD;
        }
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
