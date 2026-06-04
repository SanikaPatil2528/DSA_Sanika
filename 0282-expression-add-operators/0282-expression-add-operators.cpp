class Solution {
private:
    void dfs(string num,int target,int start,long long curr_val,long long last_operand,string expression,vector<string>&res){
        if(start==num.size()){
            if(curr_val==target) res.push_back(expression);
            return ;
        }

        // loop through all substrings starting from 'start' index
        for(int i=start;i<num.size();i++){
            // skip leading zeros in numbers
            if(i>start && num[start]=='0') return;
            // get current number
            string curr_num=num.substr(start,i-start+1);
            long long curr_num_val=stoll(curr_num);

            // if we are at first number, just start the expression
            if(start==0) dfs(num,target,i+1,curr_num_val,curr_num_val,curr_num,res);
            else{
                // add curr num with '+'
                dfs(num,target,i+1,curr_val+curr_num_val,curr_num_val,expression+"+"+curr_num,res);
                // add curr num with '-'
                dfs(num,target,i+1,curr_val-curr_num_val,-1*curr_num_val,expression+"-"+curr_num,res);
                // add curr num with '*'
                // * has higher precedence
                dfs(num,target,i+1,curr_val-last_operand+last_operand*curr_num_val,last_operand*curr_num_val,expression+"*"+curr_num,res);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        dfs(num,target,0,0,0,"",ans);
        return ans;
    }
};