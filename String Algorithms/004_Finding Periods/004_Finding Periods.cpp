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
int pre[maxn] = {};
int mul[maxn] = {};
int chd[257] = {};

void prepare() {
    srand(time(0));

    mul[0] = 1;
    for (int i=0; i<256; i++)
        chd[i] = i;
    random_shuffle(chd, chd+256);
    for (int i=1; i<=n; i++) {
        pre[i] = ( pre[i-1] * MUL + chd[s[i]] ) % MOD;
        mul[i] = mul[i-1] * MUL % MOD;
    }
}

int val(int l, int r) {
    return ( pre[r] - pre[l-1] * mul[r-l+1] % MOD + MOD ) % MOD;
}

int32_t main() {
    int i,j;

    scanf("%s", s+1);
    n = strlen(s+1);
    prepare();

    vector<int> ans;
    for (int i=1; i<=n; i++) {
        bool flag = 0;
        int key = val(1, i);

        for (j=1; j+i-1<=n; j+=i) {
            if (val(j, j+i-1) != key)
                flag = 1;
        }
        if (val(j, n) != val(1, n-j+1))
            flag = 1;
        if (!flag)
            ans.PB(i);
    }

    for (auto it: ans)
        printf("%lld ", it);
    printf("\n");

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
