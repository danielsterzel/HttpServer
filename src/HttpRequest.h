//
// Created by Daniel Sterzel on 07/10/2025.
//

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <string>


enum class HttpMethod {
    GET,
    POST,
    DELETE_,
    PUT,
    UNKNOWN
};


// problem with this method

inline HttpMethod parseMethod(const std::string& methodStr) {
    // transform applies a function to each element in range
    std::transform(methodStr.begin(), methodStr.end(), methodStr.begin(), ::toupper);

    // we use if because switch doesn't work with std::string

    if (methodStr == "GET") return HttpMethod::GET;
    if (methodStr == "POST") return HttpMethod::POST;
    if (methodStr == "DELETE") return HttpMethod::DELETE_;
    if (methodStr == "PUT") return HttpMethod::PUT;

    return HttpMethod::UNKNOWN;
}

struct HttpRequest {
    HttpRequest(const HttpMethod& method, std::string& filePath, std::string& httpVersion):
    httpRequestMethod(method), servingFilePath(std::move(filePath)), httpRequestVersion(std::move(httpVersion)){}

    HttpMethod httpRequestMethod;
    std::string servingFilePath;
    std::string httpRequestVersion;
};

#endif //HTTPREQUEST_H
