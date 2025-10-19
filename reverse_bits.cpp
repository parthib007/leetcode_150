class Solution {
public:
    int reverseBits(int n) {
        int ans= 0;
        for(int i=0;i<32;i++){
            ans <<= 1; // make a bit for the next bit
            ans |= (n&1); // take the ith bit 
            n >>= 1;
        }
        return ans;
    }
};
