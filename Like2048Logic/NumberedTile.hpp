#ifndef NUMBEREDTILE_HPP
#define NUMBEREDTILE_HPP

#include <cinttypes>
class NumberedTile
{
public:
    NumberedTile(uint64_t value);
    uint64_t value() const { return m_value; }
private:
    uint64_t m_value;
};

#endif // NUMBEREDTILE_HPP
