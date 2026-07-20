class Solution {
   private:
    stack<int> nums;
    stack<char> ops;

   public:
    int precedence(char op) {
        if (op == '+' || op == '-') {
            return 1;
        }

        if (op == '*' || op == '/') {
            return 2;
        }
        return 0;
    }
    void applyOperation(stack<int>& nums, stack<char>& ops) {
        char op = ops.top();
        ops.pop();

        int right = nums.top();
        nums.pop();

        int left = nums.top();
        nums.pop();

        int result;

        if (op == '+') {
            result = right + left;
        } else if (op == '-') {
            result = left - right;
        } else if (op == '*') {
            result = left * right;
        } else {
            result = left / right;
        }

        nums.push(result);
    }
    int calculate(string s) {
        int i = 0;

        while (i < s.size()) {
            if (s[i] == ' ') {
                i++;
                continue;
            } else if (isdigit(s[i])) {
                int num = 0;

                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                nums.push(num);
            } else if (s[i] == '(') {
                ops.push('(');
                i++;
            } else if (s[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    applyOperation(nums, ops);
                }
                ops.pop();
                i++;
            } else {
                char currentOp = s[i];
                while (!ops.empty() && ops.top() != '(' &&
                       precedence(ops.top()) >= precedence(currentOp)) {
                    applyOperation(nums, ops);
                }
                ops.push(currentOp);
                i++;
            }
        }

        while(!ops.empty()){
            applyOperation(nums, ops);
        }
        return nums.top();
    }
};
