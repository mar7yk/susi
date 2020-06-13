//
//  CoursesInPrograms.cpp
//  susi
//
//  Created by Marty Kostov on 23.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "CoursesInPrograms.hpp"


CoursesInPrograms::CoursesInPrograms(Programs& programs, Courses& courses)
    : Table("Courses-in-programs.txt"), programs_(programs), courses_(courses) {
    load(file);
}

void CoursesInPrograms::load(const String &file) {
    std::ifstream is(file.get());
    if(is.is_open()){
        size_t size;
        is >> size;
        
        coursesInPrograms.resize(size);
        
        for (size_t i = 0; i < size; ++i) {
            is >> coursesInPrograms[i].courseID >> coursesInPrograms[i].programID >> coursesInPrograms[i].year;
        }
        
        is.close();
    }
}

void CoursesInPrograms::save() const {
    std::ofstream os(file.get());
    if (os.is_open()) {
        os << coursesInPrograms.size() << std::endl;
        
        for (unsigned i = 0; i < coursesInPrograms.size(); ++i) {
            os << coursesInPrograms[i].courseID << " " << coursesInPrograms[i].programID
                << " " << coursesInPrograms[i].year << std::endl;
        }
        
        os.close();
        
    } else {
        std::cerr << "Error: CoursesInPrograms are not saved!" << std::endl;
    }
}


void CoursesInPrograms::add(const size_t courseID, const size_t programID, const short unsigned year) {
    if (courseID == 0 || programID == 0 || year == 0) {
        throw std::invalid_argument("Invalid argument");
    }
    
    CourseInProgram newCourseInProgram = {courseID, programID, year};
    
    
    coursesInPrograms.push_back(newCourseInProgram);
}

Vector<Course> CoursesInPrograms::getMandatoryForYear(const size_t programID, const unsigned short year) {
    Vector<Course> mandatoryCourses;
    
    for (size_t i = 0; i < coursesInPrograms.size(); ++i) {
        if (coursesInPrograms[i].programID == programID &&
            coursesInPrograms[i].year == year) {
            Course course = courses_.getByID(coursesInPrograms[i].courseID);
            
            if (course.optional == false) {
                mandatoryCourses.push_back(course);
            }
        }
    }
    
    return mandatoryCourses;
}

Vector<Course> CoursesInPrograms::getMandatoryToYear(const size_t programID, const unsigned short year) {
    Vector<Course> mandatoryCourses;
    
    for (size_t i = 0; i < coursesInPrograms.size(); ++i) {
        if (coursesInPrograms[i].programID == programID &&
            coursesInPrograms[i].year <= year) {
            Course course = courses_.getByID(coursesInPrograms[i].courseID);
            
            if (course.optional == false) {
                mandatoryCourses.push_back(course);
            }
        }
    }
    
    return mandatoryCourses;
}

Vector<Course> CoursesInPrograms::getMandatoryForAllYear(const size_t programID) {
    Vector<Course> mandatoryCourses;
    
    for (size_t i = 0; i < coursesInPrograms.size(); ++i) {
        if (coursesInPrograms[i].programID == programID) {
            Course course = courses_.getByID(coursesInPrograms[i].courseID);
            
            if (course.optional == false) {
                mandatoryCourses.push_back(course);
            }
            
        }
    }
    
    return mandatoryCourses;
}

Vector<Course> CoursesInPrograms::getOptional(const size_t programID) {
    Vector<Course> optionalCourses;
    
    for (size_t i = 0; i < coursesInPrograms.size(); ++i) {
        if (coursesInPrograms[i].programID == programID) {
            Course course = courses_.getByID(coursesInPrograms[i].courseID);
            
            if (course.optional == true) {
                optionalCourses.push_back(course);
            }
            
        }
    }
    
    return optionalCourses;
}

bool CoursesInPrograms::isAdded(const size_t courseID, const size_t programID) { 
    for (size_t i = 0; i < coursesInPrograms.size(); ++i) {
        if (coursesInPrograms[i].courseID == courseID &&
            coursesInPrograms[i].programID == programID) {
            return true;
        }
    }
    
    return false;
}






