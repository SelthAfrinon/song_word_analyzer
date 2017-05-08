/*
 * word.h
 *
 *  Created on: May 4, 2017
 *      Author: Selth Afrinon
 */

#ifndef WORD_H_
#define WORD_H_

#include <string> 	// for std::string.

class word{
private:
	int numb_words, numb_songs;
	bool on_song;
	std::string cont_word;
public:
	word(std::string);
	void inc_word();
	void inc_song();
	std::string get_word();
	void change_song_stat(bool);
	bool get_song_stat();
	int get_count();
	int get_songs();
	~word() {}
};



#endif /* WORD_H_ */
