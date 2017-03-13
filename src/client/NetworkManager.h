#ifndef NETWORKMANAGER_HPP
#define NETWORKMANAGER_HPP

#include <string>
#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <limits.h>
#include <atomic>
#include <memory>
#include <map>

#define STDIN           0
#define TCP_PORT 		35223
#define UDP_PORT 		35222
#define UNAME_SIZE 	    32
#define PLAYERPACK_SIZE (UNAME_SIZE + 1)
#define CHAT_BUFFSIZE 	128
#define STD_BUFFSIZE    1024
#define MAX_EVENTS 		1
#define MAX_USERS		23
#define SYNC_PACKET_MAX USHRT_MAX
#define SYNC_PACKET


//moved enums to the bottom, and commented out

class NetworkManager {
public:
    static NetworkManager& instance();
    void initClients(const char *ip);
    void closeConnection();
    int writeSocket(int, const char *, int);
    void writeUDPSocket(const char *, int);
private:
    int sockTCP;
    int sockUDP;
    in_addr_t serverIP;
    NetworkManager() {};


    void bindSocket(int sock, struct sockaddr_in addr);
    struct sockaddr_in createAddress(const in_addr_t ip, const int port) const;
    void runTCPClient();
    void runUDPClient();
    int connectSocket(const char *) const;
    int createSocket(int) const;
    int readSocket(int sock, char *buf, int len) const;

    void connectSocket(int sock, const struct sockaddr_in& addr) const;

};

#endif

/*
//ENUMS
#ifndef PACKET_SPECIFIER_ENUMCL
#define PACKET_SPECIFIER_ENUMCL

enum class P_SPECIFIER{
	  EXIT,
		UNAME,
		CHAT
};

#endif

#ifndef GAMESTATE_ENUMCL
#define GAMESTATE_ENUMCL

enum class GAMESTATE{
		GAME_RECV,
		AI_RECV
};
#endif
*/
