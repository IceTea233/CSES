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
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 5e3 + 7;
const int MOD = 1e9 + 7;

int n,k;
char s[maxn] = {};
char tmp[1000007] = {};
string words[1000007];
int pre[maxn] = {};
int mul[maxn] = {};
unordered_map<int,int> mp;

int dp[maxn] = {};

void prepare() {
    mul[0] = 1;
    for (int i=1; i<=n; i++) {
        pre[i] = (pre[i-1] * 997 + s[i]) % MOD;
        mul[i] = (mul[i-1] * 997) % MOD;
    }
}

int val(int l, int r) {
    return ( pre[r] - pre[l-1] * mul[r-l+1] % MOD + MOD ) % MOD;
}
int val(string s) {
    int ret = 0;
    for (auto it : s) {
        ret = ( ret * 997 + it ) % MOD;
    }
    return ret;
}

int32_t main() {
    int i,j;

    scanf("%s", s+1);
    n = strlen(s+1);
    prepare();
    cin >> k;
    for (int i=0; i<k; i++) {
        scanf("%s", tmp);
        words[i] = tmp;
    }

    for (int i=0; i<k; i++) {
        de(1) printf(">>> %lld\n", val(words[i]));
        mp[val(words[i])]++;
    }

    de(0) {
        while(1) {
            int l, r;
            cin >> l >> r;
            cout << val(l, r) << "\n";
        }
    }

    dp[0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<=n; j++) {
            dp[j] += dp[i] * mp[val(i+1, j)] % MOD;
            dp[j] %= MOD;
        }
    }
    // for (int i=1; i<=n; i++) {
    //     printf("%lld ", dp[i]);
    // }
    // printf("\n");
    int ans = dp[n];
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
