void nextPermutation(vector<int>& nums) {
        int left_of_hill;
        int to_swap_with;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                left_of_hill=i;
                break;
            }
        }
        if(left_of_hill<0){
            reverse(nums.begin(), nums.end());
            return;
        }
        else{
            for(int i=nums.size()-1; i>left_of_hill; i--){
                if(nums[i]>nums[left_of_hill]){
                    to_swap_with=i;
                    break;
                }
            }
            swap(nums[left_of_hill], nums[to_swap_with]);
            reverse(nums.begin()+left_of_hill+1, nums.end());
            return;
        }
}
