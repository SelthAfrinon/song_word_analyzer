Program: Song Word Analyzer
Author: Martin Rivera
Date: 2017-05-08
Readme Last Revised: 2017-05-15
Project Status: Finished

Description: Song Word Analyzer takes a list of songs and the lyrics of those songs and counts every occurrance of the words in the songs.

Inputs: -l <list_name> -p <output_file_name>

Outputs: Program can print the results to the screen or print to an output file.

Process: Song Word Analyzer reads the song file names from the indicated list, then reads lines in from the song files. The program deliminates based on spaces. For each new word it creates a new class "word" and stores the information of the word in the class. For each new song, the "song_stat" variable in each word is reset until the word appears in the song. This keeps the song counter from being increased on subsequent appearences in a single song. After each song has been analyzed, the program prints the results to the screen or the indicated file.