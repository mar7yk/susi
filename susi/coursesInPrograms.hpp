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
#include "courses.hpp"
#include "enrolleesInCourses.hpp"

class CoursesInPrograms {
    const static String file;
    
    struct CourseInProgram {
        size_t courseID;
        size_t programID;
        short unsigned year;
    };
    
    size_t size;
    size_t capacity;
    CourseInProgram* coursesInPrograms;
    
    void resize(const size_t newCapacity);
    
public:
    CoursesInPrograms();
    ~CoursesInPrograms();
    
    void add(const size_t courseID, const size_t programID, const short unsigned year);
    
    void save();
    
    void addCoursesForYear(const unsigned int fn, const size_t programID, const unsigned short yaer, EnrolleesInCourses& allEnrollees, const Courses& allCourses);
};

#endif /* coursesInPrograms_hpp */
