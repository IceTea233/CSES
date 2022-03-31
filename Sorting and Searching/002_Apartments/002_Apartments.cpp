#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

int a[200007] = {};
int b[200007] = {};

int main() {

    int i,j;
    int n,m,k;

    scanf("%d %d %d", &n, &m, &k);
    for( i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for( i=0; i<m; i++) {
        scanf("%d", &b[i]);
    }
    sort( a, a+n);
    sort( b, b+m);

    int ans = 0;
    for( i=0, j=0; i<n && j<m; i++) {
        if( a[i] + k < b[j])
            continue;
        for( ; j < m && a[i] - k > b[j]; j++);
        if( j < m && a[i]-k <= b[j] && b[j] <= a[i]+k) {
            de(1) printf("( %d, %d)\n", a[i], b[j]);
            ans++;
            j++;
        }
    }

    printf("%d\n", ans);


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
