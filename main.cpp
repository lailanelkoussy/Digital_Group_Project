#include <iostream>
#include <string>
#include <vector>
#include "KMap.h"

using namespace std;

int main() 
{
	string input;
    KMap kmap;
    bool accepted = true;
    unsigned long isize;

	cout<<"Please enter the minterms (in this form: \"0,1,2,3.\") : ";
    do
    {
        getline(cin,input);
        isize = input.size();

		if (isize < 2)
		{
			accepted = false;
			cout << "invalid input. Please re-enter: ";
		}
		else
		{
			for (int i = 0; i < isize - 1; i++)
			{
				if (input[isize - 1] != '.' || ((input[i] > '7' || input[i] < '0') && input[i] != ',') || (input[i] == ',' && input[i + 1] == ',') || ((input[i] <= '7' && input[i] >= '0') && (input[i + 1] <= '7' && input[i + 1] >= '0')))
				{
					accepted = false;
					cout << "invalid input. Please re-enter: ";
					break;
				}
				else accepted = true;
			}
		}

    } while (!accepted);

    kmap.Generate(input);
	
	system("pause");
    return 0;
}