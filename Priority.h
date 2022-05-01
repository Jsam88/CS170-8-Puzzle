#ifndef PRIORITY_H
#define PRIORITY_H

#include "Node.h"
#include "Problem.h"

using namespace std;

struct Compare_node_cost {
    bool operator()(Node* p1, Node* p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1 -> move_cost > p2 -> move_cost;
    }
};

//Only thing being done differently in the priority queue is that we are using the heuristic object to compare the nodes
//and get that value to add to the move cost giving us A * missing tile search. Then by using the same uniform cost functions
//we get uniform cost + misplaced tile = an A*search function
struct misplaced_tile_cost {                       //Helper Class for the Priority Queue Functions
    virtual bool operator() (Node* p1, Node* p2) {

        vector<vector<int>> puzzle_goal = {{1,2,3}, {4,5,6}, {7,8,0}};

        Node* final_goal_state = new Node(puzzle_goal, 0, nullptr, 0);

        Heuristic* heuristic_object = new misplaced_tile_heuristic();        //instantiate new misplaced tile heuristic distance check implemented inside node
        
        return (p1 -> move_cost) + heuristic_object->heuristic_compare(p1, final_goal_state) > p2->move_cost + heuristic_object->heuristic_compare(p2, final_goal_state);
    }   //Gets the first nodes current move costs, adds it to the # of misplaced tiles, then sorts it in cheapest move cost order
};

struct euclidean_cost {                           //Helper Class for the Priority Queue Functions
virtual bool operator() (Node* p1, Node* p2) {

        vector<vector<int>> puzzle_goal = {{1,2,3}, {4,5,6}, {7,8,0}};

        Node* final_goal_state = new Node(puzzle_goal, 0, nullptr, 0);

        Heuristic* heuristic_object = new euclidean_heuristic();        //instantiate new misplaced tile heuristic distance check implemented inside node
        
        return (p1 -> move_cost) + heuristic_object->heuristic_compare(p1, final_goal_state) > p2->move_cost + heuristic_object->heuristic_compare(p2, final_goal_state);
    }   //Gets the first nodes current move costs, adds it to the # of misplaced tiles, then sorts it in cheapest move cost order
};

#endif

// References used: https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/
//https://visualstudiomagazine.com/articles/2015/10/30/sliding-tiles-c-sharp-ai.aspx

// NOTES:       // When we use priority_queue with  structure
                // then we need this kind of syntax where
                // Compare_node_cost is the functor or comparison function
                // insert an object in priority_queue by using
                // the Compare_node_cost structure constructor