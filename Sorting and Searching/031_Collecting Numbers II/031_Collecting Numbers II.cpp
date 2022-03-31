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
const int maxn = 2e5 + 7;

int x[maxn] = {};
int p[maxn] = {};

void upd(int &ans, int pos, int d) {
    if (p[pos-1] < p[pos] && p[pos-1] >= d)
        ans++;
    if (p[pos-1] >= p[pos] && p[pos-1] < d)
        ans--;
    if (p[pos] < p[pos+1] && d >= p[pos+1])
        ans++;
    if (p[pos] >= p[pos+1] && d < p[pos+1])
        ans--;
    p[pos] = d;
}

int32_t main() {
    int i,j;
    int n,m;

    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> x[i];
    for (int i=1; i<=n; i++)
        p[x[i]] = i;
    // for (int i=1; i<=n; i++)
    //     printf("%lld ", p[i]);
    // printf("\n");
    int ans = 1;
    for (int i=2; i<=n; i++) {
        if (p[i] < p[i-1])
            ans++;
    }
    // printf("%lld\n", ans);

    while(m--) {
        int a,b;
        cin >> a >> b;
        int tmp = x[a];
        upd(ans, x[a], b);
        upd(ans, x[b], a);
        swap(x[a], x[b]);

        de(1) {
            printf("x >>> ");
            for (int i=1; i<=n; i++) {
                printf("%lld ", x[i]);
            }
            printf("\n");
            printf("p >>> ");
            for (int i=1; i<=n; i++) {
                printf("%lld ", p[i]);
            }
            printf("\n");
        }
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
