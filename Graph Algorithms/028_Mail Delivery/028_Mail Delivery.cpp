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
const int maxn = 1e5 + 7;

unordered_map<int,int> G[maxn];

vector<int> keep;
void dfs(int x) {
    // printf(">>> %lld\n", x);
    //for (auto it=begin(G[x]); it!=end(G[x]); ) {
    auto it = begin(G[x]);
    while(it = begin(G[x]), it != end(G[x])) {
        int y = it->first;
        // if (!G[x][y])
        //     continue;
        // it++;
        G[x].erase(y);
        G[y].erase(x);
        dfs(y);
    }
    keep.push_back(x);
}


main() {
    int i,j;
    int n,m;

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a,b;
        scanf("%lld %lld", &a, &b);
        G[a][b]++;
        G[b][a]++;
    }
    // printf("YEE\n");

    vector<int> odd;
    for (int i=1; i<=n; i++) {
        if (SZ(G[i]) % 2 == 1) {
            odd.PB(i);
        }
    }

    if (odd.empty()) {
        dfs(1);
        if (SZ(keep) != m+1) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    else  {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    for (auto it: keep)
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
