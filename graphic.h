#ifndef graphic_H
#define graphic_H

#include <io.h>
#include <fcntl.h>
#include <thread>
#include <chrono>


// NHỮNG HÀM LIÊN QUAN TỚI ĐỒ HỌA IN RA MÀN HÌNH

void CaroLogo(int x, int y);

void MenuLogo1(int x, int y); // logomenu1
void MenuLogo2(int x, int y);

void intro1(int x, int y);

void intro2(int x, int y);

void introLoading();

void AboutLogo(int x, int y);
void SettingLogo(int x, int y);
void GuideLogo(int x, int y);
void PauseLogo(int x, int y);

void WinEffect(int x, int y, int Mode);
void IngameLogo(int x, int y);
void IngameLogo2(int x, int y);
void IngameLogo3(int x, int y);
void IngameLogo4(int x, int y);

void nhapnhayXO(int x, int y, int mode);

void XLogo(int x, int y);
void OLogo(int x, int y);

void OfflineMode(int x, int y);
void BorderSquare(int, int, int, int, int);
void BorderSquareLine(int, int, int, int, int);
void BorderSquareFILL(int xleft, int xright, int ytop, int ybottom);

#endif
