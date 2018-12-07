#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono>

void print_vector(std::vector <char> &input_vec);

bool play_again();

void clear_screen();

struct Hangman
{
	int strikes = 0;
	std::vector<std::string> hangman_words;
	std::string hidden_word;
	std::vector <char> letters_guessed;
	std::vector<int> idx_to_update;
	std::vector <char> hidden_word_vec;
	std::vector <char> display_word_vec;

	void generate_words();

	void pick_word(std::vector<std::string> &vec);

	void generate_display_word();

	void guess_letter();

	void check_guess();

	void update_display_word(std::vector <char> &vec);

	void picture();

	bool game_won();

};

