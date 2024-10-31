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

void Problem::Search() const
{

    // cout << "Searching..." << endl;
    // cout << "initial_state: " << initial_state << endl;
    // cout << "final_state: " << final_state << endl;

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

// Node* make_node(int arr[N][N], int x, int y, int level){
//     Node* node = new Node;
//     node->arr = arr;

// }

// operators
// down
// int x and int y are the coordinates for wherever 0 is
//  Node Problem::down(Node arr[N][N], int x, int y){
//      //new node called here, copy of the parent
//      if(!(y+1 > 2)){
//          swap(arr[x][y], arr[x][y+1]);
//      }
//      return arr; //??
//  }
//  //up
//  Node Problem::up(Node arr[N][N], int x, int y){
//      if(!(y-1 < 0)){
//          swap(arr[x][y], arr[x][y-1]);
//      }
//      return arr; //??
//  }
//  //left
//  Node Problem::left(Node arr[N][N], int x, int y){
//      if(!(x-1 < 0)){
//          swap(arr[x][y], arr[x-1][y]);
//      }
//      return arr; //??
//  }
//  //right
//  Node Problem::right(Node arr[N][N], int x, int y){
//      if(x+1 > 2){
//          swap(arr[x][y], arr[x+1][y-1]);
//      }
//      return arr; //??
//  }

// is search the same for all the searchs? just different in heuristic?
// how do we do heuristic? so that we just need one algorithm?

// void Problem::search(Problem p, queuing function){
//     Problem p1;

//     //we make a new node

//     //Node temp = make_node(p1.initial_state);

//     //unexplored_queue.push(temp);

//     //p1.initial_state.down(....);

// }

// make a queue called nodes
// nodes = MAKE_QUEUE(MAKE_NODE(p.initial_state))

// while(!nodes.empty)

// nodes = popfront(nodes)

// say curr_node is what was just popped

// if  p.goal_state == curr_node

// nodes = queueing function(nodes, expand(node, p.operators))
