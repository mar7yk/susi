//
//  susiDatabase.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "susiDatabase.hpp"


void SusiDatabase::save() {
    if (isSaved) {
        
    } else {
        students.save();
        courses.save();
        programs.save();
        enrolleesInCourses.save();
        coursesInPrograms.save();
        
        isSaved = true;
    }
}

void SusiDatabase::enroll(const unsigned int fn, const String& program, const unsigned short gruop, const String &name) {
    size_t programID = programs.getID(program);
    if (programID != 0) {
        students.add(fn, name, programID, gruop);
        
        coursesInPrograms.addCoursesForYear(fn, programID, 1, enrolleesInCourses, courses);
    }
}

void SusiDatabase::advance(const unsigned int fn) {
    Student &student = students.get(fn);
    if (student.fn == 0) {
        delete &student;
    } else {
        ++student.year;
        coursesInPrograms.addCoursesForYear(student.fn, student.programID, student.year, enrolleesInCourses, courses);
    }
}

void SusiDatabase::change(const unsigned int fn, const unsigned short option, const unsigned value) {
    Student student = students.get(fn);
    if (student.fn == 0) {
        delete &student;
    } else {
        switch (option) {
            case 1:
                student.programID = value;
                break;
                
            case 2:
                student.gruop = value;
                break;
                
            case 3:
                student.year = value;
                break;
                
            default:
                break;
        }
    }
}

void SusiDatabase::graduate(const unsigned int fn) {
    Student student = students.get(fn);
    if (student.fn == 0) {
        delete &student;
    } else {
        student.status = 3;
    }
}

void SusiDatabase::interrupt(const unsigned int fn) {
    Student student = students.get(fn);
    if (student.fn == 0) {
        delete &student;
    } else {
        student.status = 2;
    }
}

void SusiDatabase::resume(const unsigned int fn) {
    Student student = students.get(fn);
    if (student.fn == 0) {
        delete &student;
    } else {
        student.status = 1;
    }
}

void SusiDatabase::print(const unsigned int fn) const {
    students.info(fn, programs);
}

void SusiDatabase::printall(const String& program, const unsigned short year) const {
    size_t programID = programs.getID(program);
    if (programID != 0) {
        students.info(programID, year, programs);
    }
}

void SusiDatabase::enrollin(const unsigned int fn, const String courseName) {
    Course course = courses.get(courseName);
    if (course.id != 0) {
        enrolleesInCourses.add(fn, course.id);
    }
    
}

void SusiDatabase::addGrade(const unsigned int fn, const String courseName, const double grade) {
    Course course = courses.get(courseName);
    if (course.id != 0) {
        enrolleesInCourses.addGrade(fn, course.id, grade);
    }
}

void SusiDatabase::protocol(const String courseName) const {
    Course course = courses.get(courseName);
    if (course.id != 0) {
        enrolleesInCourses.infoForEnrollees(course.id, students);
    }
}

void SusiDatabase::report(const unsigned int fn) const {
    enrolleesInCourses.displayForStudent(fn, courses);
}

void SusiDatabase::addProgram(const String& name) {
    programs.add(name);
}

void SusiDatabase::addCourse(const String& name, const bool optional) {
    courses.add(name, optional);
}

void SusiDatabase::addCourseToProgram(const String &courseName, const String &programName, const short unsigned year) {
    Course course = courses.get(courseName);
    size_t programID = programs.getID(programName);
    
    if (course.id != 0 && programID != 0) {
        coursesInPrograms.add(course.id, programID, year);
    }
}















