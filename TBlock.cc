#include "TBlock.h"
using namespace std;

TBlock::TBlock() : name('T'), heavyBlock(false)  {
    Xcoordinate.resize(4);
    Ycoordinate.resize(4);
    rotate = 0;
}

TBlock::~TBlock() {}

TBlock* TBlock::getPtr() {
    return new TBlock(*this);
}

char TBlock::getType() {
    return name;
}

void TBlock::set(string judge, int index, int num) {
    if (judge == "X") {
        Xcoordinate[index] = num;
    } else if (judge == "Y") {
        Ycoordinate[index] = num;
    }
}

int TBlock::get(string judge, int index) {
    if (judge == "X") {
        return Xcoordinate[index];
    } else if (judge == "Y") {
        return Ycoordinate[index];
    }
    return 0;
}

bool TBlock::exist(int Xvalue, int Yvalue) {
    for (int i = 0; i < 4; i++) {
        if(Xcoordinate[i] == Xvalue && Ycoordinate[i] == Yvalue) {
            return true;
        }
    }
    return false;
}

Block* TBlock::getCopy(Block* copy) {
    for (int i = 0; i < 4; i++) {
        int x = this->get("X", i);
        copy->set("X", i , x);
        int y = this->get("Y", i);
        copy->set("Y", i , y);
        bool state = this->getState();
        copy->setState(state);
    }
    return copy;
}

void TBlock::CW() {
    int x = 17;
    int y = 10;
    for (int i = 0; i < 4; i++) {
        int newx = Xcoordinate[i];
        int newy = Ycoordinate[i];
        if (newx < x) {
            x = newx;
        }
        if (newy < y) {
            y = newy;
        }
    }
    if (rotate == 0 && x - 1 >= 0) {
        set("X", 0, x);
        set("Y", 0, y);
        set("X", 1, x);
        set("Y", 1, y + 1);
        set("X", 2, x + 1);
        set("Y", 2, y + 1);
        set("X", 3, x - 1);
        set("Y", 3, y + 1);
        rotate++;
    } else if(rotate == 1 && y + 2 <= 10) {
        set("X", 0, x + 1);
        set("Y", 0, y);
        set("X", 1, x );
        set("Y", 1, y + 1);
        set("X", 2, x + 1);
        set("Y", 2, y + 1);
        set("X", 3, x + 1);
        set("Y", 3, y + 2);
        rotate++;
    } else if(rotate == 2 && x+ 2 <= 17) {
        set("X", 0, x);
        set("Y", 0, y + 1);
        set("X", 1, x + 1);
        set("Y", 1, y + 1);
        set("X", 2, x + 2);
        set("Y", 2, y + 1);
        set("X", 3, x + 1);
        set("Y", 3, y + 2);
        rotate++;
    } else if(rotate == 3 && y - 1 >= 0) {
        set("X", 0, x + 2);
        set("Y", 0, y);
        set("X", 1, x + 1);
        set("Y", 1, y);
        set("X", 2, x + 1);
        set("Y", 2, y - 1);
        set("X", 3, x + 1);
        set("Y", 3, y + 1);
        rotate = 0;
    }
}

bool TBlock::getState() {
    return heavyBlock;
}

void TBlock::setState(bool state) {
    heavyBlock = state;
}
