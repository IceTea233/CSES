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
const int maxn = 5e5 + 7;

struct AC_auto {
    struct node {
        int nxt[30] = {};
        int fail;
        int pre;
        vector<int> str;
        node() {
            memset(nxt, 0, sizeof(nxt));
            fail = 0;
            pre = 0;
            str.clear();
        }
    };

    int id;
    node G[maxn];
    bool v[maxn];
    AC_auto() {
        id = 0;
    }

    int chd(int x, char c) {
        if (!G[x].nxt[c])
            G[x].nxt[c] = ++id;
        return G[x].nxt[c];
    }
    void insert(string &s, int id, int cur=0, int idx=0) {
        if (idx == s.size()) {
            G[cur].str.PB(id);
            return;
        }
        insert(s, id, chd(cur, s[idx] - 'a' + 1), idx+1);
    }
    void dfs(int x=0) {
        printf("enter %lld\n", x);
        for (int c = 1; c <= 26; c++) {
            if (G[x].nxt[c] != 0) {
                dfs(G[x].nxt[c]);
            }
        }
        printf("go out of %lld\n", x);
    }
    void build_fail() {
        queue<int> que;
        que.push(0);
        while (!que.empty()) {
            int goal = que.size();
            while (goal--) {
                int x = que.front();
                que.pop();
                for (int c = 1; c <= 26; c++) {
                    if (G[x].nxt[c]) {
                        int y = G[x].nxt[c];
                        G[y].pre = x;
                        que.push(y);

                        int z = G[x].fail;
                        while (z && !G[z].nxt[c])
                            z = G[z].fail;
                        if (x && G[z].nxt[c]) {
                            G[y].fail = G[z].nxt[c];
                        }
                    }
                }
            }
        }
    }

    vector<int> travel(string &s) {
        vector<int> keep;
        int cur = 0;
        for (auto &it : s) {
            int c = it - 'a' + 1;
            while (cur && !G[cur].nxt[c]) {
                cur = G[cur].fail;
                keep.PB(cur);
            }
            if (G[cur].nxt[c]) {
                cur = G[cur].nxt[c];
                keep.PB(cur);
            }
        }
        return keep;
    }

    vector<int> lookup(vector<int> &rec) {
        vector<int> ret;
        memset(v, 0, sizeof(v));
        for (auto it : rec) {
            int cur = it;
            while (cur && !v[cur]) {
                v[cur] = true;
                for (auto it2 : G[cur].str)
                    ret.PB(it2);
                cur = G[cur].fail;
            }
        }
        return ret;
    }
} ac;

bool ans[maxn] = {};

int32_t main() {
    int i,j;
    string s;
    int k;

    cin >> s;
    cin >> k;
    vector<string> P;
    for (int i=1; i<=k; i++) {
        string p;
        cin >> p;
        P.PB(p);
    }

    for (int i=1; i<=k; i++) {
        ac.insert(P[i-1], i);
    }

    ac.build_fail();

    vector<int> rec = ac.travel(s);
    // for (auto &it : rec)
    //     printf("%lld ", it);
    // printf("\n");
    vector<int> found = ac.lookup(rec);
    for (auto &it : found)
        ans[it] = true;
    for (int i=1; i<=k; i++) {
        if (ans[i])
            printf("YES\n");
        else
            printf("NO\n");
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
