// Problem Link: https://leetcode.com/problems/minimum-time-to-repair-cars/

// Approach: Binary Search
// Time Complexity: 
// Space Complexity: O(1)

class Solution {
public:
  bool canRepair(vector<int>&ranks, long long mid, int cars) {
    long long count = 0;

    for(int i = 0;i < ranks.size(); i++) {
      count = count + sqrt(mid/ranks[i]);
    }

    return count >= cars;
  }

  long long repairCars(vector<int>& ranks, int cars) {
    int n = ranks.size();
    int maxRank = *max_element(begin(ranks), end(ranks));

    long long low = 1;
    long long high = (long long) maxRank * cars * cars;
    long long result = -1;

    while(low <= high) {
      long long mid = low + (high - low) / 2;

      if(canRepair(ranks, mid, cars)) {
        result = mid;
        high = mid-1;
      } else {
        low = mid+1;
      }
    }

    return result;
  }
};