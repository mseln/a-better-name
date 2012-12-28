

#include "game.h"

Game::Game(){
	window = new sf::RenderWindow(sf::VideoMode(1200, 800), "TCoCD");
	window->SetFramerateLimit(60);
	
	event_h = new Event_Handler(window);
	game_state = new Game_States(MENU);
	
	menu.init();
	ingame_menu.init();
	
	*game_state = MENU;
	
	pause_if_in_menu = true;
}

void Game::run(){
	while (window->IsOpened()){
		event_h->update();
		window->Clear();
		
		update();
		window->Display();
	}
}

void Game::update(){
	switch (*game_state) {
		case MENU:
			//std::cout << "in menuloop\n";
			menuloop();
			break;
		
		case IN_GAME:
			//std::cout << "in gameloop\n";
			gameloop();
			break;
		
		case IN_GAME_MENU:
			//std::cout << "in ingame menuloop\n";
			if (pause_if_in_menu) gameloop();
			ingame_menuloop();
			break;
	}
}

void Game::menuloop(){
	//if(event_h->pollCh('a')) *game_state = IN_GAME;
	
	menu.update(game_state, event_h, window);
	menu.draw(window);
	
	if(*game_state == IN_GAME) session = new Session(window, event_h);
}

void Game::gameloop(){
	if(event_h->pollSp('E')){
		*game_state = IN_GAME_MENU;
	}
	
	session->update();
	session->draw();
}

void Game::ingame_menuloop(){
	ingame_menu.update(game_state, event_h, window);
	ingame_menu.draw(window);
	
	if(*game_state == MENU) delete session;
}