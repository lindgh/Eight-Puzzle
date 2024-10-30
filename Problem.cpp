#include "Problem.h"

#include <iostream>
using namespace std;

ostream &operator<<(ostream &out, const Node &node)
{
    out << "Test Node";
    return out;
}

void Problem::Search() const
{

    // cout << "Searching..." << endl;
    // cout << "initial_state: " << initial_state << endl;
    // cout << "final_state: " << final_state << endl;
}

// constructor
Problem::Problem()
{
    //
    cout << "help im in the constructor help!!!" << endl;
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
