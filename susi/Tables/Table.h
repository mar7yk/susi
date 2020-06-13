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
#include <fstream>

class Table {
    
protected:
    const String file;
    
    /// Десериализира таблица по подаден път на файл
    ///
    /// @param file път на фаил
    virtual void load(const String& file) = 0;
    
public:
    Table(const String& _file) : file(_file) {
        
    }
    
    virtual ~Table() {}
    
    /// Десериализира таблица по подаден път на папка
    ///
    /// @param folder път на пака
    void upload(const String &folder) {
        String filePath = folder;
        filePath += "/";
        filePath += file;
        
        std::ifstream tryFile(filePath.get());
        if (tryFile.is_open()) {
            tryFile.close();
        } else {
            return;
        }
        
        load(filePath);
        save();
    }
    
    /// Сериализира таблица
    virtual void save() const = 0;
};

#endif /* Table_h */
