//
//  enrolleesInCourses.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "enrolleesInCourses.hpp"


const String EnrolleesInCourses::file = "Enrollees-in-courses.bin";

EnrolleesInCourses::EnrolleesInCourses() {
    std::ifstream is(file.get(), std::ios::binary);
    if(is.is_open()){
        is.read((char*)&size, sizeof(size_t));
        capacity = size + 20;
        enrollees = new EnrolledInCourse[capacity];
        for (size_t i = 0; i < size; ++i) {
            is.read((char*)&enrollees[i].studentFN, sizeof(short unsigned));
            is.read((char*)&enrollees[i].courseID, sizeof(size_t));
            is.read((char*)&enrollees[i].grade, sizeof(double));
        }
        is.close();
    } else {
        size = 0;
        capacity = 1000;
        enrollees = new EnrolledInCourse[capacity];
    }
}

EnrolleesInCourses::~EnrolleesInCourses() {
    delete [] enrollees;
}

void EnrolleesInCourses::add(const short unsigned studentFN, const short unsigned courseID) {
    if (size == capacity) {
        resize(capacity + 20);
    }
    enrollees[size] = {studentFN, courseID, 0};
    ++size;
}


void EnrolleesInCourses::resize(const size_t newCapacity) {
    capacity = newCapacity;
    EnrolledInCourse* buff = new EnrolledInCourse[capacity];
    for (size_t i = 0; i < size; ++i)
        buff[i] = enrollees[i];
    
    delete [] enrollees;
    enrollees = buff;
}

void EnrolleesInCourses::displayForStudent(const unsigned short studentFN, const Courses &allCourses) const{
    
    for (size_t i = 0; i < size; ++i) {
        if (enrollees[i].studentFN == studentFN) {
            Course single = allCourses.get(enrollees[i].courseID);
            std::cout << single.name << " " << enrollees[i].grade << std::endl;
        }
    }
}

void EnrolleesInCourses::addGrade(const unsigned short studentFN, const unsigned short courseID, const double grade) {
    for (size_t i = 0; i < size; ++i) {
        if (enrollees[i].studentFN == studentFN && enrollees[i].courseID == courseID) {
            enrollees[i].grade = grade;
            return;
        }
    }
}

void EnrolleesInCourses::save() {
    std::ofstream os(file.get(), std::ios::binary);
    if (os.is_open()) {
        os.write((char*)&size, sizeof(size_t));
        
        for (unsigned i = 0; i < size; ++i) {
            os.write((char*)&enrollees[i].studentFN, sizeof(short unsigned));
            os.write((char*)&enrollees[i].courseID, sizeof(size_t));
            os.write((char*)&enrollees[i].grade, sizeof(double));
        }
        os.close();
        
    } else {
        std::cerr << "Error: EnrolleesInCourses are not saved!" << std::endl;
    }
}

void EnrolleesInCourses::infoForEnrollees(unsigned short courseID, const Students &allStudents, const Programs& allPrograms) const {
    for (size_t i = 0; i < size; ++i) {
        if (enrollees[i].courseID == courseID) {
            allStudents.info(enrollees[i].studentFN, allPrograms);
        }
    }
}






