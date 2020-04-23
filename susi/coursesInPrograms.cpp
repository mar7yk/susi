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
        courseInProgram = new CourseInProgram[capacity];
        for (size_t i = 0; i < size; ++i) {
            is.read((char*)&courseInProgram[i].courseID, sizeof(size_t));
            is.read((char*)&courseInProgram[i].programID, sizeof(size_t));
        }
        is.close();
    } else {
        size = 0;
        capacity = 50;
        courseInProgram = new CourseInProgram[capacity];
    }
}


CoursesInPrograms::~CoursesInPrograms() {
    delete [] courseInProgram;
}


void CoursesInPrograms::resize(const size_t newCapacity) {
    capacity = newCapacity;
    CourseInProgram* buff = new CourseInProgram[capacity];
    for (size_t i = 0; i < size; ++i)
        buff[i] = courseInProgram[i];
    
    delete [] courseInProgram;
    courseInProgram = buff;
}


void CoursesInPrograms::add(const size_t courseID, const size_t programID) {
    if (size == capacity) {
        resize(capacity + 20);
    }
    courseInProgram[size] = {courseID, programID};
    ++size;;
}

void CoursesInPrograms::save() {
    std::ofstream os(file.get(), std::ios::binary);
    if (os.is_open()) {
        os.write((char*)&size, sizeof(size_t));
        
        for (unsigned i = 0; i < size; ++i) {
            os.write((char*)&courseInProgram[i].courseID, sizeof(size_t));
            os.write((char*)&courseInProgram[i].programID, sizeof(size_t));
        }
        os.close();
        
    } else {
        std::cerr << "Error: CoursesInPrograms are not saved!" << std::endl;
    }
}

