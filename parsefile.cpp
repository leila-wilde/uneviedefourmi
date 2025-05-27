/* Program to parse the anthill text files */

#include <iostream>
#include <fstream> // use to read and write to a file
#include <map>
#include <vector>
#include <regex>

int main() {

    std::string filename = "./fourmilieres/fourmiliere_zero.txt";
    std::ifstream input;

    input.open(filename);

    if(!input.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    // Regular Expressions:

    // 1. For ant count, e.g. "f=10"
    std::regex antRegex(R"(f\s*=\s*(\d+))");

    // 2. For rooms, e.g. "S1 { 2 }" or "S2" (no capacity specified).
    std::regex roomRegex(R"(([S]\w+)(?:\s*\{\s*(\d+)\s*\})?)");

    // 3. For tunnels: e.g. "S1 - S2". This assumes room labels have no spaces.
    std::regex tunnelRegex(R"(([S]\w+)\s*-\s*([S]\w+))");

    // Data storage
    int numAnts = 0;
    std::map<std::string, int> rooms;
    // std::vector tunnels;

    while() {
        //get ant count, rooms (vertices) with capacity and tunnels (edges)

        //error if either number of ants, a room Sv, a room Sd, an edge with Sv or an edge with Sd not found.

        input.close();

        // Give vestibule (start) and dormitory (end) capacity equal to number of ants
        rooms["Sv"] = numAnts;
        rooms["Sd"] = numAnts;

        // Output the parsed data:

    }

    return 0;
    
}

