class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n=arr.size();
        int start=0;
        int sum=0;
        int end=0;
        while(end<=n){
            if(sum<target){
                if(end==n){
                    break;
                }
                sum+=arr[end];
                end++;
            }
            if(sum>target){
                sum-=arr[start];
                start++;
            }
            if(sum==target){
                return {start+1,end};
            }
        }
        return{-1};
    }
};

