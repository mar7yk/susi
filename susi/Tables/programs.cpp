//
//  programs.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "programs.hpp"


const String Programs::file = "Programs.bin";
size_t Programs::newID = 1;


Programs::Programs() {
    std::ifstream is(file.get(), std::ios::binary);
    if(is.is_open()){
        is.read((char*)&size, sizeof(size_t));
        capacity = size + 5;
        programs = new Program[capacity];
        for (size_t i = 0; i < size; ++i) {
            is.read((char*)&programs[i].id, sizeof(size_t));
            getline(is, programs[i].name);
        }
        newID = programs[size - 1].id + 1;
        is.close();
    } else {
        size = 0;
        capacity = 50;
        programs = new Program[capacity];
    }
}


Programs::~Programs() {
    delete [] programs;
}


void Programs::add(const String &name) {
    if (size == capacity) {
        resize(capacity + 5);
    }
    programs[size] = {newID, name};
    ++newID;
    ++size;
}


void Programs::resize(const size_t newCapacity) {
    capacity = newCapacity;
    Program* buff = new Program[capacity];
    for (size_t i = 0; i < size; ++i)
        buff[i] = programs[i];
    
    delete [] programs;
    programs = buff;
}


String Programs::getName(const size_t id) const {
    String rec = "";
    for (size_t i = 0; i < size; ++i) {
        if (programs[i].id == id) {
            return programs[i].name;
        }
    }
    return rec;
}

void Programs::save() {
    std::ofstream os(file.get(), std::ios::binary);
    if (os.is_open()) {
        os.write((char*)&size, sizeof(size_t));
        
        for (unsigned i = 0; i < size; ++i) {
            os.write((char*)&programs[i].id, sizeof(size_t));
            os << programs[i].name << std::endl;
        }
        os.close();
        
    } else {
        std::cerr << "Error: Programs are not saved!" << std::endl;
    }
}

size_t Programs::getID(const String &name) const {
    for (size_t i = 0; i < size; ++i) {
        if (programs[i].name == name) {
            return programs[i].id;
        }
    }
    return 0;
}


