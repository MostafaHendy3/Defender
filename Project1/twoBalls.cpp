//#include <SFML/Graphics.hpp>
//#include "SFML/Audio.hpp"
//#include "Collision.hpp"
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//using namespace sf;
//
//const int N = 720;
//const int M = 720;
//
//bool check(Sprite sprite)
//{
//	if (sprite.getPosition().x < 0 || sprite.getPosition().x >(N - 100))
//		return false;
//	return true;
//}
//
//
//int main()
//{
//	RenderWindow window(VideoMode(720, 720), "SapceY");
//	window.setFramerateLimit(60);
//
//
//	/*    Handling High Score    */
//	string highScorest;
//	ifstream highScoreFile("HighScore.txt");
//	/*while (getline(highScoreFile, highScorest)) {
//		cout << highScorest;
//	}*/
//	int highscoreint = 0;
//	getline(highScoreFile, highScorest);
//	if (highScorest != "") highscoreint = stoi(highScorest);
//	highScoreFile.close();
//	////////////////////////////
//
//
//
//	/*     Game Photos    */
//	Texture t1, t2, t3, t4, t5;
//	if (!t1.loadFromFile("img/green.png"))
//	{
//		cout << "Error, Green ball path not found !!!!!!!!" << endl;
//	}
//	if (!t2.loadFromFile("img/blue.png"))
//	{
//		cout << "Error, Blue ball path not found !!!!!!!!!" << endl;
//	}
//	if (!t3.loadFromFile("img/purple.png"))
//	{
//		cout << "Error, Blue ball path not found !!!!!!!!!" << endl;
//	}
//	if (!t4.loadFromFile("img/background.png"))
//	{
//		cout << "Error, Background path not found !!!!!!!!!" << endl;
//	}
//	if (!t5.loadFromFile("img/space.png"))
//	{
//		cout << "Error, Space path not found !!!!!!!!!!!" << endl;
//	}
//
//	Sprite green, blue, purple, background, space;
//
//	green.setTexture(t1);
//	blue.setTexture(t2);
//	purple.setTexture(t3);
//	background.setTexture(t4);
//	space.setTexture(t5);
//
//	green.setPosition(360, 10);
//	blue.setPosition(300, 10);
//	green.setScale(0.1, 0.1);
//	blue.setScale(0.1, 0.1);
//
//	space.setPosition(310, 690);
//
//	///////////////////////////////////////////////////////////////////////////////////////////////////////////
//	/////////////////////////////////////////////////////Sound///////////////////////////////////////
//
//	//Game music
//	Music music;
//	if (!music.openFromFile("sounds/music.ogg")) {
//		cout << "Sound Erroe\n";
//	}
//	music.play();
//	music.setVolume(35);
//
//
//	SoundBuffer crashbuf;
//	if (!crashbuf.loadFromFile("sounds/crash.wav")) {
//		cout << "Sound Erroe\n";
//	}
//	Sound sound;
//	sound.setBuffer(crashbuf);
//
//
//	SoundBuffer border;
//
//	if (!border.loadFromFile("sounds/borderCrash.wav")) {
//		cout << "Sound Erroe\n";
//	}
//	Sound bordercrash;
//	bordercrash.setBuffer(border);
//
//	SoundBuffer gamedone;
//
//	if (!gamedone.loadFromFile("sounds/gameOver.wav")) {
//		cout << "Sound Erroe\n";
//	}
//	Sound gameOver;
//	gameOver.setBuffer(gamedone);
//
//	SoundBuffer over;
//
//	if (!over.loadFromFile("sounds/gameovermusic.ogg")) {
//		cout << "Sound Error\n";
//	}
//	Sound gOver;
//	gOver.setBuffer(over);
//
//	///////////////////////////////////////////////////////////////////////////////
//
//	// Basic Coordinates of moving ball..
//	float xstep = 5, ystep = 5;
//
//
//	// ///////////////////Collision. with whit space.
//	FloatRect shape1 = green.getGlobalBounds();
//	FloatRect shape2 = space.getGlobalBounds();
//	float dx = (green.getPosition().x + (shape1.width / 2)) - (space.getPosition().x + (shape2.width / 2));
//	float dy = (green.getPosition().y + (shape1.height / 2)) - (space.getPosition().y + (shape2.height / 2));
//
//	if (Collision::PixelPerfectTest(green, space, 0))
//	{
//		cout << "Colision detected\n";
//	}
//	else
//	{
//		cout << " No Colision detected\n";
//	}
//
//	/*        Font       */
//	Font font;
//	if (!font.loadFromFile("fonts/PoorStory-Regular.ttf"))
//	{
//		cout << "Font Error" << endl;
//	}
//	Text Score;
//	int score = 0;
//	int balls = 3;
//	Score.setString("Your Score: " + to_string(score) + " Balls : " + to_string(balls));
//	Score.setFont(font);
//	Score.setString("Your Score: " + to_string(score) + " Balls : " + to_string(balls));
//	Score.setPosition(245, 0);
//	Score.setFillColor(Color::Cyan);
//
//
//	/*       Game Window      */
//	while (window.isOpen())
//	{
//		Event e;
//		while (window.pollEvent(e))
//		{
//			if (e.type == Event::Closed)
//				window.close();
//			if (e.type == Event::Closed)
//				window.close();
//			if (e.key.code == Keyboard::Right)
//			{
//				space.move(20, 0);
//				if (!check(space))
//					space.setPosition(Vector2f(620, 690));
//
//			}
//			if (e.key.code == Keyboard::Left)
//			{
//				space.move(-20, 0);
//				if (!check(space))
//					space.setPosition(Vector2f(0, 690));
//			}
//		}
//
//		// Ball Moving  
//		if (green.getPosition().x > 670) {
//			xstep -= 5;
//			bordercrash.setVolume(110);
//			bordercrash.play();
//		}
//		else if (green.getPosition().x < 0) {
//			xstep = 7;
//			bordercrash.setVolume(110);
//			bordercrash.play();
//		}
//		else if (green.getPosition().y > 680) {
//			balls--;
//			Score.setString("Your Score: " + to_string(score) + " Balls : " + to_string(balls));
//			if (balls <= 0) {
//				Score.setString("Game Over");
//
//				//			Game Over  
//				window.close();
//
//				if (score > highscoreint) {
//
//					ofstream fout("HighScore.txt");
//					fout << score << endl;
//					highscoreint = score;
//					fout.close();
//				}
//				music.stop();
//				gameOver.play();
//				int tmp = 1;
//
//				gOver.play();
//				Score.setString("Your Score: " + to_string(score) + " High Score is : " + to_string(highscoreint));
//
//				Score.setPosition(175, 600);
//				Score.setFillColor(Color::Cyan);
//				RenderWindow Gameover(VideoMode(720, 720), "Game Over");
//				Texture gamedone;
//				gamedone.loadFromFile("gameover.png");
//				Sprite  gamee(gamedone);
//
//
//
//				//gamee.scale(.5, .5);
//				while (Gameover.isOpen())
//				{
//					Event event;
//					while (Gameover.pollEvent(event))
//					{
//						if (event.type == Event::Closed)
//							Gameover.close();
//					}
//					Gameover.clear();
//					Gameover.draw(gamee);
//					Gameover.draw(Score);
//					Gameover.display();
//				}
//			}
//			green.setPosition(360, 10);
//
//
//		}
//		else if (green.getPosition().y < 0) {
//			ystep = 6;
//			bordercrash.setVolume(110);
//			bordercrash.play();
//
//		}
//
//		else if ((green.getPosition().y >= 720 - 30 - green.getGlobalBounds().height) && (green.getPosition().x >= space.getPosition().x - green.getGlobalBounds().width / 2 && green.getPosition().x - 20 <= space.getPosition().x + space.getGlobalBounds().width - green.getGlobalBounds().width + 20 /*&& green.getPosition().x >= space.getPosition().x - green.getGlobalBounds().width*/))
//		{
//			cout << "collision with space " << endl;
//			sound.play();
//			ystep -= 6;
//			score += 10;
//			Score.setString("Your Score: " + to_string(score) + " Balls : " + to_string(balls));
//		}
//		green.move(xstep, ystep);
//
//		// Ball  Blue Moving  
//		if (blue.getPosition().x > 670) {
//			xstep -= 5;
//			bordercrash.setVolume(110);
//			bordercrash.play();
//		}
//		else if (blue.getPosition().x < 0) {
//			xstep = 7;
//			bordercrash.setVolume(110);
//			bordercrash.play();
//		}
//		else if (blue.getPosition().y > 680) {
//			balls--;
//			Score.setString("Your Score: " + to_string(score) + " Balls : " + to_string(balls));
//			if (balls <= 0) {
//				Score.setString("Game Over");
//
//				//			Game Over  
//				window.close();
//
//				if (score > highscoreint) {
//
//					ofstream fout("HighScore.txt");
//					fout << score << endl;
//					highscoreint = score;
//					fout.close();
//				}
//				music.stop();
//				gameOver.play();
//				int tmp = 1;
//
//				gOver.play();
//				Score.setString("Your Score: " + to_string(score) + " High Score is : " + to_string(highscoreint));
//
//				Score.setPosition(175, 600);
//				Score.setFillColor(Color::Cyan);
//				RenderWindow Gameover(VideoMode(720, 720), "Game Over");
//				Texture gamedone;
//				gamedone.loadFromFile("gameover.png");
//				Sprite  gamee(gamedone);
//
//
//
//				//gamee.scale(.5, .5);
//				while (Gameover.isOpen())
//				{
//					Event event;
//					while (Gameover.pollEvent(event))
//					{
//						if (event.type == Event::Closed)
//							Gameover.close();
//					}
//					Gameover.clear();
//					Gameover.draw(gamee);
//					Gameover.draw(Score);
//					Gameover.display();
//				}
//			}
//			blue.setPosition(300, 10);
//
//
//		}
//		else if (blue.getPosition().y < 0) {
//			ystep = 6;
//			bordercrash.setVolume(110);
//			bordercrash.play();
//
//		}
//
//
//		//Bouns ball when it hits 
//
//		else if ((blue.getPosition().y >= 720 - 30 - blue.getGlobalBounds().height) && (blue.getPosition().x >= blue.getPosition().x - blue.getGlobalBounds().width / 2 && blue.getPosition().x - 20 <= blue.getPosition().x + blue.getGlobalBounds().width - blue.getGlobalBounds().width + 20 /*&& green.getPosition().x >= space.getPosition().x - green.getGlobalBounds().width*/))
//		{
//			cout << "collision with space " << endl;
//			sound.play();
//			ystep -= 6;
//			score += 10;
//			Score.setString("Your Score: " + to_string(score) + " Balls : " + to_string(balls));
//		}
//		blue.move(xstep, ystep);
//
//
//
//
//		window.clear();
//		window.draw(background);
//		window.draw(space);
//		window.draw(green);
//		window.draw(Score);
//		window.display();
//	}
//
//
//
//	return 0;
//}