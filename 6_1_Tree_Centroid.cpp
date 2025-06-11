#include <iostream>
#include <vector>
#include <algorithm> // For std::max and std::min

using namespace std;

// Adjacency list to represent the tree
vector<vector<int>> adj;
// Array to store the size of the subtree rooted at each node
vector<int> subtree_size;
// Variables to store the minimum severance found and the corresponding centroid node ID
int min_severance = 1e9 + 7; // Initialize with a very large value to ensure any severance is smaller
int centroid_node = -1; // Initialize with an invalid node ID

// DFS function to calculate subtree sizes
// u: current node, p: parent of u
void dfs_calc_size(int u, int p) {
    subtree_size[u] = 1; // A node itself has size 1

    // Iterate over all neighbors of the current node u
    for (int v : adj[u]) {
        if (v == p) { // If v is the parent, skip it (to avoid going back up the tree)
            continue;
        }
        dfs_calc_size(v, u); // Recursively call DFS for child v
        subtree_size[u] += subtree_size[v]; // Add child's subtree size to current node's subtree size
    }
}

// DFS function to calculate severance for each node and find the centroid
// u: current node, p: parent of u, N: total number of nodes in the tree
void dfs_find_centroid(int u, int p, int N) {
    int current_max_component_size = 0; // Stores the maximum size of a component after removing u

    // Calculate maximum size among children's subtrees
    // These are components formed by removing u, and then taking each child's subtree
    for (int v : adj[u]) {
        if (v == p) { // If v is the parent, skip it
            continue;
        }
        current_max_component_size = max(current_max_component_size, subtree_size[v]);
    }

    // Calculate the size of the component connected to the parent (the "upwards" part of the tree)
    // If u is the root (p == -1), then N - subtree_size[u] will be N - N = 0. This is correct as there's no "upwards" component.
    current_max_component_size = max(current_max_component_size, N - subtree_size[u]);

    // Compare current node's severance with overall minimum severance found so far
    if (current_max_component_size < min_severance) {
        min_severance = current_max_component_size; // Update minimum severance
        centroid_node = u; // Update centroid node ID to the current node u
    } else if (current_max_component_size == min_severance) {
        // If current severance is equal to the minimum, choose the smaller node ID
        centroid_node = min(centroid_node, u);
    }

    // Recursively call DFS for children to find their severances
    for (int v : adj[u]) {
        if (v == p) { // If v is the parent, skip it
            continue;
        }
        dfs_find_centroid(v, u, N); // Call DFS for child v
    }
}

int main() {
    // Optimize C++ standard input/output streams for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // Number of nodes in the tree
    cin >> n; // Read the number of nodes

    // Resize adjacency list and subtree_size vector to accommodate N nodes (0 to N-1)
    adj.resize(n);
    subtree_size.resize(n);

    // Read N-1 edges and build the adjacency list
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v; // Read two nodes connected by an edge
        adj[u].push_back(v); // Add v to u's adjacency list
        adj[v].push_back(u); // Add u to v's adjacency list (undirected graph)
    }

    // Step 1: Calculate subtree sizes using DFS. Start from node 0 (arbitrary root), parent -1.
    dfs_calc_size(0, -1);

    // Step 2: Calculate severance for each node and find the centroid using DFS.
    // Start from node 0 (arbitrary root), parent -1.
    dfs_find_centroid(0, -1, n);

    // Output the ID of the centroid node
    cout << centroid_node << endl;

    return 0; // Program finished successfully
}
