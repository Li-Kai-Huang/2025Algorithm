#include <iostream> // 引入標準輸入輸出庫
#include <vector>   // 引入向量庫，用於儲存圖的鄰接表和節點顏色
#include <queue>    // 引入佇列庫，用於 BFS 遍歷

// 使用標準命名空間，方便程式碼撰寫
using namespace std;

// 判斷給定圖是否為二分圖的函數
// adj: 圖的鄰接表，adj[i] 儲存了節點 i 的所有鄰居
// colors: 儲存每個節點的顏色（隊伍），0 代表未著色，1 和 -1 代表兩種不同的隊伍
// start_node: 當前 BFS 遍歷的起始節點
// N: 總節點數
bool isBipartite(const vector<vector<int>>& adj, vector<int>& colors, int start_node, int N) {
    queue<int> q; // 創建一個佇列用於 BFS

    q.push(start_node); // 將起始節點加入佇列
    colors[start_node] = 1; // 為起始節點著色為隊伍 1

    while (!q.empty()) { // 當佇列不為空時，繼續遍歷
        int u = q.front(); // 取出佇列頭部的節點
        q.pop();           // 將節點從佇列中移除

        // 遍歷當前節點 u 的所有鄰居
        for (int v : adj[u]) {
            if (colors[v] == 0) { // 如果鄰居節點 v 還沒有著色
                colors[v] = -colors[u]; // 將 v 著色為與 u 相反的隊伍
                q.push(v);             // 將 v 加入佇列，以便後續遍歷其鄰居
            } else if (colors[v] == colors[u]) {
                // 如果鄰居節點 v 已經著色，並且與當前節點 u 屬於同一隊伍
                // 這表示存在不喜歡的兩人被分到同一隊，因此圖不是二分圖
                return false; // 返回 false，表示無法順利舉辦
            }
        }
    }
    return true; // BFS 遍歷完成，沒有發現任何衝突，表示圖是二分圖
}

int main() {
    // 優化 C++ 標準輸入輸出流，加快程式執行速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; // n: 參賽者人數，m: 限制數量
    cin >> n >> m; // 讀取 n 和 m

    // 創建鄰接表來表示圖
    // 由於節點編號從 1 到 n，所以向量大小設為 n+1
    vector<vector<int>> adj(n + 1);

    // 讀取 m 個限制
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y; // 讀取不喜歡配對的兩個人 x 和 y
        // 由於 x 不喜歡 y，y 也不喜歡 x，所以是雙向關係
        adj[x].push_back(y); // 將 y 加入 x 的鄰居列表
        adj[y].push_back(x); // 將 x 加入 y 的鄰居列表
    }

    // 創建顏色向量，用於儲存每個節點的隊伍
    // 初始所有節點都未著色（0）
    vector<int> colors(n + 1, 0);

    bool possible = true; // 標誌變數，表示比賽是否可以順利舉辦，預設為 true

    // 遍歷所有節點，因為圖可能不連通
    // 對於每個未著色的節點，都嘗試進行 BFS 著色
    for (int i = 1; i <= n; ++i) {
        if (colors[i] == 0) { // 如果節點 i 還沒有被著色
            // 調用 isBipartite 函數檢查以節點 i 為起點的連通分量是否為二分圖
            if (!isBipartite(adj, colors, i, n)) {
                possible = false; // 如果發現不是二分圖，則設置標誌為 false
                break;            // 提前結束循環，因為已經確定無法舉辦
            }
        }
    }

    // 根據 possible 標誌輸出結果
    if (possible) {
        cout << "Yappeee" << endl; // 如果可以順利舉辦
    } else {
        cout << "Bruh" << endl;     // 如果無法順利舉辦
    }

    return 0; // 程式成功結束
}
