#pragma once
#include <Windows.h>
#include "Types.h"

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,

};

class ConsoleHelper
{
public:
	// ���ڱ��� �Ÿ��� Ŀ��
	static void SetCursorPosition(int32 x, int32 y);
	// Ŀ�� ���� ����
	static void SetCursorColor(ConsoleColor color);
	// Ŀ���� �������� �Ⱥ������� �����ϴ� �Լ�
	static void ShowConsoleCursor(bool flag);
};

