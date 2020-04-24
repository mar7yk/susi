//
//  susiDatabase.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "susiDatabase.hpp"


SusiDatabase::SusiDatabase() {
    isSaved = true;
}

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
        
        isSaved = false;
    }
}

void SusiDatabase::advance(const unsigned int fn) {
    Student& student = students.get(fn);
    if (student.fn == 0) {
        delete &student;
    } else {
        ++student.year;
        student.average = enrolleesInCourses.getNewAverage(student.fn);
        coursesInPrograms.addCoursesForYear(student.fn, student.programID, student.year, enrolleesInCourses, courses);
        
        isSaved = false;
    }
}

void SusiDatabase::changeProgram(const unsigned fn, const String& program) {
    Student& student = students.get(fn);
    if (student.fn == 0) {
        delete &student;
    } else {
        size_t programID = programs.getID(program);
        if (programID != 0) {
            student.programID = programID;
        }
    }
}

void SusiDatabase::changeGruop(const unsigned fn, const unsigned short gruop) {
    Student& student = students.get(fn);
    if (student.fn == 0) {
        delete &student;
    } else {
        student.gruop = gruop;
    }
}

void SusiDatabase::changeYear(const unsigned fn, const unsigned short year) {
    Student student = students.get(fn);
    if (student.fn == 0) {
        delete &student;
    } else {
        student.year = year;
    }
}

void SusiDatabase::graduate(const unsigned int fn) {
    Student& student = students.get(fn);
    if (student.fn == 0) {
        delete &student;
    } else {
        student.status = 3;
        
        isSaved = false;
    }
}

void SusiDatabase::interrupt(const unsigned int fn) {
    Student& student = students.get(fn);
    if (student.fn == 0) {
        delete &student;
    } else {
        student.status = 2;
        
        isSaved = false;
    }
}

void SusiDatabase::resume(const unsigned int fn) {
    Student& student = students.get(fn);
    if (student.fn == 0) {
        delete &student;
    } else {
        student.status = 1;
        
        isSaved = false;
    }
}

StudentInfo SusiDatabase::print(const unsigned int fn) const {
    return students.info(fn, programs);
}

void SusiDatabase::printall(const String& program, const unsigned short year) const {
    size_t programID = programs.getID(program);
    if (programID != 0) {
        students.info(programID, year, programs);
    }
}

void SusiDatabase::enrollin(const unsigned int fn, const String courseName) {
    Course course = courses.get(courseName);
    if (course.id != 0 && course.optional) {
        enrolleesInCourses.add(fn, course.id);
        
        isSaved = false;
    }
    
}

void SusiDatabase::addGrade(const unsigned int fn, const String courseName, const double grade) {
    Course course = courses.get(courseName);
    if (course.id != 0) {
        enrolleesInCourses.addGrade(fn, course.id, grade);
        
        isSaved = false;
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

    isSaved = false;
}

void SusiDatabase::addCourse(const String& name, const String& type) {
    bool isOptional = true;
    if (type == "optional") {
        isOptional = true;
    } else if (type == "compulsory") {
        isOptional = false;
    } else {
        return;
    }
    courses.add(name, isOptional);
    
    isSaved = false;
}

void SusiDatabase::addCourseToProgram(const String &courseName, const String &programName, const short unsigned year) {
    Course course = courses.get(courseName);
    size_t programID = programs.getID(programName);
    
    if (course.id != 0 && programID != 0) {
        coursesInPrograms.add(course.id, programID, year);
    }
    
    isSaved = false;
}

















