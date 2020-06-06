//
//  SusiDatabase.h
//  susi
//
//  Created by Marty Kostov on 5.06.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef SusiDatabase_h
#define SusiDatabase_h

#include "students.hpp"
#include "courses.hpp"
#include "programs.hpp"
#include "enrolleesInCourses.hpp"
#include "coursesInPrograms.hpp"

struct SusiDatabase {
    Programs programs;
    Students students;
    Courses courses;
    EnrolleesInCourses enrolleesInCourses;
    CoursesInPrograms coursesInPrograms;
    
    SusiDatabase() :
        students(programs),
        enrolleesInCourses(students, courses),
        coursesInPrograms(programs, courses) {}
    
    void save() {
        programs.save();
        students.save();
        courses.save();
        enrolleesInCourses.save();
        coursesInPrograms.save();
    }
};


#endif /* SusiDatabase_h */
