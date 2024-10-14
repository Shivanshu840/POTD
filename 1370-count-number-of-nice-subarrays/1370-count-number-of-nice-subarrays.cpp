class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int prevcount = 0;
        int oddcount = 0;
        int res = 0;

        while (j < nums.size()) {

            if (nums[j] % 2 != 0) {
                oddcount++;
                prevcount = 0;
            }

            while (oddcount == k) {
                prevcount++;

                if (nums[i] % 2 == 1) {
                    oddcount--;
                }
                i++;
            }

            res += prevcount;
            j++;
        }

        return res;
    }
};