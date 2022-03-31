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
char s[maxn*2] = {};
int pre[maxn*2] = {};
int mul[maxn*2] = {};
int cht[257] = {};

void prepare() {
    srand(time(0));
    for (int i=0; i<256; i++)
        cht[i] = i;
    random_shuffle(cht, cht+256);

    mul[0] = 1;

    for (int i=1; i<=n*2; i++) {
        pre[i] = ( pre[i-1] * MUL % MOD + cht[s[i]] ) % MOD;
        mul[i] = mul[i-1] * MUL % MOD;
    }
}

int val(int l, int r) {
    return (pre[r] - pre[l-1] * mul[r-l+1] % MOD + MOD) % MOD;
}

int head = 1;
bool chk(int m, int x) {
    return val(head, head+m-1) != val(x, x+m-1);
}

int bs(int l, int r, int x) {
    if (l == r)
        return l;
    int m = (l+r) / 2;
    if (chk(m, x))
        return bs(l, m, x);
    else
        return bs(m+1, r, x);
}

int32_t main() {
    int i,j;

    scanf("%s", s+1);
    n = strlen(s+1);
    for (int i=1; i<=n; i++)
        s[n+i] = s[i];
    prepare();
    
    for (int i=1; i<=n; i++) {
        int len = bs(1, n+1, i);
        if (s[i+len-1] < s[head+len-1])
            head = i;
    }

    string ans;
    for (int i=0; i<n; i++)
        ans.PB(s[head+i]);
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
