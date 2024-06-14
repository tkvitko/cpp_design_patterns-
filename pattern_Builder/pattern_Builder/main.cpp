//
//  main.cpp
//  pattern_Builder
//
//  Created by tkvitko on 14.06.2024.
//

// Реализовать класс для построения SELECT-запроса по шаблону проектирования Builder

#include <iostream>
#include <string>
#include <vector>
#include <map>

struct SqlSelectQuery {
    // структура для хранения параметров SQL-запроса
    std::vector<std::string> columns;
    std::string table;
    std::map<std::string, std::string> conditions;
};

class SqlSelectQueryBuilder {
    // класс-строитель для формирования SELECT-запроса
    
public:
    SqlSelectQueryBuilder() {};
    
    SqlSelectQueryBuilder& AddFrom(std::string table_name) {
        query.table = table_name;
        return *this;
    }
    
    SqlSelectQueryBuilder& AddColumn(std::string column_name) {
        query.columns.push_back(column_name);
        return *this;
    }
    
    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept {
        query.columns.insert(query.columns.end(), columns.begin(), columns.end());
        return *this;
    }
    
    SqlSelectQueryBuilder& AddWhere(std::string field, std::string value) {
        query.conditions[field] = value;
        return *this;
    }
    
    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept {
        for(std::map<std::string, std::string>::const_iterator it = kv.begin(); it != kv.end(); ++it) {
            query.conditions.insert(*it);
        }
        return *this;
    }
    
    std::string BuildQuery() {
        std::string result;
        
        result+= "\"SELECT ";
        
        if (query.columns.empty()) {
            result+= "* ";
        } else {
            for (int i = 0; i != query.columns.size(); ++i) {
                result+= query.columns[i];
                if (i != query.columns.size() - 1) {
                    result+= ", ";
                } else {
                    result+= " ";
                }
            }
        }
        result+= "FROM ";
        result+= query.table;
        result+= " WHERE ";
        
        int el_num = 0;
        for (const auto& condition : query.conditions) {
            result+= condition.first;
            result+= "=";
            result+= condition.second;
            if (el_num != query.conditions.size() - 1) {
                result+= " AND ";
            }
            el_num++;
        }
        
        result+= ";\"\n";
        return result;
    }
    
    
private:
    SqlSelectQuery query;
};


int main(int argc, const char * argv[]) {
    
    // задание 1
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
    
    // задание 2
    std::map<std::string, std::string> conds;
    conds["number"] = "128";
    conds["surname"] = "Dow";
    query_builder.AddWhere(conds);
    
    std::vector<std::string> columns{"test", "foo", "bar"};
    query_builder.AddColumns(columns);
    
    // вывод
    auto s = query_builder.BuildQuery();
    std::cout << s;
//    static_assert(query_builder.BuildQuery(),
//                  "SELECT name, phone FROM students WHERE id=42 AND name=John;");
    
    return 0;
}
