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
const int maxn = 1e6 + 7;
const int MOD = 1e9+7;

int cnt[26] = {};
char s[maxn] = {};
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

void prepare(int n) {
    fac[0] = 1;
    for (int i=1; i<=n; i++)
        fac[i] = fac[i-1] * i % MOD;
}

int32_t main() {
    int i,j;

    scanf("%s", s);
    for (int i=0; s[i]; i++)
        cnt[ s[i]-'a' ]++;
    int n = strlen(s);
    prepare(n);
    int ans = fac[n];
    for (int i=0; i<26; i++) {
        ans = ans * pwr(fac[cnt[i]], MOD-2) % MOD;
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
