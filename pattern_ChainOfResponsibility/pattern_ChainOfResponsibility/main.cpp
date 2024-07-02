//
//  main.cpp
//  pattern_ChainOfResponsibility
//
//  Created by tkvitko on 30.06.2024.
//

#include <iostream>
#include <fstream>

// классы сообщений

class LogMessage {
    // абстрактный класс
public:
    enum class Type {
        kWarning,
        kError,
        kFatalError,
        kUnknown
    };
    
    virtual ~LogMessage() = default;
    virtual Type type() const = 0;
    virtual const std::string message() const = 0;
};

class WarningMessage : public LogMessage {
    // класс сообщения о предупреждении
public:
    Type type() const override { return Type::kWarning; };
    const std::string message() const override {
        return "Warning message";
    }
};

class ErrorMessage : public LogMessage {
    // класс сообщений об ошибке
public:
    Type type() const override { return Type::kError; };
    const std::string message() const override {
        return "Error message";
    }
};

class FatalErrorMessage : public LogMessage {
    // класс сообщений о фатальной ошибке
public:
    Type type() const override { return Type::kFatalError; };
    const std::string message() const override {
        return "Fatal Error message";
    }
};

class UnknownMessage : public LogMessage {
    // класс неизвестного сообщения
public:
    Type type() const override { return Type::kUnknown; };
    const std::string message() const override {
        return "Unknown message";
    }
};

// классы обработчиков сообщений

class LogMessageHandler {
    // базовый класс обработчика сообщений
public:
    LogMessageHandler(std::unique_ptr<LogMessageHandler> next) : next_(std::move(next)) {};
    virtual ~LogMessageHandler() = default;
    void receiveMessage(const LogMessage& msg) {
        if (handleMessage(msg)) {
            return;
        }
        if (!next_) {
            throw(std::runtime_error("Error: no handler for this message was found!"));
        }
        next_->receiveMessage(msg);
    }
    
private:
    virtual bool handleMessage(const LogMessage& msg) = 0;
    std::unique_ptr<LogMessageHandler> next_;
    
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

class FatalErrorHandler : public LogMessageHandler {
    // обработчик фатальных ошибок
public:
    using LogMessageHandler::LogMessageHandler;
private:
    bool handleMessage(const LogMessage& msg) override {
        if (msg.type() != LogMessage::Type::kFatalError) {
            return false;
        }
        throw(std::runtime_error(msg.message()));
        return true;
    }
};

class ErrorHandler : public LogMessageHandler {
    // обработчик ошибок
public:
    using LogMessageHandler::LogMessageHandler;
private:
    bool handleMessage(const LogMessage& msg) override {
        if (msg.type() != LogMessage::Type::kError) {
            return false;
        }
        filePrint(msg.message());
        return true;
    }
};

class WarningHandler : public LogMessageHandler {
    // обработчик предупреждений
public:
    using LogMessageHandler::LogMessageHandler;
private:
    bool handleMessage(const LogMessage& msg) override {
        if (msg.type() != LogMessage::Type::kWarning) {
            return false;
        }
        consolePrint(msg.message());
        return true;
    }
};

class UnknownMessageHandler : public LogMessageHandler {
    // обработчик неизвестных сообщений
public:
    using LogMessageHandler::LogMessageHandler;
private:
    bool handleMessage(const LogMessage& msg) override {
        if (msg.type() != LogMessage::Type::kUnknown) {
            return false;
        }
        throw(std::runtime_error("Unknown message received!"));
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // тестирование
    auto warning_handler = std::make_unique<WarningHandler>(nullptr);
    auto error_handler = std::make_unique<ErrorHandler>(std::move(warning_handler));
    auto fatal_error_handler = std::make_unique<FatalErrorHandler>(std::move(error_handler));
    auto unknown_message_handler = std::make_unique<UnknownMessageHandler>(std::move(fatal_error_handler));

    try {
        unknown_message_handler->receiveMessage(WarningMessage());
        unknown_message_handler->receiveMessage(ErrorMessage());
        unknown_message_handler->receiveMessage(FatalErrorMessage());
        unknown_message_handler->receiveMessage(UnknownMessage());
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
