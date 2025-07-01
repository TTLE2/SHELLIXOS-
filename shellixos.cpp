
#include <microhttpd.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>

#define PORT 5656

std::map<std::string, std::string> mime_types = {
    {".html", "text/html"},
    {".css", "text/css"},
    {".js", "application/javascript"},
    {".ico", "image/x-icon"}
};

std::string get_mime_type(const std::string& path) {
    auto ext = path.substr(path.find_last_of('.'));
    return mime_types.count(ext) ? mime_types[ext] : "text/plain";
}

std::string read_file(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) return "";
    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

int answer_to_connection(void *cls, struct MHD_Connection *connection,
                         const char *url, const char *method,
                         const char *version, const char *upload_data,
                         size_t *upload_data_size, void **con_cls) {
    std::string path = "public";
    path += (std::string(url) == "/" ? "/index.html" : url);

    std::string data = read_file(path);
    if (data.empty()) {
        const char *not_found = "404 Not Found";
        struct MHD_Response *response = MHD_create_response_from_buffer(strlen(not_found), (void*) not_found, MHD_RESPMEM_PERSISTENT);
        int ret = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
        MHD_destroy_response(response);
        return ret;
    }

    std::string mime = get_mime_type(path);
    struct MHD_Response *response = MHD_create_response_from_buffer(data.size(), (void*) data.c_str(), MHD_RESPMEM_MUST_COPY);
    MHD_add_response_header(response, "Content-Type", mime.c_str());
    int ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
}

int main() {
    std::cout << "Shellixₒₛ starting on http://localhost:" << PORT << std::endl;
    std::cout << "Use commands like: ado inst \"url\" or ado start settings.sys" << std::endl;

    struct MHD_Daemon *daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL,
                                                  &answer_to_connection, NULL, MHD_OPTION_END);
    if (NULL == daemon) return 1;

    getchar(); // Keep running until enter is pressed
    MHD_stop_daemon(daemon);
    return 0;
}
