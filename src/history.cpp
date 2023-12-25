#include "history.h"

ChatHistoryManager::ChatHistoryManager() {
}

void ChatHistoryManager::addUser(user_id_t user_id) {
    history[user_id] = {};
}

void ChatHistoryManager::addMessage(user_id_t user_id, const std::string& message) {
    // Добавление сообщения в историю переписок
    history[user_id].push_back(message);

    // Логирование сообщения в файл
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << user_id << ": " << message << std::endl;
        logFile.close();
    } else {
        std::cerr << "Error opening log file!" << std::endl;
    }
}

void ChatHistoryManager::printAll() const {
    std::cout << "=== Chat History ===" << std::endl;
    
    for (const auto& entry : history) {
        const std::string& user_id = entry.first;
        const std::vector<std::string>& messages = entry.second;

        std::cout << "User ID: " << user_id << std::endl;
        std::cout << "Messages: ";
        for (const auto& message : messages) {
            std::cout << message << "; ";
        }
        std::cout << std::endl;
    }

    std::cout << "====================" << std::endl;
}


std::vector<std::string> ChatHistoryManager::getHistory(user_id_t user_id) const {
    // Получение истории переписки пользователя
    auto it = history.find(user_id);
    if (it != history.end()) {
        return it->second;
    } else {
        std::cout << "User not found!";
        return {};
    }
}

std::vector<std::string> ChatHistoryManager::searchMessagesByContent(const std::string& content) const {
    // Поиск сообщений по содержанию сообщения
    std::vector<std::string> results;

    for (const auto& entry : history) {
        const auto& messages = entry.second;
        for (const auto& message : messages) {
            if (message.find(content) != std::string::npos) {
                results.push_back(entry.first + ": " + message);
            }
        }
    }

    return results;
}

