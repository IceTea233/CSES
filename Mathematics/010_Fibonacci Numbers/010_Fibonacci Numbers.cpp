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

int ans[2][2] = {
    {0, 0},
    {1, 0}
};
int M[70][2][2] = {};
int T[2][2] = {
    {0, 1},
    {1, 1}
};

void mul(int A[2][2], int B[2][2], int C[2][2]) {
    int tmp[2][2] = {};
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<2; k++) {
                tmp[i][j] += A[i][k] * B[k][j] % MOD;
                tmp[i][j] %= MOD;
            }
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            C[i][j] = tmp[i][j];
        }
    }
}

void prepare() {
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++)
            M[0][i][j] = T[i][j];
    }
    for (int i=0; i<70; i++) {
        mul(M[i], M[i], M[i+1]);
    }
}

int32_t main() {
    int i,j;
    int n;

    prepare();
    
    cin >> n;
    for (int i=0; i<64; i++) {
        if ((n>>i)&1) {
            mul(M[i], ans, ans);
        }
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
