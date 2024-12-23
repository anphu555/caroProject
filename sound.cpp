#include "Functions.h"

extern bool backgroundMusicmode;
extern bool SFXmode; // false off, true on

void introSound()
{
	PlaySound(TEXT("introloading.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void backgroundMusicSound()
{
	(backgroundMusicmode) ? mciSendString(L"play \"Swedenremix.mp3\" repeat", NULL, 0, 0) : mciSendString(L"pause \"Swedenremix.mp3\"", NULL, 0, 0);
}
void enterXSound()
{
	(SFXmode) ? PlaySound(TEXT("wood2.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(0,0,0);
}
void enterOSound()
{
	(SFXmode) ? PlaySound(TEXT("stone1.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(0, 0, 0);
}
void winSound()
{
	(SFXmode) ? PlaySound(TEXT("gameWin.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(0, 0, 0);
}
void newGameSound()
{
	(SFXmode) ? PlaySound(TEXT("newgame.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(0, 0, 0);
}
void pickSound()
{
	(SFXmode) ? PlaySound(TEXT("mclick.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(0, 0, 0);
}
void exitSound()
{
	(SFXmode) ? PlaySound(TEXT("exitsound.wav"), NULL, SND_FILENAME | SND_SYNC) : PlaySound(0, 0, 0);
}
void saveSound()
{
	(SFXmode) ? PlaySound(TEXT("savesound.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(0, 0, 0);
}

//void moveSound()
//{
//	(SFXmode) ? PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_SYNC) : PlaySound(0, 0, 0);
//}