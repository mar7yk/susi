//
//  students.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "students.hpp"


const String Students::file = "Students.bin";

Students::Students() {
    std::ifstream is(file.get(), std::ios::binary);
    if(is.is_open()){
        is.read((char*)&size, sizeof(size_t));
        capacity = size + 20;
        students = new Student[capacity];
        for (size_t i = 0; i < size; ++i) {
            is.read((char*)&students[i].fn, sizeof(unsigned));
            is.read((char*)&students[i].year, sizeof(short unsigned));
            is.read((char*)&students[i].programID, sizeof(size_t));
            is.read((char*)&students[i].gruop, sizeof(short unsigned));
            is.read((char*)&students[i].status, sizeof(short unsigned));
            is.read((char*)&students[i].average, sizeof(double));
            getline(is, students[i].name);
        }
        is.close();
    } else {
        size = 0;
        capacity = 200;
        students = new Student[capacity];
    }
}

Students::~Students() {
    delete [] students;
}

void Students::resize(const size_t newCapacity) {
    capacity = newCapacity;
    Student* buff = new Student[capacity];
    for (size_t i = 0; i < size; ++i)
        buff[i] = students[i];
    
    delete [] students;
    students = buff;
}

void Students::add(const unsigned int fn, const String &name, const size_t programID, const unsigned short gruop) {
    if (size == capacity) {
        resize(capacity + 20);
    }
    students[size] = {fn, name, 1, programID, gruop, 0, 0};
    ++size;
}

Student &Students::get(const unsigned fn) const {
    for (size_t i = 0; i < size; ++i) {
        if (students[i].fn == fn) {
            return students[i];
        }
    }
    return *(new Student);
}

void Students::save() {
    std::ofstream os(file.get(), std::ios::binary);
    if (os.is_open()) {
        os.write((char*)&size, sizeof(size_t));
        
        for (unsigned i = 0; i < size; ++i) {
            os.write((char*)&students[i].fn, sizeof(unsigned));
            os.write((char*)&students[i].year, sizeof(short unsigned));
            os.write((char*)&students[i].programID, sizeof(size_t));
            os.write((char*)&students[i].gruop, sizeof(short unsigned));
            os.write((char*)&students[i].status, sizeof(short unsigned));
            os.write((char*)&students[i].average, sizeof(double));
            os << students[i].name << std::endl;
        }
        os.close();
        
    } else {
        std::cerr << "Error: students are not saved!" << std::endl;
    }
}

void Students::info(const unsigned int fn, const Programs& allPrograms) const {
    for (size_t i = 0; i < size; ++i) {
        if (students[i].fn == fn) {
            display(students[i], allPrograms);
            return;
        }
    }
}

void Students::display(const Student &student, const Programs& allPrograms) const {
    String porgram = allPrograms.getName(student.programID);
    String status = "";
    switch (student.status) {
        case 1:
            status = "enrolled";
            break;
        case 2:
            status = "interrupt";
            break;
        case 3:
            status = "graduate";
            break;
            
        default:
            break;
    }
    std::cout << student.name << ", ";
    std::cout << "programID " << porgram << ", ";
    std::cout << "year "<< student.year << ", ";
    std::cout << "gruop "<< student.gruop << ", ";
    std::cout << "status "<< status << ", ";
    std::cout << "average "<< student.average << ", ";
    std::cout << std::endl;
}

void Students::info(const size_t programID, const unsigned short year, const Programs &allPrograms) const {
    for (size_t i = 0; i < size; ++i) {
        if (students[i].programID == programID && students[i].year == year) {
            display(students[i], allPrograms);
        }
    }
}





