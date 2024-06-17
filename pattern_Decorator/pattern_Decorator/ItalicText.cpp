//
//  ItalicText.cpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#include "ItalicText.hpp"

ItalicText::ItalicText(Text* text) : DecoratedText(text) {};

void ItalicText::render(const std::string& data) const  {
    std::cout << "<i>" << std::endl;
    text_->render(data);
    std::cout << "</i>" << std::endl;
}
