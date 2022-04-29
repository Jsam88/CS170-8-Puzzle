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

        Node* right(Node* curr_position) {
            if (curr_position -> empty_column == 2) {
                return nullptr;
            }
            Node* new_position = new Node(curr_position->matrix, curr_position -> cost + 1, curr_position);
            
            new_position -> move_node(curr_position -> empty_row, curr_position -> empty_column, curr_position -> empty_row, curr_position -> empty_column + 1);
            new_position -> empty_column += 1;
            
            return new_position;
        }

        Node* up(Node* curr_position) {
            if (curr_position -> empty_row == 0) {
                return nullptr;
            }
            Node* new_position = new Node(curr_position->matrix, curr_position -> cost + 1, curr_position);
            
            new_position -> move_node(curr_position -> empty_row, curr_position -> empty_column, curr_position -> empty_row - 1, curr_position -> empty_column);
            new_position -> empty_row -= 1;
            
            return new_position;
        }

        Node* down(Node* curr_position) {
            if (curr_position -> empty_row == 2) {
                return nullptr;
            }
            Node* new_position = new Node(curr_position->matrix, curr_position -> cost + 1, curr_position);
            
            new_position -> move_node(curr_position -> empty_row, curr_position -> empty_column, curr_position -> empty_row + 1, curr_position -> empty_column);
            new_position -> empty_row += 1;
            
            return new_position;
        }

        bool node_visited_already(Node* node_to_check, vector<Node*> visited_node){ //Do a check if the node (children) is visited already. (Utilized Resource 2)
            for (int i = 0; i < visited_node.size(); i++){
                bool visited = true;
                for (int j = 0; j < 3; j++){        //3 by 3
                    for (int k = 0; k < 3; k++){
                        if (node_to_check->matrix.at(j).at(k) != visited_node.at(i)->matrix.at(j).at(k)){
                            visited = false;
                        }
                    }
                }
        
        //We want to utilize this so that if its visited already in the search.
        //Use this in search. If visited already just pop it immediately off the queue and do not visit the nodes children
};


#endif


//RESOURCES USED: Talked to Partner Kevin Gaoabout what what we need. NEED A FUNCTION IN NODE THAT MOVES A NODE FROM ONE ROW AND COLUMN TO ANOTHER ROW AND COLUMN
//SWAPPING ELEMENTS IN COLUMNS http://www.cplusplus.com/forum/beginner/98334/
//To swap the elemnts in the rows do on the other vector!!! 
//On right add one to the last parameter. On down add one to the 3rd parameter ect.
//TO DO: create the rest of the moves (right, up, and down)

//Resource 2: //https://stackoverflow.com/questions/12962778/in-graph-algorithm-what-is-the-best-way-to-determine-if-a-node-is-visited