#include <iostream>
#include <string>
#include <zmq.hpp>
#include <vector>
#include <map>
#include "user.h"
#include "history.h"


class Server
{
    public:
        Server();
        Server(std::string IP);

        bool isOnline(std::string username);

        User search_username(std::string username);
        User search_id(zmq::message_t& id);

        void registration(zmq::message_t& id);
        void login(zmq::message_t& id, std::stringstream& input);
        void logout(zmq::message_t& id);
        
        void send(zmq::message_t& id, std::string message);
        void send_message(zmq::message_t& id, std::stringstream& input);
        void get_history(zmq::message_t& id);

        void run();
        void event_processing();
        void users_list();
        void stop();

        ~Server() = default;



    private:
        std::string IP;
        zmq::socket_t socket;
        std::vector <User> users;
        ChatHistoryManager history;
};


