//
//  Molecule.hpp
//  cellVIEWinCinder
//
//  Created by David Kouřil on 19/08/16.
//
//

#ifndef Molecule_hpp
#define Molecule_hpp

#include <stdio.h>
#include <vector>
#include "Atom.hpp"

struct Molecule {
    std::vector<Atom> atoms;
};

#endif /* Molecule_hpp */
