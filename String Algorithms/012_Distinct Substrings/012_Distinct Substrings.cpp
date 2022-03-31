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

vector<int> suffix_array(string s) {
    s = s + '$';
    int n = s.size();
    vector<int> c(n), p(n), c2(n);
    list<int> keep[maxn];
    for (int i=0; i<n; i++)
        keep[s[i]].PB(i);
    int rk = 0;
    for (int i=0, j=0; i<128; i++) {
        if (keep[i].size()) {
            while (keep[i].size()) {
                c[keep[i].front()] = rk;
                p[j++] = keep[i].front();
                keep[i].pop_front();
            }
            rk ++;
        }
    }
    for (int k=0; (1<<k) < n; k++) {
        for (int i=0; i<n; i++) {
            keep[c[(p[i] + (1<<k)) % n]].PB(p[i]);
        }
        for (int i=0, j=0; i<rk; i++) {
            while (keep[i].size()) {
                p[j++] = keep[i].front();
                keep[i].pop_front();
            }
        }

        for (int i=0; i<n; i++) {
            keep[c[p[i]]].PB(p[i]);
        }
        int rk2 = 0;
        for (int i=0, j=0; i<rk; i++) {
            while (keep[i].size()) {
                int x = keep[i].front();
                c2[x] = rk2;
                p[j++] = x;
                keep[i].pop_front();

                if (keep[i].empty() || c[(keep[i].front() + (1<<k)) % n] != c[(x + (1<<k)) % n])
                    rk2 ++;
            }
        }
        rk = rk2;
        c = c2;
    }
    return p;
}

vector<int> kasai(string &s, vector<int> &sa) {
    int n = s.size();
    vector<int> lcp(n+1, 0);
    vector<int> rank(n+1, 0);
    for (int i=0; i<n+1; i++)
        rank[sa[i]] = i;

    for (int i=0, k=0; i<n; i++, k = max(k-1, 0LL)) {
        int j = sa[rank[i] - 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
    }
    return lcp;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    string s;

    cin >> s;
    int n = s.size();
    vector<int> sa = suffix_array(s);
    vector<int> lcp = kasai(s, sa);
    int ans = 0;
    for (int i=1; i<=n; i++) {
        ans += (n - sa[i]) - lcp[i];
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
