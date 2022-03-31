#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 1000000000000000LL
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

struct edge {
    int des;
    LLI val;
};
bool operator< ( edge a, edge b) {
    return a.val > b.val;
}

int n,m;
vector<edge> adj[100007];
bool v[100007] = {};
LLI d[100007] = {};

void dijkstra( int src) {
    for( int i=1; i<=n; i++) {
        d[i] = ULTRA;
    }

    priority_queue<edge> pq;
    d[src] = 0;
    pq.push( { src, d[src]});
    while( !pq.empty()) {
        edge now = pq.top();
        pq.pop();
        if( v[now.des])
            continue;
        v[now.des] = 1;
        for( auto next: adj[now.des]) {
            if( v[next.des])
                continue;
            if( d[now.des] + next.val < d[next.des]) {
                d[next.des] = d[now.des] + next.val;
                pq.push( { next.des, d[next.des]});
            }
        }
    }
}

int main() {

    int i,j;

    cin >> n >> m;
    for( i=1; i<=m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back( { b, c});
    }

    dijkstra(1);
    for( i=1; i<=n; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";

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
