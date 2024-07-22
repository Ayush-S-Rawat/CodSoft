#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>

using namespace std;

void print(vector<vector<char>> &board)
{
    cout << "\n\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "\n\n";
}

bool checknum(int num, vector<vector<char>> &board, int i, int j)
{
    char ch = num + '0';
    for (int x = 0; x < 9; x++)
    {
        if (board[i][x] == ch)
            return false;
    }
    for (int x = 0; x < 9; x++)
    {
        if (board[x][j] == ch)
            return false;
    }
    int x = (i / 3) * 3, y = (j / 3) * 3;
    for (int k = x; k < x+3; k++)
    {
        for (int l = y; l < y+3; l++)
        {
            if (board[k][l] == ch)
                return false;
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    int n = board[0].size(), i, j;
    list<int> temp{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<pair<pair<int, int>, list<int>>> l;
    vector<list<int>::iterator> remove;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
            {
                l.push_back({{i, j}, temp});
            }
        }
    }
    while (l.size())
    {
        for (auto itr = l.begin(); itr != l.end(); itr++)
        {
            i = itr->first.first;
            j = itr->first.second;
            for (auto l1 = itr->second.begin(); l1 != itr->second.end(); l1++)
            {
                if (!checknum(*l1, board, i, j))
                {
                    // itr->second.erase(l1);
                    // l1--;
                    remove.push_back(l1);
                }
            }
            for (int i = 0; i < remove.size(); i++)
            {
                itr->second.erase(remove[i]);
            }
            remove.clear();
            if (itr->second.size() == 1)
            {
                board[i][j] = '0' + itr->second.front();
                l.erase(itr);
                itr--;
            }
        }
    }
}

int main()
{
    vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    print(board);
    solveSudoku(board);
    print(board);
    list<int> demoList{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto itr = demoList.begin();
         itr != demoList.end(); itr++)
    {
        cout << *itr << " ";
    }
    return 0;
}

// list<int> l{1,2,3,4,5,6,7,8,9,10};
// vector<list<int>::iterator> temp;
// for(auto i = l.begin() ; i != l.end() ;i++)
// {
//     cout<<*i<<"  ";
//     if(*i & 1)
//         temp.push_back(i);
// }
// for(int i=0;i<temp.size();i++)
// {
//     l.erase(temp[i]);
// }
// for(auto i = l.begin() ; i != l.end() ;i++)
//     cout<<*i<<"  ";