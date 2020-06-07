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

#include "Table.h"

#include "course.h"
#include "string.hpp"
#include "vector.h"


class Courses : public Table {
    size_t nextID;
    
    Vector<Course> courses;
    
    void load(const String& file) override;
    
public:
    Courses();
    
    void save() const override;
    
    void add(const String& name, const bool optional);
    
    Course getByID(const size_t id) const;
    
    Course getByName(const String& name) const;
};

#endif /* courses_hpp */
