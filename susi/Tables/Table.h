//
//  Table.h
//  susi
//
//  Created by Marty Kostov on 7.06.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef Table_h
#define Table_h

#include "string.hpp"

class Table {
    
protected:
    const String file;
    
    virtual void load(const String& file) = 0;
    
public:
    Table(const String& _file) : file(_file) {
        
    }
    
    void upload(const String &folder) {
        String filePath = folder;
        filePath += "/";
        filePath += file;
        load(filePath);
        save();
        
        load(file);
    }
    
    virtual void save() const = 0;
};

#endif /* Table_h */
