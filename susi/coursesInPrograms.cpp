//
//  coursesInPrograms.cpp
//  susi
//
//  Created by Marty Kostov on 23.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "coursesInPrograms.hpp"


const String CoursesInPrograms::file = "Courses-in-programs.bin";


CoursesInPrograms::CoursesInPrograms() {
    std::ifstream is(file.get(), std::ios::binary);
    if(is.is_open()){
        is.read((char*)&size, sizeof(size_t));
        capacity = size + 5;
        coursesInPrograms = new CourseInProgram[capacity];
        for (size_t i = 0; i < size; ++i) {
            is.read((char*)&coursesInPrograms[i].courseID, sizeof(size_t));
            is.read((char*)&coursesInPrograms[i].programID, sizeof(size_t));
        }
        is.close();
    } else {
        size = 0;
        capacity = 50;
        coursesInPrograms = new CourseInProgram[capacity];
    }
}


CoursesInPrograms::~CoursesInPrograms() {
    delete [] coursesInPrograms;
}


void CoursesInPrograms::resize(const size_t newCapacity) {
    capacity = newCapacity;
    CourseInProgram* buff = new CourseInProgram[capacity];
    for (size_t i = 0; i < size; ++i)
        buff[i] = coursesInPrograms[i];
    
    delete [] coursesInPrograms;
    coursesInPrograms = buff;
}


void CoursesInPrograms::add(const size_t courseID, const size_t programID, const short unsigned year) {
    if (size == capacity) {
        resize(capacity + 20);
    }
    coursesInPrograms[size] = {courseID, programID, year};
    ++size;;
}

void CoursesInPrograms::save() {
    std::ofstream os(file.get(), std::ios::binary);
    if (os.is_open()) {
        os.write((char*)&size, sizeof(size_t));
        
        for (unsigned i = 0; i < size; ++i) {
            os.write((char*)&coursesInPrograms[i].courseID, sizeof(size_t));
            os.write((char*)&coursesInPrograms[i].programID, sizeof(size_t));
        }
        os.close();
        
    } else {
        std::cerr << "Error: CoursesInPrograms are not saved!" << std::endl;
    }
}

void CoursesInPrograms::addCoursesForYear(const unsigned int fn, const size_t programID, const unsigned short yaer, EnrolleesInCourses &allEnrollees, const Courses& allCourses) {
    for (size_t i = 0; i < size; ++i) {
        if (coursesInPrograms[i].programID == programID &&
            coursesInPrograms[i].year == yaer) {
            Course course = allCourses.get(coursesInPrograms[i].courseID);
            if (!course.optional) {
                allEnrollees.add(fn, coursesInPrograms[i].courseID);
            }
        }
    }
}


