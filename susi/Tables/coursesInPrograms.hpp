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

#include "Table.h"

#include "string.hpp"
#include "vector.h"

#include "courses.hpp"
#include "programs.hpp"

class CoursesInPrograms : public Table {
    
    struct CourseInProgram {
        size_t courseID;
        size_t programID;
        short unsigned year;
    };
    
    Vector<CourseInProgram> coursesInPrograms;
    
    Programs& programs_;
    Courses& courses_;
    
    void load(const String& file) override;
    
public:
    CoursesInPrograms(Programs& programs_, Courses& courses_);
    
    void save() const override;
    
    void add(const size_t courseID, const size_t programID, const short unsigned year);
    
    Vector<Course> getMandatoryForYear(const size_t programID, const short unsigned year);
    
    Vector<Course> getMandatoryToYear(const size_t programID, const short unsigned year);
    
    Vector<Course> getMandatoryForAllYear(const size_t programID);
    
    Vector<Course> getOptional(const size_t programID);
    
    bool isAdded(const size_t courseID, const size_t programID);
};

#endif /* coursesInPrograms_hpp */
