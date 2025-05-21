class Solution {
public:
  int getCount(int mid, vector<int>&bloomDay, int k) {
    int adjCount = 0;

    for(int i = 0;i < bloomDay.size();i++) {
      if(bloomDay[i] <= mid) {
        adjCount++;
      } else {
        adjCount = 0;
      }

      if(adjCount == k) {
        count++;
        adjCount = 0;
      }
    }

    return count;
  }

  int minDays(vector<int>& bloomDay, int m, int k) {
    int low = 0;
    int high = *max_element(begin(bloomDay), end(bloomDay));
    int result = -1;

    while(low <= high) {
      int mid = low + (high-low)/2;

      if(getCount(mid,bloomDay,k) >= m) {
        result = mid;
        high = mid-1;
      } else {
        low = mid+1;
      }
    }

    return result;
    
  }
};