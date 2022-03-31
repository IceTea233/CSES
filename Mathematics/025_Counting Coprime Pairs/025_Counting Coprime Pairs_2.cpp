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
const int maxm = 1e6 + 7;

vector<int> prm;
int cnt[maxm] = {};

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

vector<int> decomp(int x) {
    vector<int> keep;
    for (int i=0; prm[i] * prm[i] <= x; i++) {
        if (x % prm[i] == 0) {
            keep.PB(prm[i]);
            while (x % prm[i] == 0) {
                x /= prm[i];
            }
        }
    }
    if (x > 1)
        keep.PB(x);
    return keep;
}

int add = 0;
void cal(vector<int> &divi, int idx, int num, int cur = 1) {
    if (idx == divi.size()) {
        if (num % 2 == 1)
            add -= cnt[cur];
        else
            add += cnt[cur];
        return;
    }

    cal(divi, idx+1, num, cur);
    cal(divi, idx+1, num+1, cur*divi[idx]);
}

void join(vector<int> &divi, int idx, int cur = 1) {
    if (idx == divi.size()) {
        cnt[cur]++;
        return;
    }

    join(divi, idx+1, cur);
    join(divi, idx+1, cur*divi[idx]);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int n;

    cin >> n;
    prepare();
    int tt = n * (n-1) / 2;

    vector<int> keep;
    for (int i=1; i<=n; i++) {
        int x;
        scanf("%lld", &x);
        keep.PB(x);
    }

    int ans = 0;
    for (int i=0; i<keep.size(); i++) {
        vector<int> divi = decomp(keep[i]);
        add = 0;
        cal(divi, 0, 0);
        ans += add;
        join(divi, 0);
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
