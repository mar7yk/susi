//
//  SusiDatabase.h
//  susi
//
//  Created by Marty Kostov on 5.06.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef SusiDatabase_h
#define SusiDatabase_h

#include "Students.hpp"
#include "Courses.hpp"
#include "Programs.hpp"
#include "EnrolleesInCourses.hpp"
#include "CoursesInPrograms.hpp"

/// Структора от таблици
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
    
    void save() const {
        programs.save();
        students.save();
        courses.save();
        enrolleesInCourses.save();
        coursesInPrograms.save();
    }
    
    void upload(const String &folder) {
        programs.upload(folder);
        students.upload(folder);
        courses.upload(folder);
        enrolleesInCourses.upload(folder);
        coursesInPrograms.upload(folder);
    }
};


#endif /* SusiDatabase_h */
