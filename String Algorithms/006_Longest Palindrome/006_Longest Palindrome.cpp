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
const int maxn = 1e6 + 7;
const int MOD = 1e9 + 7;
const int MUL = 997;

int n;
char s[maxn] = {};
int cht[257] = {};
int pre[maxn] = {};
int suf[maxn] = {};
int mul[maxn] = {};

void prepare() {
    srand(time(0));
    for (int i=0; i<256; i++)
        cht[i] = i;
    random_shuffle(cht, cht+256);
    mul[0] = 1;
    for (int i=1; i<=n; i++) {
        pre[i] = ( pre[i-1] * MUL + cht[s[i]] ) % MOD;
        mul[i] = mul[i-1] * MUL % MOD;
    }
    for (int i=n; i>=1; i--) {
        suf[i] = ( suf[i+1] * MUL + cht[s[i]] ) % MOD;
    }
}

int val1(int l, int r) {
    return (pre[r] - pre[l-1] * mul[r-l+1] % MOD + MOD) % MOD;
}
int val2(int l, int r) {
    return (suf[l] - suf[r+1] * mul[r-l+1] % MOD + MOD) % MOD;
}

bool chk1(int m, int x) {
    int l = x - m;
    int r = x + m;
    if (l >= r)
        return 1;
    return val1(l, r) == val2(l, r);
}
bool chk2(int m, int x) {
    int l = x - m;
    int r = x + m - 1;
    if (l >= r)
        return 1;
    return val1(l, r) == val2(l, r);
}

int bs(int l, int r, int x, function<bool(int, int)> chk) {
    if (l == r)
        return l;
    int m = (l + r + 1) / 2;
    if (chk(m,x))
        return bs(m, r, x, chk);
    else
        return bs(l, m-1, x, chk);
}

int32_t main() {
    int i,j;

    scanf("%s", s+1);
    n = strlen(s+1);
    prepare();
    int maxi = 0;
    int mid = 0;
    for (int i=1; i<=n; i++) {
        int q = bs(0, min(i-1, n-i), i, chk1);
        if (1 + q*2 > maxi) {
            maxi = 1 + q*2;
            mid = i;
        }
        q = bs(0, min(i-1, n-i+1), i, chk2);
        if (q*2 > maxi) {
            maxi = q*2;
            mid = i;
        }
    }

    // printf("maxi = %lld, mid = %lld\n", maxi, mid);
    string ans;
    for (int i=0; i<maxi; i++)
        ans.PB(s[mid-maxi/2+i]);
    cout << ans << "\n";

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
