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
const int maxn = 5e3 + 7;
const int maxm = 1e6 + 7;
const int MOD = 1e9 + 7;

struct trie {
    struct node {
        int val = 0;
        int chd[26] = {};
    };

    node tree[maxm];
    int id;
    trie() {
        id = 1;
    }

    void insert(string &s, int idx=0, int i=1) {
        if (idx == s.size()) {
            tree[i].val++;
            return;
        }
        if (!tree[i].chd[s[idx]-'a'])
            tree[i].chd[s[idx]-'a'] = ++id;
        int nxt = tree[i].chd[s[idx]-'a'];
        insert(s, idx+1, nxt);
    }
}trie;

int n,k;
char s[maxn] = {};
char tmp[maxm] = {};
string words[maxm];
int dp[maxn] = {};

int32_t main() {
    int i,j;

    scanf("%s", s+1);
    n = strlen(s+1);
    cin >> k;
    for (int i=0; i<k; i++) {
        scanf("%s", tmp);
        words[i] = tmp;
    }

    for (int i=0; i<k; i++) {
        trie.insert(words[i]);
    }

    dp[0] = 1;
    for (int i=0; i<n; i++) {
        int now = 1;
        for (j=i+1; j<=n; j++) {
            now = trie.tree[now].chd[s[j]-'a'];
            if (!now)
                break;
            dp[j] += dp[i] * trie.tree[now].val % MOD;
            dp[j] %= MOD;
        }
    }

    // for (int i=1; i<=n; i++) {
    //     printf("%lld ", dp[i]);
    // }
    // printf("\n");
    printf("%lld\n", dp[n]);

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
