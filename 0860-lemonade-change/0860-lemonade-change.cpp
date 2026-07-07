class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0,tens=0,twenties=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5) fives++;
            else if(bills[i]==10) tens++;
            else twenties++;

            if(bills[i]==10){
                if(fives==0) return false;
                else fives--;
            }
            if(bills[i]==20){
                if(tens>0 && fives>0){
                    tens--;
                    fives--;
                }
                else if(tens==0 && fives>=3) fives-=3;
                else return false;
            }
        }
        return true;
    }
};