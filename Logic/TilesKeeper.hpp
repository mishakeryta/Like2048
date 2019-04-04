#ifndef TILESKEEPER_HPP
#define TILESKEEPER_HPP

#include "Tile.hpp"

#include <vector>
#include <memory>

class TilesKeeper
{
    using TilesContainer = std::vector<std::vector<std::unique_ptr<Tile>>>;
public:
    TilesKeeper(size_t rowCount, size_t columnCount,const Tile &defaultTile);
    TilesKeeper(const TilesKeeper& tileKeeper);
    TilesKeeper& operator=(const TilesKeeper& tileKeeper);
    Tile &at(size_t rowIndex, size_t columnIndex);
    const Tile& at(size_t rowIndex, size_t columnIndex) const;
    Tile &operator()(size_t rowIndex, size_t columnIndex);
    const Tile &operator()(size_t rowIndex, size_t columnIndex) const;

    size_t rowCount() const;
    size_t columnCount() const;
private:
    TilesContainer m_tiles;
};

#endif // TILESKEEPER_HPP
