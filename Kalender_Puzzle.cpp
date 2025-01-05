#include <iostream>
#include <bitset>
#include <list>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <unordered_set>

/*********************************************************************************************************************/

constexpr size_t nRows{7};
constexpr size_t nMaxCols{8}; // add one "protection" bit which may never be set

// we store always full 8 bits per row, so some bits do not represent actual positions on the board
constexpr size_t nBits = nRows*nMaxCols;

constexpr size_t nPieces{9};

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

    bool operator==(const Piece& other) const {
        return other.mask == mask && other.id == id;
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

void visualize(std::list<Piece> pieces) {
    size_t position = 0;
    for(size_t row=0; row<nRows; ++row) {
        for(size_t col=0; col<nMaxCols; ++col) {
            int id=0;
            for(const auto &p : pieces) {
                if(!p.mask.test(positionToBit(position))) continue;
                if(id == 0) {
                    id = p.id;
                }
                else {
                    id = -1;
                }
            }
            if(id == 0) {
                std::cout << " ";
            }
            else if(id == -1) {
                std::cout << "!";
            }
            else {
                std::cout << id;
            }
            ++position;
        }
        std::cout << std::endl;
    }
}

/*********************************************************************************************************************/

// Map Index: first used position of the piece
std::map<size_t, std::list<Piece>> piece_positions;

size_t nSolutionsFound{0};

/*********************************************************************************************************************/
/*********************************************************************************************************************/

void recursiveSolver(std::bitset<nBits> board, size_t nextPosition, std::bitset<nPieces> usedPieceIds,
                    std::list<Piece> usedPieces) {

    //
    if(board.all()){
        // solution found!
        std::cout << "Solution " << ++nSolutionsFound << std::endl;
        visualize(usedPieces);
    }

    // find next free position
    while(board.test(positionToBit(nextPosition)) || piece_positions.find(nextPosition) == piece_positions.end()) {
        ++nextPosition;
        if(positionToBit(nextPosition) >= nBits) {
            // no solution possible...
            return;
        }
    }

    // check all pieces on that position
    for(auto p : piece_positions.at(nextPosition)) {
        if(usedPieceIds.test(p.id-1)) {
            // piece is already used
            continue;
        }
        if((board & p.mask).any()) {
            // piece collides with something already on the board
            continue;
        }
        auto boardWithP = board | p.mask;
        auto usedPieceIdsWithP = usedPieceIds;
        usedPieceIdsWithP.set(p.id - 1);
        auto usedPiecesWithP = usedPieces;
        usedPiecesWithP.push_back(p);
        recursiveSolver(boardWithP, nextPosition+1, usedPieceIdsWithP, usedPiecesWithP);
    }


}


/*********************************************************************************************************************/
/*********************************************************************************************************************/

int main(int argc, char** argv) {
    // parse command line
    if(argc != 3) {
        std::cout << "Usage: Kalender_Puzzle <day> <month>" << std::endl;
        std::cout << "With day: 1-31 and month: 1-12" << std::endl;
        return 1;
    }

    size_t month = std::atoi(argv[2]);
    size_t day = std::atoi(argv[1]);

    if(day < 1 || day > 31) {
        std::cout << "Day " << day << " out of range!" << std::endl;
        return 1;
    }
    if(month < 1 || month > 12) {
        std::cout << "Month` " << month << " out of range!" << std::endl;
        return 1;
    }


    // fill piece_positions
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
                piece_positions[pieceShifted.getFirstPosition()].push_back(pieceShifted);
            }
        }
    }


    // Reserve date positions on board 
    auto board = boundingBox;

    size_t monthBit = nBits - month - (month > 6 ? nMaxCols-6 : 0);
    board.set(monthBit);

    size_t dayBit = nBits-1 - 2*nMaxCols - ((day-1)/7)*nMaxCols - (day-1)%7;
    board.set(dayBit);

    // start recursive solver
    recursiveSolver(board, 0, {}, {});
    return 0;
}