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
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
    
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
};

class ErrorsObserver : public Observer {
    // обработчик ошибок
public:
    void onWarning(const std::string& message) {
        filePrint(message);
    }
};

class FatalErrorsObserver : public Observer {
    // обработчик фатальных ошибок
public:
    void onWarning(const std::string& message) {
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
//            observer->onWarning(message);
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
//    void addObserver(Observer* observer) {
        observers_.push_back(observer);
    }
    
private:
    std::vector<std::weak_ptr<Observer>> observers_;
//    std::vector<Observer*> observers_;
};


int main(int argc, const char * argv[]) {
    
    // тестирование
    MessageGenerator generator = MessageGenerator();
    
    WarningsObserver warning_processor = WarningsObserver();
    std::weak_ptr<Observer> obs_weak;
    auto obs_shared = std::make_shared<Observer>(warning_processor);
    obs_weak = obs_shared;
    generator.addObserver(obs_weak);
//    generator.addObserver(&warning_processor);
    
    generator.warning("warning here!");
    return 0;
}
