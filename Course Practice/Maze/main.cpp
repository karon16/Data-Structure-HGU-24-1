//
// Created by Christopher Buhendwa on 4/10/24.
//
#include "Stack.h"
#include <iostream>
#include <vector>

using namespace std;

// Function to generate maze
vector<vector<int> > generateMaze(int height, int width);

int main() {
    // Generate the maze
    vector<vector<int> > maze = generateMaze(8, 8); // Adjust height and width as needed

    // Print the generated maze
    for (size_t i = 0; i < maze.size(); ++i) {
        const vector<int>& row = maze[i];
        for (size_t j = 0; j < row.size(); ++j) {
            int cell = row[j];
            cout << cell << " ";
        }
        cout << endl;
    }

    // Use the Stack to perform operations on the maze if needed
    Stack* stack = new Stack(3);
    Element* item;

    item = new Element;

    // Cleanup
    delete stack;
    delete item;

    return 0;
}

// Function to generate a random maze
vector<vector<int> > generateMaze(int height, int width) {
    // Initialize the maze with walls
    vector<vector<int> > maze(height + 2, vector<int>(width + 2, 1));

    // Set the entrance and exit
    maze[1][1] = 0;
    maze[height][width] = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate the maze
    for (int i = 2; i <= height - 1; i++) {
        for (int j = 2; j <= width - 1; j++) {
            // Randomly decide whether to create a wall or not
            if (rand() % 2 == 0) {
                maze[i][j] = 1; // Wall
            } else {
                maze[i][j] = 0; // Path
            }
        }
    }

    return maze;
}
