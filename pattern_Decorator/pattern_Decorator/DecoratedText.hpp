//
//  DecoratedText.hpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#ifndef DecoratedText_hpp
#define DecoratedText_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "Text.hpp"


class DecoratedText : public Text {
public:
    explicit DecoratedText(std::shared_ptr<Text> text);
    std::shared_ptr<Text>  text_;
};

#endif /* DecoratedText_hpp */
