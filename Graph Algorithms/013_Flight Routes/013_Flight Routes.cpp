#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

struct edge {
    int to;
    LLI val;
};
bool operator<( edge a, edge b) {
    return a.val > b.val;
}

int n,m,k;
vector<edge> adj[100007];
int v[100007] = {};
LLI d[100007] = {};
vector<LLI> ans[100007];

void Dijkstra( int src) {
    priority_queue<edge> pq;
    d[1] = 0;
    pq.push( { 1, 0});
    while( !pq.empty() && v[n] != n) {
        edge x = pq.top();
        pq.pop();
        if( v[x.to] == k)
            continue;
        d[ x.to ] = x.val;
        ans[ x.to ].push_back( d[x.to]);
        v[ x.to ]++;
        for( auto y: adj[x.to]) {
            if( v[ y.to ] == k)
                continue;
            pq.push( { y.to, d[x.to] + y.val});
        }
    }
}

int main() {

    int i,j;

    cin >> n >> m >> k;

    for( int i=1; i<=m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back( { b, c});
    }

    Dijkstra(1);
    for( auto it: ans[n]) {
        cout << it << " ";
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
