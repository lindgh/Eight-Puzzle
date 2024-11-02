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

void Problem::search()
{
    bool foundSolution = false;

    // FIRST ORDER OF BUSINESS!! push onto queue.
    unexplored.push(initial_state); // test: good
    Node exploring_node;

    while (!unexplored.empty() && !foundSolution)
    {
        if (unexplored.size() > maxQueueNodes)
        {
            maxQueueNodes = unexplored.size();
        }
        exploring_node = unexplored.top(); // remove node from top of queue

        cout << "The best state to expand with g(n) = " << exploring_node.depth
             << ", h(n) = " << exploring_node.heuristic << " is...\n"
             << exploring_node << endl;

        unexplored.pop();
        explored.push_back(exploring_node);

        if (exploring_node == final_state) // check if final soln
        {
            cout << "\nYAY! Solution has been found!" << endl;
            foundSolution = true;
            // below should be setting all of final_state's data to exploring_node's
            final_state = exploring_node;
        }
        else
        {
            explore(exploring_node);
        }
    }

    // cout << "queue empty now!" << endl;
    if (!foundSolution)
    {
        cout << "solution hasn't been found :(" << endl;
    }
}

void Problem::trace()
{
    // using final_state, save backtracing to problem's solution stack
    // cout << "pushing final_state to soln stack: \n"
    //      << solution.top() << endl;

    // check if equal to initial state, if not then access its parent index
    Node temp;
    temp = final_state;
    solution.push(temp);
    int solution_nodes = 1;

    while (!(temp == initial_state))
    {
        temp = explored.at(temp.parent);
        solution.push(temp);
        ++solution_nodes;
    }

    // count nodes explored
    int numExplored = 0;
    while (!explored.empty())
    {
        explored.pop_back();
        ++numExplored;
    }

    cout << "To solve this problem, our search algorithm expanded a total of "
         << numExplored << " nodes." << endl;
    cout << "The maximum number of nodes in the queue at any one time: "
         << maxQueueNodes << endl;
    cout << "The depth of the goal node was " << final_state.depth << "."
         << endl;
    cout << "Nodes in solution: " << solution_nodes << endl;
    cout << "\nBacktracking: \n"
         << endl;

    // below prints out the backtracking of the solution
    while (!solution.empty())
    {
        cout << solution.top() << endl;
        solution.pop();
    }
}

// constructor
Problem::Problem(int userChoice, int temp_initial[3][3])
{
    // to store user choice for other functions to use
    algorithmChoice = userChoice;
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

    maxQueueNodes = 0;
}

// left
Node Problem::left(const Node &exploring_node)
{
    Node temp = exploring_node;
    swap(temp.table[temp.zero_x][temp.zero_y], temp.table[temp.zero_x][temp.zero_y - 1]);
    temp.zero_y = temp.zero_y - 1;
    temp.depth += 1;
    temp.parent = explored.size() - 1;
    temp.heuristic = calculateHeuristic(temp);

    return temp;
}

// up
Node Problem::up(const Node &exploring_node)
{
    Node temp = exploring_node;
    swap(temp.table[temp.zero_x][temp.zero_y], temp.table[temp.zero_x - 1][temp.zero_y]);
    temp.zero_x = temp.zero_x - 1;
    temp.depth += 1;
    temp.parent = explored.size() - 1;
    temp.heuristic = calculateHeuristic(temp);

    return temp;
}

// down
Node Problem::down(const Node &exploring_node)
{
    Node temp = exploring_node;
    swap(temp.table[temp.zero_x][temp.zero_y], temp.table[temp.zero_x + 1][temp.zero_y]);
    temp.zero_x = temp.zero_x + 1;
    temp.depth += 1;
    temp.parent = explored.size() - 1;
    temp.heuristic = calculateHeuristic(temp);

    return temp;
}

// right
Node Problem::right(const Node &exploring_node)
{
    Node temp = exploring_node;
    swap(temp.table[temp.zero_x][temp.zero_y], temp.table[temp.zero_x][temp.zero_y + 1]);
    temp.zero_y = temp.zero_y + 1;
    temp.depth += 1;
    temp.parent = explored.size() - 1;
    temp.heuristic = calculateHeuristic(temp);

    return temp;
}

// OTHER HEURISTICS

// for euclidean distance
int Problem::find_final_x(int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (num == final_state.table[i][j])
            {
                return i;
            }
        }
    }
    return 0;
}

int Problem::find_final_y(int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (num == final_state.table[i][j])
            {
                return j;
            }
        }
    }
    return 0;
}

int Problem::uniform_heuristic(const Node &temp)
{
    return 0;
}

int Problem::a_misplaced_tile_heuristic(const Node &temp)
{
    int res;
    // for each index [n][n]-
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // if initial != final position the calclulate
            // checks if value in initial = value in final
            if (temp.table[i][j] != final_state.table[i][j])
            {
                // we need to find where the position supposed to for value
                res += 1;
            }
        }
    }
    return res;
}

int Problem::a_euclidean_distance_heuristic(const Node &temp)
{
    int final_x;
    int final_y;
    int res = 0;
    int tempA = 0;
    int tempB = 0;
    // for each index [n][n]
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // if initial != final position the calclulate
            // checks if value in initial = value in final
            if (temp.table[i][j] != final_state.table[i][j])
            {
                // we need to find where the position supposed to be
                final_x = find_final_x(temp.table[i][j]);
                final_y = find_final_y(temp.table[i][j]);
                // if this is error, calculate x and y seperate then add
                tempA = pow((i - final_x), 2);
                tempB = pow((j - final_y), 2);
                res += sqrt(tempA + tempB);
            }
        }
    }
    return res;
}

bool Problem::repeated(const Node &exploring_node)
{
    bool detected = false;

    // check explored vector to see if exploring_node is repeated
    for (int i = 0; i < explored.size(); i++)
    {
        if (explored.at(i) == exploring_node)
        {
            detected = true;
            break;
        }
    }

    return detected;
}

// call heuristic function based on algorithmChoice
int Problem::calculateHeuristic(const Node &temp)
{
    int h = 0;

    switch (algorithmChoice)
    {
    case 1:
        h = uniform_heuristic(temp);
        break;
    case 2:
        // cout << "\nA* with the Misplaced Tile heuristic under construction..." << endl;
        h = a_misplaced_tile_heuristic(temp);
        break;
    case 3:
        // cout << "\nA* with the Euclidean distance heuristic under construction..." << endl;
        h = a_euclidean_distance_heuristic(temp);
        break;
    }

    return h;
}

// if ever error, recheck zero_x and zero_y, sorry i was lazy
// explores all valid children from operations
void Problem::explore(const Node &exploring_node)
{
    // each section makes valid child, adds it to queue

    // up
    if (exploring_node.zero_x > 0)
    {
        Node explore_child = up(exploring_node);
        if (!repeated(explore_child))
        {
            unexplored.push(explore_child);
        }
    }

    // left
    if (exploring_node.zero_y > 0)
    {
        Node explore_child = left(exploring_node);
        if (!repeated(explore_child))
        {
            unexplored.push(explore_child);
        }
    }

    // down
    if (exploring_node.zero_x < 2)
    {
        Node explore_child = down(exploring_node);
        if (!repeated(explore_child))
        {
            unexplored.push(explore_child);
        }
    }

    // right
    if (exploring_node.zero_y < 2)
    {
        Node explore_child = right(exploring_node);
        if (!repeated(explore_child))
        {
            unexplored.push(explore_child);
        }
    }

    // if you wanna test with node return type
    // make sure to comment the queue line
    // return exploring_node;
}