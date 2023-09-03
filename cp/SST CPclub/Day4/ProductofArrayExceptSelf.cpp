// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        vector<int> prenums(n);
        vector<int> suffnums(n);
        prenums[0]=nums[0];
        suffnums[n-1]=nums[n-1];
        for(int i =1;i<n-1;i++)
        {
            prenums[i]=prenums[i-1]*nums[i];
            suffnums[n-1-i]=nums[n-1-i]*suffnums[n-i];
        }
        prenums[n-1]=prenums[n-2]*nums[n-1];
        suffnums[0]=suffnums[1]*nums[0];
        nums[0]=suffnums[1];
        for(int i=1;i<n-1;i++)
            nums[i]=prenums[i-1]*suffnums[i+1];
        nums[n-1]=prenums[n-2];
        // if(count>1)
        //     prod=0;
        // for(int i=0;i<nums.size();i++)
        //     if(count==0)
        //         nums[i]=prod/nums[i];
        //     else
        //         if(nums[i]!=0)
        //             nums[i]=0;
        //         else
        //             nums[i]=prod;
        return nums;
    }
};
