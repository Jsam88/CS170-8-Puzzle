#ifndef NODE_H
#define NODE_H

#include <cmath>
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
    
    Node(vector <vector<int> > Matrix, int move_cost, Node* parentNode) {
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
    
    //NEED A WAY TO MOVE * NODE IN MATRIX
    
    void move_node(int first_row, int first_column, int new_row, int new_column) {
        int temp = this -> matrix.at(new_row).at(new_column);
        matrix.at(new_row).at(new_column) = matrix.at(first_row).at(first_column);
        matrix.at(first_row).at(first_column) = temp;
    }

    //RESOURCES USED: modified the implementation of http://www.cplusplus.com/forum/beginner/9126/ (How to print a 3 by 3 matrix)
    void Print() {
        for (int i = 0; i < matrix.size(); i++) {
            cout << "{";
            for (int j = 0; j < matrix.at(i).size(); j++) {
                cout << matrix[i][j];
                if (j != matrix[i].size() - 1){
                    cout << " ";
                }
            }
            cout << "}";
            cout << endl;
        }
        cout << endl;
    }
};

class Heuristic {
    public:
        Heuristic(){}
        virtual int heuristic(Node* current_position, Node* goal_position) = 0;     //VIRTUAL to ensure that the correct function is called on the object
};

//Given a node, compare it to where it belongs.
class misplaced_tile_heuristic : public Heuristic {
    public:
        misplaced_tile_heuristic(){};       //constructor for data member of the current/goals position

        virtual int heuristic(Node* current_position, Node* goal_position){
            int distance = 0;
            for (int i = 0; i < 3; i++) {               //double for loop allows for coordinates in matrix like (y,x)
                for (int j = 0; j < 3; j++) {
                    if (current_position -> matrix.at(i).at(j) != goal_position -> matrix.at(i).at(j)) {
                        distance++;
                    }
                }
            }
            return distance;
        }
};

#endif

/*EX VISUALIZATION FOR HEURISTIC VALUE:
Current puzzle:
        |1 2 3|
        |4 5 6|
        |7 * 8|

Goal state:
        |1 2 3|
        |4 5 6|
        |7 8 *|

heuristic(Node pointing to start, Node* pointing to goal)
distance from goal should return 1 since only the 8 is misplaced.
Checks all the positions (0,0) to (3,3)
*/