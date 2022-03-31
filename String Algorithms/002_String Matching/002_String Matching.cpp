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
const int MOD = 1e9 + 7;
const int MUL = 998244353;

char a[maxn];
string b;
int n,m;
int pre[maxn] = {};
int mul[maxn] = {};
int cht[maxn] = {};

void prepare() {
    mul[0] = 1;
    for (char c='a'; c<='z'; c++)
        cht[c] = c;
    random_shuffle(cht+'a', cht+'z'+1);
    for (int i=1; i<=n; i++) {
        pre[i] = (pre[i-1] * MUL + cht[ a[i] ]) % MOD;
        mul[i] = mul[i-1] * MUL % MOD;
    }
}

int val(int l, int r) {
    return (pre[r] - pre[l-1] * mul[r-l+1] % MOD + MOD) % MOD;
}
int val(string s) {
    int ret = 0;
    for (auto it: s)
        ret = (ret * MUL + cht[it]) % MOD;
    return ret;
}

int32_t main() {
    int i,j;

    srand(time(0));
    scanf("%s", a+1);
    cin >> b;
    n = strlen(a+1);
    m = b.size();
    prepare();

    int k = val(b);
    int ans = 0;
    for (int i=1; i+m-1 <= n; i++) {
        if (val(i, i+m-1) == k)
            ans++;
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
