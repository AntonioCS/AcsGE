#include "MouseManager.h"

namespace AcsGameEngine {
    MouseManager& MouseManager::getInstance()
    {
        static MouseManager mm;
        return mm;
    }
}
