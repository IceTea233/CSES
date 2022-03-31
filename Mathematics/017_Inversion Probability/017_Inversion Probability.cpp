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
const int maxn = 1e2 + 7;

int r[maxn] = {};
double e[maxn][maxn] = {};

int32_t main() {
    int i,j;
    int n;

    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> r[i];
    for (int i=1; i<=r[1]; i++) {
        e[1][i] = (double) (r[1]-i+1) / r[1];
    }

    double ans = 0;
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=100; j++) {
            for (int k=j; k<=100; k++) {
                e[i][j] = e[i-1][j] + (double) max( 0LL, (r[i]-j+1)) / r[i];
            }
        }

        for (int j=1; j<=r[i]; j++) {
            ans += e[i-1][j+1] * (1.0 / r[i]);
        }
    }

    // for (int i=1; i<=n; i++) {
    //     for (int j=1; j<=10; j++) {
    //         printf("%.6f ", e[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%.6f\n", ans);

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
