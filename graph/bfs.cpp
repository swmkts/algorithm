#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000000
#define WHITE 0
#define GLAY 1
#define BLACK -1

const int MAX_E = 100;
const int MAX_V = 100;

struct vertex{
    vector<int> from;
    vector<int> to;
    int d;
    int color;
    int pi;
};

vertex vs[MAX_V];

int V, E;

void bfs(int s) {
    vs[s].color = GLAY;
    vs[s].d = 0;
    vs[s].pi = s;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v: vs[u].to) {
            if (vs[v].color == WHITE) {
                vs[v].color = GLAY;
                vs[v].d = vs[u].d + 1;
                vs[v].pi = u;
                Q.push(v);
            }
        }
    }
}

int main(){
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++){
        int f, t;
        scanf("%d %d", &f, &t);
        // input to vertex structure
        // Input type is Undirected Graph
        vs[f].to.push_back(t);
        vs[t].to.push_back(f);
        vs[f].from.push_back(t);
        vs[t].from.push_back(f);
        vs[f].color = WHITE;
        vs[t].color = WHITE;
        vs[f].d = INF;
        vs[t].d = INF;
        vs[f].pi = -1;
        vs[t].pi = -1;
    }
    bfs(0);
    for (int i = 0; i < V; i++) {
        cout << i << " : " << vs[i].d << endl;
    }
}