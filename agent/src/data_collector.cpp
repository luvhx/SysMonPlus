// src/data_collector.cpp
#include <cpprest/http_listener.h>
#include "system_monitor.h"

using namespace web::http;
using namespace web::http::experimental::listener;

class DataCollector {
    http_listener listener;
    SystemMonitor monitor;

public:
    DataCollector(const utility::string_t& url) : listener(url) {
        listener.support(methods::GET, std::bind(&DataCollector::handle_get, this, std::placeholders::_1));
    }

    void handle_get(http_request request) {
        auto status = monitor.get_current_status();
        json::value response;
        response["cpu_load"] = status.cpu_load;
        response["memory_usage"] = status.memory_usage;
        response["disk_usage"] = status.disk_usage;
        
        request.reply(status_codes::OK, response);
    }
};
