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
    while (std::getline(ifs, line))
    {
        auto tokens = split(line);
        if (tokens[0] == "ATOM")
        {
            
        }
    }
    
    Atom a;
    mol->atoms.push_back(a);
    return mol;
}