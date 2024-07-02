//
//  main.cpp
//  pattern_Observer
//
//  Created by tkvitko on 30.06.2024.
//

#include <iostream>
#include <fstream>
#include <vector>

class Observer{
    // абстрактный класс-наблюдатель
public:
    virtual void onWarning(const std::string& message) = 0;
    virtual void onError(const std::string& message) = 0;
    virtual void onFatalError(const std::string& message) = 0;
    
protected:
    // методы для работы потомков класса
    void consolePrint(const std::string& message) {
        std::cout << message << std::endl;
    }
    void filePrint(const std::string& message) {
        std::ofstream out("log.txt", std::ios::app);
        if (out.is_open()) {
            out << message << std::endl;
        }
        out.close();
    }
};

class WarningsObserver : public Observer {
    // обработчик предупреждений
public:
    void onWarning(const std::string& message) {
        consolePrint(message);
    }
    void onError(const std::string& message) {}
    void onFatalError(const std::string& message){}
};

class ErrorsObserver : public Observer {
    // обработчик ошибок
public:
    void onWarning(const std::string& message) {}
    void onError(const std::string& message) {
        filePrint(message);
    }
    void onFatalError(const std::string& message){}
};

class FatalErrorsObserver : public Observer {
    // обработчик фатальных ошибок
public:
    void onWarning(const std::string& message) {}
    void onError(const std::string& message) {}
    void onFatalError(const std::string& message) {
        consolePrint(message);
        filePrint(message);
    }
};

class MessageGenerator {
    // наблюдаемый класс
public:
    void warning(const std::string& message) const {
        // случилось предупреждение
        for (auto observer : observers_) {
            if (auto strong_ptr = observer.lock()) {
                strong_ptr->onWarning(message);
            }
        }
    }
    
    void error(const std::string& message) const{
        // случилась ошибка
        for (auto observer : observers_) {
            if (auto strong_ptr = observer.lock()) {
                strong_ptr->onError(message);
            }
        }
    }

    void fatalError(const std::string& message) const{
        // случилась фатальная ошибка
        for (auto observer : observers_) {
            if (auto strong_ptr = observer.lock()) {
                strong_ptr->onFatalError(message);
            }
        }
    }
    
    void addObserver(std::weak_ptr<Observer> observer) {
        observers_.push_back(observer);
    }
    
private:
    std::vector<std::weak_ptr<Observer>> observers_;
};


int main(int argc, const char * argv[]) {
    
    // тестирование
    MessageGenerator generator = MessageGenerator();
    auto obs = std::make_shared<WarningsObserver>();
    generator.addObserver(obs);
    generator.warning("warning here!");
    return 0;
}
