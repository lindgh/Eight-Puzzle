#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>

using namespace std;

struct Node{

    //stores matrix
    int table[3][3];

    //stores where 0 is in matrix
    int x;
    int y;

    //heuristic -> h(n)
    int cost;

    //depth -> g(n)
    int level;

    //overload operator >
};

class Problem{
    public:

        //final_state

        Node make_node(int arr[N][N], int x, int y, int level);

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