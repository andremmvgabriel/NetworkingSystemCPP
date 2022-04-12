#include <utils/NetworkUtils.hpp>

std::string gabe::network::utils::receive(zmq::socket_ref socket, int flags) {
    // Creates a zmq message object
    zmq::message_t zmq_message;

    // Receives the message from the socket
    socket.recv(&zmq_message, flags);

    // Converts the message data into a string
    return std::string(
        static_cast<char*>(zmq_message.data()), zmq_message.size()
    );
}

bool gabe::network::utils::receive_more(zmq::socket_ref socket) {
    // Control variables to know if there is any data left to be received
    int more = 0;
    size_t more_size = sizeof(more);

    // Checks if there is data left to be received
    socket.getsockopt( ZMQ_RCVMORE, &more, &more_size);

    return more;
}

bool gabe::network::utils::send(zmq::socket_ref socket, const std::string &message, int flags) {
    // Creates a zmq message object with the needed size
    zmq::message_t zmq_message(message.size());

    // Copies the content into the zmq message
    memcpy(zmq_message.data(), message.data(), message.size());
}

bool gabe::network::utils::send_more(zmq::socket_ref socket, const std::string &message) {
    return send(socket, message, ZMQ_SNDMORE);
}

void gabe::network::utils::set_identity(zmq::socket_ref socket, const std::string &id) {
    socket.setsockopt(ZMQ_IDENTITY, id.c_str(), id.size());
}
