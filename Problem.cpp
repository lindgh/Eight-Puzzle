#include "Problem.h"

#include <iostream>
using namespace std;

ostream &operator<<(ostream &out, const Node &node)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            out << node.table[i][j] << "   ";
        }
        out << endl;
    }
    out << "h(n): " << node.heuristic << ", g(n): " << node.depth << ", zero position: [" << node.zero_x << "]["
        << node.zero_y << "]" << endl;
    return out;
}

void Problem::Search() 
{
    bool foundSolution = false;
    
    // cout << "Searching..." << endl;
    // cout << "initial_state: \n" << initial_state << endl;
    // cout << "final_state: \n" << final_state << endl;

    //FIRST ORDER OF BUSINESS!! push onto queue.
    unexplored_queue.push(initial_state);
   
    Node exploring_node;

    while (!unexplored_queue.empty() && !foundSolution) {
        exploring_node = unexplored_queue.top();
        unexplored_queue.pop();

        cout << "exploring node: \n" << exploring_node << endl;

        if (exploring_node == final_state) {
            cout << "solution has been found!" << endl;
            foundSolution = true;
        }
        else {
            // do the explore stuff
            explore(exploring_node);
            explored_queue.push(exploring_node); 
        }


    }

    cout << "queue empty now!" << endl;


    

    


    /*
    while (queue not empty) {
        Node exploringNode = exploring_queue.pop
        if (exploringNode != goalstate) {
            explore(exploringNode) //when this done, queue should have all its children added
            explored.push(exploringNode)
        }
        else {
            you found solution!
        }
    }
    */
}

// constructor
Problem::Problem(int userChoice)
{
    // 1) initialize final_state node

    int goal_state[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}};

    for (int i = 0; i < 3; ++i) // set final_state to goal_state
    {
        for (int j = 0; j < 3; ++j)
        {
            final_state.table[i][j] = goal_state[i][j];
            if (final_state.table[i][j] == 0)
            {
                final_state.zero_x = i;
                final_state.zero_y = j;
            }
        }
    }

    final_state.depth = 99999;
    final_state.heuristic = 0;

    // when checking if state == another, only check if tables equal

    // 2) initialize initial_state node

    int temp_initial[3][3] = // THIS IS TEMPORARILY HARD CODED NO MATTER WHAT FOR TESTING!!!
        {
            {1, 2, 3},
            {4, 8, 0},
            {7, 6, 5}};

    for (int i = 0; i < 3; ++i) // set initial_state to temp_inital
    {
        for (int j = 0; j < 3; ++j)
        {
            initial_state.table[i][j] = temp_initial[i][j];
            if (initial_state.table[i][j] == 0)
            {
                initial_state.zero_x = i;
                initial_state.zero_y = j;
            }
        }
    }

    initial_state.heuristic = 0; // TESTING. AFTER IMPLEMENTING HEURISTICS, CALL FUNC USING userChoice
    initial_state.depth = 0;
}


void Problem::explore(const Node& exploring_node) {
    cout << "exploring!" << endl; 
}
//down
Node Problem::down(const Node& exploring_node){
    Node temp = exploring_node;
    // swap(temp[temp.zero_x][temp.zero_y], temp[temp.zero_x-1][temp.zero_y]);
    // temp.zero_x = temp.zero_x - 1;
    // temp.depth += 1;
    return temp; 
}
//up
Node Problem::up(const Node& exploring_node){
    return exploring_node;
}
//left
Node Problem::left(const Node& exploring_node){
    return exploring_node;
}
//right
Node Problem::right(const Node& exploring_node) {
    return exploring_node;
}