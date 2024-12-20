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
void LoadLogo(int x, int y);//giao diện màn hình load game
void SaveNewFileLogo(int x, int y);//giao diện màn hình lưu game
void PlayAgianLogo(int x, int y);//giao diện màn hình chơi
void SaveGameLogo(int x, int y);
void GameModeLogo(int x, int y);
void nhapnhayXO(int x, int y, int mode);

void XLogo(int x, int y);
void OLogo(int x, int y);

void OfflineMode(int x, int y);
void BorderSquare(int, int, int, int, int);
void BorderSquareLine(int, int, int, int, int);
void BorderSquareFILL(int xleft, int xright, int ytop, int ybottom);

void backgroundGraphic();
void CreeperMini(int x, int y);

void DiamondPickaxe(int x, int y);
void DiamondSword(int x, int y);
void DiamondSword2(int x, int y);
void MenuCloud(int x, int y);
void MenuLogoTree(int x, int y);

void RedMushroom(int x, int y);

void GoldOre(int x, int y);

#endif
