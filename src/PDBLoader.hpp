//
//  PDBLoader.hpp
//  cellVIEWinCinder
//
//  Created by David Kouřil on 19/08/16.
//
//

#ifndef PDBLoader_hpp
#define PDBLoader_hpp

#include <stdio.h>
#include "Molecule.hpp"

class PDBLoader {
    
public:
    static Molecule * loadFromFile(const char * path);
    
};

#endif /* PDBLoader_hpp */
