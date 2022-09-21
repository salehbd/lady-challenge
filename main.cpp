// LadyChallengeYou.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#undef WIN32_LEAN_AND_MEAN
#include <iostream>
#include <array>
#include <Windows.h>

using std::cout;
using std::endl;

// answer enumeration
enum answer { a, b, c };

//user score (number of question correct)
int score = 0;

//number of challenge
const int CHALLENGES_NUM = 10;

//player's name
std::string playerName;

// player's diaologue
std::string playerSay;

//lady name
std::string lady = "\033[95mLady:\033[0m ";

// numberArt for printing score
std::string numberArt[12][5];

//my name
std::string me = "\033[96mMuhammad: \033[0m";

// this block fills number art array
void fillNumberArt()
{
	// zero
	numberArt[0][0] = "  _/_/  ";
	numberArt[0][1] = "_/  _/_/";
	numberArt[0][2] = "_/_/_/_/";
	numberArt[0][3] = "_/_/  _/";
	numberArt[0][4] = "  _/_/  ";

	// one
	numberArt[1][0] = "  _/";
	numberArt[1][1] = "_/_/";
	numberArt[1][2] = "  _/";
	numberArt[1][3] = "  _/";
	numberArt[1][4] = "  _/";

	// two
	numberArt[2][0] = "_/_/_/  ";
	numberArt[2][1] = "      _/";
	numberArt[2][2] = "  _/_/  ";
	numberArt[2][3] = "_/      ";
	numberArt[2][4] = "_/_/_/_/";

	// three
	numberArt[3][0] = "_/_/_/  ";
	numberArt[3][1] = "      _/";
	numberArt[3][2] = "  /_/   ";
	numberArt[3][3] = "      _/";
	numberArt[3][4] = "_/_/_/  ";

	// four
	numberArt[4][0] = "    _/  ";
	numberArt[4][1] = "  _/    ";
	numberArt[4][2] = "_/    _/";
	numberArt[4][3] = "_/_/_/_/";
	numberArt[4][4] = "      _/";

	// five
	numberArt[5][0] = "_/_/_/_/";
	numberArt[5][1] = "_/      ";
	numberArt[5][2] = "_/_/_/_/";
	numberArt[5][3] = "      _/";
	numberArt[5][4] = "_/_/_/  ";

	// six
	numberArt[6][0] = "  _/_/_/";
	numberArt[6][1] = "_/      ";
	numberArt[6][2] = "_/_/_/_/";
	numberArt[6][3] = "_/    _/";
	numberArt[6][4] = "  _/_/  ";

	// seven
	numberArt[7][0] = "_/_/_/_/";
	numberArt[7][1] = "      _/";
	numberArt[7][2] = "    _/  ";
	numberArt[7][3] = "   _/   ";
	numberArt[7][4] = "   _/   ";

	// eight
	numberArt[8][0] = "  _/_/  ";
	numberArt[8][1] = "_/    _/";
	numberArt[8][2] = "  _/_/  ";
	numberArt[8][3] = "_/    _/";
	numberArt[8][4] = "_/_/_/_/";

	// nine
	numberArt[9][0] = "_/_/_/_/";
	numberArt[9][1] = "_/    _/";
	numberArt[9][2] = "  _/_/_/";
	numberArt[9][3] = "      _/";
	numberArt[9][4] = "_/_/_/  ";

	// ten
	numberArt[10][0] = "  _/   _/_/  ";
	numberArt[10][1] = "_/_/ _/  _/_/";
	numberArt[10][2] = "  _/ _/_/_/_/";
	numberArt[10][3] = "  _/ _/_/  _/";
	numberArt[10][4] = "  _/   _/_/  ";

	// template
	numberArt[11][0] = "    ";
	numberArt[11][1] = "   ";
	numberArt[11][2] = "  ";
	numberArt[11][3] = " ";
	numberArt[11][4] = "";
}
// available functions

//
void start();
// intro to challenge
void intro();
// ask user to press any key
void prompt();
void prompt1();
// closing of challenge
void closing();
// print current user score
void prtScore();
// print user final score
void prtFinalScore();
// finish the challenge
void finish();
// challenge quizes
void challenge();
// love from me
void loveLetter();
// play sound
void play(std::string sound)
{
	// PlaySound(TEXT(sound), NULL, SND_FILENAME);
}

// challenge class definition;
class Challenge;

class Challenge
{
public:
	enum answer correctAnswer;

	std::string question;
	std::string answerChoices[3];
	std::string explanation;

	// print answer choices
	void printAnswers()
	{
		for (char i = 'a'; i <= 'c'; i++)
		{
			std::cout << i << ". " << answerChoices[i - 'a'] << std::endl;
		}
	}

	// print challenge question
	void ask()
	{
		std::cout << question << std::endl;
	}

	// print challenge answer's explanation
	void explain()
	{
		if(explanation.length() > 0)
			std::cout << "Penjelasan: " << explanation << std::endl;
	}

	// return true if user answer is correct
	bool check(char c)
	{
		return c - 'a' == correctAnswer;
	}

	// print correct answer
	void printCorrectAnswer()
	{
		std::cout << "Jawaban yang benar: " << answerChoices[correctAnswer] << std::endl;
	}

	// prompt answer from player and check them
	void getAnswer()
	{
		char ans;

		//prompt answer from player
		std::cin >> ans;

		//if the answer correct
		if (check(ans))
		{
			// play a success sound
			PlaySound(TEXT("success.wav"), NULL, SND_FILENAME);
			std::cout << lady << "Meoww! Kamu benar!" << std::endl;
			score++; // one more question correct
		}
		else
		{
			// play a fail sound
			PlaySound(TEXT("fail2.wav"), NULL, SND_FILENAME);

			std::cout << lady << "Miyu... Kamu salah..." << std::endl;
			printCorrectAnswer();
		}
	}
};

// challenge class instantiation
Challenge gameChallenges[CHALLENGES_NUM];

//start menu
void start()
{
	// clear the screen first
	system("cls");

	// print intro title
	intro();
	std::cout << "Welcome To Lady Challenges You in Mother's Day!" << std::endl;
	
	std::cout << "mohon masukkan namamu" << std::endl;
	
	std::cin >> playerName;

	playerSay = "\033[93m" + playerName + ": \033[0m";
	
	std::cout << lady << "Haiii " << playerName << ", aku Lady! Selamat datang di tantangan! Meoww... aku adalah kucing Keluarga Rinjani. Hehehe..." << endl;
	PlaySound(TEXT("intro.lady.1.wav"), NULL, SND_FILENAME);
	prompt1();
	std::cout << playerSay << "haii, eh.. kucing kok bisa ngomong ?"  << endl;
	PlaySound(TEXT("intro.player.1.wav"), NULL, SND_FILENAME);
	prompt1();
	std::cout << lady << "eh, iya juga ya... gini deh, aku jelasin gimana ceritanya. Jadi aku tuh dari dulu pingin bisa ngomong. Aku pingin menyampaikan rasa terimakasihku kepada Keluarga Rinjani 10 karena telah merawatku. Khususnya kepada Umi, yang udah seperti ibuku. Lady tiap malem doa terus... minta di kasi kesempatan ngomong, walaupun sehari aja. Terus, saat malam sebelum Hari Ibu tahun ini, doa Lady terkabul! Lady seneng banget! Tapi Lady tahu kalo ini kesempatannya cuma sehari, jadi Lady cari cara untuk menyelesaikan keinginan Lady untuk menyampaikan terima kasih. Gak lama kemudian, Muhammad kebangun. Muhammad ngeliat jendela kamar lady. Lady berusaha ngomong, walau kurang jelas(maklum, hari pertama bisa bicara...). Untung Muhammad denger, walau pertama dia ngira dirinya lagi mimpi. Kita pun merencanakan untuk membuat permainan ini untuk merayakan Hari Ibu. Gitu deh ceritanya." << endl;
	PlaySound(TEXT("intro.lady.2.wav"), NULL, SND_FILENAME);
	prompt1();
	std::cout << playerSay << "hooh, begitu to...  terus permainannya seperti apa?" << endl;
	PlaySound(TEXT("intro.player.2.wav"), NULL, SND_FILENAME);
	prompt1();
	std::cout << lady << "Meoww, Nanti, kamu akan diberikan " << CHALLENGES_NUM << " pertanyaan tentang Umi, yang akan menguji seberapa kamu mengenalnya. setiap pertanyaan yang benar bernilai 100 skor. Meoww, ini memang momen yang pas untuk melakukannya :)" << endl;
	PlaySound(TEXT("intro.lady.3.wav"), NULL, SND_FILENAME);
	prompt1();
	std::cout << lady << "Meoww, Ayo kita mulai permainannya. Semoga kamu dapat menjawab semuanya!" << endl;
	PlaySound(TEXT("intro.lady.4.wav"), NULL, SND_FILENAME);
	prompt1();

	// clear the screen
	system("cls");
}

// this prompt user in order to stop the program
void prompt()
{
	std::cout << "Press enter to continue..." << std::endl;

	std::cin.ignore(256, '\n');
	std::cin.ignore(256, '\n');

	// cout << "\r\r\r";
}

void prompt1()
{
	std::cout << "Press enter to continue..." << std::endl;

	std::cin.ignore(256, '\n');

	// cout << "\r\r\r";
}

// finish
void finish()
{
	// prints intro title
	intro();

	std::cout << lady << "permainan selesai. \033[91mMeoww, Selamat hari Ibu!\033[0m" << std::endl;
	prtFinalScore();

}

// prints current player's score plainly
void prtScore()
{
	std::cout << "\033[93mYour score is \033[92m" << score * 100 << "\033[0m!" << std::endl;
}

// introduction of game
void intro()
{
	// play intro sound
	PlaySound(TEXT("intro.wav"), NULL, SND_FILENAME);

	std::string title[7];
	// this contains title for the game
	title[0] = "|                                                                                                                      |\n";
	title[1] = "|     _/       _/_/_/_/ _/_/_/   _/     _/_/   _/    _/    _/_/_/ _/       _/       _/_/_/_/ _/    _/   _/_/_/ _/_/_/_/|\n";
	title[2] = "|    _/       _/       _/    _/ _/   _/    _/ _/    _/  _/    _/ _/       _/       _/       _/_/  _/ _/       _/       |\n";
	title[3] = "|   _/       _/_/_/_/ _/    _/ _/   _/       _/_/_/_/  _/    _/ _/       _/       _/_/_/_/ _/  _/_/ _/  _/_/ _/_/_/_/  |\n";
	title[4] = "|  _/       _/       _/    _/ _/   _/    _/ _/    _/  _/_/_/_/ _/       _/       _/       _/    _/ _/    _/ _/         |\n";
	title[5] = "| _/_/_/_/ _/_/_/_/ _/_/_/   _/     _/_/   _/    _/  _/    _/ _/_/_/_/ _/_/_/_/ _/_/_/_/ _/    _/   _/_/   _/_/_/_/    |\n";
	title[6] = "|                                                                                                                      |\n";

	std::cout << "\033[1;31;44m";

	for (int i = 0; i < 7; i++)
		std::cout << title[i];
	
	std::cout << "\033[0m";

}

// this is the main game. challenge the player with several questions
void challenge()
{
	for (int i = 0; i < CHALLENGES_NUM; i++)
	{
		// prints intro title
		intro();

		//print challenge number
		std::cout << "\033[91mChallenge \033[92m#" << i + 1 << "\033[0m" << std::endl;
		// print question
		gameChallenges[i].ask();
		// print answer
		gameChallenges[i].printAnswers();
		// get answer and check them
		gameChallenges[i].getAnswer();
		// print explanation
		gameChallenges[i].explain();
		// print current user score
		prtScore();
		
		// wait player to continue
		prompt();

		PlaySound(TEXT("next3.wav"), NULL, SND_FILENAME);
		// clear the screen
		system("cls");
	}
}

void prtFinalScore()
{
	PlaySound(TEXT("scoring.wav"), NULL, SND_FILENAME);

	std::cout << "\033[91mPlayer:\033[93m " << playerName << "\033[0m" << endl;

	std::cout << "Your final score is: \033[92m" << score * 100 << "\033[0m out of " << CHALLENGES_NUM * 100 << std::endl;

	std::cout << "\033[32m" << endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "   " << numberArt[11][i] << numberArt[score][i] << " " << numberArt[0][i] << " " << numberArt[0][i] << "   " << std::endl;
	}
	std::cout << "\033[0m" << endl;

}

void check()
{
	prtFinalScore();
	
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		score++;
		
		prtFinalScore();
		
		std::cout << std::endl;
	}
}

// the main dish, my message
void loveLetter()
{
	prompt1();
	PlaySound(TEXT("bonus1.wav"), NULL, SND_FILENAME);
	cout << lady << "oh tunggu, hampir aja lupa... ada pesan dari muhammad." << endl;
	PlaySound(TEXT("message.lady.0.wav"), NULL, SND_FILENAME);
	cout << "\033[32mloading...\033[0m" << endl;
	prompt1();
	PlaySound(TEXT("bonus2.wav"), NULL, SND_FILENAME);
	cout << me << "Selamat hari Ibu Umi! Umi itu perempuan paling hebat di dunia. Terima kasih ya, telah sabar menemaniku selama 17 tahun. Semoga Umi suka hadiahnya. Muhammad sayang Umi : )" << endl;
	PlaySound(TEXT("message.muhammad.1.wav"), NULL, SND_FILENAME);
	prompt1();
	cout << lady << "Iya, Lady juga sayang sama Umi. Umi udah nyelamatin Lady dulu saat Lady masih keciiil.. masih inget dulu, ujan-ujan Lady sebatang kara. Merasa takut, kedinginan, dan kelaparan. Terus lady masuk ke sebuah rumah. Ada Umi dan Abi disitu. Umi bawa lady pulang. Lady dirawat dengan penuh ketulusan selama 6 tahun. Kalo Lady kesel dikerjain sama yang lain, Umi selalu ngerti kalo Lady lagi ga mau main. Makanya Lady suka pingin banget ada di kamar Umi terus. Umi adalah Ibunya Lady. Selamat hari ibu Umi! Akhirnya Lady bisa menyelesaikan keinginan Lady.. /\\. ./\\" << endl;
	PlaySound(TEXT("message.lady.1.wav"), NULL, SND_FILENAME);
	prompt1();
	cout << me << " Ini Muhammad sama Lady berdua yang bikin hadiahnya. Muhammad yang bikin quiznya Lady yang jadi hostnya. Lady juga mencurahkan inspirasi kepadaku dengan tatapannya yang imut itu. Good girl Lady! Misi Berhasil!" << endl;
	PlaySound(TEXT("message.muhammad.2.wav"), NULL, SND_FILENAME);
	prompt1();
	cout << lady << "Baguslah. Mission Complete! Dan Lady akan kembali menjadi kucing biasa lagi, Sampai Jumpa!" << endl;
	PlaySound(TEXT("message.lady.2.wav"), NULL, SND_FILENAME);
	cout << "\033[96m------------THE END------------\033[0m" << endl;
	prompt1();
}	


int main()
{
	// filling number art
	fillNumberArt();

	// filling of the challenges;
	std::string questions[CHALLENGES_NUM] = 
	{	
		"Kemanakah Umi pergi SD?", 
		"Siapakah dibawah ini yang merupakan guru TK Umi?", 
		"Kemanakah Umi pergi SMP", 
		"Dimana Umi SMA?", 
		"Di Rumah Sakit manakah Umi lahir?" , 
		"Nama sahabat Umi yang rumahnya di depan TKP kecelakaan Umi saat mahasiswa: ", 
		"Umi adalah angkatan Fakultas Kedokteran Universitas Airlangga tahun: ", 
		"Manakah yang merupakan restoran favorit Umi:", 
		"Siapa ART yang mengasuh Umi?", 
		"Kejadian lucu berikut ini yang pernah menimpa Umi adalah:"
	};
	
	// answer choices of each questions
	std::string answers[CHALLENGES_NUM][3] =
	{
		{"SD Perak Barat","SD Mulyorejo","SDN Morokrembangan 3"},
		{"Bu Ina","Bu Ana","Bu Yanti"},
		{"SMP Unesa 1","SMP Hang Tuah 4","SMP 7 Surabaya"},
		{"SMA 7 Surabaya","SMA 6 Surabaya","SMA 5 Surabaya"},
		{"Rumah Sakit PKU Muhammadiyah Surabaya","Rumah Sakit al-Irsyad Surabaya","RSUD Muhammad Soewandie"},
		{"Putu", "Calcarina", "Elia"},
		{"86", "87", "88"},
		{"Warung Soto Ayam Ambengan Pak Sadi Asli", "Bon Cafe", "Zangrandi"},
		{"Mbak Ti", "Mak Sarina", "Mbak Radini"},
		{"Masuk FK dengan sepatu bola dan gelang banyak sampai siku.", "Lupa nama dosen anatomi.", "Salah masuk gedung saat pertama kali masuk FK."}
	};

	enum answer correctAnswers[CHALLENGES_NUM] = { c, a, c, b, a, a, b, b, c, a};
	std::string explanations[CHALLENGES_NUM] = 
	{ 
		"SD Morokrembangan adalah tempat Umi menghabiskan masa SD. Alamatnya terletak di Jalan Gadukan Utara.",
		"Bu Ina adalah guru TK yang mengajarkan anak-anak Abeb Soleh. Beliau dikenal sangat sabar. Gedung TK-nya ada di Jalan Jakarta Barat, tapi sekarang sudah tidak ada lagi.",
		"SMP 7 adalah SMP Umi dan saudara-saudara kandungnya, serta banyak keluarga Umi lainnya, termasuk Ati Firdaus.",
		"SMA 6 terletak di Kawasan Elit Tunjungan. SMA ini adalah almamater dari Umi, Ati Firdaus, Ati Jufriah, Saudara kandung Umi, serta banyak keluarga Umi lainnya termasuk Nadira.",
		"RS PKU Muhammadiyah dulunya adalah sebuah rumah persalinan. Selain itu, rumah sakit ini sekarang juga merupakan salah satu tempat praktek Dr. Soraya.",
		"Ibu Putu adalah sahabat umi yang tinggal di Jalan Perak Timur. Kini beliau merupakan seorang dokter anestesi di Lampung.",
		"",
		"Bon Cafe merupakan restoran favorit Abeb Soleh sekeluarga, termasuk umi. Salah satu menu unggulannya adalah steak.",
		"Mak Ni dan Mak Na adalah adik-kakak asal lamongan yang lama bekerja sebagai pembantu keluarga abeb Soleh. Mak Ni merupakan pembantu yang mengasuh Umi. Sangat disayangkan, kini keduanya telah meninggal dunia.",
		"Umi pernah masuk FK dengan memakai gelang banyak sampai siku dan sepatu bola. Konon,  temen-temen dan guru-gurunya sampai ketawa geli saat melihatnya. FYI, saat SMA umi gemar mengoleksi gelang.",
	};

	// inserting value above to class
	for (int i = 0; i < CHALLENGES_NUM; i++)
	{
		// the question
		gameChallenges[i].question = questions[i];

		// answer choices
		for (int j = 0; j < 3; j++)
		{
			gameChallenges[i].answerChoices[j] = answers[i][j];
		}

		// correct answer 
		gameChallenges[i].correctAnswer = correctAnswers[i];

		// explanation to the answer
		gameChallenges[i].explanation = explanations[i];
	}
	
	// main program
	start();
	challenge();
	finish();
	loveLetter();	
	
	//PlaySound(TEXT("bonus2.wav"), NULL, SND_FILENAME);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

