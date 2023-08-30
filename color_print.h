#ifndef colorprint

#define colorprint// header guard ?

typedef enum
{
    kDBlue = 1, //!< dark blue
    kGreen = 2, //!< green
    kBlue  = 3, //!< blue
    kRed   = 4, //!< red
    kPurp  = 5, //!< purple
    kGold  = 6, //!< golden
    kWhite = 7, //!< white
    kGrey  = 8, //!< grey
    kSky   = 9, //!< sky blue
} Colors;

void SetColor(Colors color_code);

void ColorPrintf(Colors color_code, const char *fmt, ...);

#endif
