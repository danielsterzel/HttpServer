//
// Created by Daniel Sterzel on 21/09/2025.
//

#ifndef SERVER_H
#define SERVER_H

#include "ClientSession.h"

using boost::asio::ip::tcp;

class Server {

public:
    explicit Server(boost::asio::io_context& io_context);
    void startAccepting();

private:
    boost::asio::io_context& io_ctx;
    tcp::acceptor acceptor;
};

#endif //SERVER_H
