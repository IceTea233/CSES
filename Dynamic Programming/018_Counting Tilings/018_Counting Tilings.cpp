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
const int maxm = 1e3 + 7;
const int MOD = 1e9 + 7;

int n,m;

vector<int> states;
vector<int> src[1<<10] = {};
int dp[maxm][1<<10] = {};

bool legal(int src, int des) {
    for (int i=0; i<n; i++) {
        if ((des>>i)&1) {
            if (!((src>>i)&1))
                continue;

            if (!((src>>(i+1))&1) || !((des>>(i+1))&1))
                return 0;
            i++;
        } else {
            if (!((src>>i)&1))
                return 0;
        }
    }
    return 1;
}

void prepare() {
    for (int i=0; i<(1LL<<n); i++) {
        for (int j=0; j<(1LL<<n); j++) {
            if (legal(i, j))
                src[j].PB(i);
        }
    }
}

int32_t main() {
    int i,j;

    cin >> n >> m;
    prepare();

    dp[0][(1LL<<n)-1] = 1;
    for (int i=1; i<=m; i++) {
        for (int j=0; j<(1LL<<n); j++) {
            for (auto it : src[j]) {
                dp[i][j] += dp[i-1][it];
                dp[i][j] %= MOD;
            }
        }
    }

    int ans = dp[m][(1LL<<n)-1];
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
