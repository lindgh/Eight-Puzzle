#include <iostream>
#include "Problem.h"

using namespace std;

// overload output operator for a Node

int main()
{
    int user_initial_state;
    int userAlgorithmChoice;

    // below is if user wants default puzzle. Only modify it if they select option "2"
    int temp_initial[3][3] =
        {
            {1, 2, 3},
            {4, 8, 0},
            {7, 6, 5}};

    // welcome the user
    cout << "\nWelcome to Ghunaim and Kethidi's 8 puzzle solver." << endl;
    cout << "Type \"1\" to enter your own puzzle, or \"2\" to use a default puzzle: ";
    cin >> user_initial_state;
    cout << endl;

    if (user_initial_state == 1)
    {
        // create or change array to users array
        cout << "\nEnter your puzzle, using zero to represent the blank tile:\n"
             << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Enter row " << i << ", using a space between numbers. Hit enter once done: ";
            for (int j = 0; j < 3; j++)
            {
                cin >> temp_initial[i][j];
            }
            // cout << endl;
        }
        cout << "\nYour puzzle: "
             << endl;
    }
    else
    {
        cout << "Using default puzzle: "
             << endl;
    }
    // for testing: printing resulting matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << temp_initial[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // ask user what search algorithm they want
    cout << "Enter your choice of algorithm" << endl;
    cout << "Type \"1\" for Uniform Cost Search" << endl;
    cout << "Type \"2\" for A* with the Misplaced Tile heuristic" << endl;
    cout << "Type \"3\" for A* with the Euclidean distance heuristic" << endl;
    cin >> userAlgorithmChoice;

    if (!((userAlgorithmChoice == 1) || (userAlgorithmChoice == 2) || (userAlgorithmChoice == 3)))
    {
        cout << "\nInvalid algorithm choice.";
        userAlgorithmChoice = 1;
    }

    // do we need edge case for this too?? i dont want to
    switch (userAlgorithmChoice)
    {
    case 1:
        cout << "\nPerforming Uniform Cost Search on your puzzle..." << endl;
        break;
    case 2:
        // uncomment below once function implemented
        cout << "\nPerforming A* with the Misplaced Tile heuristic on your puzzle..." << endl;

        // comment out below 2 lines once function implemented
        // cout << "\nA* with the Misplaced Tile under construction! Doing uniform cost search..." << endl;
        // userAlgorithmChoice = 1;
        break;
    case 3:
        // uncomment below once function implemented
        cout << "\nPerforming A* with the Euclidean distance heuristic on your puzzle..." << endl;

        // comment out below 2 lines once function implemented
        // cout << "\nA* with the Euclidean distance under construction! Doing uniform cost search..." << endl;
        // userAlgorithmChoice = 1;

        break;
    }

    // now, we can make the problem and perform our search on the problem
    Problem problem(userAlgorithmChoice, temp_initial);
    problem.search();
    problem.trace();

    return 0;
}