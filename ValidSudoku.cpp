/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/

#include <iostream>
#include <vector>
#include <map>


using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, int> rows;
        map<char, int> cols;
        map<char, int> sub_box;
        
        // This function checks if a character is repeated 
        // except for the '.' character
        auto character_check = [](auto row)
        {
            for(auto& [key, value] : row)
            {
                if(value > 1)
                {
                   return false; 
                }
            }   
            return true;
        };      
        
        // Create hash map for rows
        // return true if no number is repeated
        bool row_validity = true;
        for (auto& row :  board)
        {
            for(auto& el : row)
            {
                if(el!='.')
                {
                    rows[el]++; 
                }
            } 
            row_validity = row_validity && character_check(rows);
            rows.clear();
        }
                
        bool col_validity = true;
        for(auto i=0; i<9; i++)
        {
            for(auto j=0; j<9; j++)
            {
                if(board[j][i] != '.')
                {
                    cols[board[j][i]]++;   
                }
            }
            col_validity = col_validity && character_check(cols);
            cols.clear();
        }
                   
        bool sub_box_validity = true;
        // create hash map for sub_box
        for(auto n=0; n<9; n++)
        {   
            int q = n/3;
            int r = n%3; 
            
            int i = 3*q + 1;
            int j = 3*r + 1;
            
            for(auto itr=-1; itr<2; itr++)
            {
                for (auto jtr=-1; jtr<2; jtr++)
                {
                    if (board[i+itr][j+jtr] != '.')
                    {
                        sub_box[board[i+itr][j+jtr]]++;
                    }
                }
            }
            
            for (auto& [key, value] : sub_box)
            {
                cout << key << ":" << value << ",";
            }
            
            cout << endl;
            
            sub_box_validity = sub_box_validity && character_check(sub_box);
            sub_box.clear();
        }
        
        return (row_validity && col_validity && sub_box_validity);
    }
};