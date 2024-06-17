//
//  Text.hpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#ifndef Text_hpp
#define Text_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class Text {
public:
    virtual void render(const std::string& data) const;
};

#endif /* Text_hpp */
