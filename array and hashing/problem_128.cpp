// Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/

// Approac 1: Using linear search
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    bool search(vector<int>&nums, int cur, int n) {
        for(int i = 0;i < n;i++) {
            if(nums[i] == cur) {
                return true;
            }
        }

        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int lcs = 1;
        int n = nums.size();

        for(int i = 0;i < n; i++) {
            int cur = nums[i];
            int len = 1;

            while(search(nums,cur+1,n)) {
                len++;
                cur = cur + 1;
            }

            lcs = max(lcs, len);
        }

        return lcs;
    }
};

// Approach 2: Using sorting and binary search
// Time Complexity: O(nlogn * logn)
// Space Complexity: O(1)

class Solution {
public:
    bool search(vector<int>&nums, int cur, int n) {
        int low = 0, high = n-1;

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == cur) {
                return true;
            } else if(nums[mid] > cur) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int lcs = 1;
        int n = nums.size();

        for(int i = 0;i < n; i++) {
            int cur = nums[i];
            int len = 1;

            while(search(nums,cur+1,n)) {
                len++;
                cur = cur + 1;
            }

            lcs = max(lcs, len);
        }

        return lcs;
    }
};

// Approach 3: Using hashing
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) {
            return 0;
        }

        unordered_set<int>seen(begin(nums), end(nums));
        int lcs = 1;

        for(auto it : seen) {
            if(seen.find(it-1) == seen.end()) {
                int len = 1;
                int cur = it;

                while(seen.find(cur+1) != seen.end()) {
                    len++;
                    cur = cur+1;
                }


                lcs = max(lcs,len);
            }
        }

        return lcs;
    }
};