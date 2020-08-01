#ifndef __IOSTREAM__
#define __IOSTREAM__

#include <iostream>
#endif

#ifndef __WINDOWS_H__
#define __WINDOWS_H__

#include <windows.h> //for handle
#endif

#ifndef __CONIO_H__
#define __CONIO_H__

#include <conio.h>
#endif

#ifndef NAMESPACE
#define NAMESPACE

using namespace std;
#endif

#ifndef __MMSYSTEM_H__
#define __MMSYSTEM_H__

//playSound함수로 사운드를 재생하는데 wav파일만 지원된다 
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//왜인지는 모르겠으나, winmm 라이브러리가 보이지 않음에도 
//프로젝트 옵션 > 매개변수들 > 링커에 -lwinmm 을 추가하자 정상적으로 작동됨 
#endif
/*
이 헤더파일은 winmm.lib라는 파일을 사용한다 
mp3파일은 mci를 사용하면 된다 

wav파일을 bgm으로 지정 시 상당한 용량으로 부담된다
또한, 이 함수를 이용할 경우 배경음과 효과음을 동시에
사용할 수 없다. 따라서 mp3를 지원하는 mci와, sndPlaySoundA
를 동시에 이용하면 된다. bgm을 작은 용량을 이용하도록
mci로 연주해주고, 효과음을 sndPlaySoundA를 사용하면 좋다.
-효과음 자체가 용량이 작다-
*/
