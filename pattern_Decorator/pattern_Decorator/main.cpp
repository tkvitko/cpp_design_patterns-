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
    
    std::unique_ptr<Text> text = std::make_unique<Text>();
    std::unique_ptr<Paragraph> text_block = std::make_unique<Paragraph>(text); // No matching constructor for initialization of 'Paragraph'
    text_block->render("Hello world");
    std::cout << std::endl;
    
    auto text_block1 = new Reversed(new Text());
    text_block1->render("Hello world");
    std::cout << std::endl;
    
    auto text_block2 = new Link(new Text());
    text_block2->render("netology.ru", "Hello world");
    std::cout << std::endl;
}
