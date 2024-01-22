

template<typename Type1, typename Type2, typename Type3>
class Triplet {
public:
    Triplet(Type1 first, Type2 second, Type3 third) {
        this->firstValue = first;
        this->secondValue = second;
        this->thirdValue = third;
    }

    Type1 first() {
        return this->firstValue;
    }

    Type2 second() {
        return this->secondValue;
    }

    Type3 third() {
        return this->thirdValue;
    }

    void setFirst(Type1 newFirst) {
        this->firstValue = newFirst;
    }

    void setSecond(Type2 newSecond) {
        this->secondValue = newSecond;
    }

    void setThird(Type3 newThird) {
        this->thirdValue = newThird;
    }

private:
    Type1 firstValue;
    Type2 secondValue;
    Type3 thirdValue;
};