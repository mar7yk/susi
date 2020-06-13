//
//  EnrolleesInCourses.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "EnrolleesInCourses.hpp"


EnrolleesInCourses::EnrolleesInCourses(Students& students, Courses& courses)
    : Table("Enrollees-in-courses.txt"), students_(students), courses_(courses) {
    load(file);
}

void EnrolleesInCourses::load(const String &file) {
    std::ifstream is(file.get());
    if(is.is_open()){
        size_t size;
        is >> size;
        
        enrollees.resize(size);
        
        for (size_t i = 0; i < size; ++i) {
            is >> enrollees[i].studentFN >> enrollees[i].courseID >> enrollees[i].grade;
        }
        is.close();
    }
}

void EnrolleesInCourses::save() const {
    std::ofstream os(file.get());
    if (os.is_open()) {
        os << enrollees.size() << std::endl;
        
        for (unsigned i = 0; i < enrollees.size(); ++i) {
            os << enrollees[i].studentFN << " " << enrollees[i].courseID << " " << enrollees[i].grade << std::endl;
        }
        os.close();
        
    } else {
        std::cerr << "Error: EnrolleesInCourses are not saved!" << std::endl;
    }
}

void EnrolleesInCourses::add(const short unsigned studentFN, const short unsigned courseID) {
    if (studentFN == 0 || courseID == 0) {
        throw std::invalid_argument("Invalid argument");
    }
    
    EnrolledInCourse newEnrolled = {studentFN, courseID, 0};
    enrollees.push_back(newEnrolled);
}

void EnrolleesInCourses::update_grade(const unsigned short studentFN, const unsigned short courseID, const double grade) {
    if (grade < 2 || grade > 6) {
        throw std::invalid_argument("Invalid argument");
    }
    
    for (size_t i = 0; i < enrollees.size(); ++i) {
        if (enrollees[i].studentFN == studentFN && enrollees[i].courseID == courseID) {
            enrollees[i].grade = grade;
            return;
        }
    }
}

Vector<StudentProtocol> EnrolleesInCourses::get_protocol(const size_t courseID) const {
    Vector<StudentProtocol> protocol;
    
    for (size_t i = 0; i < enrollees.size(); ++i) {
        if (enrollees[i].courseID == courseID) {
            Student student = students_.getByFN(enrollees[i].studentFN);
            
            StudentProtocol protocol_line;
            
            protocol_line.fn = student.fn;
            protocol_line.name = student.name;
            protocol_line.program = student.program;
            protocol_line.gruop = student.gruop;
            protocol_line.grade = enrollees[i].grade;
            
            protocol.push_back(protocol_line);
        }
    }
    
    return protocol;
}

Vector<CourseReport> EnrolleesInCourses::get_report_by_fn(const unsigned int fn) {
    Vector<CourseReport> report;
    
    for (size_t i = 0; i < enrollees.size(); ++i) {
        if (enrollees[i].studentFN == fn) {
            Course course = courses_.getByID(enrollees[i].courseID);
            
            CourseReport courseReport;
            
            courseReport.courseName = course.name;
            courseReport.grade = enrollees[i].grade;
            
            report.push_back(courseReport);
        }
    }
    
    return report;
}



