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
const int maxn = 1e6 + 7;

bool win[maxn] = {};
int gval[maxn] = {};

int mex(set<int> &st) {
    auto it = st.begin();
    for (int i=0; i<st.size(); i++, it++) {
        if (*it != i)
            return i;
    }
    return st.size();
}

void prepare() {
    for (int i=3; i<=1222; i++) {
        set<int> st;
        for (int j=1; j < i - j; j++) {
            int nim = gval[j] ^ gval[i-j];
            st.insert(nim);
        }
        gval[i] = mex(st);
        // if (!gval[i])
        //     printf("%lld\n", i);
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    prepare();
    while (t--) {
        int n;
        cin >> n;
        if (n <= 1222) {
            if (gval[n])
                printf("first\n");
            else
                printf("second\n");
        } else {
            printf("first\n");
        }
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
