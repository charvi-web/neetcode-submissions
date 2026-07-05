class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        sort(numbers.begin(),numbers.end());
        int n = numbers.size();
        int i=0;
        int j=n-1;
        while(i<j)
        {
            int summ = numbers[i]+numbers[j];
            if (summ==target)
            {
                return {i+1,j+1};
            }
            else if (summ<target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return {};
    }
};
