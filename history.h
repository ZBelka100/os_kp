// chat_history_manager.h
#pragma once

#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using user_id_t = std::string;

class ChatHistoryManager {
public:
    ChatHistoryManager();
    void addUser(user_id_t user_id);
    void addMessage(user_id_t user_id, const std::string& message);

    std::vector<std::string> getHistory(user_id_t user_id) const;
    std::vector<std::string> searchMessagesByContent(const std::string& content) const;

    void printAll() const;

private:
    std::unordered_map<user_id_t, std::vector<std::string>> history;
};
