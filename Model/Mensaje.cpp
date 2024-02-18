#include "Mensaje.h"

std::string Mensaje::ConvertirMayusculas(const std::string& mensaje) {
    std::string result = mensaje;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}
