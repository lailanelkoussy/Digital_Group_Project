//
// Created by Laila Nasser ElKoussy 900160812 on 3/2/18.
//

#include "KMap.h"
#include <vector>
#include <iomanip>

KMap::KMap() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            map[i][j] = 0;

}

KMap::~KMap() {

}

void KMap::inputEx(string &a) {
    string temp = "";
    int preloc = 0;
    bool inte = true;
    unsigned long isize = a.length(); //size of the input


    for (int i = 0; i < isize; i++) {
        if ((a[i] == ',') || (i == isize - 1)) { // checks for commas or end of input
            for (int j = preloc; j < i; j++) //basically just goes from the last saved location (where the number
                temp += a[j];            //started) to right before the current comma and puts it all in temp
            if (i == isize - 1)
                temp += a[i];            //when it's the last position it skips the last one so I just add it lol
            cout << temp << endl;            //the random couts scattered are used for debugging

            if (temp.length() > 1) //checking to see if got any periods or spaces characters
            {
                for (int r = 0; r < temp.length() && inte; r++) {
                    if ((temp[r] == '.') || (isspace(temp[r]))) {
                        inte = false;
                        temp.erase(r, 1);
                    }
                }
            }
            storage.push_back(stoi(temp)); //turns temp into an int and pushes it into storage
            temp = "";
            preloc = i + 1; //updates where the next number starts (after the comma by one)

        }
    }
    noOfOnes(); // updates numbers of ones based on the size of storage
	fill();
}

void KMap::noOfOnes() {
    ones = storage.size();
}

void KMap::fill() {
    int index;

    for (auto element: storage) {
        index = getIndex(element);
        if (element % 2 == 0) // all even minterms are in the first row
            map[0][index] = 1;
        else map[1][index] = 1;

    }

    cout << "The K-Map looks like this: " << endl;
    printMap();

}

int KMap::getIndex(int &a) { //this is me taking the easy way out instead of using binary conversion lol
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

void KMap::printMap() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++)
            cout << setw(4) << map[i][j];
        cout << endl;
    }


}

//TODO: Need to check if all entered inputs are valid.