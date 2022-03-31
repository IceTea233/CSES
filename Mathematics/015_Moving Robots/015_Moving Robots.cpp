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
const int maxn = 10;
const int maxk = 1e2+7;

int K;
double p[maxn][maxn][maxn][maxn] = {};
int mask[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    { 0,-1}
};

bool okay(int r, int c) {
    return 1 <= r && r <= 8 && 1 <= c && c <= 8;
}

void generate(int r, int c) {
    double tmp[maxk][maxn][maxn] = {};
    tmp[0][r][c] = 1;
    for (int i=0; i<K; i++) {
        for (int j=1; j<=8; j++) {
            for (int k=1; k<=8; k++) {
                int cnt = 0;
                for (int h=0; h<4; h++) {
                    int n_r = j + mask[h][0];
                    int n_c = k + mask[h][1];
                    if (okay(n_r,n_c))
                        cnt++;
                }
                for (int h=0; h<4; h++) {
                    int n_r = j + mask[h][0];
                    int n_c = k + mask[h][1];
                    if (okay(n_r,n_c))
                        tmp[i+1][n_r][n_c] += tmp[i][j][k] / cnt;
                }
            }
        }
    }

    double sum = 0;
    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            sum += tmp[K][i][j];
            p[r][c][i][j] = 1 - tmp[K][i][j];
        }
    }
}

int32_t main() {
    int i,j;
    cin >> K;

    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            generate(i, j);
        }
    }
    
    double ans = 0;
    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            double add = 1;
            for (int k=1; k<=8; k++) {
                for (int h=1; h<=8; h++) {
                    add *= p[k][h][i][j];
                }
            }
            ans += add;
            // for (int k=1; k<=8; k++) {
            //     for (int h=1; h<=8; h++) {
            //         printf("%.9f ", p[i][j][k][h]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");
        }
    }

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
