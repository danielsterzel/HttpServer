//
// Created by Daniel Sterzel on 21/09/2025.
//
//
#include "Server.h"
#include <iostream>

Server::Server(boost::asio::io_context &io_context): io_ctx(io_context),
    acceptor(io_context, tcp::endpoint(tcp::v4(), 12345)) {}

void Server::startAccepting() {

    auto clientSocket = std::make_shared<tcp::socket>(io_ctx);
    acceptor.async_accept(*clientSocket,
        [this, clientSocket](const boost::system::error_code& ec) {
           if (!ec) {
            const auto client = std::make_shared<ClientSession>(std::move(*clientSocket));
            client->start();

           }else {
               std::cerr << "Accept error: " << ec.message() << "\n";
           }
            startAccepting();
        });
}



