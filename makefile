FLAGS = -std=c++20 -lzmq -pthread -o

all: client server
client: start_client.cpp client.cpp user.cpp
	g++ -fsanitize=address start_client.cpp client.cpp user.cpp ${FLAGS} client -w

server: start_server.cpp server.cpp user.cpp history.cpp
	g++ -fsanitize=address start_server.cpp server.cpp user.cpp history.cpp ${FLAGS} server -w	