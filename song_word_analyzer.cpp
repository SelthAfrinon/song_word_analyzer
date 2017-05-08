//============================================================================
// Name        : word_counter.cpp
// Author      : Selth Afrinon
// Date Start  : 2017-05-04
// Date End	   : 2017-05-06
// Version     : 1
// Copyright   : 
// Description : Takes two types of files: one is a text document of song lyrics, the other is a text document with the names of the song lyric files.
//					Word_counter reads the songs from the list document, then counts the occurrences of each word in the song. These occurrences are tracked
//					across all the songs in the list. At the end, the tally is output to the screen.
//============================================================================

#include <iostream>			// for cout.
#include <fstream>			// for ifstream, ofstream.
#include <string>			// for string.
#include "word_tracker.h"

using namespace std;

int main(int argc, char *argv[]) {
	string list_name;
	ofstream out_file;
	for(int i = 0; i < argc; i++){
		if(string(argv[i]) == "-p"){				// If user wants results printed to a file, gets output file name
			out_file.open(string(argv[i+1]).c_str());
			if(!out_file.is_open()){
				cout << "Could not open \"" << string(argv[i+1]).c_str() << "\", aborting operation.\n";
				return 0;
			}
		}else if(string(argv[i]) == "-l"){			// Gets list name from -l argument
			list_name = string(argv[i+1]);
		}
	}
	word_tracker* tracker = new word_tracker(); 	// Creates new song tracker for session
	ifstream list(list_name.c_str());				// Opens specified list file
	if(list.is_open()){								// Checks for list's existence
		while(!list.eof()){
			string song_name;
			getline(list,song_name);				// Gets song file names from list
			ifstream song(song_name.c_str());
			if(song.is_open()){						// Checks if song exists
				string verse;
				while(!song.eof()){
					getline(song,verse);			// Gets song verse
					int search_begin = 0, search_end = 0;
					while(search_end != -1){															// checks for end of verse
						search_end = verse.find(" ", search_begin);										// find next space, which delimits words
						if((search_begin != 0) || (search_end != -1)){									// check for empty lines
							tracker->inc_word(verse.substr(search_begin,search_end - search_begin));	// adds new word/ increments existing words
						}
						search_begin = search_end + 1;													// sets search for next word
					}
				}
			}else{									// If song does not exist, print message to screen
				cout << "No song \"" << song_name << "\" available.\n";
			}										// end song
			song.close();							// close song file
			tracker->new_song();					// reset tracker contents to recognize new song
		}
		list.close();

		if(out_file.is_open()){								// prints to file if user specified -p.
			out_file << tracker->print_content().c_str();
			out_file.close();
		}else{										// If user did not specify output file, prints contents of tracker after all songs have been analyzed
			cout << tracker->print_content();
		}
		}else{											// If list does not exist, print message to screen
		cout << "No list \"" << list_name << "\" available. Aborting operation.\n";
	} 												// end list
	return 0;
}
