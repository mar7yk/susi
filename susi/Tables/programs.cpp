//
//  Programs.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "Programs.hpp"


Programs::Programs() : Table("Programs.txt") {
    load(file);
}

void Programs::load(const String &file) {
    std::ifstream is(file.get());
    if(is.is_open()){
        size_t size;
        is >> size;
        
        programs.resize(size);
        
        programs.resize(size);
        
        for (size_t i = 0; i < size; ++i) {
            is >> programs[i].ID;
            
            is.ignore();
            getline(is, programs[i].name);
        }
        
        nextID = programs.back().ID + 1;
        
        is.close();
        
    } else {
        nextID = 1;
    }
}

void Programs::save() const {
    std::ofstream os(file.get());
    if (os.is_open()) {
        
        os << programs.size() << std::endl;
        
        for (unsigned i = 0; i < programs.size(); ++i) {
            os << programs[i].ID << " " << programs[i].name << std::endl;
        }
        
        os.close();
        
    } else {
        std::cerr << "Error: Programs are not saved!" << std::endl;
    }
}

void Programs::add(const String &name) {
    if (name == "") {
        throw std::invalid_argument("Invalid argument");
    }
    Program newProgram = {nextID, name};
    programs.push_back(newProgram);
    
    ++nextID;
}

String Programs::getNameByID(const size_t id) const {
    for (size_t i = 0; i < programs.size(); ++i) {
        if (programs[i].ID == id) {
            return programs[i].name;
        }
    }
    return "Unknown";
}

size_t Programs::getIDByName(const String &name) const {
    for (size_t i = 0; i < programs.size(); ++i) {
        if (programs[i].name == name) {
            return programs[i].ID;
        }
    }
    return 0;
}







