//
// Created by Daniel Sterzel on 28/09/2025.
//

#ifndef CLIENTSESSION_H
#define CLIENTSESSION_H

#include <boost/asio.hpp>

class ClientSession : public std::enable_shared_from_this<ClientSession>{
public:
   explicit ClientSession(boost::asio::ip::tcp::socket&& socket_);
    void start();
    void getRequest();
    void sendResponse();
private:
    boost::asio::ip::tcp::socket socket;
    boost::asio::streambuf buffer;


};



#endif //CLIENTSESSION_H
