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
const int maxn = 1e5 + 7;
const int MOD = 1e9 + 7;

int ans[6][6] =
{
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {2, 0, 0, 0, 0, 0},
    {4, 0, 0, 0, 0, 0},
    {8, 0, 0, 0, 0, 0},
    {16, 0, 0, 0, 0, 0}
};
int T[6][6] =
{
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
};

int M[70][6][6] = {};

void mul(int a[6][6], int b[6][6], int c[6][6]) {
    int tmp[6][6] = {};
    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            for (int k=0; k<6; k++) {
                tmp[i][j] += a[i][k] * b[k][j] % MOD;
                tmp[i][j] %= MOD;
            }
        }
    }
    // for (int i=0; i<6; i++) {
    //     for (int j=0; j<6; j++) {
    //         printf("%lld ", tmp[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            c[i][j] = tmp[i][j];
        }
    }
}

void prepare() {
    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            M[0][i][j] = T[i][j];
        }
    }
    for (int i=0; i<64; i++) {
        mul(M[i], M[i], M[i+1]);
    }
}

int32_t main() {
    int i,j;
    int n;

    cin >> n;
    prepare();

    for (int i=0; i<64; i++) {
        if ((n>>i)&1LL)
            mul(M[i], ans, ans);
    }
    printf("%lld\n", ans[0][0]);

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
