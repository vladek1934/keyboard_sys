
#include <stdio.h>
#include <hidapi/hidapi.h>

typedef unsigned char byte;
struct color
{
    byte R;
    byte G;
    byte B;
};

void colorize_part(hid_device *keyboard, struct color newcolor, byte part)
{

    byte buffer[8];
    buffer[0] = 1;
    buffer[1] = 2;
    buffer[2] = 64;
    buffer[3] = part;
    buffer[4] = newcolor.R;
    buffer[5] = newcolor.G;
    buffer[6] = newcolor.B;
    hid_send_feature_report(keyboard, buffer, 8);
}

int main(int argc, char **argv)
{
    int check = hid_init();
    hid_device *keyboard = NULL;
    keyboard = hid_open(0x1770, 0xff00, 0); //can be found using a lsusb command in the terminal

    printf("Entered the program\n");
    if (check == 0)
        //printf(keyboard->device_handle);
        //printf(keyboard->device_handle);

    if (keyboard != NULL)
    {
        printf("Entered the keyboard\n");
        struct color newcolor;
        byte part;
        switch (argv[1][0])
        {
        case '1':
            part = 1;
            break;
        case '2':
            part = 2;
            break;
        case '3':
            part = 3;
            break;
        }
        switch (argv[1][1])
        {
        case 'r':
            newcolor.R = 255;
            newcolor.G = 0;
            newcolor.B = 0;
            break;
        case 'g':
            newcolor.R = 0;
            newcolor.G = 255;
            newcolor.B = 0;
            break;
        case 'b':
            newcolor.R = 0;
            newcolor.G = 0;
            newcolor.B = 255;
            break;
        case 'n':
            newcolor.R = 0;
            newcolor.G = 0;
            newcolor.B = 0;
            break;
        }
        colorize_part(keyboard, newcolor, part);
        hid_close(keyboard);
    }
    else
    {
        printf("No compatible keyboard found!\n");
    }

    return 0;
}
