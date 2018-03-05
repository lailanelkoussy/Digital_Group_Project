#include <iostream>
#include <string>
#include <vector>
#include "KMap.h"

using namespace std;

int main() {
    string input;
    KMap kmap;
    bool accepted = true;
    unsigned long size;

    cout<<"Please enter the minterms: ";
    do
    {
        getline(cin,input);
        cout<<input<<endl;
        size = input.size();


        for (int i = 0; i<size-1; i++){
            if (input[i] == '.')
            { accepted = false;
                cout<<"invalid input. Please re-enter: ";
                break; }

            else accepted = true;

                                        }

    } while (!accepted);

    kmap.inputEx(input);



    return 0;
}