#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "GameLoop.h"
#include "Menu.h"
#include "GameOver.h"

#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>  
#include <crtdbg.h> 


/* Nice links
Smart pointers
http://stackoverflow.com/questions/16894400/how-to-declare-stdunique-ptr-and-what-is-the-use-of-it
Image manager
https://github.com/SFML/SFML/wiki/Tutorial:-Image-Manager
*/

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	GameLoop gl;
	gl.run();
	

	return 0;
}
