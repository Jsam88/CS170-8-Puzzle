#ifndef PROBLEM_H
#define PROBLEM_H

#include <string>
#include <queue>
#include <cmath>
#include <utility>
#include "Node.h"

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
/*We want up,down,left,right to move the * into the position the search algo wants it to move into
As stated in the project "Each node object has a pointer to its parent node. We use the pointers to 
parent nodes in order to create the final solution*/

//TO DO: Initialize a function in node that switches the positions 
        Node* left(Node* curr_position) {
            if (curr_position -> empty_column == 0) {       //WE cant move any further left
                return nullptr;
            }
            Node* new_position = new Node(curr_position->matrix, curr_position -> cost + 1, curr_position); //New position takes the current position in the matrix, updates the cost, then updates the current position
            
            new_position -> move_node(curr_position -> empty_row, curr_position -> empty_column, curr_position -> empty_row, curr_position -> empty_column - 1);
            new_position -> empty_column -= 1;          //SUBTRACT 1 here to move left in the vector of vectors
            
            return new_position;
        }
};

#endif
};


//RESOURCES USED: Talked to Partner about what what we need. NEED A FUNCTION IN NODE THAT MOVES A NODE FROM ONE ROW AND COLUMN TO ANOTHER ROW AND COLUMN
//TO DO: create the rest of the moves (right, up, and down)