#include <iostream>
#include <conio.h>

bool game_over;

int x, score;
const int WIDTH = 20, HEIGHT = 20;

void setup() {
	game_over = false;
	score = 0;

	x = WIDTH / 2;

}

void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			if (x != 1) {
				x--;
			}
			break;
		case 'd':
			if (x != WIDTH) {
				x++;
			}
			break;
		case ' ':
			std::cout << '\a';
			break;
		default:
			break;
		}
	}
}

void logic() {

}

void draw() {
	system("cls");
	for (int j = 0; j < HEIGHT + 2; j++) {
		for (int i = 0; i < WIDTH + 2; i++) {
			if (j == 0 || j == HEIGHT + 1 || i == 0 || i == WIDTH + 1) {
				std::cout << "#";
			}
			else if (i == x && j == HEIGHT - 2) {
				std::cout << "&";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Score: " << score;
}

int main() {
	setup();
	while (!game_over) {
		logic();
		draw();
		input();
	}
	return 0;
}
