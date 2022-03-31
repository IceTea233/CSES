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

int dp[20][12] = {};

int cnt(int x) {
    if (x < 10)
        return x + 1;
    vector<int> arr;
    while (x) {
        arr.PB(x % 10);
        x /= 10;
    }
    reverse(all(arr));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < arr[0]; i++)
        dp[0][i] = 1;
    dp[0][10] = 1;
    dp[0][11] = 1;

    for (int i = 1; i < arr.size(); i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (j != k)
                    dp[i][j] += dp[i-1][k];
            }
            if (j < arr[i] && j != arr[i-1])
                dp[i][j] += dp[i-1][11];
            if (j != 0)
                dp[i][j] += dp[i-1][10];
        }
        dp[i][10] += dp[i-1][10];
        if (arr[i] != arr[i-1])
        dp[i][11] += dp[i-1][11];
    }

    // for (int i=0; i<arr.size(); i++) {
    //     for (int j=0; j<=11; j++) {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    int ret = 0;
    for (int i = 0; i <= 11; i++)
        ret += dp[arr.size()-1][i];

    return ret;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int a, b;

    // while (1) {
    //     int x;
    //     cin >> x;
    //     printf(">>> %lld\n", cnt(x));
    // }
    cin >> a >> b;
    int l = cnt(a-1);
    int r = cnt(b);
    int ans = r - l;

    // for (int i=1; i<=b; i++) {
    //     if (cnt(i) > cnt(i-1))
    //         printf("%lld found -> %lld\n", i, cnt(i));
    // }
    // printf("%lld %lld\n", l, r);
    printf("%lld\n", r - l);

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
