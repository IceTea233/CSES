#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 1000000000000000LL
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

int x[400007] = {};
LLI sum_a[400007] = {};
LLI pre[400007] = {};
LLI dp[400007] = {};

int main() {

    int i,j;
    int n, a, b;

    cin >> n >> a >> b;
    for( i=1; i<=n; i++) {
        cin >> x[i];
    }
    b -= a;

    LLI sum = 0;
    for( i=1; i<=a; i++) {
        sum += x[i];
    }
    sum_a[a] = sum;
    for( i=a+1; i<=n; i++) {
        sum_a[i] = sum_a[i-1] + x[i] - x[i-a];
    }

    for( i=1; i<=n+b; i++) {
        pre[i] = pre[i-1] + x[i];
    }

    multiset< LLI, greater<LLI> > st;
    for( i=0; i<b; i++) {
        st.insert( pre[i]);
    }
    for( i=1; i<=n; i++) {
        st.insert( pre[i+b-1]);
        dp[i] = *st.begin() - pre[i-1];
        st.erase( st.find(pre[i-1]) );
    }

    LLI ans = -ULTRA;
    for( i=a; i<=n; i++) {
        ans = max( ans, sum_a[i] + dp[i+1]);
    }

    cout << ans << "\n";

    de(1) {
        printf(">>> ");
        for( i=1; i<=n+b; i++) {
            printf("%d ", dp[i]);
        }
        printf("\n");
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
