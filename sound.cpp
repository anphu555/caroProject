#include "Functions.h"

extern int musicSong; // 0 menu, 1 ingame
extern bool backgroundMusicmode;
extern bool SFXmode; // false off, true on

void introSound()
{
	PlaySound(TEXT("introloading.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void backgroundMusicSound()
{
	if (musicSong == 0) // menu
	{
		mciSendString(L"stop \"Creator.mp3\"", NULL, 0, 0); //stop ingame music
		(backgroundMusicmode) ? mciSendString(L"play \"Sweden.mp3\" repeat", NULL, 0, 0) : mciSendString(L"pause \"Sweden.mp3\"", NULL, 0, 0);
	}
	else if (musicSong == 1) 
	{
		mciSendString(L"stop \"Sweden.mp3\"", NULL, 0, 0);
		(backgroundMusicmode) ? mciSendString(L"play \"Creator.mp3\" repeat", NULL, 0, 0) : mciSendString(L"pause \"Creator.mp3\"", NULL, 0, 0);
	}
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
	(SFXmode) ? PlaySound(TEXT("RareAchievement.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(0, 0, 0);
}
void newGameSound()
{
	(SFXmode) ? PlaySound(TEXT("mclick.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(0, 0, 0);
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
void moveSound()
{
	(SFXmode) ? PlaySound(TEXT("moveXO.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(0, 0, 0);
}