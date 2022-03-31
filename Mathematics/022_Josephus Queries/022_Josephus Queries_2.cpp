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


int32_t main() {
    cin.tie(0);
    int i,j;
    int q;

    cin >> q;
    while (q--) {
        int n, k;
        scanf("%lld %lld", &n, &k);
        int cur = 1 % (n - k + 1);
        for (int i=n-k+1; i<n; ) {
            // printf("i = %lld, ", i);
            int add = ((i + 1) - cur) / 2;
            if (add <= 1) {
                // printf("Case 1\n");
                cur = (cur + 2) % (i+1);
                i += 1;
            } else if (i + add >= n) {
                // printf("Case 2\n");
                cur = ( cur + 2 * (n - i) ) % n;
                i = n;
            } else {
                // printf("Case 3\n");
                cur += add * 2;
                i += add;
            }
        }
        printf("%lld\n", cur+1);
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
