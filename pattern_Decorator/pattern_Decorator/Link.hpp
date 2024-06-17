//
//  Link.hpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#ifndef Link_hpp
#define Link_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "DecoratedText.hpp"

class Link : public DecoratedText {
public:
    explicit Link(std::shared_ptr<Text>  text);
    void render(const std::string url, const std::string& data) const;
};

#endif /* Link_hpp */
