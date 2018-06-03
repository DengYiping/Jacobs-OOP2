/*
    JTSK-320111
    WindGauge.h
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <vector>
class WindGauge {
    public:
        WindGauge(int period = 12);
        void currentWindSpeed(int speed);
        int highest() const;
        int lowest() const;
        int average() const;
    private:
        // add properties and/or method(s) here
        std::vector<int> vec;
        int max_element;
};
