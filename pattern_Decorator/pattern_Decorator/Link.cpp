//
//  Link.cpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#include "Link.hpp"

Link::Link(std::shared_ptr<Text>  text) : DecoratedText(text) {}

void Link::render(const std::string url, const std::string& data) const {
    std::cout << "<a href=\"";
    std::cout << url;
    std::cout << "\">" << std::endl;
    text_->render(data);
    std::cout << "</a>" << std::endl;
}
