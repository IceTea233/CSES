#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 1e15
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

struct edge {
    int des;
    LLI val;
};
bool operator<( edge a, edge b) {
    return a.val > b.val;
}

vector<edge> adj1[100007];
vector<edge> adj2[100007];
LLI d1[100007] = {};
LLI d2[100007] = {};
int n,m;

void dijkstra( vector<edge> g[], int src, LLI d[]) {
    bool v[100007] = {};
    for( int i=1; i<=n; i++) {
        d[i] = ULTRA;
    }

    priority_queue<edge> pq;
    d[src] = 0;
    pq.push( { src, 0});
    while( !pq.empty()) {
        edge now = pq.top();
        pq.pop();
        if( v[now.des])
            continue;
        v[now.des] = 1;
        for( auto next: g[now.des]) {
            LLI n_d = d[now.des] +  next.val;
            if( n_d < d[next.des]) {
                if( v[next.des])
                    exit(-1);
                d[next.des] = n_d;
                pq.push( { next.des, n_d});
            }
        }
    }
}

int main() {

    int i,j;

    cin >> n >> m;
    for( i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj1[a].push_back( { b, c});
        adj2[b].push_back( { a, c});
    }

    dijkstra( adj1, 1, d1);
    dijkstra( adj2, n, d2);
    LLI ans = d1[n];
    for( i=1; i<=n; i++) {
        for( auto it:adj1[i] ) {
            int p1 = i;
            int p2 = it.des;

            ans = min( ans, d1[p1] + d2[p2] + it.val / 2);
        }
    }
    cout << ans << "\n";

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
