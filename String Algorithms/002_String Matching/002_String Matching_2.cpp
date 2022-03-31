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

int prefix[maxn] = {};

void prepare(string &p, int m) {
    prefix[1] = 0;
    for (int i=1, j=0; i<m; i++) {
        while (j && p[i+1] != p[j+1]) {
            j = prefix[j];
        }
        if (p[i+1] == p[j+1])
            prefix[i+1] = ++j;
        else
            prefix[i+1] = j;
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;
    string s;
    string p;

    cin >> s;
    cin >> p;
    int n = s.size();
    int m = p.size();
    s = ' ' + s;
    p = ' ' + p;

    prepare(p, m);
    // for (int i=1; i<=m; i++)
    //     printf("%lld ", prefix[i]);
    // printf("\n");

    int ans = 0;
    for (int i=0, j=0; i<n; i++) {
        while (j && (j == n || s[i+1] != p[j+1])) {
            j = prefix[j];
        }
        if (s[i+1] == p[j+1]) {
            j++;
        }
        if (j == m)
            ans++;
    }

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