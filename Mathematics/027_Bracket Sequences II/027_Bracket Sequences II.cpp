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

void prepare() {
    fac[0] = 1;
    for (int i=1; i<maxn; i++)
        fac[i] = fac[i-1] * i % MOD;
}

int pwr(int x, int k) {
    int ret = 1;
    while (k) {
        if (k & 1) {
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
        k >>= 1;
    }
    return ret;
}

int inv(int x) {
    return pwr(x, MOD-2);
}

int C(int a, int b) {
    // printf("C(%lld, %lld)\n", a, b);
    return fac[a] * inv(fac[b]) % MOD * inv(fac[a-b]) % MOD;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int n;
    string s;

    cin >> n;
    cin >> s;
    prepare();
    if (n % 2 ==1) {
        printf("0\n");
        return 0;
    }

    int x = 0;
    int pos = 0;
    int neg = 0;
    for (auto &it : s) {
        if (it == '(') {
            pos ++;
            x ++;
        }
        else {
            neg ++;
            x --;
        }

        if (x < 0) {
            printf("0\n");
            return 0;
        }
    }

    if (x > n - s.size()) {
        printf("0\n");
        return 0;
    }

    int ans = C(n - s.size(), n / 2 - pos) - C(n - s.size(), n / 2 - pos + x +1);
    ans = (ans % MOD + MOD) % MOD;
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
