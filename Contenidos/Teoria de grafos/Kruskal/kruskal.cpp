#include <bits/stdc++.h>
using namespace std;

class DSU {
    int* padre;
    int* rango;
 
public:
    DSU(int n){
        padre = new int[n];
        rango = new int[n];
 
        for (int i = 0; i < n; i++) {
            padre[i] = -1;
            rango[i] = 1;
        }
    }
 
    int find(int i){
        if (padre[i] == -1)
            return i;
 
        return padre[i] = find(padre[i]);
    }
 
    void unite(int x, int y){
        int s1 = find(x);
        int s2 = find(y);
 
        if (s1 != s2) {
            if (rango[s1] < rango[s2]) {
                padre[s1] = s2;
                rango[s2] += rango[s1];
            }
            else {
                padre[s2] = s1;
                rango[s1] += rango[s2];
            }
        }
    }
};
 
class Graph {
    vector<vector<int> > edgelist;
    int V;
 
public:
    Graph(int V) { this->V = V; }
 
    void addEdge(int x, int y, int w){
        edgelist.push_back({ w, x, y });
    }
 
    void kruskals_mst(){
        sort(edgelist.begin(), edgelist.end());
 
        DSU s(V);
        int ans = 0;
        cout << "Following are the edges in the "
                "constructed MST"
             << endl;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w
                     << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans;
    }
};
 
int main(){
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
 
    // Function call
    g.kruskals_mst();
    return 0;
}
