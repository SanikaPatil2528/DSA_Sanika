class Solution {
public:
    int addDigits(int num) {
        while(num/10!=0)
        {
            int check=num;
            int sum=0;
            while(check)
            {
                sum=sum+(check%10);
                check=check/10;
            }
            num=sum;
        }
        return num;
    }
};