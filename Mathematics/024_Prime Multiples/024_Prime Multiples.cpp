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

int n,k;
int a[maxn] = {};
int ans = 0;

void build(int idx, int cnt, int cur=1) {
    if (idx > k) {
        if (cur == 1)
            return;

        // printf("(%lld, %lld)\n", cnt, cur);
        if (cnt % 2 == 1)
            ans += n / cur;
        else
            ans -= n / cur;
        return;
    }

    build(idx+1, cnt, cur);
    if (cur * a[idx] / a[idx] == cur)
        build(idx+1, cnt+1, cur * a[idx]);
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> n >> k;

    for (int i=1; i<=k; i++) {
        scanf("%lld", &a[i]);
    }
    build(1, 0);

    printf("%lld\n", ans);

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
