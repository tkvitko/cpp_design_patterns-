//
//  main.cpp
//  pattern_Decorator
//
//  Created by tkvitko on 17.06.2024.
//

#include <string>
#include <iostream>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data << std::endl;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const  {
        std::cout << "<i>" << std::endl;
        text_->render(data);
        std::cout << "</i>" << std::endl;
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>" << std::endl;
        text_->render(data);
        std::cout << "</b>" << std::endl;
    }
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<p>" << std::endl;
        text_->render(data);
        std::cout << "</p>" << std::endl;
    }
};

class Reversed : public DecoratedText {
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::string reversed = data;
        std::reverse(reversed.begin(), reversed.end());
        text_->render(reversed);
    }
};

class Link : public DecoratedText {
public:
    explicit Link(Text* text) : DecoratedText(text) {}
    void render(const std::string url, const std::string& data) const {
        std::cout << "<a href=\"";
        std::cout << url;
        std::cout << "\">" << std::endl;
        text_->render(data);
        std::cout << "</a>" << std::endl;
    }
};

int main() {
//    auto text_block = new ItalicText(new BoldText(new Text()));
//    text_block->render("Hello world");
    
    auto text_block = new Paragraph(new Text());
    text_block->render("Hello world");
    std::cout << std::endl;
    
    auto text_block1 = new Reversed(new Text());
    text_block1->render("Hello world");
    std::cout << std::endl;
    
    auto text_block2 = new Link(new Text());
    text_block2->render("netology.ru", "Hello world");
    std::cout << std::endl;
}
