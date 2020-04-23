//
//  programs.hpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef programs_hpp
#define programs_hpp

#include <stdio.h>
#include <fstream>

#include "program.hpp"

class Programs {
    const static String file;
    static size_t newID;
    
    size_t size;
    size_t capacity;
    Program* programs;
    
    void resize(const size_t newCapacity);
    
public:
    Programs();
    ~Programs();
    
    void add(const String& name);
    
    void save();
    
    String getName(const size_t id) const;
    
    size_t getID(const String& name) const;
};

#endif /* programs_hpp */
