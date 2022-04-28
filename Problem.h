#ifndef PROBLEM_H
#define PROBLEM_H

#include <string>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;
//give it to the search algorithm as the input parameter. 
class Problem {
    private:                                                        //Pass in inital and goal state of the 8-puzzle
        Node* initial_puzzle_state;
        Node* goal_state;

    public:                                                         //Implement uniform cost search, a * missing tile and euclidean search
        Problem(Node* initial_puzzle_state, Node* goal_state) {
                this->initial_puzzle_state = initial_puzzle_state;
                this->goal_state = goal_state;
        }



//Helper functions to move the * (Empty tile)
//We want to use these helper functions to do something to the current node and then we want to check the visited nodes.
//MAKE A HELPER FUNCTION THAT CHECK IF ITS VISITED
    private:
//We want up,down,left,right
};
#endif