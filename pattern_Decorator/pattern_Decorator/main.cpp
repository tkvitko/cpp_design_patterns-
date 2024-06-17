//
//  main.cpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#include <string>
#include <iostream>

#include "Text.hpp"
#include "DecoratedText.hpp"
#include "ItalicText.hpp"
#include "BoldText.hpp"
#include "Paragraph.hpp"
#include "Reversed.hpp"
#include "Link.hpp"



int main() {
//    auto text_block = new ItalicText(new BoldText(new Text()));
//    text_block->render("Hello world");
    
    std::shared_ptr<Paragraph> text_block = std::make_shared<Paragraph>(std::make_shared<Text>());
    text_block->render("Hello world");
    std::cout << std::endl;
    
    std::shared_ptr<Reversed> text_block1 = std::make_shared<Reversed>(std::make_shared<Text>());
    text_block1->render("Hello world");
    std::cout << std::endl;

    std::shared_ptr<Link> text_block2 = std::make_shared<Link>(std::make_shared<Text>());
    text_block2->render("netology.ru", "Hello world");
    std::cout << std::endl;
}
