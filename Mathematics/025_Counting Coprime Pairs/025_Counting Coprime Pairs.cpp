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

vector<int> prm;
int cnt[maxn] = {};

void prepare() {
    prm.PB(2);
    for (int i=3; i<=1000000; i++) {
        bool flag = false;
        for (int j=0; prm[j] * prm[j] <= i; j++) {
            if (i % prm[j] == 0) {
                flag = true;
                break;
            }
        }
        if (!flag)
            prm.PB(i);
    }
}

void decomp(int x) {
    for (int i=0; prm[i] * prm[i] <= x; i++) {
        while (x % prm[i] == 0) {
            cnt[prm[i]] ++;
            x /= prm[i];
        }
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int n;

    cin >> n;
    int tt = n * (n-1) / 2;

    list<int> keep;
    for (int i=1; i<=n; i++) {
        int x;
        scanf("%lld", &x);
        keep.PB(x);
    }

    int cut = 0;
    for (auto &it : prm) {
        // vector<list<int>::iterator> kicked;
        for (auto cur = keep.begin(); cur != keep.end(); ) {
            if (*cur % it == 0) {
                cut += cnt[it];
                decomp(*cur);
                auto tmp = ++cur;
                keep.erase(tmp);
            } else {
                ++cur;
            }
        }
    }

    int ans = tt - cut;
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
