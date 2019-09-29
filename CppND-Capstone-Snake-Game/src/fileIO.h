#ifndef FILE_H
#define FILE_H

using namespace std;

class FileIO{
    public :
        FileIO(string filePath);
		~FileIO();
	    int getMaxScore() const;
		void setMaxScore(int score);

    private :
    string _filePath;
    int _maxScore;
};

#endif