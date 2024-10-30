// #ifndef PROBLEM_H
// #define PROBLEM_H

// #include <iostream>
// using namespace std;

// //class or a struct? whats the difference
// struct Node{

//     //stores matrix
//     int arr[N][N];

//     //stores where 0 is in matrix
//     int x;
//     int y;

//     //heuristic -> h(n)
//     int cost;

//     //depth -> g(n)
//     int level;
// };

// class Problem{
//     public:
//         //variables
//         int initial_state[3][3];

//         //functions
//         //inherit the curr state of the prior node, the coords of x,y, and level (g(n))
//         Node* make_node(int arr[N][N], int x, int y, int level);

//         //operators 

//         //down
//         //int x and int y are the coordinates for wherever 0 is
//         void down(int arr[N][N], int x, int y);
//         //up
//         void up(int arr[N][N], int x, int y);
//         //left
//         void left(int arr[N][N], int x, int y);
//         //right
//         void right(int arr[N][N], int x, int y);

// };


// #endif