/*
 * This is free and unencumbered software released into the public domain.
 *
 * For more information, please refer to <https://unlicense.org>
 */

#ifndef terminal_color_h
#define terminal_color_h



//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//High intensty background
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//High intensty text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Bold high intensity text
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//Reset
#define reset "\e[0m"

//Defentions in different format need to improve this

    std::string fgBlack = "\033[30m";
    std::string fgBrightBlack = "\033[30;1m";
    std::string bgBlack = "\033[40m";
    std::string bgBrightBlack = "\033[40;1m";

    std::string fgRed = "\033[31m";
    std::string fgBrightRed = "\033[31;1m";
    std::string bgRed = "\033[41m";
    std::string bgBrightRed = "\033[41;1m";

    std::string fgGreen = "\033[32m";
    std::string fgBrightGreen = "\033[32;1m";
    std::string bgGreen = "\033[42m";
    std::string bgBrightGreen = "\033[42;1m";

    std::string fgYellow = "\033[33m";
    std::string fgBrightYellow = "\033[33;1m";
    std::string bgYellow = "\033[43m";
    std::string bgBrightYellow = "\033[43;1m";

    std::string fgBlue = "\033[34m";
    std::string fgLight_Blue = "\033[104m";
    std::string fgBrightBlue = "\033[34;1m";
    std::string bgBlue = "\033[44m";
    std::string bgBrightBlue = "\033[44;1m";

    std::string fgMagenta = "\033[35m";
    std::string fgBrightMagenta = "\033[35;1m";
    std::string bgMagenta = "\033[45m";
    std::string bgBrightMagenta = "\033[45;1m";

    std::string fgCyan = "\033[36m";
    std::string fgBrightCyan = "\033[36;1m";
    std::string bgCyan = "\033[46m";
    std::string bgBrightCyan = "\033[46;1m";

    std::string fgWhite = "\033[37m";
    std::string fgBrightWhite = "\033[37;1m";
    std::string bgWhite = "\033[47m";
    std::string bgBrightWhite = "\033[47;1m";

#endif /* terminal_color_h */
