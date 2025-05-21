// Problem Link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/

// Approach: Djikstra Algorithm
// Time Complexity: O(m*n*log(m*n))
// Space Complexity: O(m*n)

class Solution {
public:
  vector<vector<int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
  typedef pair<int,pair<int,int>>P;

  int minTimeToReach(vector<vector<int>>& moveTime) {
    int m = moveTime.size();
    int n = moveTime[0].size();

    vector<vector<int>>result(m,vector<int>(n,INT_MAX));
    priority_queue<P,vector<P>,greater<P>>pq;

    result[0][0] = 0;
    pq.push({0,{0,0}});

    while(!pq.empty()) {
      int curTime = pq.top().first;
      pair<int,int>coord = pq.top().second;
      int i = coord.first;
      int j = coord.second; 
      pq.pop();

      if(i == m-1 && j == n-1) {
        return curTime;
      }

      for(auto &dir : directions) {
        int i_ = i + dir[0];
        int j_ = j + dir[1];

        if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
          int cost = (i_ + j_) % 2 == 0 ? 2 : 1;
          int waitTime = max(moveTime[i_][j_] - curTime, 0);
          int arrTime = waitTime + curTime + cost;

          if(result[i_][j_] > arrTime) {
            result[i_][j_] = arrTime;
            pq.push({arrTime, {i_,j_}});
          }
        }
      }
    }

    return -1;
  }
};