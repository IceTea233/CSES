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
const int maxn = 1e2 + 7;
const int MOD = 1e9 + 7;

int n,m,k;
vector<int> G[maxn];
int ans[maxn][maxn] = {};
int T[maxn][maxn] = {};
int M[40][maxn][maxn] = {};

void mul(int a[maxn][maxn], int b[maxn][maxn], int c[maxn][maxn]) {
    int tmp[maxn][maxn] = {};
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                tmp[i][j] += a[i][k] * b[k][j] % MOD;
                tmp[i][j] %= MOD;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            c[i][j] = tmp[i][j];
        }
    }
}

void prepare() {
    ans[1][1] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            M[0][i][j] = T[i][j];
        }
    }
    for (int i=0; i<32; i++) {
        mul(M[i], M[i], M[i+1]);
    }
}

int32_t main() {
    int i,j;

    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        int a,b;
        scanf("%lld %lld", &a, &b);
        T[b][a]++;
    }
    prepare();
    de(0) {
        for (int k=1; k<=10; k++) {
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    printf("%lld ", M[k][i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    for (int i=0; i<32; i++) {
        if ((k>>i)&1)
            mul(M[i], ans, ans);
    }
    de(1) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                printf("%lld ", ans[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("%lld\n", ans[n][1]);

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
