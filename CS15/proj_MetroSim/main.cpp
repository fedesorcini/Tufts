/*
 *      main.cpp
 *      MetroSim
 *      Comp 15 Proj 1
 *      Federico Sorcini
 */

#include "MetroSim.h"
#include <iostream>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc < 3 | argc > 4) {
        std::cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]"
            << std::endl;
        return EXIT_FAILURE;
    }

    std::string stationsFile = argv[1];
    std::string outputFile = argv[2];
    std::string commandsFile;
    if (argc == 4) {
        commandsFile = argv[3];
    } else {
        commandsFile = "";
    }

    MetroSim myMetroSim(stationsFile, outputFile, commandsFile);
    myMetroSim.run();

    std::cout << "Thanks for playing MetroSim. Have a nice day!" << std::endl;

    return EXIT_SUCCESS;
}
