#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int src , dest , weight;
};

class UnionFind{
    private:
        vector<int> parent , rank ;

    public:
        UnionFind(int n){
            parent.resize(n);
            rank.resize(n , 0);
            for (int i = 0; i < n; i++)
            {
                parent[i] = i ;
            }
        }

        int find(int x){
            if(parent[x]!=x) parent[x]=find(parent[x]);
            return parent[x];
        }

        void unite(int x,int y){
            int rootX = find(x);
            int rootY = find(y);

            if(rootX == rootY) return ;

            if(rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } 
            else {
                parent[rootY] = rootX;
                if(rank[rootX] == rank[rootY]) {
                    rank[rootX]++;
                }
            } 
        }
};

bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int kruskalMST(vector<Edge>& edges, int n) {
    // 1. 按權重排序所有邊
    sort(edges.begin(), edges.end(), compareEdges);
    
    // 2. 初始化並查集
    UnionFind uf(n);
    int mstWeight = 0;  // MST總權重
    int edgeCount = 0;  // 已加入的邊數量
    
    // 3. 遍歷每條邊
    for (Edge& edge : edges) {
        // 檢查是否已經有n-1條邊（MST完成）
        if (edgeCount == n - 1) break;
        
        int srcRoot = uf.find(edge.src);
        int destRoot = uf.find(edge.dest);
        
        // 檢查加入此邊是否會形成迴路
        if (srcRoot != destRoot) {
            // 不會形成迴路，加入此邊
            mstWeight += edge.weight;
            uf.unite(edge.src, edge.dest);
            edgeCount++;
        }
    }
    
    return mstWeight;
}


int main() {
    int n, m;  // n: 頂點數量, m: 邊數量
    cin >> n >> m;
    
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    
    int totalWeight = kruskalMST(edges, n);
    cout << "The cost of minimum spanning tree: " << totalWeight << endl;
    
    return 0;
}