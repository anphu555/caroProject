﻿#ifndef Color_H
#define Color_H

// dinh nghia bo mau. ANSI CODE
// 1 Basic colors
#define COLOR_BLACK         "\u001b[30m"   
#define COLOR_RED           "\u001b[31m"    
#define COLOR_GREEN			"\u001b[32m"
#define COLOR_YELLOW		"\u001b[33m"
#define COLOR_BLUE          "\u001b[34m" 
#define COLOR_MAGNETA		"\u001b[35m"
#define COLOR_CYAN          "\u001b[36m" 
#define COLOR_WHITE         "\u001b[37m" 
#define COLOR_PINK			"\u001b[38;5;218m"
#define COLOR_PINK_DARK    "\u001b[38;5;125m"
#define COLOR_PINK2        "\u001b[38;5;200m" 

//// High intesity colors
 #define COLOR_BLACK_HI       "\u001b[90m"   
#define COLOR_RED_HI			"\u001b[91m"    
#define COLOR_GREEN_HI			"\u001b[92m"
#define COLOR_YELLOW_HI			"\u001b[93m"
#define COLOR_BLUE_HI			"\u001b[94m" 
#define COLOR_MAGNETA_HI			"\u001b[95m"
#define COLOR_CYAN_HI			"\u001b[96m" 
#define COLOR_WHITE_HI			"\u001b[97m" 

// 2 Reset
//#define COLOR_RESET         "\u001b[0m\u001b[106m\u001b[30m"
#define COLOR_RESET         "\u001b[0m\u001b[107m\u001b[30m"
//#define COLOR_RESET         "\u001b[0m" chỉnh cho thành nền trắng chữ đen

// 3 Format
// Bold text
#define COLOR_BOLD          "\u001b[1m" 

// Darker color
#define COLOR_DARK          "\u001b[2m"   

// Italic text
#define COLOR_ITALIC        "\u001b[3m"

// Regular underline text
#define COLOR_UNDERLINE     "\u001b[4m"   

// CACH SU DUNG: printf(1 3 "<text>" 2); // reset de lan sau khoi dinh dang lai

// ========chua biet sai ==============
// High intensty background 
#define BACKGROUND_GRAY		"\u001b[100m"
#define BACKGROUND_BLACK "\u001b[40m"
#define BACKGROUND_RED			"\u001b[101m"
#define BACKGROUND_RED_DARK		"\u001b[41m"
#define BACKGROUND_GREEN		"\u001b[102m"
#define BACKGROUND_YELLOW		"\u001b[103m"
#define BACKGROUND_YELLOW_DARK	"\u001b[43m"
#define BACKGROUND_BLUE			"\u001b[104m"
//#define BACKGROUND_BLUE_DARK	"\u001b[44m"
#define BACKGROUND_MAGNETA		"\u001b[105m"
#define BACKGROUND_CYAN			"\u001b[106m"
#define BACKGROUND_WHITE		"\u001b[107m"
#define BACKGROUND_GREEN_DARK       "\u001b[42m"
#define BACKGROUND_WHITE_SOFT     "\u001b[48;5;255m"  // Trắng nhẹ

//\e[40m	Black
//\e[41m	Red
//\e[42m	Green
//\e[43m	Yellow
//\e[44m	Blue
//\e[45m	Purple
//\e[46m	Cyan
//\e[47m	White
// ========================


#endif