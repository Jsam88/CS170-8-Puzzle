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
        return p1 -> move_cost < p2 -> move_cost;
    }
};

#endif

// References used: https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/

// NOTES:       // When we use priority_queue with  structure
                // then we need this kind of syntax where
                // Compare_node_cost is the functor or comparison function
                // insert an object in priority_queue by using
                // the Compare_node_cost structure constructor