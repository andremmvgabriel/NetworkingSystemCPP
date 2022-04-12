#pragma once

#include <string>
#include <zmq.hpp>

namespace gabe
{
    namespace network
    {
        namespace utils
        {
            std::string receive(zmq::socket_ref socket, int flags = 0);
            bool receive_more(zmq::socket_ref socket);
            bool send(zmq::socket_ref socket, const std::string &message, int flags = 0);
            bool send_more(zmq::socket_ref socket, const std::string &message);
            void set_identity(zmq::socket_ref socket, const std::string &id);
        }

        enum class Connection
        {
            BIND    = 0,
            CONNECT = 1
        };
    }
}