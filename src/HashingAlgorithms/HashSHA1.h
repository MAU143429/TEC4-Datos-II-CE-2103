//
// Created by njohnson on 6/11/21.
// // Algorithm based of the code retrieved from: http://www.zedwood.com/article/cpp-sha1-function
//

#ifndef TEC4_DATOS_II_HASHSHA1_H
#define TEC4_DATOS_II_HASHSHA1_H

#include <iostream>
#include <string>
using namespace std;

class HashSHA1 {
public:
    HashSHA1();
    void update(const string &s);
    void update(istream &is);
    string final();
    static string from_file(const string &filename);

private:
    typedef unsigned long int uint32;
    typedef unsigned long long uint64;

    static const unsigned int DIGEST_INTS = 5;
    static const unsigned int BLOCK_INTS = 16;
    static const unsigned int BLOCK_BYTES = BLOCK_INTS * 4;

    uint32 digest[DIGEST_INTS]{};
    string buffer;
    uint64 transforms{};

    void reset();
    void transform(uint32 block[BLOCK_BYTES]);

    static void buffer_to_block(const string &buffer, uint32 block[BLOCK_BYTES]);
    static void read(std::istream &is, string &s, int max);
};
string initHashSHA1(const string &string);

#endif //TEC4_DATOS_II_HASHSHA1_H
