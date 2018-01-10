#pragma once

#include <iostream>



using namespace std;
#include <fstream>
#include <assert.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include "Cursor.h"
#include "Menu.h"
#include "ATM.h"
#include "Card.h"

#define COIS	60 
#define LINES	25
#define U8	unsigned char	
#define U16	unsigned short	
#define U32	unsigned int	

extern const string MENU_TEXT1[3];

void Initial(void);