class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int sum=0;
        unordered_map<char,int>mpp={
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        for(int i=0;i<n-1;i++){
            int curr=s[i];int next=s[i+1];
            int sign=1;
            if(curr=='I' && (next=='V' || next=='X')) sign=-1;
            if(curr=='X' && (next=='L' || next=='C')) sign=-1;
            if(curr=='C' && (next=='D' || next=='M')) sign=-1;
            sum+=(mpp[curr]*sign);
        }
        sum+=mpp[s[n-1]];
        return sum;
    }
};