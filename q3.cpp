/*
  Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

  Each letter in the magazine string can only be used once in your ransom note.
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hashR[26] = {0};
        int hashM[26]={0};
            int r = ransomNote.length();
            int m = magazine.length();
            for(int i=0;i<r;i++){
                hashR[ransomNote[i]-'a']++;
            }
            for(int i=0;i<m;i++){
                hashM[magazine[i]-'a']++;
            }
	    for(int i=0;i<26;i++){
	        cout<<"hashR["<<char(i+97)<<"]: "<<hashR[i]<<"\t"<<"hashM["<<char(i+97)<<"]: "<<hashM[i]<<endl;
	    }
            for(int i=0;i<26;i++){    
                if(hashR[i]>hashM[i])
                    return false;
            }
        return true;
    }
};
