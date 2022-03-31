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
const int INF = 2e18;
const int maxn = 1e2 + 7;
const int maxk = 1e9 + 7;

int n,m,k;
int adj[maxn][maxn] = {};
int dis[40][maxn][maxn] = {};
int ans[2][maxn][maxn] = {};

void prepare() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dis[0][i][j] = adj[i][j];
        }
    }
    for (int i=0; i<32; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                dis[i+1][j][k] = INF;
            }
        }
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                for (int h=1; h<=n; h++) {
                    dis[i+1][j][k] = min(dis[i+1][j][k], dis[i][j][h] + dis[i][h][k]);
                }
            }
        }
    }
}

int32_t main() {
    int i,j;

    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            adj[i][j] = INF;
            ans[0][i][j] = INF;
        }
    }
    for (int i=1; i<=m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }
    prepare();

    int now = 0;
    ans[0][1][1] = 0;
    for (int i=0; i<32; i++) {
        if ((k>>i)&1) {
            for (int j=1; j<=n; j++) {
                for (int k=1; k<=n; k++) {
                    ans[!now][j][k] = INF;
                    for (int h=1; h<=n; h++) {
                        ans[!now][j][k] = min(ans[!now][j][k], ans[now][j][h] + dis[i][h][k]);
                    }
                }
            }
            now ^= 1;
        }
    }

    if (ans[now][1][n] == INF)
        printf("-1\n");
    else
        printf("%lld\n", ans[now][1][n]);
    // for (int i=1; i<=n; i++) {
    //     for (int j=1; j<=n; j++) {
    //         printf("%lld ", ans[now][i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

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
