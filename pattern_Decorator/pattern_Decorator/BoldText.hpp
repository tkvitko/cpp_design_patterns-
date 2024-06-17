//
//  BoldText.hpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#ifndef BoldText_hpp
#define BoldText_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "DecoratedText.hpp"


class BoldText : public DecoratedText {
public:
    explicit BoldText(std::shared_ptr<Text> text);
    void render(const std::string& data) const;
};

#endif /* BoldText_hpp */
