#include<bits/stdc++.h>
#define int long long
#define PB push_back
#define PP pop_back
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if( x!=0 && MODE==x)
#define MODE 1
using namespace std;

const int maxn = 1e5+7;
int n,m;
vector<int> G[maxn*2+7];

int t[maxn*2] = {};
bool instk[maxn*2] = {};
int low[maxn*2] = {};
int scc[maxn*2] = {};
int sat[maxn*2] = {};

int inv(int x) {
    if (x <= m)
        return x + m;
    else
        return x - m;
}

int id = 0;
vector<int> stk;
vector<int> keep;
void tarjan(int x) {
    stk.PB(x);
    instk[x] = 1;
    t[x] = ++id;
    low[x] = id;
    for (auto y: G[x]) {
        if (!t[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (instk[y]) {
            low[x] = min(low[x], t[y]);
        }
    }

    if (low[x] == t[x]) {
        int now;
        do {
            now = stk.back();
            stk.PP();
            instk[now] = 0;
            scc[now] = x;
        } while (now != x);
        keep.push_back(x);
    }
}

int32_t main() {
    int i,j;

    scanf("%lld %lld", &n, &m);
    for( i=1; i<=n; i++) {
        char c1, c2;
        int num1, num2;
        char s[7];
        fgets( s, 7, stdin);
        scanf("%c %lld %c %lld", &c1, &num1, &c2, &num2);
        int u = (c1 == '+' ? num1 : inv(num1));
        int v = (c2 == '+' ? num2 : inv(num2));
        G[inv(u)].PB(v);
        G[inv(v)].PB(u);
    }

    // for (i=1; i<=m; i++) {
    //     printf("%lld  >>> ", i);
    //     for (auto it: G[i]) {
    //         printf("%lld ", it);
    //     }
    //     printf("\n");
    //
    //     printf("%lld\' >>> ", i);
    //     for (auto it: G[inv(i)]) {
    //         printf("%lld ", it);
    //     }
    //     printf("\n");
    // }

    for (int i=1; i<=m; i++) {
        if (!t[i])
            tarjan(i);
        if (!t[inv(i)])
            tarjan(inv(i));
    }

    // for (int i=1; i<=m*2; i++) {
    //     printf("%lld >>> %lld\n", i, scc[i]);
    // }

    for (int i=1; i<=m; i++) {
        if (scc[i] == scc[inv(i)]) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }

    for (auto it : keep) {
        if (!sat[ scc[it] ]) {
            sat[ scc[it] ] = 1;
            sat[ scc[inv(it)] ] = -1;
        }
    }

    for (i=1; i<=m; i++) {
        if (sat[ scc[i] ] == 1)
            printf("+ ");
        else
            printf("- ");
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
