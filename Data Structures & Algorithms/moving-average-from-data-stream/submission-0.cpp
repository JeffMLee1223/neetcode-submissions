class MovingAverage {
   private:
    queue<int> q;
    int _size;
    double sum;

   public:
    MovingAverage(int size) {
        _size = size;
        sum = 0;
    }

    double next(int val) {
        q.push(val);
        sum += val;

        if (q.size() > _size) {
            sum -= q.front();
            q.pop();
        }

        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
