/*
    JTSK-320111
    Stack.h
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <cstring>
template<typename T>
class Stack{
    private:
        T* head;
        int count; //num of elements
        int size; //current stack size
    public:
        Stack(){
            head = new T[10]; //allocate size of 10
            count = 0;
            size = 10;
        }
        ~Stack(){
            delete [] head;
        }

        Stack(const Stack<T>& other){
            head = new T[other.size];
            count = other.count;
            size = other.size;

            //copy content
            for(int i = 0; i < count; i++){
                head[i] = other.head[i]; //assignment
            }
        }

        Stack(int size){
            //construct a fixed size stack
            this->head = new T[size];
            this->size = size;
            this->count = 0;
        }

        bool pop(T& out){
            //push out a element
            if(count < 1)
                return false;
            out = head[count - 1];
            count--;
            return true;
        }

        T back(){
            //check the back element
            return head[count - 1];
        }

        bool push(T element){
            if(count >= size)
                return false;
            head[count] = element;
            count++;
            return true;
        }

        int getNumEntries(){
            return count;
        }
};
