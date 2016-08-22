//
//  PDBLoader.cpp
//  cellVIEWinCinder
//
//  Created by David Kouřil on 19/08/16.
//
//

#include "PDBLoader.hpp"
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

vector<string> split(string line)
{
    vector<string> results;
    string::const_iterator end = line.end();
    string::const_iterator current = line.begin();
    string::const_iterator next = find(current, end, ' ');
    while (next != end)
    {
        results.push_back(string(current, next));
        current = next + 1;
        next = find(current, end, ' ');
    }
    results.push_back(string(current, next));
    return results;
}

Molecule * PDBLoader::loadFromFile(const char * path)
{
    Molecule * mol = new Molecule;
    
    std::fstream ifs(path, std::ifstream::in);
    string line;
//    int i = 0;
    while (std::getline(ifs, line))
    {
        auto tokens = split(line);
        if (tokens[0] == "ATOM")
        {
            string xStr = tokens[20];
            string yStr = tokens[21];
            string zStr = tokens[22];
            
            double x = ::atof(xStr.c_str());
            double y = ::atof(yStr.c_str());
            double z = ::atof(zStr.c_str());
            
            Atom atom;
            atom.position.x = x;
            atom.position.y = y;
            atom.position.z = z;
            
            mol->atoms.push_back(atom);
//            if (i > 0) return nullptr;
//            int tokenNumber = 0;
//            for (auto string : tokens) {
//                cout << tokenNumber << ": " << string << endl;
//                tokenNumber += 1;
//            }
//            cout << endl;
//            i += 1;
        }
    }
    
    return mol;
}