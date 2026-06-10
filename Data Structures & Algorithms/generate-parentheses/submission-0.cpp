class Solution {
   public:
   void solve(vector<string>&ans,int open,int close,string curr,int n)
   {
    if (curr.size()==2*n)
    {
        ans.push_back(curr);
        return;
    }
    if (open<n)
    {
        solve(ans,open+1,close,curr+'(',n);
    }
    if (close<open)
    {
        solve(ans,open,close+1,curr+')',n);
    }
   }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(ans,0,0,"",n);
        return ans;
    }
};
