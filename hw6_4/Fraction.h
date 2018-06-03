class Fraction {
    private:
        int num;
        int denum;
    public:
        Fraction(){
            num = 0;
            denum = 1;
        }

        Fraction(int num, int denum){
            this->num = num;
            this->denum = denum;
        }
};
