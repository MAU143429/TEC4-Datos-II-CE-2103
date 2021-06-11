//
// Created by njohnson on 6/11/21.
// Algorithm based of the code retrieved from: http://www.zedwood.com/article/cpp-md5-function
//

#ifndef TEC4_DATOS_II_HASHMD5_H
#define TEC4_DATOS_II_HASHMD5_H

#include <cstring>
#include <iostream>
using namespace std;

class HashMD5 {
public:
    typedef unsigned int size_type; // must be 32bit

    HashMD5();
    explicit HashMD5(const string& text);
    void update(const unsigned char *buf, size_type length);
    void update(const char *buf, size_type length);
    HashMD5& finalize();
    string hexdigest() const;
    friend ostream& operator<<(ostream&, HashMD5 md5);

private:
    void init();
    typedef unsigned char uint1;
    typedef unsigned int uint4;
    enum {blocksize = 64};

    void transform(const uint1 block[blocksize]);
    static void decode(uint4 output[], const uint1 input[], size_type len);
    static void encode(uint1 output[], const uint4 input[], size_type len);

    bool finalized{};
    uint1 buffer[blocksize]{};
    uint4 count[2]{};
    uint4 state[4]{};
    uint1 digest[16]{};

    static inline uint4 F(uint4 x, uint4 y, uint4 z);
    static inline uint4 G(uint4 x, uint4 y, uint4 z);
    static inline uint4 H(uint4 x, uint4 y, uint4 z);
    static inline uint4 I(uint4 x, uint4 y, uint4 z);
    static inline uint4 rotate_left(uint4 x, int n);
    static inline void FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
    static inline void II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
};

string initHashMD5(const string& str);


#endif //TEC4_DATOS_II_HASHMD5_H
