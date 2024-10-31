#include <iostream>
#include "Problem.h"

using namespace std;

// overload output operator for a Node

int main()
{
    // int user_choice;
    // string row = "first";
    // int user_algo_choice;

    // GET USER ALG CHOICE BEFORE MAKING PROBLEM
    int userAlgorithmChoice = 2;

    Problem problem(userAlgorithmChoice);

    cout << "problem.initial_state: \n"
         << problem.initial_state << endl;

    //testing: explore and left operator
    //if you wanna test, change explore to Node and only have one op at a time
    // Node smth = problem.explore(problem.initial_state);
    // cout << smth;
    // cout << "problem.final_state: \n"
    //      << problem.final_state << endl;

    // //welcome the user
    // cout << "Welcome to 862331573 and 862267489's and HOLLAND SID 8 puzzle solver." << endl;
    // cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;
    // cin >> user_choice;
    // cout << endl;
    // // add edge case that only lets 1 or 2 as options
    // //  if(user_choice == 1){
    // //      //user array = default
    // //      //for testing: printing resulting matrix
    // //      //idk what to add here
    // //  }
    // if (user_choice == 2)
    // {
    //     // create or change array to users array
    //     cout << "Enter your puzzle, use zero to represent the blank" << endl;
    //     for (int i = 0; i < 3; i++)
    //     {
    //         cout << "Enter the " << row << " row, use space or tabs between numbers ";
    //         for(int j = 0; j < 3; j++){
    //             cin >> initial_state[i][j];
    //             if(initial_state[i][j] == 0){
    //                 Problem.x = i;
    //                 Problem.y = j;
    //             }
    //         }
    //         if (row == "first")
    //         {
    //             row = "second";
    //         }
    //         else if (row == "second")
    //         {
    //             row = "third";
    //         }
    //         cout << endl;
    //     }
    // }
    // //for testing: printing resulting matrix
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         cout << "\t" << initial_state[i][j];
    //     }
    //     cout << endl;
    // }

    // // ask user what search algorithm they want
    // cout << "Enter your choice of algorithm" << endl;
    // cout << "Type \"1\" for Uniform Cost Search" << endl;
    // cout << "Type \"2\" for A* with the Misplaced Tile heuristic" << endl;
    // cout << "Type \"3\" for A* with the Euclidean distance heuristic" << endl;
    // cin >> user_algo_choice;

    // //do we need edge case for this too?? i dont want to
    // switch(user_algo_choice){
    //     case 1:
    //         //testing: to see it goes with the right choice
    //         //please replace cout statement with your own algorithm file (we could put all algos in one file once we done)
    //         //call search(p, 1);
    //         cout << "Uniform Cost Search" << endl;
    //         break;
    //     case 2:
    //         cout << "A* with the Misplaced Tile heuristic" << endl;
    //         break;
    //     case 3:
    //         cout << "A* with the Euclidean distance heuristic" << endl;
    //         break;
    //     //search(p, (1,2, or 3));
    // }

    // // do we need edge case for this too?? i dont want to
    // switch (user_algo_choice)
    // {
    // case 1:
    //     // testing: to see it goes with the right choice
    //     // please replace cout statement with your own algorithm file (we could put all algos in one file once we done)
    //     cout << "Uniform Cost Search" << endl;
    //     break;
    // case 2:
    //     cout << "A* with the Misplaced Tile heuristic" << endl;
    //     break;
    // case 3:
    //     cout << "A* with the Euclidean distance heuristic" << endl;
    //     break;
    // }

    return 0;
}