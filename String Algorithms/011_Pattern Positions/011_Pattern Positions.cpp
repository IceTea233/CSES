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
const int maxn = 5e5 + 7;

struct AC_auto {
    int nxt[maxn][30] = {};
    int fail[maxn] = {};
    int in[maxn] = {};
    vector<int> output[maxn];
    int id = 0;

    int code(char c) {
        return c - 'a' + 1;
    }
    int chd(int x, int c) {
        if (!nxt[x][c])
            nxt[x][c] = ++ id;
        return nxt[x][c];
    }
    void insert(string &s, int num, int cur=0, int idx=0) {
        if (idx == s.size()) {
            output[cur].PB(num);
            return;
        }
        insert(s, num, chd(cur, code(s[idx])), idx + 1);
    }
    void build_fail() {
        queue<int> que;
        que.push(0);
        while (que.size()) {
            int goal = que.size();
            while (goal--) {
                int x = que.front();
                que.pop();
                for (int c=1; c<=26; c++) {
                    if (nxt[x][c]) {
                        int y = nxt[x][c];
                        que.push(y);
                        int z = fail[x];
                        while (z && !nxt[z][c])
                            z = fail[z];
                        if (x != z && nxt[z][c])
                            fail[y] = nxt[z][c];
                    }
                }
            }
        }
    }
    void scan(string &s) {
        int x = 0;
        for (int i=0; i<s.size(); i++) {
            while (x && !nxt[x][code(s[i])])
                x = fail[x];
            x = nxt[x][code(s[i])];
            if (!in[x])
                in[x] = i + 1;
            de(1) printf("x = %lld\n", x);
        }
    }
    vector<int> query(int k) {
        vector<int> ret(k+1, 0);
        queue<int> que({0});
        vector<int> keep;
        while (que.size()) {
            int goal = que.size();
            while (goal--) {
                int x = que.front();
                keep.PB(x);
                que.pop();
                for (int i=1; i<=26; i++) {
                    if (nxt[x][i])
                        que.push(nxt[x][i]);
                }
            }
        }

        while (keep.size()) {
            int x = keep.back();
            keep.PP();
            if (!in[fail[x]])
                in[fail[x]] = in[x];
            else
                in[fail[x]] = min(in[fail[x]], fail[x]);
        }

        for (int i=1; i<=id; i++) {
            for (auto it : output[i])
                ret[it] = in[i];
        }

        return ret;
    }
} ac;

string p[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    string s;

    cin >> s;
    int k;
    cin >> k;
    for (int i=1; i<=k; i++) {
        cin >> p[i];
    }

    for (int i=1; i<=k; i++)
        ac.insert(p[i], i);
    ac.build_fail();
    ac.scan(s);
    de(1) {
        for (int i=1; i<=ac.id; i++) {
            printf("in[%lld] = %lld\n", i, ac.in[i]);
        }
    }

    vector<int> ans = ac.query(k);
    for (int i=1; i<=k; i++) {
        if (ans[i])
            printf("%lld\n", ans[i] - p[i].size() + 1);
        else
            printf("-1\n");
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
