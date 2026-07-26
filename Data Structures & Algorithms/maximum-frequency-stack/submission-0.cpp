class FreqStack {
   private:
    stack<int> stk;
    unordered_map<int, int> freq;
    unordered_map<int, int>::iterator it;

   public:
    FreqStack() {}

    void push(int val) {
        stk.push(val);
        freq[val]++;
    }

    int pop() {
        int highestFreq = 0;
        for (it = freq.begin(); it != freq.end(); it++) {
            highestFreq = max(highestFreq, it->second);
        }

        stack<int> temp;
        int answer = -1;

        while (!stk.empty()) {
            int current = stk.top();
            stk.pop();
            if (freq[current] == highestFreq) {
                answer = current;
                break;
            }

            temp.push(current);
        }
        while (!temp.empty()) {
            stk.push(temp.top());
            temp.pop();
        }
        freq[answer]--;
        

        return answer;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */