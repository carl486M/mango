#include "mango/engine.hpp"

int main() {
    mango mango(854, 480, "NO");

    while (!mango.shouldQuit) {
        mango.update();
    }

    mango.quit();
    return 0;
}