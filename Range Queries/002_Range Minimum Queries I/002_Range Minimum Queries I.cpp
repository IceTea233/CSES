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
const int maxn = 2e5 + 7;

int x[maxn] = {};
int st[20][maxn] = {};

main() {
    int i,j;
    int n,q;

    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> x[i];
        st[0][i] = x[i];
    }

    for (int i=1; i<20; i++) {
        for (int j=1; j + (1<<i) - 1 <= n; j++) {
            st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        for (i=0; l+(1<<i)-1 < r-(1<<i)+1; i++);
        int ans = min(st[i][l], st[i][r-(1<<i)+1]);
        printf("%lld\n", ans);
    }


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
