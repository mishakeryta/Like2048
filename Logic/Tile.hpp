#ifndef NUMBEREDTILE_HPP
#define NUMBEREDTILE_HPP

#include <cinttypes>
class Tile
{
public:
    Tile(uint64_t value = 0);
    uint64_t value() const { return m_value; }
private:
    uint64_t m_value;
};

#endif // NUMBEREDTILE_HPP
