#include "Server.h"
#include <iostream>

#include "Parser.h"

int main() {

    try {
        boost::asio::io_context io_context;
        Server server(io_context);
        server.startAccepting();
        io_context.run();
    }catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
