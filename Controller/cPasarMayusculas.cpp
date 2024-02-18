#include "cPasarMayusculas.h"
#include "../Model/Mensaje.h"
#include <iostream>

void cPasarMayusculas::ClickBoton(HWND hEdit) {
    char buffer[256];
    GetWindowText(hEdit, buffer, sizeof(buffer));

    std::string textoConvertido = Mensaje::ConvertirMayusculas(buffer);

    std::cout << "Texto ingresado (en mayusculas): " << textoConvertido << std::endl;

    PostQuitMessage(0);
}
