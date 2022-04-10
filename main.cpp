#include <logging.hpp>
//#include <zmq.hpp>
#include <openssl/sha.h>
#include <vector>
#include <string>

int main() {
    std::string string = "01234567890123456789012345678901";
    unsigned char hash[32];

    SHA256_CTX context;

    if (!SHA256_Init(&context)) return 1;
    if (!SHA256_Update(&context, string.data(), 32)) return 1;
    if (!SHA256_Final(hash, &context)) return 1;

    for(int i = 0; i < 32; i++)
        printf("%02x ", string[i]);
    printf("\n");

    for(int i = 0; i < 32; i++)
        printf("%02x ", hash[i]);
    printf("\n");

    return 0;
}