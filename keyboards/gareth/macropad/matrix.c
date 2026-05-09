#include "matrix.h"
#include "print.h"

void matrix_init_custom(void) {
        print("[HALLSCAN] Initializing matrix hardware\n");

}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    print("[HALLSCAN] matrix_scan_custom called\n");
    return false;
}
