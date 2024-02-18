#include <windows.h>
#include <chrono>
#include <iostream>
#include "../AC_TAD_G7_C++/Model/Mensaje.h"
#include "../AC_TAD_G7_C++/View/vPasarMayusculas.h"
#include "../AC_TAD_G7_C++/Controller/cPasarMayusculas.h"

HWND hEdit;
HWND hButton;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main() {

    // Registrar la clase de la ventana
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = "MyWindowClass";
    RegisterClass(&wc);

    // Crear la ventana
    HWND hwnd = CreateWindowEx(0, "MyWindowClass", "Convertir a mayusculas",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        400, 150, nullptr, nullptr, GetModuleHandle(nullptr), nullptr);

    if (hwnd == nullptr) {
        return 1;
    }

    // Mostrar y actualizar la ventana
    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    // Crear controles
    hEdit = vPasarMasyusculas::CrearCuadroTexto(hwnd);
    hButton = vPasarMasyusculas::CrearBotonConvertir(hwnd, hEdit);

    // Bucle de mensajes
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            break;
        }
        case WM_COMMAND: {
            if (reinterpret_cast<HWND>(lParam) == hButton && HIWORD(wParam) == BN_CLICKED) {
                // Botón presionado, permite manejar el evento en el controlador
                cPasarMayusculas::ClickBoton(hEdit);
            }
            break;
        }
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}
