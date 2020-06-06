//
//  courses.hpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef courses_hpp
#define courses_hpp

#include <stdio.h>
#include <fstream>

#include "course.h"
#include "string.hpp"
#include "vector.h"


class Courses {
    const String file;
    size_t nextID;
    
    Vector<Course> courses;
    
public:
    Courses();
    
    void save();
    
    void add(const String& name, const bool optional);
    
    Course getByID(const size_t id) const;
    
    Course getByName(const String& name) const;
};

#endif /* courses_hpp */
