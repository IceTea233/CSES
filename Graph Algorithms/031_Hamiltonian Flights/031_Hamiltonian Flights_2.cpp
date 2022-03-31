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
const int maxn = 27;
const int MOD = 1e9 + 7;

int G[maxn][maxn];
int b2i[1<<20] = {};
int dp[20][1<<20] = {};

void prepare(int n) {
    for (int i=0; i<n; i++)
        b2i[1<<i] = i;
}

void display(int x, int n) {
    for (int i=n-1; i>=0; i--)
        printf("%lld", (x>>i)&1);
    printf("\n");
}

main() {
    int i,j;
    int n,m;

    cin >> n >> m;
    prepare(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b]++;
    }

    dp[0][1] = 1;
    for (int i=1; i<(1<<n); i++) {
        for (int j = i; j>0; j -= (j&-j)) {
            for (int k = i^((1<<n)-1); k>0; k -= (k&-k)) {
                int a = b2i[j&(-j)];
                int b = b2i[k&(-k)];
                dp[b][i|(k&-k)] += dp[a][i] * G[a][b] % MOD;
                dp[b][i|(k&-k)] %= MOD;
            }
        }
    }

    printf("%lld\n", dp[n-1][(1<<n)-1]);

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
