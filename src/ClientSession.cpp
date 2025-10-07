//
// Created by Daniel Sterzel on 28/09/2025.
//

#include "ClientSession.h"
#include <iostream>
#include "Parser.h"

ClientSession::ClientSession(boost::asio::ip::tcp::socket&& socket_): socket(std::move(socket_)) {

}

void ClientSession::start() {
    getRequest();
}

void ClientSession::sendResponse() {
    auto self = shared_from_this();

    Parser parser;
    parser.read("/Users/daniel/CLionProjects/CustomHtppClass/files/index.html");

    const std::string http_body = parser.returnString();

    std::string http_response = "HTTP/1.1 200 OK\r\n"
        "Content-Length: " + std::to_string(http_body.size()) + "\r\n"
        "Content-Type: text/html\r\n"
        "Connection: close\r\n"
        "\r\n" +
            http_body;

    boost::asio::async_write(socket, boost::asio::buffer(http_response),
        [self](const boost::system::error_code& ec,const std::size_t len) {
            if (!ec) {
                std::cout << "Sent HTTP response (" << len << " bytes)\n";
                self->socket.close();
            }
            else {
                std::cerr << ec.message() << "\n";
            }
        });
}

void ClientSession::getRequest() {
    auto self = shared_from_this();

    boost::asio::async_read_until(socket, buffer, "\r\n\r\n",
        [self](const boost::system::error_code& ec, std::size_t bytes_transferred) {
            if (ec) {
                std::cerr << "Read error: " << ec.message() << "\n";
            return;
            }

            // perhaps use parser object for reading?


            std::istream requestStream(&self->buffer);
            std::string requestLine;
            std::string headerLine;

            std::getline(requestStream, requestLine);

            requestLine.pop_back(); // get rid of "\r" in order to properly view the string in console
            std::cout << "REQUEST LINE: " << requestLine << "\n";
            std::cout <<" ---------------------------------- \n";

            std::vector<std::string> parsedRequestLine = {};
            std::stringstream ss(requestLine);
            std::string t;

            // maybe find a better way to do this? Also get rid of whitespaces
            while (std::getline(ss, t, '/')) {
                parsedRequestLine.emplace_back(std::move(t));
            }

            for (const auto& el: parsedRequestLine) {
                std::cout << el << "\n";
            }



            // after reading the header we have to parse it.
            // check what type of method it is
            // probably map the method to an enum? or just chuck it into a map?
            // will probably require a lot of switch statements

            while (std::getline(requestStream, headerLine)) {

                if (!headerLine.empty() && headerLine.back() == '\r') {
                    headerLine.pop_back();
                }

                std::cout << headerLine << "\n";

            }

            self->sendResponse();
        });
}



