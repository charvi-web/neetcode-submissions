class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash(256,0);
        int cnt=0;
        for(auto it : t)
        {
            hash[it]++;
        }
        int l=0;
        int minlen=INT_MAX;
        int startindex=-1;
        int n = s.size();
        for(int r=0;r<n;r++)
        {
            if (hash[s[r]]>0) cnt++;
            hash[s[r]]--;
            while(cnt==t.size())
            {
                if (r-l+1<minlen)
                {
                    minlen=r-l+1;
                    startindex=l;
                }
                hash[s[l]]++;
                if (hash[s[l]]>0) cnt--;
                l++;
            }
        }
        return startindex==-1?"":s.substr(startindex,minlen);
    }
};
