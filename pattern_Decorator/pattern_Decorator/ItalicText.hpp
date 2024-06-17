//
//  ItalicText.hpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#ifndef ItalicText_hpp
#define ItalicText_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "DecoratedText.hpp"


class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text);
    void render(const std::string& data) const;
};

#endif /* ItalicText_hpp */
