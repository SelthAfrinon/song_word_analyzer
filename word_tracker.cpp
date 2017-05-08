/*
 * word_tracker.cpp
 *
 *  Created on: May 4, 2017
 *      Author: Selth Afrinon
 */

#include "word_tracker.h"

word_tracker::word_tracker():words(0){
	// initializes "words" vector to size 0.
}

// for adding new word to "words" vector.
void word_tracker::add_word(std::string in){
	words.push_back(new word(in));
}

// increments a word's counter. Adds new word if indicated word does not exist.
//	increments song count counter if first instance of the word in the song.
void word_tracker::inc_word(std::string in){
	word* check_word;
	std::transform(in.begin(), in.end(), in.begin(), ::tolower);	// makes every letter lower case.
	for(int i = 0; i <= (int)words.size(); i++){					// iterates through words vector.
		if(i == (int)words.size()){									// checks if the index has reached the end of the vector.
			add_word(in);											// if the index reaches the end of the vector, adds new word to vector.
			break;													// exits loop.
		}
		check_word = words.at(i);									// gets word to check
		if(check_word->get_word() == in){							// checks if the word is in the vector
			check_word->inc_word();									// if it finds the word, increments its count.
			if(check_word->get_song_stat() == false){				// checks if the word has been in the song before
				check_word->inc_song();								// if the word has not been in the song, increases the word's song counter
				check_word->change_song_stat(true);					// indicates that the word has been in the current song before.
			}
			break;
		}
	}
}

// indicates to the words that the word_tracker has started a new song.
void word_tracker::new_song(){
	for(int i = 0; i < (int)words.size(); i++){
		words.at(i)->change_song_stat(false);							// sets each word's song_stat to false.
	}
}

// returns the number of words in the "words" vector.
int word_tracker::get_num_words(){
	return (int)words.size();
}

// returns a formated string with the contents of the "words" vector.
std::string word_tracker::print_content(){
	word* tmp;
	char buffer[50];													// buffer for sprintf's output.
	std::string output = "Contents of songs: \nWord \t\tNum Occurrences\t\tNum songs appeared in\n";
	for(int i = 0; i < (int)words.size(); i++){
		tmp = words.at(i);
		sprintf(buffer,"\t\t%d\t\t\t%d \n", tmp->get_count(), tmp->get_songs());	// converts the integer values to strings.
		output = output + tmp->get_word() + buffer;
	}
	return output;
}
