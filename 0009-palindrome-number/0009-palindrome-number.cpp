class Solution {
public:
    bool isPalindrome(int x) {
        int rev=0;
        int digit;
        int check=x;
        if (x<0) return false;
        while(x)
        {
            digit=x%10;
            x=x/10;
            if(rev>INT_MAX/10 || (rev==INT_MAX/10 && digit>7)) 
            {
                rev=0;
                break;
            }
            if(rev<INT_MIN/10 || (rev==INT_MIN/10 && digit<-8))
            {
                rev=0;
                break;
            }
            rev=rev*10+digit;
        }
        if(check==rev) return true;
        else return false;
    }
};