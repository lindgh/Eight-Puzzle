#include "Problem.h"

#include <iostream>
#include <queue>
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
    //to store user choice for other functions to use
    user_choice = userChoice;
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



//left
Node Problem::left(const Node& exploring_node){
    Node temp = exploring_node;
    swap(temp.table[temp.zero_x][temp.zero_y], temp.table[temp.zero_x][temp.zero_y-1]);
    temp.zero_y = temp.zero_y - 1;
    temp.depth += 1;

    //call heuristic for uniform rn
    if(user_choice == 1){
        temp.heuristic = uniform_heuristic(exploring_node);
    }
    else if(user_choice == 2){
        temp.heuristic = a_misplaced_tile_heuristic(exploring_node);
    }
    else if(user_choice == 3){
        temp.heuristic = a_euclidean_distance_heuristic(exploring_node);
    }
    else{
        cout << "Not done yet!" << endl;
    }
    //then make calls to the other heuristic

    return temp;

}
//up
Node Problem::up(const Node& exploring_node){
    Node temp = exploring_node;
    swap(temp.table[temp.zero_x][temp.zero_y], temp.table[temp.zero_x-1][temp.zero_y]);
    temp.zero_x = temp.zero_x - 1;
    temp.depth += 1;

    //call heuristic for uniform rn
    if(user_choice == 1){
        temp.heuristic = uniform_heuristic(exploring_node);
    }
    else if(user_choice == 2){
        temp.heuristic = a_misplaced_tile_heuristic(exploring_node);
    }
    else if(user_choice == 3){
        temp.heuristic = a_euclidean_distance_heuristic(exploring_node);
    }
    else{
        cout << "Not done yet!" << endl;
    }
    //then make calls to the other heuristic

    return temp;

}


//down
Node Problem::down(const Node& exploring_node){
    Node temp = exploring_node;
    swap(temp.table[temp.zero_x][temp.zero_y], temp.table[temp.zero_x+1][temp.zero_y]);
    temp.zero_x = temp.zero_x + 1;
    temp.depth += 1;

    //call heuristic for uniform rn
    if(user_choice == 1){
        temp.heuristic = uniform_heuristic(exploring_node);
    }
    else if(user_choice == 2){
        temp.heuristic = a_misplaced_tile_heuristic(exploring_node);
    }
    else if(user_choice == 3){
        temp.heuristic = a_euclidean_distance_heuristic(exploring_node);
    }
    else{
        cout << "Not done yet!" << endl;
    }
    //then make calls to the other heuristic

    return temp;

}


//right
Node Problem::right(const Node& exploring_node){
    Node temp = exploring_node;
    swap(temp.table[temp.zero_x][temp.zero_y], temp.table[temp.zero_x][temp.zero_y+1]);
    temp.zero_y = temp.zero_y + 1;
    temp.depth += 1;

    //call heuristic for uniform rn
    if(user_choice == 1){
        temp.heuristic = uniform_heuristic(exploring_node);
    }
    else if(user_choice == 2){
        temp.heuristic = a_misplaced_tile_heuristic(exploring_node);
    }
    else if(user_choice == 3){
        temp.heuristic = a_euclidean_distance_heuristic(exploring_node);
    }
    else{
        cout << "Not done yet!" << endl;
    }
    //then make calls to the other heuristic

    return temp;

}

//for euclidean distance
int Problem::find_final_x(int num){
    for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(num == final_state.table[i][j]){
				return i;
				
			}
		}
	}
	return 0;

}

int Problem::find_final_y(int num){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(num == final_state.table[i][j]){
                return j;
                
            }
        }
	}
	return 0;
}


int Problem::uniform_heuristic(const Node& initial_state){
    return 0;
}

int Problem::a_misplaced_tile_heuristic(const Node& initial_state){
    int res;
	//for each index [n][n]-
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			//if initial != final position the calclulate
			//checks if value in initial = value in final
			if(initial_state.table[i][j] != final_state.table[i][j]){
				//we need to find where the position supposed to for value
				res += 1;
			}
		}
	}
	return res;

}


int Problem::a_euclidean_distance_heuristic(const Node& initial_state){
    int final_x;
	int final_y;
	int res = 0;
	//for each index [n][n]
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			//if initial != final position the calclulate
			//checks if value in initial = value in final
			if(initial_state.table[i][j] != final_state.table[i][j]){
				//we need to find where the position supposed to be
				final_x = find_final_x(initial_state.table[i][j]);
				final_y = find_final_y(initial_state.table[i][j]);
				//if this is error, calculate x and y seperate then add
				res += sqrt((i-final_x)^2 + (j-final_y)^2);
			}
		}
    }
    return res;
}

//if ever error, recheck zero_x and zero_y, sorry i was lazy
//explores all valid children from operations
void Problem::explore(const Node& exploring_node){
        //each section makes valid child, adds it to queue

        //up
        if(exploring_node.zero_x > 0){
            Node explore_child = up(exploring_node);
            unexplored.push(explore_child);
        }

        //left
        if(exploring_node.zero_y > 0){
            Node explore_child = left(exploring_node);
            unexplored.push(explore_child);
        }

        //down
        if(exploring_node.zero_x < 2){
            Node explore_child = down(exploring_node);
            unexplored.push(explore_child);
        }

        //right
        if(exploring_node.zero_y < 2){
            Node explore_child = right(exploring_node);
            unexplored.push(explore_child);
        }
        //if you wanna test with node return type
        //make sure to comment the queue line
        //return exploring_node;
    }