// Problem Link: https://leetcode.com/problems/redundant-connection/

// Approach 1: DSU
// Time Complexity: O(n*alpha)
// Space Complexity: O(n)

class DSU {
  vector<int>parent;
  vector<int>rank;

  public:
  DSU(int n) {
    parent.resize(n+1);
    rank.resize(n+1);

    for(int i = 1;i <= n;i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if(x == parent[x]) {
      return x;
    }

    return parent[x] = find(parent[x]);
  }

  void Union(int x, int y) {
    int parent_x = find(x);
    int parent_y = find(y);

    if(parent_x == parent_y) {
      return;
    }

    if(rank[parent_x] > rank[parent_y]) {
      parent[parent_y] = parent_x;
    } else if(rank[parent_y] > rank[parent_x]) {
      parent[parent_x] = parent_y;
    } else {
      parent[parent_x] = parent_y;
      rank[parent_y]++;
    }
  }
};

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    DSU dsu(n);

    for(auto edge : edges) {
      int u = edge[0];
      int v = edge[1];

      if(dsu.find(u) == dsu.find(v)) {
        return edge;
      }

      dsu.Union(u,v);
    }

    return {};
  }
};

// Approach 2: DFS
// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
  bool dfs(int u, int v, unordered_map<int, vector<int>>& adj,vector<bool>& vis) {
    vis[u] = true;

    if (u == v) {
      return true;
    }

    for (auto& ngbr : adj[u]) {
      if(!vis[ngbr]) {
        if(dfs(ngbr, v, adj, vis)) {
          return true;
        }
      }
    }

    return false;
  }

  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    unordered_map<int, vector<int>> adj;
    vector<bool> vis(n + 1, false);

    for (auto& edge : edges) {
      int u = edge[0];
      int v = edge[1];

      if (adj.find(u) != adj.end() && adj.find(v) != adj.end() && dfs(u, v, adj, vis)) {
        return edge;
      }

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    return {};
  }
};

// Approach 3: BFS
// Time Complexity: O(n*2)
// Space Complexity: O(n)

class Solution {
public:
  bool bfs(int u, int v, unordered_map<int, vector<int>>&adj, vector<bool>&vis) {
    vis[u] = true;
    queue<int>q;
    q.push(u);

    while(!q.empty()) {
      int node = q.front();
      q.pop();

      if(node == v) {
        return true;
      }

      for(auto &ngbr : adj[node]) {
        if(!vis[ngbr]) {
          vis[ngbr] = true;
          q.push(ngbr);
        }
      }
    }

    return false;
  }

  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    unordered_map<int,vector<int>>adj;
    vector<bool>vis(n+1, false);

    for(auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];

      if(adj.find(u) != adj.end() && adj.find(v) != adj.end() && bfs(u,v,adj,vis)) {
        return edge;
      }

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    return {};
  }
};