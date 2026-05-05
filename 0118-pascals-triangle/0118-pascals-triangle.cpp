class Solution {
private:
    vector<int> generate_row(int r){
        int prod=1;
        vector<int>res;
        res.push_back(prod);
        for(int i=1;i<r-1;i++){
            prod=prod*(r-i);
            prod=prod/i;
            res.push_back(prod);
        }
        res.push_back(1);
        return res;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if(numRows==0) return ans;
        vector<int>temp;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==1) return ans;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==2) return ans;
        for(int i=3;i<=numRows;i++){
            ans.push_back(generate_row(i));
        }
        return ans;
    }
};