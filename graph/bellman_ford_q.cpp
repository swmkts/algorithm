#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000000

const int MAX_E = 100;
const int MAX_V = 100;

struct edge {
    int from;
    int to;
    int cost;
};

int d[MAX_V];
int V, E;

edge es[MAX_E];

void bfs(int s){
    for (int i = 0; i < V; i++) {
        d[i] = INF;
    }
    es[s].from = 0;
    d[s] = 0; // distance from start to start
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        // cout << "u: " << u << endl;
        Q.pop();
        bool update = false;
        for (int i = 0; i < E; i++) {
            edge e = es[i];
            if (e.from == u) {
                if (d[e.to] > d[e.from] + e.cost) {
                    d[e.to] = d[e.from] + e.cost;
                }
                Q.push(i);
                update = true;
                // cout << i << endl;
            }
        }
        if (!update) break;
    }
}

int main(){
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++){
        int f, t, c;
        scanf("%d %d %d", &f, &t, &c);
        edge e = {f, t, c};
        es[i] = e;
    }
    bfs(0);
    for (int i = 0; i < V; i++){
        printf("%d: %d\n", i, d[i]);
    }
}