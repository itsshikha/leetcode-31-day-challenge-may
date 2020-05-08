/*
  Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.
*/

class Solution {
public:
    int findComplement(int num) {
        if(num==0)
            return 1;
        int ptr = 31;
        while(!(num&(1<<ptr)))
            ptr--;
        for(ptr; ptr>=0; ptr--){
            num = num^(1<<ptr);
        }
        return num;
    }
};
