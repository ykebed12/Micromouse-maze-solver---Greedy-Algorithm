#include <iostream>
#include <string>
#include <vector>

#include "API.h"

using namespace std;

int H(const int *nextNode, const vector<int *> &goalNodes);
int *bestOption(vector<int *> &options, const vector<int *> &goalNodes);

void log(const string &text) {
    cerr << text << endl;
}

int main(int argc, char *argv[]) {
    vector<int[]> frontier;
    vector<int[]> visited;

    log("Running...");
    API::setColor(0, 0, 'b');
    API::setText(0, 0, "abc");
    // while (true) {
    //     if (!API::wallLeft()) {
    //         API::turnLeft();
    //     }
    //     while (API::wallFront()) {
    //         API::turnRight();
    //     }
    //     API::moveForward();
    // }
}

/*
 * Greedy heuristic function
 */
int H(const int *nextNode, const vector<int *> &goalNodes) {
    int minDistance = INT16_MAX, distance, i;

    for (i = 0; i < goalNodes.size(); i++) {
        distance = abs(nextNode[0] - goalNodes.at(i)[0]) +
                   abs(nextNode[1] - goalNodes.at(i)[1]);

        minDistance = min(distance, minDistance);
    }

    return minDistance;
}

/*
 * This function returns the best coordinates (1-Dim int array of size 2) 
 * according to the greedy search algorithm. These cordinates are removed from
 * options vector. 
 * 
 */
int *bestOption(vector<int *> &options, const vector<int *> &goalNodes) {
    int *bestNode = nullptr, *node;
    int minDistance = INT16_MAX, distance, indexOfBestNode = 0;

    for (int i = 0; i < options.size(); i++) {
        node = options.at(i);
        distance = H(node, goalNodes);

        if (distance < minDistance) {
            minDistance = distance;
            bestNode = node;
            indexOfBestNode = i;
        }
    }

    options.erase(options.begin() + indexOfBestNode);

    return bestNode;
}

