//
// Created by Laila Nasser ElKoussy 900160812 on 3/2/18.
//

#include "KMap.h"
#include <vector>

KMap::KMap() {
    for (int i = 0; i<2; i++)
        for (int j = 0; j<4; j++)
            map[i][j]=0;

}
KMap::~KMap() {

}
void KMap::inputEx(string &a) {
    string input, temp = "";
    int preloc = 0;
    bool inte = true;
    unsigned long isize = a.length(); //size of the input


    for (int i = 0; i < isize; i++) {
        if ((input[i] == ',') || (i == isize - 1)) {
            for (int j = preloc; j < i; j++)
                temp += input[j];
            if (i == isize - 1)
                temp += input[i];
            cout << temp << endl;

            if (temp.length() > 1) //checking to see if got any periods or wrong characters
            {
                for (int r = 0; r < temp.length() && inte; r++) {
                    if ((temp[r] == '.')||(isspace(temp[r]))){
                        inte = false;
                        temp.erase(r, 1);
                    }
                }
            }
            storage.push_back(stoi(temp));
            temp = "";
            preloc = i + 1;

        }
    }
    noOfOnes();

}
void KMap::noOfOnes() {
    ones = storage.size();
}
void KMap::fill() {
    int index;

    for (auto element: storage) {
        index = getIndex(element);
        if (element%2 == 0) // all even minterms are in the first row
            map [0][index] = 1;
        else map [1][index] = 1;

    }

}
int KMap::getIndex(int &a) {
switch (a) {
    case 0:
    case 1:
        return 0;
    case 2:
    case 3:
        return 1;
    case 6:
    case 7:
        return 2;
    default :
        return 3;

}

}

//TODO: Need to check if all entered inputs are valid.