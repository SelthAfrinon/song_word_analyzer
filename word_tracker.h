/*
 * word_tracker.h
 *
 *  Created on: May 4, 2017
 *      Author: Selth Afrinon
 */

#ifndef WORD_TRACKER_H_
#define WORD_TRACKER_H_

#include <vector>		// for std::vector
#include <algorithm>	// for std::transform
#include <stdio.h>		// for std::sprintf
#include "word.h"

class word_tracker{
private:
	std::vector<word*> words;
	void add_word(std::string);
public:
	word_tracker();
	void inc_word(std::string);
	void new_song();
	int get_num_words();
	std::string print_content();
	~word_tracker() {}
};

#endif /* WORD_TRACKER_H_ */
