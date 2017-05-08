/*
 * word.cpp
 *
 *  Created on: May 4, 2017
 *      Author: Selth Afrinon
 */

#include "word.h"

// initializes the word.
word::word(std::string in){
	numb_words = 1;				// all are initialized to 1 because the word has one use when it is found.
	numb_songs = 1;
	on_song = true;
	cont_word = in;
}

// increments the word count.
void word::inc_word(){
	numb_words++;
}

// increments the song count.
void word::inc_song(){
	numb_songs++;
}

// returns the string of the word.
std::string word::get_word(){
	return cont_word;
}

// changes the song stat of the word to the input.
void word::change_song_stat(bool in){
	on_song = in;
}

// returns the song stat.
bool word::get_song_stat(){
	return on_song;
}

// returns the number of occurrences of the word.
int word::get_count(){
	return numb_words;
}

// returns the number of songs the word appears in.
int word::get_songs(){
	return numb_songs;
}
