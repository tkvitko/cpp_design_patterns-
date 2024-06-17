//
//  Reversed.cpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#include "Reversed.hpp"

Reversed::Reversed(std::shared_ptr<Text>  text) : DecoratedText(text) {}

void Reversed::render(const std::string& data) const {
    std::string reversed = data;
    std::reverse(reversed.begin(), reversed.end());
    text_->render(reversed);
}
