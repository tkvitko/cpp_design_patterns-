//
//  main.cpp
//  SOLID_principles
//
//  Created by tkvitko on 30.06.2024.
//


#include <fstream>
#include <string>


class Data {
public:
    Data(std::string text) : text_(text) {};
    virtual ~Data() = default;
    virtual std::string getData() = 0;
protected:
    std::string text_;
};

class HtmlData : public Data {
public:
    std::string getData() override {
        return "<html>" + text_ + "<html/>";
    }
};

class JsonData : public Data {
public:
    std::string getData() override {
        return "{ \"data\": \"" + text_ + "\"}";
    }
};

class TextData : public Data {
public:
    std::string getData() override {
        return text_;
    }
};

class FileSaver {
public:
    FileSaver(Data* data) : data_(data) {};
    void sendDataToStream(std::ostream& stream) {
        stream << data_->getData() << std::endl;
    }
private:
    Data* data_;
};
