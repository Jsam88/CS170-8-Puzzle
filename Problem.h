#ifndef PROBLEM_H
#define PROBLEM_H

#include <string>
#include <queue>
#include <cmath>
#include <utility>
#include "Node.h"
#include "Priority.h"

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

        int uniform_cost_search(int & nodesExpanded, int & queueMax, int & depth){
            priority_queue<Node*, vector<Node*>, Compare_node_cost> Q;      //Refer to Prioirty Queue explanation in Priority.h

            vector<Node*> visited_nodes;                                    //Creating vector to create track of the nodes expanded
                                                                            //node_visited_already will check if the node has been visited already

            Q.push(initial_puzzle_state);
 
                while(!Q.empty()) {                     //Compare the frontier size. If its queue is larger then the current max, update it
                    if(Q.size() > queueMax){
                        queueMax = Q.size();
                    }

                    Node* enqueued_node = Q.top();      //point to the top of the queue
                    Q.pop();                            //Remove the top of the queue

                    enqueued_node -> Print();
                    //Now we want to check if the node is at the goal (Check before we make any node moves)
                    //Now we want to check if the queued node (top)/current node if it has any children going left, right, up, or down
                    //If it does, then we want check if it was visited already so that we do not have to visit it again.
                    //While loop takes care of going through the nodes until it finishes the enqueued nodes completely.
                
                nodesExpanded++;        //Increment the nodes expanded
                
                if(enqueued_node->check_goal(enqueued_node, goal_state)) { //check if top node visited or goal
                    depth = enqueued_node -> depth;
                    return enqueued_node -> move_cost;
                }

                    
                    if(!node_visited_already(enqueued_node, visited_nodes)) {
                            visited_nodes.push_back(enqueued_node);

                        if (left(enqueued_node) != nullptr) {
                            if (!node_visited_already(left(enqueued_node), visited_nodes)){
                                Q.push(left(enqueued_node));
                            }
                        }

                        if (right(enqueued_node) != nullptr) {
                            if (!node_visited_already(right(enqueued_node), visited_nodes)){
                                Q.push(right(enqueued_node));
                            }
                        }

                        if (up(enqueued_node) != nullptr) {
                            if (!node_visited_already(up(enqueued_node), visited_nodes)){
                                Q.push(up(enqueued_node));
                            }
                        }

                        if (down(enqueued_node) != nullptr) {
                            if (!node_visited_already(down(enqueued_node), visited_nodes)){
                                Q.push(down(enqueued_node));
                            }
                        }
                    }
                }
            return -1;
        }

        void misplaced_heuristic(int & nodesExpanded, int & queueMax, int & depth){
            
        }


//Helper functions to move the * (Empty tile)
//We want to use these helper functions to do something to the current node and then we want to check the visited nodes.
//MAKE A HELPER FUNCTION THAT CHECK IF ITS VISITED
    private:
/*We want up,down,left,right to move the * into the position the search algo wants it to move into
As stated in the project "Each node object has a pointer to its parent node. We use the pointers to 
parent nodes in order to create the final solution*/

        Node* left(Node* curr_position) {
            if (curr_position -> empty_column == 0) {       //WE cant move any further left
                return nullptr;
            }
            Node* new_position = new Node(curr_position->matrix, curr_position -> move_cost + 1, curr_position, curr_position -> depth + 1); //New position takes the current position in the matrix, updates the cost, then updates the current position
            
            new_position -> move_node(curr_position -> empty_row, curr_position -> empty_column, curr_position -> empty_row, curr_position -> empty_column - 1);
            new_position -> empty_column -= 1;          //SUBTRACT 1 here to move left in the vector of vectors
            
            return new_position;
        }

        Node* right(Node* curr_position) {
            if (curr_position -> empty_column == 2) {
                return nullptr;
            }
            Node* new_position = new Node(curr_position->matrix, curr_position -> move_cost + 1, curr_position, curr_position -> depth + 1);
            
            new_position -> move_node(curr_position -> empty_row, curr_position -> empty_column, curr_position -> empty_row, curr_position -> empty_column + 1);
            new_position -> empty_column += 1;
            
            return new_position;
        }

        Node* up(Node* curr_position) {
            if (curr_position -> empty_row == 0) {
                return nullptr;
            }
            Node* new_position = new Node(curr_position->matrix, curr_position -> move_cost + 1, curr_position, curr_position -> depth + 1);
            
            new_position -> move_node(curr_position -> empty_row, curr_position -> empty_column, curr_position -> empty_row - 1, curr_position -> empty_column);
            new_position -> empty_row -= 1;
            
            return new_position;
        }

        Node* down(Node* curr_position) {
            if (curr_position -> empty_row == 2) {
                return nullptr;
            }
            Node* new_position = new Node(curr_position->matrix, curr_position -> move_cost + 1, curr_position, curr_position -> depth + 1);
            
            new_position -> move_node(curr_position -> empty_row, curr_position -> empty_column, curr_position -> empty_row + 1, curr_position -> empty_column);
            new_position -> empty_row += 1;
            
            return new_position;
        }

        //Use this in search. If visited already just pop it immediately off the queue and do not visit the nodes children
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
            if(visited){
                return true;
            }
            
            }
            return false;
        }
};

#endif


//RESOURCES USED: Talked to Partner Kevin Gaoabout what what we need. NEED A FUNCTION IN NODE THAT MOVES A NODE FROM ONE ROW AND COLUMN TO ANOTHER ROW AND COLUMN
//SWAPPING ELEMENTS IN COLUMNS http://www.cplusplus.com/forum/beginner/98334/
//To swap the elemnts in the rows do on the other vector!!! 
//On right add one to the last parameter. On down add one to the 3rd parameter ect.
//TO DO: create the rest of the moves (right, up, and down)

//Resource 2: //https://stackoverflow.com/questions/12962778/in-graph-algorithm-what-is-the-best-way-to-determine-if-a-node-is-visited