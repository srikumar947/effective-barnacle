/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

Your MovingAverage object will be instantiated and called as such:
MovingAverage obj = new MovingAverage(size);
double param_1 = obj.next(val);
*/

class MovingAverage {
public:
    vector<int> values;
    int limit;

    MovingAverage(int size) {
        limit = size;
    }

    double next(int val) {
        if (values.size() == limit) {
            values.erase(values.begin());
            values.push_back(val);
        }
        else
            values.push_back(val);

        int sum = 0;

        for (auto x:values)
            sum += x;

        return sum/(double)values.size();
    }
};
