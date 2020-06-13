//
//  students.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "students.hpp"


Students::Students(Programs& programs)
    : Table("Students.txt"), programs_(programs) {
    load(file);
}

void Students::load(const String &file) {
    std::ifstream is(file.get());
    if(is.is_open()){
        size_t size;
        is >> size;
        
        students.resize(size);
        
        for (size_t i = 0; i < size; ++i) {
            
            is >> students[i].fn >> students[i].year >> students[i].programID
            >> students[i].gruop >> students[i].status >> students[i].average;
            
            is.ignore();
            getline(is, students[i].name);
        }
        
        is.close();
        
    }
}

void Students::save() const {
    std::ofstream os(file.get());
    if (os.is_open()) {
        os << students.size() << std::endl;
        
        for (unsigned i = 0; i < students.size(); ++i) {
            os << students[i].fn << " " << students[i].year << " " << students[i].programID
                << " " << students[i].gruop << " " << students[i].status
                << " " << students[i].average << " " << students[i].name << std::endl;
        }
        
        os.close();
        
    } else {
        std::cerr << "Error: students are not saved!" << std::endl;
    }
}

void Students::add(const unsigned int fn, const String &name,
                   const size_t programID, const unsigned short gruop) {
    
    if (fn == 0 || name == "" || gruop == 0) {
        throw std::invalid_argument("Invalid argument");
    }
    
    StudentData newStudent = {fn, name, 1, programID, gruop, 1, 0};
    students.push_back(newStudent);
}

Student Students::getByFN(const unsigned int fn) const {
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].fn == fn) {
            Student student = get(students[i]);
            
            return student;
        }
    }
    
    return {};
}

Vector<Student> Students::getByProgramIDAndYear(const size_t programID, const short unsigned year) const {
    Vector<Student> studentsInfo;
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].programID == programID &&
            students[i].year == year) {
            
            Student student = get(students[i]);
            
            studentsInfo.push_back(student);
        }
    }
    
    return studentsInfo;
}

Student Students::get(const StudentData &data) const {
    Student student;
    
    size_t programID = data.programID;
    
    String program = programs_.getNameByID(programID);
    
    student.fn = data.fn;
    student.name = data.name;
    student.program = program;
    student.year = data.year;
    student.gruop = data.gruop;
    student.status = data.status;
    student.average = data.average;
    
    return student;
}

void Students::update_year(const unsigned int fn,
                           const unsigned short year) {
    if (year == 0) {
        throw std::invalid_argument("Invalid argument");
    }
    
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].fn == fn) {
            students[i].year = year;
            return;
        }
    }
    
}

void Students::update_group(const unsigned int fn,
                            const unsigned short gruop) {
    if (gruop == 0) {
        throw std::invalid_argument("Invalid argument");
    }
    
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].fn == fn) {
            students[i].gruop = gruop;
            return;
        }
    }
}

void Students::update_program(const unsigned int fn,
                              const size_t programID) {
    if (programID == 0) {
        throw std::invalid_argument("Invalid argument");
    }
    
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].fn == fn) {
            students[i].programID = programID;
            return;
        }
    }
}

void Students::update_status(const unsigned int fn,
                             const unsigned short status) {
    
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].fn == fn) {
            students[i].status = status;
            return;
        }
    }
}

void Students::update_average(const unsigned int fn,
                              const double average) {
    
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].fn == fn) {
            students[i].average = average;
            return;
        }
    }
}





