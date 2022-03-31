#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

char s[1000007] = {};
int cht[107] = {};

int main() {

    int i,j;

    scanf("%s", s);
    for( i=0; s[i]; i++)
        cht[ s[i] - 'A' ]++;

    string s1;
    string s2;

    int cnt = 0;
    for( i=0; i<26; i++) {
        if( cht[i] % 2) {
            cnt++;
            for( j=0; j<cht[i]; j++) {
                s1.push_back( i + 'A');
            }
        }
        else {
            for( j=0; j<cht[i] / 2; j++) {
                s2.push_back( i + 'A');
            }
        }
    }

    if( cnt >= 2) {
        printf("NO SOLUTION\n");
    }
    else {
        string ans = s2 + s1;
        reverse( begin(s2), end(s2));
        ans = ans + s2;
        cout << ans << "\n";
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
