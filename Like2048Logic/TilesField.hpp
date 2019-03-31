#ifndef TILESFIELD_HPP
#define TILESFIELD_HPP

#include "NumberedTile.hpp"

#include <vector>
#include <cinttypes>


class AbstactTilesField
{
public:
    AbstactTilesField(std::size_t rowCount, std::size_t columnCount, NumberedTile defaultTile = NumberedTile(0));

    const NumberedTile& tileAt() const;
    AbstactTilesField& setTileAt(std::size_t rowIndex, std::size_t columnIndex, NumberedTile newTile);

    AbstactTilesField& resetAll();

    const NumberedTile& defaultTile() { return m_defaultTile; }
private:
    std::vector<std::vector<NumberedTile>> m_tiles;
    NumberedTile m_defaultTile;
};

#endif // TILESFIELD_HPP
