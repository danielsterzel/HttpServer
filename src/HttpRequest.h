//
// Created by Daniel Sterzel on 07/10/2025.
//

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <string>


enum class HttpRequest {
    GET,
    POST,
    DELETE_,
    PUT,
    UNKNOWN
};

inline HttpRequest parseMethod(const std::string& methodStr) {
    // transform applies a function to each element in range
    std::transform(methodStr.begin(), methodStr.end(), methodStr.begin(), ::toupper);

    // we use if because switch doesn't work with std::string

    if (methodStr == "GET") return HttpRequest::GET;
    if (methodStr == "POST") return HttpRequest::POST;
    if (methodStr == "DELETE") return HttpRequest::DELETE_;
    if (methodStr == "PUT") return HttpRequest::PUT;

    return HttpRequest::UNKNOWN;
}



#endif //HTTPREQUEST_H
