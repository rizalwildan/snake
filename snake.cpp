#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

bool gameOver;
int width =20, height = 20, x, y, fruitX, fruitY, score;
enum direction{ STOP = 0, LEFT, RIGHT, UP, DOWN};
direction dir;
void setup(){
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height /2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void draw(){
	system("cls");
	
	for(int i = 0; i <= width; i++){
		cout<<"#";	
	}
	cout << endl;
	
	for(int i = 0; i<height; i++){
		for(int j = 0; j<=width; j++){
			
			if(j==0 || j == width){
				cout << "#";
			}else if(i == y && j == x){
				cout << "O";
			}else if(i == fruitY && j == fruitX){
				cout << "*";
				cout << "*";a
			}else{
				cout << " ";
			}
		}
		
		cout << endl;
	}
	
	for(int i = 0; i <= width; i++){
		cout<<"#";
	}
	cout << endl;
	
	
}

void input(){
	
	if(_kbhit()){
		switch(_getch()){
			case 'a':
				dir = LEFT;
			break;
			case 'd':
				dir = RIGHT;
			break;
			case 'w':
				dir = UP;
			break;
			case 's':
				dir = DOWN;
			break;
			case 'x':
				gameOver = true;
			break;
		}
	}
}

void logic(){
	
	switch(dir){
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
	}
}

int main(){
	setup();
	while(!gameOver){
		draw();
		input();
		logic();
	}
}
