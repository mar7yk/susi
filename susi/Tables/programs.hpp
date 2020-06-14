//
//  Programs.hpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef Programs_hpp
#define Programs_hpp

#include <stdio.h>

#include "string.hpp"
#include "vector.h"

#include "Table.h"

class Programs : public Table {
    size_t nextID;
    
    struct Program {
        size_t ID;
        String name;
    };
    
    Vector<Program> programs;
    
    void load(const String& file) override;
    
public:
    Programs();
    
    void save() const override;
    
    void add(const String& name);
    
    String getNameByID(const size_t id) const;
    
    size_t getIDByName(const String& name) const;
};

#endif /* Programs_hpp */
