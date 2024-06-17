//
//  BoldText.cpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#include "BoldText.hpp"

BoldText::BoldText(Text* text) : DecoratedText(text) {}

void BoldText::render(const std::string& data) const {
    std::cout << "<b>" << std::endl;
    text_->render(data);
    std::cout << "</b>" << std::endl;
}
