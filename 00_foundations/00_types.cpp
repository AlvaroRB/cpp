/**
 * 00_types.cpp
 * Tamaños garantizados vs tamaños dependientes de plataforma.
 * En sistemas embebidos importa muchp (<cstdint> es obligatorio)
 */

#include <iostream>
#include <cstdint>
#include <climits>

int main() {
    // --- Tipos básicos: tamaño NO garantizado por estándar ---
    std::cout << "=== Tipos básicos (plataforma-dependientes) ===\n";
    std::cout << "char:      " << sizeof(char)      << " byte(s)\n";
    std::cout << "short:     " << sizeof(short)     << " byte(s)\n";
    std::cout << "int:       " << sizeof(int)       << " byte(s)\n";
    std::cout << "long:      " << sizeof(long)      << " byte(s)\n";
    std::cout << "long long: " << sizeof(long long) << " byte(s)\n";
    std::cout << "float:     " << sizeof(float)     << " byte(s)\n";
    std::cout << "double:    " << sizeof(double)    << " byte(s)\n";

    // --- Tipos de ancho fijo: tamaño GARANTIZADO (<cstdint>) ---
    // Usar siempre en código portable o embebido.
    std::cout << "\n=== Tipos de ancho fijo (cstdint) ===\n";
    std::cout << "int8_t:   " << sizeof(int8_t)   << " byte(s)\n";
    std::cout << "int16_t:  " << sizeof(int16_t)  << " byte(s)\n";
    std::cout << "int32_t:  " << sizeof(int32_t)  << " byte(s)\n";
    std::cout << "int64_t:  " << sizeof(int64_t)  << " byte(s)\n";
    std::cout << "uint32_t: " << sizeof(uint32_t) << " byte(s)\n";

    // --- Rangos ---
    std::cout << "\n=== Rangos ===\n";
    std::cout << "int32_t max: " << INT32_MAX << "\n";
    std::cout << "int32_t min: " << INT32_MIN << "\n";
    std::cout << "uint32_t max: " << UINT32_MAX << "\n";

    // --- Conversiones implícitas: fuente de bugs silenciosos ---
    std::cout << "\n=== Conversiones implícitas (cuidado) ===\n";
    int32_t  a = -1;
    uint32_t b = a;   // -1 se convierte a 4294967295 sin warning por defecto
    std::cout << "int32_t  -1  cast a uint32_t: " << b << "\n";

    // Compilar con -Wsign-conversion para detectarlo.

    return 0;
}