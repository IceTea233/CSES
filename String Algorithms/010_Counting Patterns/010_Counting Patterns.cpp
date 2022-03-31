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

string p[maxn] = {};

struct AC_auto {
    int nxt[maxn][30] = {};
    int fail[maxn] = {};
    vector<int> output[maxn];
    int cnt[maxn] = {};
    int id = 0;

    int code(char c) {return c - 'a' + 1;}

    int chd(int x, int c) {
        if (!nxt[x][c])
            nxt[x][c] = ++id;
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
                // printf("x = %lld\n", x);
                que.pop();
                for (int c=1; c<=26; c++) {
                    if (nxt[x][c]) {
                        int y = nxt[x][c];
                        int z = fail[x];
                        que.push(y);

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
        for (auto &it : s) {
            de(1) printf("x = %lld\n", x);
            while (x && !nxt[x][code(it)])
                x = fail[x];
            if (nxt[x][code(it)])
                x = nxt[x][code(it)];
            cnt[x] ++;
        }
    }

    vector<int> count(int k) {
        vector<int> ret(k+1, 0);
        vector<int> keep;
        queue<int> que;
        que.push(0);
        while (que.size()) {
            int goal = que.size();
            while (goal--) {
                int x = que.front();
                keep.PB(x);
                que.pop();
                for (int c=1; c<=26; c++) {
                    if (nxt[x][c]) {
                        que.push(nxt[x][c]);
                    }
                }
            }
        }

        while (keep.size()) {
            int x = keep.back();
            de(1) printf("x = %lld, cnt(%lld) = %lld\n", x, x, cnt[x]);
            keep.PP();
            for (auto it : output[x])
                ret[it] += cnt[x];
            cnt[fail[x]] += cnt[x];
        }
        return ret;
    }
} ac;

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

    for (int i=1; i<=k; i++) {
        ac.insert(p[i], i);
    }

    ac.build_fail();
    ac.scan(s);
    de(1) {
        for (int i=1; i<=ac.id; i++) {
            printf("fail(%lld) = %lld, cnt(%lld) = %lld\n", i, ac.fail[i], i, ac.cnt[i]);
        }
    }
    vector<int> ans = ac.count(k);
    for (int i=1; i<=k; i++)
        printf("%lld\n", ans[i]);


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
