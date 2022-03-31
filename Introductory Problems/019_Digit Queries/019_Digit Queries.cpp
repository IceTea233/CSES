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
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

int cnt[20] = {};
int base[20] = {};

void prepare() {
    for (int i=1, j=9; i<18; i++, j *= 10) {
        cnt[i] = i * j;
        base[i+1] = base[i] + j;
    }
}

int32_t main() {
    int i,j;
    int q;

    prepare();

    cin >> q;
    while(q--) {
        int k;
        cin >> k;
        for (i=1; i<18; i++) {
            if (k - cnt[i] < 0)
                break;
            k -= cnt[i];
        }
        int len = i;
        int num = base[i] + k / len + (k%len > 0);
        int dig = (k-1 + len) % len;
        de(1) printf("num = %lld, dig = %lld\n", num, dig);
        for (int i=0; i<(len-1)-dig; i++) {
            num /= 10;
        }
        int ans = num % 10;
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
