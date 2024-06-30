//
//  main.cpp
//  pattern_Command
//
//  Created by tkvitko on 30.06.2024.
//

// Реализовать наследников класса таким образом,
// чтобы один наследник печатал сообщение message в консоль,
// а другой умел печатать сообщение в файл, по указанному пути.
// Реализовать функцию, которая будет выполнять команды


#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
    // класс-потомок для вывода лога в консоль
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class FileLogCommand : public LogCommand {
    // класс-потомок для записи лога в файл
public:
    void print(const std::string& message) override {
        std::ofstream out("log.txt", std::ios::app);
        if (out.is_open()) {
            out << message << std::endl;
        }
        out.close();
    }
};

void print(LogCommand& log_command, const std::string& message) {
    // функция - команда для выполнения задачи записи лога
    log_command.print(message);
};

int main(int argc, const char * argv[]) {
    
    // тестирование
    ConsoleLogCommand command_console = ConsoleLogCommand();
    print(command_console, "text to console");
    
    FileLogCommand command_file = FileLogCommand();
    print(command_file, " text to file");
    
    return 0;
}
