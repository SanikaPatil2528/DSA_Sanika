class Solution {
private:
    vector<int>getDigits(int num){
        vector<int>temp;
        while(num){
            int d=num%10;
            temp.push_back(d);
            num=num/10;
        }
        return temp;
    }
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int num:nums){
            vector<int>temp=getDigits(num);
            ans.insert(ans.end(),temp.rbegin(),temp.rend());
        }
        return ans;
    }
};