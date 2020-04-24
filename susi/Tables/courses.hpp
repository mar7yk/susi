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

class Courses {
    const static String file;
    static size_t newID;
    
    size_t size;
    size_t capacity;
    Course* courses;
    
    void resize(const size_t newCapacity);
    
public:
    Courses();
    ~Courses();
    
    void add(const String& name, const bool optional);
    void add(const Course& course);
    
    void save();
    
    Course get(const size_t id) const;
    
    Course get(const String& name) const;
};

#endif /* courses_hpp */
