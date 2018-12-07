#include "stdafx.h"
#include "hangman_header.h"

void print_vector(std::vector<char> &input_vec)
{
	for (auto elem : input_vec)
	{
		std::cout << elem << " ";
	}
	std::cout << "\n";
}

bool play_again()
{
	char YorNo;
	std::cout << "\nWant to play again? [Y/N]";
	std::cin >> YorNo;
	char YorNo_normalized = toupper(YorNo);
	if (YorNo_normalized == 'N') {
		std::cout << "\nThanks for playing.\n";
		return false;
	}
	else 
	{
		return true;
	}
}

void clear_screen()
{
	std::cout << std::string(20, '\n');
}

void Hangman::generate_words() 
{
	std::ifstream theFile("hangman_words.txt");

	std::string word;

	while (theFile >> word)
	{
		hangman_words.push_back(word);
	}
}

void Hangman::pick_word(std::vector<std::string> &vec) 
{
	unsigned ms = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(vec.begin(), vec.end(), std::default_random_engine(ms));
	
	hidden_word = vec[0];
}

void Hangman::generate_display_word()
{
	for (int i = 0; i < hidden_word.size(); i++) 
		{
			display_word_vec.push_back('-');
		}	
}

void Hangman::guess_letter()
{
	char guess;
	bool strike = true;
	std::cout << "Guess a letter: ";
	std::cin >> guess;
	letters_guessed.push_back(guess);
}

void Hangman::check_guess()
{
	idx_to_update.clear();
	bool strike = true;
	for (int i = 0; i < hidden_word.size(); i++)
	{
		if (letters_guessed.back() == hidden_word[i])
		{
			strike = false;
			idx_to_update.push_back(i);
		}
	}

	if (strike == true)
	{
		strikes += 1;
	}
}

void Hangman::update_display_word(std::vector <char> &vec)
{
	for (auto idx : idx_to_update)
	{
		vec[idx] = hidden_word[idx];
	}
}

void Hangman::picture()
{
	switch (strikes) {
	case 0:
		std::cout << "_____ " << std::endl;
		std::cout << "     |" << std::endl;
		std::cout << "     |" << std::endl;
		std::cout << "     |" << std::endl;
		std::cout << "     |" << std::endl;
		std::cout << "     |" << std::endl;
		std::cout << "\n\n";
		break;
	case 1:
		std::cout << "_____" << std::endl;
		std::cout << "o    |" << std::endl;
		std::cout << "     |" << std::endl;
		std::cout << "     |" << std::endl;
		std::cout << "     |" << std::endl;
		std::cout << "     |" << std::endl;
		std::cout << "\n\n";
		break;
	case 2:
		std::cout << "_____" << std::endl;
		std::cout << "o    |" << std::endl;
		std::cout << "|    |" << std::endl;
		std::cout << "|    |" << std::endl;
		std::cout << "     |" << std::endl;
		std::cout << "     |" << std::endl;
		std::cout << "\n\n";
		break;
	case 3:
		std::cout << " _____" << std::endl;
		std::cout << " o    |" << std::endl;
		std::cout << "{|    |" << std::endl;
		std::cout << " |    |" << std::endl;
		std::cout << "      |" << std::endl;
		std::cout << "      |" << std::endl;
		std::cout << "\n\n";
		break;
	case 4:
		std::cout << " _____ " << std::endl;
		std::cout << " o    |" << std::endl;
		std::cout << "{|}   |" << std::endl;
		std::cout << " |    |" << std::endl;
		std::cout << "      |" << std::endl;
		std::cout << "      |" << std::endl;
		std::cout << "\n\n";
		break;
	case 5:
		std::cout << " _____ " << std::endl;
		std::cout << " o    |" << std::endl;
		std::cout << "{|}   |" << std::endl;
		std::cout << " |    |" << std::endl;
		std::cout << " /    |" << std::endl;
		std::cout << "      |" << std::endl;
		std::cout << "\n\n";
		break;
	case 6:
		std::cout << " _____ " << std::endl;
		std::cout << " o    |" << std::endl;
		std::cout << "{|}   |" << std::endl;
		std::cout << " |    |" << std::endl;
		std::cout << "/ \\   |" << std::endl;
		std::cout << "      |" << std::endl;
		std::cout << "\n\n";
	}
}

bool Hangman::game_won()
{
	for (auto elem : display_word_vec)
	{
		if (elem == '-')
		{
			return false;
		}
	}
	return true;
}