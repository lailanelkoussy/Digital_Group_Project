#include <iostream>
#include <string>
#include <vector>
#include "KMap.h"

using namespace std;


int main() 
{
    string input, temp="";
    KMap kmap;
    int preloc = 0;
    bool inte = true;
    bool accepted = true;
    unsigned long isize;
    vector<int> storage;

	cout<<"Please enter the minterms (in this form: \"0,1,2,3.\") : ";
    do
    {
        getline(cin,input);
        cout<<input<<endl;
        isize = input.size();


        for (int i = 0; i<isize-1; i++){
			if (input[i] == '.' || ((input[i] > '7' || input[i] < '0')&& input[i]!=','))
            { accepted = false;
                cout<<"invalid input. Please re-enter: ";
                break; }

            else accepted = true;

                                        }

    } while (!accepted);

    kmap.inputEx(input);
	

	system("pause");
    return 0;
}