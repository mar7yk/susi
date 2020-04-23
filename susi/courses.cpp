//
//  courses.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "courses.hpp"

const String Courses::file = "Courses.bin";
size_t Courses::newID = 1;


Courses::Courses() {
    std::ifstream is(file.get(), std::ios::binary);
    if(is.is_open()){
        is.read((char*)&size, sizeof(size_t));
        capacity = size + 5;
        courses = new Course[capacity];
        for (size_t i = 0; i < size; ++i) {
            is.read((char*)&courses[i].id, sizeof(size_t));
            is.read((char*)&courses[i].optional, sizeof(bool));
            getline(is, courses[i].name);
        }
        newID = courses[size - 1].id + 1;
        is.close();
    } else {
        size = 0;
        capacity = 50;
        courses = new Course[capacity];
    }
}

Courses::~Courses() {
    delete [] courses;
}

void Courses::add(const String &name, const bool optional) {
    if (size == capacity) {
        resize(capacity + 5);
    }
    courses[size] = {newID, name, optional};
    ++newID;
    ++size;
}

void Courses::add(const Course& course) {
    if (size == capacity) {
        resize(capacity + 5);
    }
    courses[size] = course;
    ++newID;
    ++size;
}

void Courses::resize(const size_t newCapacity) {
    capacity = newCapacity;
    Course* buff = new Course[capacity];
    for (size_t i = 0; i < size; ++i)
        buff[i] = courses[i];
    
    delete [] courses;
    courses = buff;
}

Course Courses::get(const size_t id) const {
    Course rec = {0};
    for (size_t i = 0; i < size; ++i) {
        if (courses[i].id == id) {
            return courses[i];
        }
    }
    return rec;
}

void Courses::save() {
    std::ofstream os(file.get(), std::ios::binary);
    if (os.is_open()) {
        os.write((char*)&size, sizeof(size_t));
        
        for (unsigned i = 0; i < size; ++i) {
            os.write((char*)&courses[i].id, sizeof(size_t));
            os.write((char*)&courses[i].optional, sizeof(bool));
            os << courses[i].name << std::endl;
        }
        os.close();
        
    } else {
        std::cerr << "Error: courses are not saved!" << std::endl;
    }
}

Course Courses::get(const String &name) const {
    Course rec = {0};
    for (size_t i = 0; i < size; ++i) {
        if (courses[i].name == name) {
            return courses[i];
        }
    }
    
    return rec;
//    return {0};
}






