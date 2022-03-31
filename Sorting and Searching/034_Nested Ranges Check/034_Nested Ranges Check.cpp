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

struct info {
    int id;
    pii val;
};

pii r[maxn] = {};

bool cmp1(info a, info b) {
    if (a.val.F == b.val.F)
        return a.val.S > b.val.S;
    return a.val.F < b.val.F;
}
bool cmp2(info a, info b) {
    if (a.val.S == b.val.S)
        return a.val.F > b.val.F;
    return a.val.S < b.val.S;
}

int ans1[maxn] = {};
int ans2[maxn] = {};

int32_t main() {
    int i,j;
    int n;

    cin >> n;
    for (int i=1; i<=n; i++) {
        scanf("%lld %lld", &(r[i].F), &(r[i].S));
    }
    vector<info> keep;
    for (int i=1; i<=n; i++) {
        keep.PB({i, r[i]});
    }
    sort(all(keep), cmp1);
    int maxi = 0;
    for (auto it : keep) {
        if (it.val.S <= maxi)
            ans1[it.id] = 1;
        maxi = max(maxi, it.val.S);
    }

    sort(all(keep), cmp2);
    maxi = 0;
    for (auto it : keep) {
        if (it.val.F <= maxi)
            ans2[it.id] = 1;
        maxi = max(maxi, it.val.F);
    }

    for (int i=1; i<=n; i++)
        printf("%lld ", ans2[i]);
    printf("\n");

    for (int i=1; i<=n; i++)
        printf("%lld ", ans1[i]);
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
