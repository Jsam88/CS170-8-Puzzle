#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <sstream>

using namespace std;

int main() {
    vector< vector<int> > puzzle_goal = {{1,2,3}, {4,5,6}, {7,8,0}}; //Set vector with a goal value for *search to find
    vector< vector<int> > puzzle_one = {{1,0,3}, {4,2,6}, {7,5,8}}; //Given puzzle from pdf image
    vector< vector<int> > custom_initial_vec; //vector for userinput
    bool userPuzzle = false;
    
    cout << "Welcome to 862148753's 8 puzzle solver." << endl << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;

    int userInput;

    cin >> userInput;

    while (userInput != 1 && userInput != 2) {
        cout << "Invalid input. Try again." << endl;
        cin >> userInput;
    }

    //The default puzzle is set. We only switch to the userPuzzles if the input is 2 and if they finish putting in valid inputs.
    //If it is, then we set it to true and call the algorithm on the custom vector of vectors.
    //we have to grabs 9 numbers from the user(3 sets of 3 user inputs) to make a 3 by 3 matrix
    
    if (userInput == 2) {
        cout << "Enter your puzzle, use a zero to represent the blank" << endl <<  "Enter the first row, use space or tabs between numbers\n";
        stringstream streamInput;      //Using string stream to convert the user's inputted values to integers
        int customLineInputs;
        string userValues;
        vector<int> firstRow;
        vector<int> secondRow;
        vector<int> thirdRow;

        getline(cin, userValues);
        streamInput << userValues;

        while(streamInput >> customLineInputs) {        //Extract the string and convert it to an integer
            firstRow.push_back(customLineInputs);       //While streaming, push it back onto the respective rows.
        }                                               //Repeat this for the next two rows and clear the streams Input for new user values

        streamInput.clear();
        cout << "Enter the second row, use space or tabs between numbers\n";
        getline(cin, userValues);
        streamInput << userValues;

        while(streamInput >> customLineInputs) {
            secondRow.push_back(customLineInputs);
        }

        streamInput.clear();
        cout << "Enter the third row, use space or tabs between numbers\n";
        getline(cin, userValues);
        streamInput << userValues;

        while(streamInput >> customLineInputs) {
            thirdRow.push_back(customLineInputs);
        }
        //PUSH BACK THE VECTOR ONTO VECTOR TO MAKE (3 x 3) MATRIX
        custom_initial_vec.push_back(firstRow);
        custom_initial_vec.push_back(secondRow);
        custom_initial_vec.push_back(thirdRow);
        userPuzzle = true;                              //Set the userPuzzle to true so that we know we are using a custom inputted puzzle
    }

    cout << "Enter your choice of algorithm." << endl << "(1) Uniform Cost Search" << endl << "(2) Misplaced Tile Heuristic" << endl << "(3) the Eucledian Distance Heuristic.\n";

    cin.clear(); //Ensure that the user input is new
    int userInput = 0;
    cin >> userInput;

    while (userInput != 1 && userInput != 2 && userInput !=3) {
        cout << "Invalid input. Try again." << endl;
        cin >> userInput;
    }


    int queueMax = 0;           
    int nodesExpanded = 0; 

    if (userInput == 1){
    }

    else if (userInput == 2){
    }

    else if (userInput == 3){
    }
    
    cout << "To solve this problem the search expanded a total of  " << nodesExpanded << " nodes" << endl;
    cout << "The maximum number of nodes in the queue at any one time: " << queueMax << endl;

    return 0;
}