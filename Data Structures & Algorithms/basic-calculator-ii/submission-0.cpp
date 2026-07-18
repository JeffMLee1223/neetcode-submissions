class Solution {
public:
    int calculate(string s) {
        stack<int> nums;

        int num = 0;
        char op = '+';

        for(int i = 0; i < s.size(); i++){
            char c = s[i];

            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }

            if((!isdigit(c) && c != ' ') || i == s.size()-1){
                if(op == '+'){
                    nums.push(num);
                }else if(op == '-'){
                    nums.push(-num);
                }else if(op == '*'){
                    int left =nums.top();
                    int right = num;
                    nums.pop();
                    nums.push(left * right);
                }else{
                    int left = nums.top();
                    int right = num;
                    nums.pop();
                    nums.push(left / right);
                }
                if(c == '+' || c == '-' || c == '*' || c == '/'){
                    op = c;
                }
                
                num = 0;
            }

        }

        int result = 0;
        while(!nums.empty()){
            int element = nums.top();
            nums.pop();
            result += element;
        }

        return result;
    }
};