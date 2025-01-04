#include <iostream>
#include <bitset>
#include <list>
#include <vector>
#include <array>
#include <map>

/*********************************************************************************************************************/

constexpr size_t nRows{7};
constexpr size_t nMaxCols{8}; // add one "protection" bit which may never be set

// we store always full 8 bits per row, so some bits do not represent actual positions on the board
constexpr size_t nBits = nRows*nMaxCols;


/*********************************************************************************************************************/

size_t getNCols(size_t row) {
    return row < 2 ? 6 : row < 6 ? 7 : 3;
}

/*********************************************************************************************************************/

// These bits may never be set
std::bitset<nBits> boundingBox(
    "00000011"      \
    "00000011"      \
    "00000001"     \
    "00000001"     \
    "00000001"     \
    "00000001"     \
    "00011111");


/*********************************************************************************************************************/

size_t positionToBit(size_t position) {
    return nBits-1-position;
}

/*********************************************************************************************************************/

struct Piece {
    std::bitset<nBits> mask;
    size_t id;

    size_t getFirstPosition() const {
        for(size_t i=0; i<nBits; ++i) {
            if(mask.test(positionToBit(i))) {
                return i;
            }
        }
        throw; // cannot happen
    }

    size_t getHeight() const {
        for(size_t i=nBits-1; i>=0; --i) {
            if(mask.test(positionToBit(i))) {
                return i / nMaxCols + 1;
            }
        }
        throw; // cannot happen
    }

};

/*********************************************************************************************************************/

// Define Pieces in first position
std::array<Piece, 39> pieces{{
    {std::bitset<nBits>(
    "01000000"      \
    "11000000"      \
    "01000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),1},
    {std::bitset<nBits>(
    "10000000"      \
    "11000000"      \
    "10000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),1},
    {std::bitset<nBits>(
    "01000000"      \
    "11100000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),1},
    {std::bitset<nBits>(
    "11100000"      \
    "01000000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),1},

    {std::bitset<nBits>(
    "11000000"      \
    "11000000"      \
    "01000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),2},
    {std::bitset<nBits>(
    "11000000"      \
    "11000000"      \
    "10000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),2},
    {std::bitset<nBits>(
    "11100000"      \
    "11000000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),2},
    {std::bitset<nBits>(
    "11000000"      \
    "11100000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),2},
    {std::bitset<nBits>(
    "10000000"      \
    "11000000"      \
    "11000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),2},
    {std::bitset<nBits>(
    "01000000"      \
    "11000000"      \
    "11000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),2},
    {std::bitset<nBits>(
    "01100000"      \
    "11100000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),2},
    {std::bitset<nBits>(
    "11100000"      \
    "01100000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),2},

    {std::bitset<nBits>(
    "11000000"      \
    "11000000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),3},

    {std::bitset<nBits>(
    "10100000"      \
    "11100000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),4},
    {std::bitset<nBits>(
    "11100000"      \
    "10100000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),4},
    {std::bitset<nBits>(
    "11000000"      \
    "10000000"      \
    "11000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),4},
    {std::bitset<nBits>(
    "11000000"      \
    "01000000"      \
    "11000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),4},

    {std::bitset<nBits>(
    "01000000"      \
    "01000000"      \
    "11000000"     \
    "01000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),5},
    {std::bitset<nBits>(
    "01000000"      \
    "11000000"      \
    "01000000"     \
    "01000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),5},
    {std::bitset<nBits>(
    "11110000"      \
    "01000000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),5},
    {std::bitset<nBits>(
    "11110000"      \
    "00100000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),5},
    {std::bitset<nBits>(
    "10000000"      \
    "11000000"      \
    "10000000"     \
    "10000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),5},
    {std::bitset<nBits>(
    "10000000"      \
    "10000000"      \
    "11000000"     \
    "10000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),5},
    {std::bitset<nBits>(
    "01000000"      \
    "11110000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),5},
    {std::bitset<nBits>(
    "00100000"      \
    "11110000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),5},

    {std::bitset<nBits>(
    "10000000"      \
    "10000000"      \
    "10000000"     \
    "10000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),6},
    {std::bitset<nBits>(
    "11110000"      \
    "00000000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),6},

    {std::bitset<nBits>(
    "11000000"      \
    "01000000"      \
    "01100000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),7},
    {std::bitset<nBits>(
    "01100000"      \
    "01000000"      \
    "11000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),7},
    {std::bitset<nBits>(
    "10000000"      \
    "11100000"      \
    "00100000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),7},
    {std::bitset<nBits>(
    "00100000"      \
    "11100000"      \
    "10000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),7},

    {std::bitset<nBits>(
    "11000000"      \
    "01100000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),8},
    {std::bitset<nBits>(
    "01100000"      \
    "11000000"      \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),8},
    {std::bitset<nBits>(
    "10000000"      \
    "11000000"      \
    "01000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),8},
    {std::bitset<nBits>(
    "01000000"      \
    "11000000"      \
    "10000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),8},

    {std::bitset<nBits>(
    "10000000"      \
    "10000000"      \
    "11100000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),9},
    {std::bitset<nBits>(
    "00100000"      \
    "00100000"      \
    "11100000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),9},
    {std::bitset<nBits>(
    "11100000"      \
    "00100000"      \
    "00100000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),9},
    {std::bitset<nBits>(
    "11100000"      \
    "10000000"      \
    "10000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"     \
    "00000000"),9}
}};

/*********************************************************************************************************************/

void visualize(Piece piece) {
    size_t position = 0;
    for(size_t row=0; row<nRows; ++row) {
        for(size_t col=0; col<nMaxCols; ++col) {
            if(piece.mask.test(positionToBit(position))) {
                std::cout << piece.id;
            }
            else {
                std::cout << " ";
            }
            ++position;
        }
        std::cout << std::endl;
    }
}

/*********************************************************************************************************************/

// Map Index: first used position of the piece
std::map<size_t, std::list<Piece>> piece_positions;


/*********************************************************************************************************************/

int main() {

    for(size_t idx = 0; idx < pieces.size(); ++idx ) {
        const Piece& piece = pieces[idx]; 
        size_t maxRowShift = nRows - piece.getHeight();
        for(size_t rowShift = 0; rowShift <= maxRowShift; ++rowShift) {
            size_t lastRow = rowShift + piece.getHeight() - 1;
            size_t minColWidth = std::min(getNCols(rowShift), getNCols(lastRow));
            for(size_t colShift = 0; colShift <= nMaxCols-1; ++colShift) {
                size_t bitShift = colShift + rowShift*nMaxCols;
                Piece pieceShifted = piece;
                pieceShifted.mask = piece.mask >> bitShift;
                if((pieceShifted.mask & boundingBox).any()) continue; // violates bounding box
                visualize(pieceShifted);
                std::cout << "--- " << std::endl;
                piece_positions[pieceShifted.getFirstPosition()].push_back(pieceShifted);
            }
        }
    }




}