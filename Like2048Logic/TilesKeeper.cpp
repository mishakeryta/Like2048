#include "TilesKeeper.hpp"

#include <QtGlobal>

using namespace std;


TilesKeeper::TilesKeeper(size_t rowCount, size_t columnCount,const Tile& defaultTile) :
    m_tiles(rowCount, vector<unique_ptr<Tile>>(columnCount, unique_ptr<Tile>(new Tile(defaultTile))))
{
    Q_ASSERT_X(rowCount != 0, "TilesKeeper::TilesKeeper", "Row count can't be zero");
    Q_ASSERT_X(columnCount != 0, "TilesKeeper::TilesKeeper", "Column count can't be zero");
}

Tile &TilesKeeper::at(size_t rowIndex, size_t columnIndex)
{
    return const_cast<Tile&>(static_cast<const TilesKeeper&>(*this).at(rowIndex,columnIndex));
}

const Tile &TilesKeeper::at(size_t rowIndex, size_t columnIndex) const
{
    return *m_tiles.at(rowIndex).at(columnIndex);
}

Tile &TilesKeeper::operator()(size_t rowIndex, size_t columnIndex)
{
    return *const_cast<Tile&>(static_cast<const TilesKeeper&>(*this).operator()(rowIndex,columnIndex));
}

const Tile &TilesKeeper::operator()(size_t rowIndex, size_t columnIndex) const
{
    return *m_tiles[rowIndex][columnIndex];
}

size_t TilesKeeper::rowCount() const
{
    return m_tiles.size();
}

size_t TilesKeeper::columnCount() const
{
    return m_tiles.front().size();
}
