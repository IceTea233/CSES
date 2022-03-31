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
const int maxn = 1e3 + 7;
const int maxm = 1e2 + 7;
const int MOD = 1e9 + 7;

int n,m;
string s;
int dp[maxn][maxm] = {};
int T[maxm][maxm] = {};

void prepare() {
    int i,j;
    string now;
    for (int i=0; i<m; i++) {
        for (char c='A'; c <= 'Z'; c++) {
            string suf = now + c;
            string pre = now + s[i];
            for (j=i+1; j>0; j--) {
                if (suf == pre) {
                    break;
                }
                reverse(all(suf));
                suf.PP();
                reverse(all(suf));
                pre.PP();
            }
            T[i][j]++;
        }
        now.PB(s[i]);
    }
}

int32_t main() {
    int i,j;

    cin >> n;
    cin >> s;
    m = s.size();
    prepare();
    // for (int i=0; i<=m; i++) {
    //     for (int j=0; j<=m; j++) {
    //         printf("%lld ", T[i][j]);
    //     }
    //     printf("\n");
    // }

    dp[0][0] = 1;
    int tt = 1;
    for (int i=0; i<n; i++) {
        tt *= 26;
        tt %= MOD;
        for (int j=0; j<m; j++) {
            for (int k=0; k<m; k++) {
                dp[i+1][k] += dp[i][j] * T[j][k];
                dp[i+1][k] %= MOD;
            }
        }
    }

    int sum = 0;
    for (int i=0; i<m; i++) {
        sum += dp[n][i];
        sum %= MOD;
    }
    // for (int i=0; i<=n; i++) {
    //     for (int j=0; j<=m; j++) {
    //         printf("%9lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    int ans = ( ( tt - sum ) % MOD + MOD ) % MOD;
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
