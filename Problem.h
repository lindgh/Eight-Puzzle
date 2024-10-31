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

    Problem(int userChoice);
    void Search() const;


    Node explore(Node& exploring_node const);

    //operators 

    //down
    //int x and int y are the coordinates for wherever 0 is
    Node down(Node& exploring_node const);
    //up
    void up(Node& exploring_node const);
    //left
    void left(Node& exploring_node const);
    //right
    void right(Node& exploring_node const);

    //heuristics

    int uniform_heuristic(Node& initial_state const);
    int a_misplaced_tile_heuristic(Node& initial_state const);
    int a_euclidean_distance_heuristic(Node& initial_state const);
    int find_final_x(int num);
    int find_final_y(int num);
};

#endif