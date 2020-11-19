#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// RETURN MAZE PATH

vector<string>* return_maze_path(int start_row, int start_col, int end_row, int end_col)
{
    if (start_row == end_row && start_col == end_col)
    {
        vector<string> *base_arr = new vector<string>();
        base_arr->push_back("");
        return base_arr;
    }

    vector<string> *first_horizontal_step = new vector<string>();
    vector<string> *first_vertical_step = new vector<string>();
    if (start_row < end_row)
    {
        first_vertical_step = return_maze_path(start_row, start_col + 1, end_row, end_col);
    }
    if (start_col < end_col)
    {
        first_horizontal_step = return_maze_path(start_row + 1, start_col, end_row, end_col);
    }
    vector<string> *final_path = new vector<string>();
    for (int i = 0; i < first_horizontal_step->size(); i++)
    {
        string horizontal = first_horizontal_step->at(i);
        final_path->push_back("h" + horizontal);
    }
    for (int i = 0; i < first_vertical_step->size(); i++)
    {
        string vertical = first_horizontal_step->at(i);
        final_path->push_back("v" + vertical);
    }
    return final_path;
}

int main()
{

    int source_row, source_col, end_row, end_col;
    cout << "Enter the row and column number for the source: " << endl;
    cin >> source_row >> source_col;
    cout << "Enter the row and column number for the destination: " << endl;
    cin >> end_row >> end_col;
    vector<string> *final_maze_path = return_maze_path(source_row, source_col, end_row, end_col);
    for (int i = 0; i < final_maze_path->size(); i++)
    {
        cout << final_maze_path->at(i) << endl;
    }
}
