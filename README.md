# SSD1331 Temperature Display

Some example code to use the SSD1331 display to show temperature readout.

## Color Constants

The following definitions are provided for convenience 
```
#define BLACK     0x0000
#define BLUE      0x001F
#define	RED       0xF800
#define	GREEN     0x07E0
#define CYAN      0x07FF
#define MAGENTA   0xF81F
#define YELLOW    0xFFE0
#define WHITE     0xFFFF
```

## Display Text Functions

displayText(int x, int y, int size, String text, int color)

x and y - define the postion to draw the text
size - how large the text should be
color - the colour of the text (see constants at the top of the file)

## How to extend

Take a look at the updateDisplay() function. You can add more code in here to create a string, possibly by calling your own functions. Then call displayText() to display your string at a given position, size and colour.
