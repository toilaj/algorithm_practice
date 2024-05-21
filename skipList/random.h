//
// Created by joe_jing on 24-5-20.
//

#ifndef SKIPLIST_RANDOM_H
#define SKIPLIST_RANDOM_H

#include <random>
#include <cinttypes>

class Random {

public:
    Random()  {
        std::random_device rd;
        std::default_random_engine engine(rd());
        std::uniform_int_distribution<uint64_t> dig(0,0xffffffffffffffff);
        seed = dig(engine);
    }

    uint32_t Next() {
        uint8_t r = ((0xff00000000000000 & seed) >> 56) & 0xff;
        seed <<= 1;
        seed |= r;
        return r;
    }

    uint32_t Uniform(int n) { return (Next() % n); }

private:
    uint64_t seed;
};

#endif //SKIPLIST_RANDOM_H
