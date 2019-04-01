#include "AbstractTilesField.hpp"
#include "NumberedTile.hpp"

#include <vector>
#include <algorithm>

using namespace std;

AbstractTilesField::AbstractTilesField(std::size_t rowCount, std::size_t columnCount, NumberedTile defaultValue) :
    m_tiles(rowCount, vector<NumberedTile>(columnCount, defaultValue)),
    m_defaultTile(defaultValue)
{
}

const NumberedTile &AbstractTilesField::tileAt(size_t rowIndex, size_t columnIndex) const
{
    return m_tiles.at(rowIndex).at(columnIndex);
}

AbstractTilesField &AbstractTilesField::setTileAt(size_t rowIndex, size_t columnIndex, NumberedTile newTile)
{
    m_tiles.at(rowIndex).at(columnIndex) = newTile;
    return *this;
}

AbstractTilesField &AbstractTilesField::resetAll()
{
    for(auto& tilesRow : m_tiles) {
        for(auto& tile : tilesRow) {
            tile = m_defaultTile;
        }
    }
    return *this;
}

size_t AbstractTilesField::rowCount() const
{
    return m_tiles.size();
}

size_t AbstractTilesField::columnCount() const
{
    return m_tiles.front().size();
}

