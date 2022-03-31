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
char s[maxn];
int mul[maxn] = {};
int cht[maxn] = {};

void prepare() {
    mul[0] = 1;
    for (int i=1; i<=n; i++) {
        mul[i] = mul[i-1] * MUL % MOD;
    }
    srand(time(0));
    for (int i=0; i<256; i++) {
        cht[i] = i;
    }
    random_shuffle(cht, cht+256);
}

int32_t main() {
    int i,j;

    scanf("%s", s+1);
    n = strlen(s+1);
    prepare();
    int key1 = 0;
    int key2 = 0;
    vector<int> ans;
    for (int i=1; i<n; i++) {
        key1 = ( key1 * MUL + cht[s[i]] ) % MOD;
        key2 = ( key2 + cht[s[n-i+1]] * mul[i-1] ) % MOD;
        // printf(">>> %lld %lld\n", key1, key2);
        if (key1 == key2)
            ans.PB(i);
    }
    for (auto it: ans) {
        printf("%lld ", it);
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
