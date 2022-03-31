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
const int MOD = 1e9 + 7;
const int B = 599;

struct bit {
    int arr[maxn] = {};

    void add(int x, int d) {
        while (x < maxn) {
            arr[x] = (arr[x] + d) % MOD;
            x += (x & (-x));
        }
    }
    int query(int x) {
        int ret = 0;
        while (x) {
            ret = (ret + arr[x]) % MOD;
            x -= (x & (-x));
        }
        return ret;
    }
    int sum(int l, int r) {
        return ((query(r) - query(l-1)) % MOD + MOD) % MOD;
    }
};

char s[maxn] = {};
int mul[maxn] = {};
bit bit1, bit2;

void prepare() {
    mul[0] = 1;
    for (int i=1; i<maxn; i++)
        mul[i] = mul[i-1] * B % MOD;
}

int pwr(int x, int k) {
    int ret = 1;
    while (k) {
        if (k & 1) {
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
        k >>= 1;
    }
    return ret;
}

int inv(int x) {
    return pwr(x, MOD - 2);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int n,m;

    cin >> n >> m;
    prepare();
    scanf("%s", s+1);
    for (int i=1; i<=n; i++) {
        bit1.add(i, s[i] * mul[i-1] % MOD);
        bit2.add(n-i+1, s[n-i+1] * mul[i-1] % MOD);
    }
    for (int i=1; i<=m; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int k;
            char x;
            cin >> k >> x;
            int d1 = ((x - s[k]) % MOD + MOD) * mul[k-1] % MOD;
            int d2 = ((x - s[k]) % MOD + MOD) * mul[n-k] % MOD;
            bit1.add(k, d1);
            bit2.add(k, d2);
            s[k] = x;
        } else if (cmd == 2) {
            int a, b;
            cin >> a >> b;
            int sum1 = bit1.sum(a, b) * inv(mul[a - 1]) % MOD;
            int sum2 = bit2.sum(a, b) * inv(mul[n - b]) % MOD;
            if (sum1 == sum2) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
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
