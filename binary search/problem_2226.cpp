// Problem Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

// Approach: Brute Force
// Time Complexity: O(n * max_value_in_candies)
// Space Complexity: O(1)

class Solution {
public:
  int maximumCandies(vector<int>& candies, long long k) {
    int n = candies.size();

    int total_candies = 0, max_value = 0;

    for(int &candy : candies) {
      max_value = max(max_value, candy);
      total_candies += candy;
    }

    if(candy < k) {
      return 0;
    }

    for(int candy = max_value; candy >= 1; candy--) {
      long long count = 0;

      for(int i = 0;i < n;i++) {
        count += (candies[i]/candy);
      }

      if(count >= k) {
        return candy;
      }
    }

    return 0;
  }
};

// Approach 2: Binary Search on Answer
// Time Complexity: O(n * log(max_value_in_candies))
// Space Complexity: O(1)

class Solution {
public:
  bool canDistribute(int mid, vector<int>& candies, long long k) {
    for(int i = 0;i < candies.size(); i++) {
      k -= (candies[i]/mid);
    }

    return k <= 0;
  }

  int maximumCandies(vector<int>& candies, long long k) {
    int n = candies.size();

    int total_candies = 0, max_value = 0;

    for(int &candy : candies) {
      max_value = max(max_value, candy);
      total_candies += candy;
    }

    if(candy < k) {
      return 0;
    }

    int low = 1, high = max_value;
    int result = 0;

    while(low <= high) {
      int mid = low + (high-low)/2;

      if(canDistribute(mid,candies,k)) {
        result = mid;
        low = mid+1;
      } else {
        high = mid-1;
      }
    }

    return result;
  }
};