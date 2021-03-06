#include "stdafx.h"
#include "hangman_header.h"

int main() {
	do
	{
		clear_screen();

		Hangman game1;

		game1.generate_words();
		game1.pick_word(game1.hangman_words);
		game1.generate_display_word();

		game1.picture();
		print_vector(game1.display_word_vec);

		while (game1.strikes < 6 && game1.game_won() == false)
		{
			game1.guess_letter();
			game1.check_guess();
			clear_screen();
			game1.update_display_word(game1.display_word_vec);
			game1.picture();
			std::cout << "\nLetters guessed: ";
			print_vector(game1.letters_guessed);
			std::cout << "\n\n";
			print_vector(game1.display_word_vec);
			game1.game_won();
		}

		if (game1.strikes == 6)
		{
			std::cout << "\nGame over. The word was " << '\'' << game1.hidden_word << '\'' << "\n";
		}

		else
		{
			std::cout << "\nGood job you won.\n";
		}

	} while (play_again() == true);
}