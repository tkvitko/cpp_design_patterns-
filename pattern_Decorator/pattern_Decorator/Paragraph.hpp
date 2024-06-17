//
//  Paragraph.hpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#ifndef Paragraph_hpp
#define Paragraph_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "DecoratedText.hpp"

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(std::shared_ptr<Text> text);
    void render(const std::string& data) const;
};

#endif /* Paragraph_hpp */
