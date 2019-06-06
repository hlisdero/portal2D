#include "common/objects/size.h"

Size::Size(float x, float y) : x(x), y(y) {
    if (x < 0 || y < 0) {
        throw std::runtime_error("Error: tamaño de objeto con componentes negativas");
    }
}
