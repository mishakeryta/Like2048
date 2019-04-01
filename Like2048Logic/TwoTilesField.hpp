#ifndef TWOTILESFIELD_HPP
#define TWOTILESFIELD_HPP
#include "AbstractTilesField.hpp"

class TwoTilesField : public AbstractTilesField
{
    const static NumberedTile EMPTY;
public:
    TwoTilesField(std::size_t rowCount, std::size_t columnCount);

    AbstractTilesField &handle(Swipe direction);
};

#endif // TWOTILESFIELD_HPP
