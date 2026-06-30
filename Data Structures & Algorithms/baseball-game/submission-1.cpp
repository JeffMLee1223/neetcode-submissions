class Solution {
   public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        int sum = 0;

        for (string op : operations) {
            if (op == "+") {
                int last = record.top();
                record.pop();

                int secondLast = record.top();

                record.push(last);
                record.push(last + secondLast);
                sum += last + secondLast;

            } else if (op == "D") {
                record.push(record.top() * 2);
                sum += record.top();
            } else if (op == "C") {
                int waste = record.top();
                record.pop();
                sum -= waste;
            } else {
                record.push(stoi(op));
                sum += stoi(op);
            }
        }

        return sum;
    }
};