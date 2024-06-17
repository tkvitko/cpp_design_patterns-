//
//  Reversed.hpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#ifndef Reversed_hpp
#define Reversed_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "DecoratedText.hpp"

class Reversed : public DecoratedText {
public:
    explicit Reversed(Text* text);
    void render(const std::string& data) const;
};

#endif /* Reversed_hpp */
