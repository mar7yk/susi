//
//  susiDatabase.hpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef susiDatabase_hpp
#define susiDatabase_hpp

#include <stdio.h>

#include "students.hpp"
#include "courses.hpp"
#include "programs.hpp"
#include "enrolleesInCourses.hpp"
#include "coursesInPrograms.hpp"

class SusiDatabase {
    Students students;
    Courses courses;
    Programs programs;
    EnrolleesInCourses enrolleesInCourses;
    CoursesInPrograms coursesInPrograms;
    
public:
    bool isSaved;
    
    SusiDatabase();
    
    void save();
    
    void enroll(const unsigned fn, const String& program, const short unsigned gruop, const String &name);//†
    
    void advance(const unsigned fn);//†
    
    void changeProgram(const unsigned fn, const String& program);
    void changeGruop(const unsigned fn, const unsigned short gruop);
    void changeYear(const unsigned fn, const unsigned short year);
    
    void graduate(const unsigned fn);
    
    void interrupt(const unsigned fn);
    
    void resume(const unsigned fn);
    
    void print(const unsigned fn) const;//?
    
    void printall(const String& program, const short unsigned year) const;//?
    
    void enrollin(const unsigned fn, const String courseName);//†
    
    void addGrade(const unsigned fn, const String courseName, const double grade);//†
    
    void protocol(const String courseName) const;//?+
    
    void report(const unsigned fn) const;//?
    
    void addProgram(const String& name);
    
    void addCourse(const String& name, const String& type);
    
    void addCourseToProgram(const String& courseName, const String& programName, const short unsigned year);
};

#endif /* susiDatabase_hpp */
