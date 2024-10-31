#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include <queue>
using namespace std;

struct Node
{

    int table[3][3]; // the eight table

    // stores where 0 is in matrix, heuristic -> h(n), depth -> g(n)
    int zero_x, zero_y, heuristic, depth;

    // overload operator>: allows us to make min priority queue!
    bool operator>(const Node &rhs) const
    {
        // returns true that N1 > N2 if its f(n) is less than N2's
        return (heuristic + depth) < (rhs.heuristic + rhs.depth);
    }

    bool operator<(const Node &rhs) const
    {
        // returns true that N1 > N2 if its f(n) is less than N2's
        return (heuristic + depth) > (rhs.heuristic + rhs.depth);
    }

    // overloads assignment operator
    Node &operator=(const Node &rhs)
    {
        // sets tables equal to each other
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                table[i][j] = rhs.table[i][j];
                if (table[i][j] == 0)
                {
                    zero_x = i;
                    zero_y = j;
                }
            }
        }
        // for now just a zero, maybe can call alg here
        //  then maybe option for algorithm should be saved
        //  here
        heuristic = rhs.heuristic;
        // also might need to be changed...
        depth = rhs.depth;
        return *this;
    }
};

// overload output operator for a Node
ostream &operator<<(ostream &out, const Node &node);

class Problem
{
public:
    // variables
    Node initial_state;
    Node final_state;
    priority_queue<Node> unexplored;
    queue<Node> explored;
    int user_choice;

    Problem(int userChoice);

    void Search() const;


    void explore(const Node& exploring_node);
    //to test: instead of pushing to queue, output it instead

    //operators 

    //down
    Node down (const Node& exploring_node);
    //up
    Node up(const Node& exploring_node);
    //left
    Node left(const Node& exploring_node);
    //right
    Node right(const Node& exploring_node);

    //heuristics

    int uniform_heuristic(const Node& initial_state);
    // int a_misplaced_tile_heuristic(const Node& initial_state);
    // int a_euclidean_distance_heuristic(const Node& initial_state);
    // int find_final_x(int num);
    // int find_final_y(int num);
};

#endif