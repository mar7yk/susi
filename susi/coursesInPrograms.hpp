//
//  coursesInPrograms.hpp
//  susi
//
//  Created by Marty Kostov on 23.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef coursesInPrograms_hpp
#define coursesInPrograms_hpp

#include <stdio.h>
#include <fstream>

#include "string.hpp"

class CoursesInPrograms {
    const static String file;
    
    struct CourseInProgram {
        size_t courseID;
        size_t programID;
    };
    
    size_t size;
    size_t capacity;
    CourseInProgram* courseInProgram;
    
    void resize(const size_t newCapacity);
    
public:
    CoursesInPrograms();
    ~CoursesInPrograms();
    
    void add(const size_t courseID, const size_t programID);
    
    void save();
};

#endif /* coursesInPrograms_hpp */
