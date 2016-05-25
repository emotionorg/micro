#include <Wtv020sd16p.h>

Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);

void say(int number) {
    wtv020sd16p.reset();
    int length;
    int* sounds = numberToFileNames(number, length);
    for (int i = 0; i < length; i++) {
        wtv020sd16p.asyncPlayVoice(sounds[i]);
    }
}

int* numberToFileNames(int number, int &length) {
    String digits = String(number);
    int* sounds = new int[10];
    length = 0;
    for (int i = 0; i < digits.length(); i++) {
        int digit = digits[i] - '0';
        int row = (digits.length() - 1 - i) % 3 + 1;
        if (row == 2 && digit == 1 && (digits[i + 1] - '0') != 0) {
            row = 4;
            digit = digits[++i] - '0';
        }
        bool isThousand = digits.length() - i == 4;
        if (isThousand && digit == 2) {
            sounds[length++] = 40;
        } else if (!(isThousand && digit == 1 && row != 4) && digit != 0) {
            sounds[length++] = 9 * (row - 1) + digit;
        }
        if (isThousand) {
            int thousand;
            if (row == 4) {
                thousand = 39;
            } else switch (digit) {
                case 1:
                    thousand = 37;
                    break;
                case 2:
                case 3:
                case 4:
                    thousand = 38;
                    break;
                default:
                    thousand = 39;
                    break;
            }
            sounds[length++] = thousand;
        }
    }
    return sounds;
}

