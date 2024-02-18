#include "vPasarMayusculas.h"

HWND vPasarMasyusculas::CrearCuadroTexto(HWND hwnd) {
    return CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
        10, 10, 350, 25, hwnd, (HMENU)1, GetModuleHandle(nullptr), nullptr);
}

HWND vPasarMasyusculas::CrearBotonConvertir(HWND hwnd, HWND hEdit) {
    return CreateWindow("BUTTON", "Convertir",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        10, 50, 350, 25, hwnd, (HMENU)hEdit, GetModuleHandle(nullptr), nullptr);
}
