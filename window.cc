
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "window.h"
#include "board.h"
#include "piece.h"



using namespace std;

Xwindow::Xwindow(int width, int height) {

  d = XOpenDisplay(NULL);
  if (d == NULL) {
    cerr << "Cannot open display" << endl;
    exit(1);
  }
  s = DefaultScreen(d);
  w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                          BlackPixel(d, s), WhitePixel(d, s));
  XSelectInput(d, w, ExposureMask | KeyPressMask);
  XMapRaised(d, w);

  Pixmap pix = XCreatePixmap(d,w,width,
        height,DefaultDepth(d,DefaultScreen(d)));
  gc = XCreateGC(d, pix, 0,(XGCValues *)0);

  XFlush(d);
  XFlush(d);

  // Set up colours.
  XColor xcolour;
  Colormap cmap;
  char color_vals[7][10]={"white", "black", "red", "green", "blue"};

  cmap=DefaultColormap(d,DefaultScreen(d));
  for(int i=0; i < 5; ++i) {
      XParseColor(d,cmap,color_vals[i],&xcolour);
      XAllocColor(d,cmap,&xcolour);
      colours[i]=xcolour.pixel;
  }

  XSetForeground(d,gc,colours[Black]);

  // Make window non-resizeable.

  // This shit doesnt work

  XSizeHints hints;
  hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
  hints.height = hints.base_height = hints.min_height = hints.max_height = height;
  hints.width = hints.base_width = hints.min_width = hints.max_width = width;
  XSetNormalHints(d, w, &hints);

  XSynchronize(d,True);

  usleep(1000);

}

Xwindow::~Xwindow() {
  XFreeGC(d, gc);
  XCloseDisplay(d);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
  XSetForeground(d, gc, colours[colour]);
  XFillRectangle(d, w, gc, x, y, width, height);
  XSetForeground(d, gc, colours[Black]);
}

void Xwindow::drawString(int x, int y, string msg, int fontsize, string fontcolor) {
  // Convert color string to XColor
  XColor xcolour;
  Colormap cmap = DefaultColormap(d, DefaultScreen(d));
  XParseColor(d, cmap, fontcolor.c_str(), &xcolour);
  XAllocColor(d, cmap, &xcolour);
  XSetForeground(d, gc, xcolour.pixel);
  // Load the font and set the font size
  string fontname = "fixed"; // Change this to your desired font name if needed
  XFontStruct *font = XLoadQueryFont(d, fontname.c_str());
  // 

  // Draw the string centered within each grid
  int textWidth = XTextWidth(font, msg.c_str(), msg.length());
  int textHeight = font->ascent - font->descent;
  int centerX = x + 50 - (textWidth / 2); // Center text horizontally
  int centerY = y + 50 + (textHeight / 2); // Center text vertically

  XDrawString(d, w, gc, centerX, centerY, msg.c_str(), msg.length());

  XSetForeground(d, gc, colours[Black]);
}
void Xwindow::draw_board(Board &board) {
  int fontsize = 30; // Adjust this value as needed for your desired font size
  for (int row = 0; row <= 7; row++) {
    int y = row * 100;
    for (int col = 0; col <= 7; col++) {
      int x = col * 100;
      // Now, x and y hold the top left corner of the box they want to display
      bool isWhiteTile = (row + col) % 2 == 0;

      // Now we know the tile color
      fillRectangle(x, y, 100, 100, !isWhiteTile);
      drawString(x, y, board.getPieceType(row, col), fontsize, "blue");
    }
  }
}
