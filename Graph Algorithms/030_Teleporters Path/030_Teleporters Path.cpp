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

multiset<int> out[maxn];
multiset<int> in[maxn];

vector<int> ans;
void dfs(int x) {
    while(!out[x].empty()) {
        int y = *begin(out[x]);
        out[x].erase(begin(out[x]));
        dfs(y);
        ans.PB(y);
    }
}

main() {
    int i,j;
    int n, m;

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a,b;
        cin >> a >> b;
        in[b].insert(a);
        out[a].insert(b);
    }

    vector<int> s;
    vector<int> t;
    for (int i=1; i<=n; i++) {
        if (SZ(in[i]) - SZ(out[i]) == 1)
            t.PB(i);
        else if (SZ(in[i]) - SZ(out[i]) == -1)
            s.PB(i);
        else if (SZ(in[i]) != SZ(out[i])) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }

    if (SZ(s) == 1 && SZ(t) == 1) {
        dfs(s[0]);
        ans.PB(s[0]);
    } else if(SZ(s) == 0 && SZ(t) == 0) {
        dfs(1);
        ans.PB(1);
    } else {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    reverse(begin(ans), end(ans));
    if (ans.front() != 1 || ans.back() != n || SZ(ans) != m+1) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for (auto it: ans) {
        printf("%lld ", it);
    }
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
