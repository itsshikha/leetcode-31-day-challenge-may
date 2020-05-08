/*
  Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]={0}, ind[26];
        memset(ind,-1,26);
        for(int i=0; i<s.size(); i++){
            if(freq[s[i]-'a']){
                freq[s[i]-'a']++;
                continue;
            }
            freq[s[i]-'a']++;
            ind[s[i]-'a'] = i;
        }
        int res = INT_MAX;
        for(int i=0; i<26; i++){
            if(freq[i]==1)
                res = min(res,ind[i]);
        }
        if(res==INT_MAX)
            return -1;
        return res;
    }
};
