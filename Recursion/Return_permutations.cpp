#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
//Return Permutations

vector<string> *return_permutations(string str)
{
    if (str.size() == 0)
    {
        vector<string> *base_arr = new vector<string>();
        base_arr->push_back("");
        return base_arr;
    }
    char single_char = str[0];
    vector<string> *recursion_output = return_permutations(str.substr(1));
    vector<string> *return_array = new vector<string>();
    for (int i = 0; i < recursion_output->size(); i++)
    {
        string test = recursion_output->at(i);
        for (int j = 0; j <= test.size(); j++)
        {
            return_array->push_back(test.substr(0, j) + single_char + test.substr(j));
        }
    }
    return return_array;
}

int main()
{

    string str;
    cout << "Enter a string: " << endl;
    cin >> str;
    cout << endl;
    vector<string> *final_array = return_permutations(str);
    for (int i = 0; i < final_array->size(); i++)
    {
        cout << i + 1 << ") " << final_array->at(i) << endl;
    }
   // delete[] final_array;
}
