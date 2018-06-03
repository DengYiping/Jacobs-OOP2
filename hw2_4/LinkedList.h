/*
    JTSK-320111
    LinkedList.h
    Yiping Deng
    y.deng@jacobs-university.de
*/
template<typename T>
class Node{
    public:
        //internal class, it will
        //not be available from class
        //user, so we don't need private
        //member
        Node* prev;
        Node* next;
        T data;
        Node(T& data){
            this->prev = 0;
            this->next = 0;
            this->data = data;
        }
        Node(T& data, Node* prev, Node* next){
            this->prev = prev;
            this->next = next;
            this->data = data;
        }
        ~Node(){} //empty destructor, don't do anything
};

template<typename T>
class DoublyLinkedList{
    private:
        //private member
        Node<T>* first;
        Node<T>* last;
        int count;
    public:
        DoublyLinkedList(){
            // initialization
            first = 0;
            last = 0;
            count = 0;
        }
        ~DoublyLinkedList(){
            Node<T>* current = 0;
            Node<T>* tmp = this->first;
            while(count--){
                current = tmp;
                tmp = tmp->next;
                //free the node
                delete current;
            }
        }
        T front(){
            return first->data;
        }
        T back(){
            return last->data;
        }
        void push_front(T ele){
            Node<T>* nd = new Node<T>(ele, 0, this->first);
            this->count++;
            this->first = nd;
            if(count == 1)
                this->last = nd;
            else
                nd->next->prev = nd;
            return;
        }
        void push_back(T ele){
            Node<T>* nd = new Node<T>(ele, this->last, 0);
            this->count++;
            this->last = nd;
            if(count == 1)
                this->first = nd;
            else
                nd->prev->next = nd;
            return;
        }
};
