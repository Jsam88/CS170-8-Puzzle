#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node{
 public:
    vector< vector<int> > matrix; //We need a matrix to hold the values of the puzzle (Vector of a vector)

    int empty_column = 0;         //Column of the empty spot with a *   |1 2 3 |
                                  //                                    |4 5 6 |
    int empty_row = 0;            //Row of the empty spot with a *      |7 8 * |

    int move_cost = 0; //cost of node and path to get to goal state 

    //We use the pointers to parent nodes in order to create the final solution (by following the parents of the goal 
    //node all the way up to the root of the tree).
    Node* parentNode; //used for printing solution path

    // Node() will have three parameters. The matrix values, cost to move, and the parent node to decide the next move
    
    Node(vector<vector<int>> Matrix, int cost, Node* parentNode) {
        this->matrix = Matrix;
        this->move_cost = move_cost;
        for (int i = 0; i < Matrix.size(); i++) {
            for (int j = 0; j < Matrix.at(i).size(); j++) {
                if(Matrix.at(i).at(j) == 0) {
                    empty_row = i;
                    empty_column = j;
                }
            }
        }
        this->parentNode = parentNode;
    }
};
    

#endif 