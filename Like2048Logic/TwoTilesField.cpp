#include "TwoTilesField.hpp"

#include <functional>
const NumberedTile TwoTilesField::EMPTY = NumberedTile(0);

TwoTilesField::TwoTilesField(std::size_t rowCount, std::size_t columnCount) :
    AbstractTilesField (rowCount, columnCount, EMPTY)
{

}

AbstractTilesField &TwoTilesField::handle(Swipe direction)
{
    size_t lineCount = 0;
    size_t lineSize = 0;
    size_t  rowIndex = 0, columnIndex = 0;
    std::function<void (std::size_t &, std::size_t &)> nextCurrent = nullptr;
    std::function<void (std::size_t &, std::size_t &)> nextLine = nullptr;
    switch(direction)
    {
    case Swipe::Up:
    case Swipe::Down:
        if(direction == Swipe::Up) {
            nextCurrent = [](size_t& rowindex, size_t& columnindex) { ++rowindex; (void) columnindex; };
            rowIndex = 0;
        }
        else {
            nextCurrent = [](size_t& rowIndex, size_t& columnIndex) { --rowIndex; (void) columnIndex; };
            rowIndex = rowCount();
        }
        nextLine = [](size_t& rowIndex, size_t& columnIndex) { (void)rowIndex; ++columnIndex; };
        columnIndex = 0;
        lineSize = rowCount();
        lineCount = columnCount() - 1;
        break;
    case Swipe::Right:
    case Swipe::Left:
        if(direction == Swipe::Right) {
            nextCurrent = [](size_t& rowIndex, size_t& columnIndex) {  (void) rowIndex; ++columnIndex; };
            columnIndex = 0;
        }
        else {
            nextCurrent = [](size_t& rowIndex, size_t& columnIndex) {  (void) rowIndex; --columnIndex; };
            columnIndex = columnCount() - 1;
        }
        nextLine = [](size_t& rowindex, size_t& columnindex) { ++rowindex; (void) columnindex; };
        rowIndex = 0;
        lineSize = columnCount();
        lineCount = rowCount();
        break;
    }

    size_t followingRowIndex = rowIndex, followingColumnIndex = columnIndex;
    nextCurrent(followingRowIndex, followingColumnIndex);
    --lineSize;
    while(lineCount != 0) {
        while(lineSize != 0) {
            if(tileAt(rowIndex, columnIndex).value() == tileAt(followingRowIndex, followingColumnIndex).value()) {
                setTileAt(rowIndex, columnIndex, 2 * tileAt(rowIndex, columnIndex).value());
                setTileAt(followingRowIndex, followingColumnIndex, defaultTile());
            }
            nextCurrent(rowIndex, columnIndex);
            nextCurrent(followingRowIndex, followingColumnIndex);
            --lineSize;
        }
        nextLine(rowIndex, columnIndex);
        --lineCount;
    }

    return *this;
}
