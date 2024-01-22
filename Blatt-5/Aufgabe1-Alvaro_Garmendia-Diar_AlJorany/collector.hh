
template<typename NumType>
class Collector {
public:
    Collector(NumType startValue, NumType changeValue) {
        this->change = changeValue;
        this->start = startValue;
    }

    void add(NumType value) {
        this->start += change + value;
    }

    NumType digest() {
        return this->start;
    }

private:
    NumType change;
    NumType start;
};