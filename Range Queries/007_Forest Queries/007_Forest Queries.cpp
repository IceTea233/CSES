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
const int maxn = 1e3 + 7;

int n,q;
char s[maxn] = {};
int table[maxn][maxn] = {};
int bit[maxn][maxn] = {};

void add(int r, int c, int d) {
    while(r <= n) {
        int x2 = c;
        while(x2 <= n) {
            bit[r][x2] += d;
            x2 += x2 & (-x2);
        }
        r += r & (-r);
    }
}

int query(int r, int c) {
    int ret = 0;
    while(r) {
        int x2 = c;
        while(x2) {
            ret += bit[r][x2];
            x2 -= x2 & (-x2);
        }
        r -= r & (-r);
    }
    return ret;
}

int sum(int y1, int x1, int y2, int x2) {
    return query(y2, x2) - query(y2, x1-1) - query(y1-1, x2) + query(y1-1, x1-1);
}

main() {
    int i,j;

    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        scanf("%s", s+1);
        for (int j=1; j<=n; j++) {
            if (s[j] == '*')
                table[i][j] = 1;
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (table[i][j])
                add(i, j, 1);
        }
    }

    while(q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int ans = sum(y1, x1, y2, x2);
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
