#include <map>

class Access {
    public:
        void activate(unsigned int code, unsigned int level);
        void deactivate(unsigned int code);
        bool isactive(unsigned int code, unsigned int level);
        void addCode(unsigned int code, unsigned int level);
    private:
        std::map<unsigned int, unsigned int> codes;
        std::map<unsigned int, unsigned int> activated;
};

