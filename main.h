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

//playSound�Լ��� ���带 ����ϴµ� wav���ϸ� �����ȴ� 
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//�������� �𸣰�����, winmm ���̺귯���� ������ �������� 
//������Ʈ �ɼ� > �Ű������� > ��Ŀ�� -lwinmm �� �߰����� ���������� �۵��� 
#endif
/*
�� ��������� winmm.lib��� ������ ����Ѵ� 
mp3������ mci�� ����ϸ� �ȴ� 

wav������ bgm���� ���� �� ����� �뷮���� �δ�ȴ�
����, �� �Լ��� �̿��� ��� ������� ȿ������ ���ÿ�
����� �� ����. ���� mp3�� �����ϴ� mci��, sndPlaySoundA
�� ���ÿ� �̿��ϸ� �ȴ�. bgm�� ���� �뷮�� �̿��ϵ���
mci�� �������ְ�, ȿ������ sndPlaySoundA�� ����ϸ� ����.
-ȿ���� ��ü�� �뷮�� �۴�-
*/
