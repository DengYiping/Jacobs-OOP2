/*
    JTSK-320111
    pq.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
/*
    JTSK-320111
    pq.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <queue>
#include <functional>
#include <vector>
#include <iostream>

/*
 * the signature for priority queue
 template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;

*/

struct Cmp{
    bool operator()(const int& i1, const int& i2){
        return i1 > i2;
    }
};

using namespace std;
int main(int argc, char** argv){
    priority_queue<int> q; //define a priority queue of integer

    int data[] = {4, 9, 5, 3, 6, 7, 8, 2}; //data to put in the queue
    //put it all into the queue
    for(int i = 0; i < 8; i++){
        q.push(data[i]); //insert into the queue
    }
    cout << "size of the queue: " << q.size() << endl;

    cout << "top of the queue: " << q.top() << endl;
    q.pop();
    cout << "pop one, then top of the queue: " << q.top() << endl;

    //print and pop
    cout << "rest of the priority queue: ";
    for(int i = 0; i < 7; i++){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl; //change line

    //example for user defined container and lambda as comparator
    auto cmp = [](int a, int b){ return a > b; };
    priority_queue<int, vector<int>, decltype(cmp)> q1(cmp); //use user defined comparator
    cout << "insert into the queue order by lambda" << endl;
    for(int i = 0; i < 8; i++){
        q1.push(data[i]);
    }
    cout << "pop the element: ";
    for(int i = 0; i < 8; i++){
        cout << q1.top() << " ";
        q1.pop();
    }
    cout << endl;

    return 0;
}
