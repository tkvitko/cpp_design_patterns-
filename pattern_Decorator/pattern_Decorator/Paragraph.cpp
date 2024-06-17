//
//  Paragraph.cpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#include "Paragraph.hpp"

Paragraph::Paragraph(Text* text) : DecoratedText(text) {}

void Paragraph::render(const std::string& data) const {
    std::cout << "<p>" << std::endl;
    text_->render(data);
    std::cout << "</p>" << std::endl;
}
