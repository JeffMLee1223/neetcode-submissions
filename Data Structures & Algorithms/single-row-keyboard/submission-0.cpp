class Solution {
   public:
    int calculateTime(string keyboard, string word) {
        vector<int> position(26);
        for (int i = 0; i < keyboard.size(); i++) {
            position[keyboard[i] - 'a'] = i;
        }

        int totalTime = 0;

        int currentPosition = 0;

        for (char c : word) {
            int targetPosition = position[c - 'a'];

            totalTime += abs(currentPosition - targetPosition);

            currentPosition = targetPosition;
        }

        return totalTime;
    }
};
