#ifndef TILESFIELD_HPP
#define TILESFIELD_HPP

#include "NumberedTile.hpp"

#include <vector>
#include <cinttypes>

enum class Swipe:char
{
    Up    = 2 << 0,
    Right = 2 << 1,
    Down  = 2 << 2,
    Left  = 2 << 3
};


class AbstractTilesField
{
public:
    AbstractTilesField(std::size_t rowCount, std::size_t columnCount,  NumberedTile defaultTile = NumberedTile(0));
    virtual ~AbstractTilesField() = default;

    const NumberedTile &defaultTile() { return m_defaultTile; }
    const NumberedTile &tileAt(std::size_t rowIndex, std::size_t columnIndex) const;
    AbstractTilesField &setTileAt(std::size_t rowIndex, std::size_t columnIndex, NumberedTile newTile);

    AbstractTilesField& resetAll();

    virtual AbstractTilesField &handle(Swipe direction) = 0;

    std::size_t rowCount() const;
    std::size_t columnCount() const;

private:
    std::vector<std::vector<NumberedTile>> m_tiles;
    NumberedTile m_defaultTile;
};

#endif // TILESFIELD_HPP
