#include<iostream>
using namespace std;
void input(int sudoku[9][9])
{
    cout<< "Enter the Unsolved Sudoku "<<endl;
    for(int i=0 ; i<9 ; i++)
    {
        for(int j=0 ; j<9 ; j++)
        {
            cin >> sudoku[i][j];
        }
    } 
}
void print_solution(int sudoku[9][9])
{
    cout<<"The solution is "<<endl;
    for(int i=0 ; i<9 ; i++)
    {
        for(int j=0 ; j<9 ; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout<<endl;
    }
}
bool IsEmpty(int sudoku[9][9])
{
    for (int row=0 ; row<9 ; row++)
    {
        for(int col=0 ; col<9 ; col++)
        {
            if (sudoku[row][col] == 0)
            return true;
        }
    }
    return false;
}
bool IsSafe(int row , int col , int sudoku[9][9] , int val)
{
    for (int i=0 ; i<9 ; i++)
    {
        if (sudoku[row][i] == val)
            return false;

        if (sudoku[i][col] == val)
            return false;
    }
    int startRow = row - row % 3,
        startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sudoku[i + startRow][j + startCol] == val)
                return false;
 
    return true;
}
bool solve(int sudoku[9][9])
{
    int row , col;
    if (!IsEmpty(sudoku))
        return true;
    
    for(int val = 0 ; val<=9 ; val ++)
    {
        if(IsSafe(row , col , sudoku , val))
        {
            sudoku[row][col] = val;
            if(solve(sudoku))
            return true;

            sudoku[row][col] = 0;
        }
        
    }
    return false;
}
// bool solve(int sudoku[9][9])
// {
//     int n = 9;
//     for(int row=0 ; row<n ; row++)
//     {
//         for(int col=0 ; col<n ; col++)
//         {
//             if(sudoku[row][col] == 0)
//             {
//                 for (int val=0 ; val<=9 ; val++)
//                 {
//                     if(IsSafe(row , col , sudoku , val))
//                     {
//                         sudoku[row][col] = val;

//                         bool SolutionPossible = solve(sudoku);

//                         if(SolutionPossible)
//                             return true;
//                         else
//                             sudoku[row][col] = 0;
//                     }
//                 }
//                 return false;
//             }
//         }
//     }
//     return true;
// }
int main()
{
    int sudoku[9][9] = { {3 , 0 , 6 , 5 , 0 , 8 , 4 , 0 , 0},
                         {5 , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                         {0 , 8 , 7 , 0 , 0 , 0 , 0 , 3 , 1},
                         {0 , 0 , 3 , 0 , 1 , 0 , 0 , 8 , 0},
                         {9 , 0 , 0 , 8 , 6 , 3 , 0 , 0 , 5},
                         {0 , 8 , 0 , 0 , 0 , 0 , 8 , 8 , 0},
                         {1 , 3 , 0 , 0 , 0 , 0 , 2 , 5 , 0},
                         {0 , 0 , 0 , 0 , 0 , 0 , 0 , 7 , 4},
                         {0 , 0 , 5 , 2 , 0 , 6 , 3 , 0 , 0},
                        };
    solve(sudoku);
    print_solution(sudoku);
    return 0;
}