#include <iostream>

int main() {
    int colors_per_row = 8; // Número de colores por fila
    int color_count = 64; // Queremos 64 colores
    
    for (int i = 0; i < color_count; ++i) {
        // Mostrar 64 colores en una línea
        std::cout << "\033[38;5;" << i << "m" << "Color " << i << "\033[0m" << "\t";

        // Cambiar de línea después de mostrar 8 colores
        if ((i + 1) % colors_per_row == 0) {
            std::cout << std::endl;
        }
    }
    
    return 0;
}
