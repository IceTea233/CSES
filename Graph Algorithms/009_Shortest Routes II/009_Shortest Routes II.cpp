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
bool operator< ( edge a, edge b) {
    return a.val > b.val;
}

int n,m,q;
LLI d[507][507] = {};
bool cal[507][507] = {};
vector<edge> adj[507];

void dijkstra( int src) {
    bool v[507] = {};
    for( int i=1; i<=n; i++) {
        cal[src][i] = 1;
        cal[i][src] = 1;
    }

    priority_queue<edge> pq;
    pq.push( { src, d[src][src]});
    while( !pq.empty()) {
        edge now = pq.top();
        pq.pop();
        if( v[now.des])
            continue;
        v[now.des] = 1;
        for( auto next:adj[now.des]) {
            if( v[next.des])
                continue;
            if( d[src][now.des] + next.val <= d[src][next.des]) {
                d[src][next.des] = d[src][now.des] + next.val;
                pq.push( { next.des, d[src][next.des]});
            }
        }
    }
    for( int i=1; i<=n; i++) {
        d[i][src] = d[src][i];
    }
}

int main() {

    int i,j;

    cin >> n >> m >> q;
    for( i=1; i<=m; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back( { b, c});
        adj[b].push_back( { a, c});
    }
    for( i=1; i<=n; i++) {
        for( j=1; j<=n; j++) {
            if( i != j)
                d[i][j] = ULTRA;
        }
    }

    while(q--) {
        int a,b;
        scanf("%d %d", &a, &b);
        if( !cal[a][b])
            dijkstra(a);
        LLI ans = d[a][b];
        if( ans == ULTRA)
            printf("-1\n");
        else
            printf("%lld\n", ans);
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
