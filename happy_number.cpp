class Solution {
public:
    int f(int n){
        int ans = 0;
        while(n>0){
            int digit = n%10;
            ans += digit*digit;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        // flyod cycle detection algorithm
        int slow = n;
        int fast = f(n);
        // continue looping until fast comes to 1 or slow becomes equal to fast
        while(fast!=1 && slow!=fast){
            slow = f(slow); // move by 1 step
            fast = f(f(fast)); // move by 2 step
        }
        return fast==1;
    }
};
