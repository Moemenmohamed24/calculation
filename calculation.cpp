#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
int RandomNumber(int from, int to)
{
	int randNum = rand() % (to - from + 1) + from;
	return randNum;

}
enum finalreslt { pass = 1, faile = 2 };
enum levels { easy = 1, mid = 2, hard = 3, mixerr = 4 };
enum opretation { add = 1, sub = 2, mul = 3, dive = 4, mixer = 5 };

string getoptypesymbol(opretation optype)
{
	switch (optype)
	{
	case opretation::add:
		return "+";

	case opretation::sub:
		return "-";

	case opretation::mul:
		return "*";

	case opretation::dive:
		return "/";
	default:
		return "mix";
	}
}


string getQuestionlevel(levels questionlevel)
{
	string arrquestiotext[4] = { " easy ", "mid", "hard", "mixerr" };
	return arrquestiotext[questionlevel - 1];
}


void setscreenColor(bool  rigth)
{
	if (rigth)
		system("color 2f");
	else
	{
		system("color 4f");
		cout << "\a";
	}

}

short readtheQuestion()
{
	int Question;
	cout << "how mony Question do you want answer ?\n";
	cin >> Question;

	return Question;

}

levels ReadQuestionlevels()
{

	short questionlevels = 0;
	do
	{
		cout << "enter the level [1] easy , [2] med , [3] hared , [4] mix ? ";
		cin >> questionlevels;
	} while (questionlevels < 1 || questionlevels > 4);

	return levels(questionlevels);
}

opretation Readoptype()
{

	short optype;
	cout << "enter the operation [1] add , [2] sub , [3] mul , [4] div , [5] mix  ?\n";
	cin >> optype;
	return opretation(optype);

}

struct stQuestion
{
	int number1 = 0;
	int number2 = 0;
	opretation operation;
	levels questinlevel;
	int correctanswer = 0;
	int playeranswer = 0;
	bool Answerreaslt = false;
};
struct stQuizz
{

	stQuestion Questionlist[100];
	short numberofquestion;
	levels levelgame;
	opretation op;
	int numberofwronganswer = 0;
	int numberofrigthanswer = 0;
	bool ispasse = false;
};

int simplecalculat(int num1, int num2, opretation op)
{

	switch (op)
	{
	case opretation::add:
		return num1 + num2;

	case opretation::sub:
		return num1 - num2;

	case opretation::mul:
		return num1 * num2;

	case opretation::dive:
		return num1 / num2;

	default:
		return num1 + num2;
	}
}
opretation Getrandomoperationtype()
{
	int op = RandomNumber(1, 4);
	return (opretation)op;


}

int readthemonyQuestion()
{
	int Question;
	cout << "how mony Question do you want answer ?\n";
	cin >> Question;

	return Question;

}


stQuestion GenaratQuestion(levels Questinlevel, opretation optype)
{

	stQuestion Question;

	if (Questinlevel == levels::mixerr)
	{
		Questinlevel = (levels)RandomNumber(1, 3);
	}

	if (optype == opretation::mixer)
	{
		optype = Getrandomoperationtype();
	}



	Question.operation = optype;

	switch (Questinlevel)
	{

	case levels::easy:
		Question.number1 = RandomNumber(1, 10);
		Question.number2 = RandomNumber(1, 10);


		Question.correctanswer = simplecalculat(Question.number1, Question.number2, Question.operation);
		Question.questinlevel = Questinlevel;
		return Question;

	case levels::mid:
		Question.number1 = RandomNumber(10, 50);
		Question.number2 = RandomNumber(10, 50);


		Question.correctanswer = simplecalculat(Question.number1, Question.number2, Question.operation);
		Question.questinlevel = Questinlevel;
		return Question;

	case levels::hard:
		Question.number1 = RandomNumber(50, 100);
		Question.number2 = RandomNumber(50, 100);


		Question.correctanswer = simplecalculat(Question.number1, Question.number2, Question.operation);
		Question.questinlevel = Questinlevel;
		return Question;


	case levels::mixerr:
		Question.number1 = RandomNumber(50, 100);
		Question.number2 = RandomNumber(50, 100);


		Question.correctanswer = simplecalculat(Question.number1, Question.number2, Question.operation);
		Question.questinlevel = Questinlevel;
		return Question;
	}
	return Question;

}
void Genaratequestion(stQuizz& Quizz)
{


	for (short question = 0; question < Quizz.numberofquestion; question++)
	{
		Quizz.Questionlist[question] = GenaratQuestion(Quizz.levelgame, Quizz.op);


	}
}

int ReadquestionAnswer()
{
	int answer = 0;
	cin >> answer;
	return answer;


}


void printtheQuestion(stQuizz& Quizz, short questionnuber)
{

	cout << "\n";
	cout << "Question [" << questionnuber + 1 << "/" << Quizz.numberofquestion << "] \n\n";
	cout << Quizz.Questionlist[questionnuber].number1 << endl;
	cout << Quizz.Questionlist[questionnuber].number2 << " ";
	cout << getoptypesymbol(Quizz.Questionlist[questionnuber].operation);
	cout << "\n_" << endl;


}

void CorrecttheQuestionAnswer(stQuizz& Quizz, short questionnuber)
{


	if (Quizz.Questionlist[questionnuber].playeranswer != Quizz.Questionlist[questionnuber].correctanswer)
	{
		Quizz.Questionlist[questionnuber].Answerreaslt = false;
		Quizz.numberofwronganswer++;


		cout << "Worng Answer :-( \n";
		cout << "The right answer is: ";
		cout << Quizz.Questionlist[questionnuber].correctanswer;
		cout << "\n";


	}
	else
	{
		Quizz.Questionlist[questionnuber].Answerreaslt = true;
		Quizz.numberofrigthanswer++;
		cout << "right answer ";
	}

	cout << endl;
	setscreenColor(Quizz.Questionlist[questionnuber].Answerreaslt);

}



void AskAndcorretQuestionAnswer(stQuizz& Quizz)
{

	for (short questionnumber = 0; questionnumber < Quizz.numberofquestion;questionnumber++)
	{

		printtheQuestion(Quizz, questionnumber);

		Quizz.Questionlist[questionnumber].playeranswer = ReadquestionAnswer();

		CorrecttheQuestionAnswer(Quizz, questionnumber);

	}

	Quizz.ispasse = (Quizz.numberofrigthanswer >= Quizz.numberofwronganswer);


}

string getfinalreslts(bool  pass)
{
	if (pass)
		return "pass :-)";
	else
		return "fial :-(";

}
void printQuizzResultst(stQuizz Quizz)
{

	cout << "\n";
	cout << "\n----------------------------\n";
	cout << " Final Resutls is " << getfinalreslts(Quizz.ispasse);
	cout << "\n--------------------------------------_\n\n";
	cout << "Number of Questions: " << Quizz.numberofquestion << endl;
	cout << "Questions Level    : " << getQuestionlevel(Quizz.levelgame) << endl;
	cout << "OpType             : " << getoptypesymbol(Quizz.op) << endl;
	cout << "Number of Right Answers: " << Quizz.numberofrigthanswer << endl;
	cout << "Number of Wrong Answers: " << Quizz.numberofwronganswer << endl;
	cout << "------------------------------------_\n";



}
void playgammath()
{
	stQuizz Quizz;

	Quizz.numberofquestion = readthemonyQuestion();
	Quizz.levelgame = ReadQuestionlevels();
	Quizz.op = Readoptype();


	Genaratequestion(Quizz);
	AskAndcorretQuestionAnswer(Quizz);
	printQuizzResultst(Quizz);
}

void resetscrean()
{
	system("cls");
	system("color 0f");


}

void startGame()
{

	char playagain = 'Y';

	do
	{
		resetscrean();
		playgammath();


		cout << "\n" << "do you want to play again Y/N ? ";
		cin >> playagain;

	} while (playagain == 'Y' || playagain == 'y');
}
int main()
{
	startGame();
	return 0;
}