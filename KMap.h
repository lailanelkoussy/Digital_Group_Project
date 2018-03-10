//
// Created by Laila Nasser ElKoussy 900160812 on 3/2/18.
// Yousef Mohab Koura - 900160083
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
    struct Minterms {
        int value;
        int noOfInclusions;
        int decIndex;

        Minterms();

    };

    struct Implicant {
        string name;
        vector<Minterms> mins;
        int size; //the number of ones inside of it

    };

    vector<int> storage; // storage vector for the minterms
    void noOfOnes ();
    int ones, variables;
    Minterms map[2][4];
    vector<Implicant> imps;

    void fill (); //takes the storage vector and fills the array with the values
    int getIndex (int&);
    void printMap();
    void extract(); //this function extracts all possible implicants from the KMap


};

#endif //GROUP_PROJECT_KMAP_H
