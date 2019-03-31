#include "TilesField.hpp"
#include "NumberedTile.hpp"
#include <vector>

using namespace std;

TilesField::TilesField(std::size_t rowCount, std::size_t columnCount, uint64_t defaultValue) :
    m_tiles(rowCount, vector<NumberedTile>(columnCount, defaultValue))
{
}
