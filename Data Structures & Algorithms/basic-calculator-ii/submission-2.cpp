class Solution {
   public:
    int calculate(string s) {
        stack<int> nums;

        int num = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {  // this will keep update number until it reach operator(number ends)
                num = num * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                // when it's not a digit, that means we came to the end of one number
                // so what we have to do us using the operator that we previously save to decide how
                // to operate this number. But we also save this current operator to decide what we
                // will do for the next number
                if (op == '+') {
                    nums.push(num);
                } else if (op == '-') {
                    nums.push(-num);
                } else if (op == '*') {
                    int left = nums.top();
                    nums.pop();
                    nums.push(left * num);
                } else {
                    int left = nums.top();
                    nums.pop();
                    nums.push(left / num);
                }
                if (op == '+' || op == '-' || op == '*' || op == '/') {
                    op = c;
                }
                num = 0;
            }
        }  // (+invisible) 3 * 100 + 5 - 20 / 4   A calculation can be view as finite part of
           // addition.
        /*

        we push 3 into stack when we reach operator * 3 will be viewed as +3 and we save operator *
        after that, we keep reading next number 100 and then we reach + that means we got a complete
        number 100 and this number need to do multiply because previous op we save is * so we pop
        stack and times it with current number and push it into stack.

        And we save + Then read number 5 until reaching (-) and add 5 (push as is into stack) and
        save -
        we read 20 and push it into stack with negative sign because we reach / (save it)
        and then we reach the last number, so we go inside loop again and previous saved operator is
        / which means we have to pop last element -20 and divide it with 4 and then push -5 back.

        */

        int result = 0;
        while (!nums.empty()) {
            int element = nums.top();
            nums.pop();
            result += element;
        }

        return result;
    }
};