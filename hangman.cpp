// hangman.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <math.h>

class Hangman {
public:

	int strikes;
	std::string hidden_word;
	std::string letters_guessed;
	std::vector <char> hidden_word_vec;
	std::vector <char> display_word_vec;
	/////////////////////////////////////////
	
	std::vector <char> generate_word() {
		std::vector <std::string> wordbank = { "null", "wedges", "cakesniffer", "chinchilla", "hippo", "porpoise", "squirrels", "zap", "paste", "cocoa", "rhythm", "seaturtle", "cardinal", "fro", "bronze", "chrysanthemum", "zip" };
		
		auto start = std::chrono::steady_clock::now();
		std::cout << "Loading..." << std::endl;
		for (int i = 1; i < 2000; i++) {
			std::cout << std::endl;
		}  // make computer to do something so time would pass.

		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);

		double x = elapsed.count();
		while (x > wordbank.size() - 1) {
			x = x / (rand() % wordbank.size() + 1);
		}
		int y = round(x);

		hidden_word = wordbank[y];

		for (int i = 0; i < hidden_word.size(); i++) {
			hidden_word_vec.push_back(hidden_word[i]);
		}
		return hidden_word_vec;
	}

	std::vector <char> generate_display_word() {
		for (int i = 0; i < hidden_word.size(); i++) {
			display_word_vec.push_back('-');
		}
		return display_word_vec;
	}

	std::vector <char> guess_letter() {
		char guess;
		bool strike = true;
		std::cout << "Guess a letter: ";
		std::cin >> guess;
		for (int i = 0; i < hidden_word_vec.size(); i++) {
			if (guess == hidden_word_vec[i]) {
				display_word_vec[i] = guess;
				strike = false;
			}
		}
		if (strike == true) {
			strikes += 1;
			letters_guessed += guess;
		}
		return display_word_vec;
	}
	
	std::string print_vector(std::vector <char> input_vec) {
		std::string output = "";
		for (int i = 0; i < input_vec.size(); i++) {
			output += input_vec[i];
			output += " ";
		}
		std::cout << std::endl;
		std::cout << output << std::endl;
		return output;
	}

	void picture() {
		switch (strikes) {
		case 0:
			std::cout << "_____ " << std::endl;
			std::cout << "     |" << std::endl;
			std::cout << "     |" << std::endl;
			std::cout << "     |" << std::endl;
			std::cout << "     |" << std::endl;
			std::cout << "     |" << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < letters_guessed.size(); i++) {
				std::wcout << letters_guessed[i] << " ";
			}
			std::wcout << std::endl;
			break;
		case 1:
			std::cout << "_____" << std::endl;
			std::cout << "o    |" << std::endl;
			std::cout << "     |" << std::endl;
			std::cout << "     |" << std::endl;
			std::cout << "     |" << std::endl;
			std::cout << "     |" << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < letters_guessed.size(); i++) {
				std::wcout << letters_guessed[i] << " ";
			}
			std::wcout << std::endl;
			break;
		case 2:
			std::cout << "_____" << std::endl;
			std::cout << "o    |" << std::endl;
			std::cout << "|    |" << std::endl;
			std::cout << "|    |" << std::endl;
			std::cout << "     |" << std::endl;
			std::cout << "     |" << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < letters_guessed.size(); i++) {
				std::wcout << letters_guessed[i] << " ";
			}
			std::wcout << std::endl;
			break;
		case 3:
			std::cout << " _____" << std::endl;
			std::cout << " o    |" << std::endl;
			std::cout << "{|    |" << std::endl;
			std::cout << " |    |" << std::endl;
			std::cout << "      |" << std::endl;
			std::cout << "      |" << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < letters_guessed.size(); i++) {
				std::wcout << letters_guessed[i] << " ";
			}
			std::wcout << std::endl;
			break;
		case 4:
			std::cout << " _____ " << std::endl;
			std::cout << " o    |" << std::endl;
			std::cout << "{|}   |" << std::endl;
			std::cout << " |    |" << std::endl;
			std::cout << "      |" << std::endl;
			std::cout << "      |" << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < letters_guessed.size(); i++) {
				std::wcout << letters_guessed[i] << " ";
			}
			std::wcout << std::endl;
			break;
		case 5:
			std::cout << " _____ " << std::endl;
			std::cout << " o    |" << std::endl;
			std::cout << "{|}   |" << std::endl;
			std::cout << " |    |" << std::endl;
			std::cout << " /    |" << std::endl;
			std::cout << "      |" << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < letters_guessed.size(); i++) {
				std::wcout << letters_guessed[i] << " ";
			}
			std::wcout << std::endl;
			break;
		case 6:
			std::cout << " _____ " << std::endl;
			std::cout << " o    |" << std::endl;
			std::cout << "{|}   |" << std::endl;
			std::cout << " |    |" << std::endl;
			std::cout << "/ \\   |" << std::endl;
			std::cout << "      |" << std::endl;
			std::cout << std::endl;
			std::cout << "GAME OVER. The word was " << '\'' << hidden_word << '\'' << ". " << std::endl;
			std::cout << std::endl;
			break;
		}
	}

	
};

int main() {
	bool play_game = true;
	while (play_game == true) {
		Hangman game1;
		game1.strikes = 0;
		game1.generate_word();
		game1.print_vector(game1.generate_display_word());
		game1.picture();
		
		while (game1.strikes < 6) {
			game1.print_vector(game1.guess_letter());
			game1.picture();
			if (game1.hidden_word_vec == game1.display_word_vec) {
				std::wcout << std::endl;
				std::cout << "You win." << std::endl;
				std::wcout << std::endl;
				break;
			}
		}
		char YorNo;
		std::wcout << std::endl;
		std::wcout << "Want to play again? [Y/N]";
		std::cin >> YorNo;
		char YorNo_normalized = toupper(YorNo);
		if (YorNo_normalized == 'N') {
			std::wcout << std::endl;
			std::cout << "Thanks for playing." << std::endl;
			std::wcout << std::endl;
			play_game = false;
		}
	

	}
	return 0;
}
