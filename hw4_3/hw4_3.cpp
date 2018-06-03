#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>

using namespace std;
int main(int argc, char** argv){
    set<int> A;
    multiset<int> B;

    int reading;
    while(cin >> reading){
        if(reading < 0)
            break; //read until negative
        A.insert(reading);
        B.insert(reading);
        //insertion
    }

    //print the elements
    cout << "A:";
    for(auto& ele: A){
        cout << ele << " ";
    }
    cout << endl;
    cout << endl; //extra line

    cout << "B:";
    for(auto& ele: B){
        cout << ele << " ";
    }
    cout << endl;
    cout << endl; //extra empty line

    //delete 5
    A.erase(5);
    B.erase(5);

    cout << "A:";
    for(auto& ele: A){
        cout << ele << " ";
    }
    cout << endl;
    cout << endl; //extra line

    cout << "B:";
    for(auto& ele: B){
        cout << ele << " ";
    }
    cout << endl;
    cout << endl; //extra empty line

    //add two more to A
    A.insert(14);
    A.insert(198);

    //manual union as multiset
    //we don't use any library function because the multiplicity
    //should be kept in such process
    multiset<int> uRes;
    for(auto& ele: A){
        uRes.insert(ele);
    }
    for(auto& ele: B){
        uRes.insert(ele);
    }
    cout << "union intrepretation #1: ";
    for(auto& ele: uRes){
        cout << ele << " ";
    }
    cout << endl;

    //another inprepreation of the question is
    //to use the library function
    multiset<int> uRes1;
    cout << "union using library function: ";
    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(uRes1, uRes1.begin()));
    for(auto& ele: uRes1){
        cout << ele << " ";
    }
    cout << endl;

    set<int> intersection;
    cout << "intersection of the two: ";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(intersection, intersection.begin()));
    for(auto& ele: intersection){
        cout << ele << " ";
    }
    cout << endl;

    //intersection can be done by first convert B into
    set<int> diff;
    cout << "difference of the two: ";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(diff, diff.begin()));
    for(auto& ele: diff)
        cout << ele << " ";
    cout << endl;

    //symmetric difference
    set<int> sym_diff;
    cout << "symmetric difference: ";
    set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(sym_diff, sym_diff.begin()));
    for(auto& ele: diff)
        cout << ele << " ";
    cout << endl;

    return 0;
}
