#include<iostream>
#include<string>
#include<ctime>
using namespace std;
string getSecretWord();
char playerGuess();
void update(string &guessedWord, string Key, char guess, int& badGuess,int &passGuess, string &listBadGuessed);
void Draw(int badGuess,int passGuess,int character,string guessedWord, string listBadGuessed);
string fakeGuess(int character);
int isContinus = 0;
//int badGuess = 0, passGuess = 0, character = 0;
//string listBadGuessed;
int main() {
	do {
		srand(time(NULL));
		int badGuess = 0, passGuess = 0, character = 0;
		string listBadGuessed;
		string Key = getSecretWord(); character = Key.size();
		string guessedWord = fakeGuess(character);
		do {
			Draw(badGuess, passGuess, character, guessedWord, listBadGuessed);
			char guess = playerGuess();
			update(guessedWord, Key, guess, badGuess, passGuess, listBadGuessed);
		} while (passGuess < character && badGuess < 7);
		Draw(badGuess, passGuess, character, guessedWord, listBadGuessed);
		cout << "Do you want to play again?\n (1)-Yes\t\t (0)-No\n";
		cin >> isContinus;
	} while (isContinus == 1);
	return 0;
}
string getSecretWord() {
	string WORD_LIST[] = {
 "angle", "ant", "apple", "arch", "arm", "army",
 "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry", "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
 "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
 "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
 "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
 "cow", "cup", "curtain", "cushion",
 "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
 "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
 "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut",
 "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
 "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
 "rail", "rat", "receipt", "ring", "rod", "roof", "root",
 "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
 "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
 "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
 "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
 "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
 "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
	};
	int pos = rand() % WORD_LIST->size();
	return WORD_LIST[pos];
}
char playerGuess() {
	char guess;
	cin >> guess;
	return guess;
}
void update(string& guessedWord, string Key, char guess, int& badGuess, int& passGuess,string& listBadGuessed) {
	bool isPassGuess = false;
	for (int i = 0; i < guessedWord.size(); i++) {
		if (Key[i] == guess) {
			isPassGuess = true;
			if (guessedWord[i] == '-') {
				guessedWord[i] = Key[i];
				passGuess++;
			}
		}
	}
	if (!isPassGuess) {
		badGuess++;
		listBadGuessed += guess;
	}
}
string fakeGuess(int character) {
	string fake;
	for (int i = 0; i < character; i++)fake += '-';
	return fake;
}
void Draw(int badGuess, int passGuess, int character, string guessedWord,string listBadGuessed) {
	char c = 92;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	switch (badGuess) {
	case 0: {
		cout << "  -------------\n  |\n  |\n  |\n  |\n  |\n-----\n\n"; break;
	}
	case 1: {
		cout << "  -------------\n  |           |\n  |\n  |\n  |\n  |\n-----\n\n"; break;
	}
	case 2: {
		cout << "  -------------\n  |           |\n  |           O\n  |\n  |\n  |\n-----\n\n"; break;
	}
	case 3: {
		cout << "  -------------\n  |           |\n  |           O\n  |          /\n  |\n  |\n-----\n\n"; break;
	}
	case 4: {
		cout << "  -------------\n  |           |\n  |           O\n  |          /|\n  |\n  |\n-----\n\n"; break;
	}
	case 5: {
		cout << "  -------------\n  |           |\n  |           O\n  |          /|" << c << "\n  |\n  |\n-----\n\n"; break;
	}
	case 6: {
		cout << "  -------------\n  |           |\n  |           O\n  |          /|" << c << "\n  |          /\n  |\n-----\n\n"; break;
	}
	case 7: {
		cout << "  -------------\n  |           |\n  |           O\n  |          /|" << c << "\n  |          / " << c << "\n  |\n-----\n\n"; break;
	}
	}
	cout << "Secret Word: " << guessedWord << endl;
	if (badGuess > 0 && passGuess != character) {
		cout << "You have " << badGuess << " bad guesses :" << listBadGuessed << endl;
	}
	if (badGuess < 7 && passGuess < character)cout << "Enter your Guess: ";
	if (badGuess == 7)cout << "Oops! You lose!\n";
	if (passGuess == character)cout << "Congratulations! You win!\n";
}