class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        long fnval=0,maxfnv=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            fnval+=(i*nums[i]);
        }
        maxfnv=fnval;
        for(int las=n-1;las>0;las--){
            fnval=fnval-(nums[las]*(n-1))+(sum-nums[las]);
            if(fnval>maxfnv){
                maxfnv=fnval;
            }
        }
        return (int)maxfnv;
    }
};
