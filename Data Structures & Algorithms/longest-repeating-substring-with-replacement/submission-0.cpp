class Solution {
   public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int n = s.size();
        int mf = 0;
        int mx = 0;
        vector<int> m(26, 0);
        for (int r = 0; r < n; r++) {
            m[s[r] - 'A']++;
            mf = max(mf, m[s[r] - 'A']);
            if ((r - l + 1) - mf > k) {
                m[s[l] - 'A']--;
                l++;
            }
            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};
