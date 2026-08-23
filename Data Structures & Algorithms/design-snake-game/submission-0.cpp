class SnakeGame {
   private:
    int _width;
    int _height;
    int foodIndex = 0;
    vector<vector<int>> _food;

    deque<pair<int, int>> snake;

   public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        _width = width;
        _height = height;
        _food = food;
        snake.push_back({0, 0});
    }

    int move(string direction) {
        auto head = snake.back();

        int row = head.first;
        int col = head.second;

        // 1. new head
        if (direction == "R") {
            col++;
        } else if (direction == "L") {
            col--;
        } else if (direction == "U") {
            row--;
        } else if (direction == "D") {
            row++;
        }

        // 2. check boundary
        if (row < 0 || row >= _height || col < 0 || col >= _width) {
            return -1;
        }

        // 3. check if there is a food
        bool ateFood = false;

        if (foodIndex < _food.size() && row == _food[foodIndex][0] && col == _food[foodIndex][1]) {
            ateFood = true;
            foodIndex++;
        }

        // 4. don't have a food, delete the tail
        if (!ateFood) {
            snake.pop_front();
        }

        // 5. doesn't matter if we eat food or not, our head will be the original coordinate + our
        // operation
        for (auto position : snake) {
            if (position.first == row && position.second == col) {
                return -1;
            }
        }

        // 6. add new head
        snake.push_back({row, col});

        return foodIndex;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
