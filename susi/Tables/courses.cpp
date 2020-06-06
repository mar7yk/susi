//
//  courses.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "courses.hpp"


Courses::Courses() : file("Courses.txt") {
    std::ifstream is(file.get());
    if(is.is_open()){
        size_t size;
        is >> size;
        
        courses.resize(size);
        
        for (size_t i = 0; i < size; ++i) {
            is >> courses[i].ID >> courses[i].optional;
            
            is.ignore();
            getline(is, courses[i].name);
        }
        nextID = courses.back().ID + 1;
        
        is.close();
        
    } else {
        nextID = 1;
    }
}

void Courses::save() {
    std::ofstream os(file.get());
    if (os.is_open()) {
        os << courses.size() << std::endl;
        
        for (unsigned i = 0; i < courses.size(); ++i) {
            os << courses[i].ID << " " << courses[i].optional << " " << courses[i].name << "\n";
        }
        
        os.close();
        
    } else {
        std::cerr << "Error: courses are not saved!" << std::endl;
    }
}

void Courses::add(const String &name, const bool optional) {
    Course newCourse = {nextID, name, optional};
    courses.push_back(newCourse);
    
    ++nextID;
}



Course Courses::getByID(const size_t id) const {
    for (size_t i = 0; i < courses.size(); ++i) {
        if (courses[i].ID == id) {
            return courses[i];
        }
    }
    return {};
}



Course Courses::getByName(const String &name) const {
    for (size_t i = 0; i < courses.size(); ++i) {
        if (courses[i].name == name) {
            return courses[i];
        }
    }
    
    return {};
}






