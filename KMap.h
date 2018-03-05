//
// Created by Laila Nasser ElKoussy 900160812 on 3/2/18.
//

#ifndef GROUP_PROJECT_KMAP_H
#define GROUP_PROJECT_KMAP_H

#include <iostream>
#include <vector>

using namespace std;
class KMap {
public:
    KMap();
    ~KMap();
    void inputEx(string &); //takes in string input, put values in storage vector as ints and counts numbers of
                            // one and sets them


private:
    vector<int> storage;
    void noOfOnes ();
    int ones, variables, map[2][4];

    void fill (); //takes the storage vector and fills the array with the values
    int getIndex (int&);

};


#endif //GROUP_PROJECT_KMAP_H
