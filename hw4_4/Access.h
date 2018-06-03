#include <set>

class Access {
    public:
        void activate(unsigned int code);
        void deactivate(unsigned int code);
        bool isactive(unsigned int code);
        void addCode(unsigned int code);
    private:
        std::set<unsigned int> codes;
        std::set<unsigned int> activated;
};

