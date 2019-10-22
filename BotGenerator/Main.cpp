#include "stdafx.h"

using namespace std;

void generateBotPy();
void generateBotPhp();

void clear() {
	system("cls");
}

class GenerateCode {
public:
	GenerateCode(string token) {
		this->token = "";
		this->token = token;
	}
	GenerateCode(string token, string confCode, string secretK) {
		this->confCode = confCode;
		this->secretK = secretK;
		this->token = token;
	}
	GenerateCode(string login, string password) {
		this->login = login;
		this->password = password;
	}
	string GetCodePhp() {
		return code =
			"// CREATED BY VK-BOT GENERATOR 0.1 VERSION \n"
			"// Author: Danil Romanov (vk.com/sha1.encryption) \n"
			"< ? php \n"
			"\n"
			"if (!isset($_REQUEST)) { \n"
				"return; \n"
			"} \n"
			"\n"
			"$confirmationToken = '" + confCode + "'; \n"
			"\n"
			"//Ключ доступа сообщества \n"
			"$token = '" + token + "'; \n"
			"// Secret key \n"
			"$secretKey = '" + secretK + "'; \n"
			"//Получаем и декодируем уведомление \n"
			"$data = json_decode(file_get_contents('php://input')); \n"
			"// проверяем secretKey \n"
			"if (strcmp($data->secret, $secretKey) != = 0 && strcmp($data->type, 'confirmation') != = 0) \n"
			"\treturn; \n"

			"//Проверяем, что находится в поле \"type\" \n"
			"switch ($data->type) { \n"
			"//Если это уведомление для подтверждения адреса сервера... \n"
			"\tcase 'confirmation': \n"
			"\t\techo $confirmationToken; \n"
			"\t\tbreak; \n"
			"\tcase 'message_new': \n"
			"\t\t// YOUR CODE \n"
			"\t\tbreak; \n"
	
			"\tcase 'group_join': \n"
			"\t\t// YOUR CODE \n"
			"\t\tbreak; \n"
			"} \n"
			"? > \n";
	}

	string GetCodePythonConf() {
		return code =
			"# CREATED BY VK-BOT GENERATOR 0.1 VERSION \n"
			"# Author: Danil Romanov (vk.com/sha1.encryption) \n"
			"import vk_api \n"
			"import requests \n"
			"\n"
			"session = requests.Session() \n"
			"login, password = '" + login + "', '" + password + "' \n"
			"vk_session = vk_api.VkApi(login, password) \n" 
			"try : \n"
			"vk_session.auth(token_only = True) \n" 
			"except vk_api.AuthError as error_msg : \n" 
			"\tprint(error_msg) \n"
			"\treturn \n"
			"for event in longpoll.listen(): \n"
			"\tif event.type == VkEventType.MESSAGE_NEW: # NEW MESSAGE \n"
			"\t\tif event.to_me: # Message to me \n"
			"\t\t\trequest = event.text # Event = message text \n"
			"\t\t\tif request == \"Hello!\": \n"
			"\t\t\t\t# YOUR CODE \n";
	}

	string GetCodePythonGroup() {
		return code =
			"# CREATED BY VK-BOT GENERATOR 0.1 VERSION \n"
			"# Author: Danil Romanov (vk.com/sha1.encryption) \n"
			"import vk_api \n"
			"from vk_api.longpoll import VkLongPoll, VkEventType \n"
			"\n"
			"def write_msg(user_id, message): \n"
			"\tvk.method('messages.send', { 'user_id': user_id, 'message' : message }) \n"
			"token = \"" + token + "\" \n"
			"vk = vk_api.VkApi(token=token) \n"
			"longpoll = VkLongPoll(vk) \n"
			"for event in longpoll.listen():\n"
			"\tif event.type == VkEventType.MESSAGE_NEW: # NEW MESSAGE \n"
			"\t\tif event.to_me: # Message to me \n"
			"\t\t\trequest = event.text # Event = message text \n"
			"\t\t\tif request == \"Hello!\": \n"
			"\t\t\t\t# YOUR CODE \n";
	}
private:
	string token;
	string code;
	string confCode;
	string secretK;
	string login;
	string password;
};

int main()
{
	string lang = ""; // Programming languague
	cout << "\n\t[WELCOME TO VK BOT-GENERATOR 0.1 VERSION]" << endl; // WE
	cout << "\n\tEnter programming languague(Python, PHP): ";		//	  LCOME
	getline(cin, lang);
	if (lang == "Python") // If user choose Python programming languague
		generateBotPy();
	if (lang == "PHP") { // If user choose php programming languague
		generateBotPhp();
	}
	else {
		clear(); // Clear console
		main();
	}
	return 0;
}

void generateBotPy() {
	clear(); // Clear console
	string token;
	string mode;
	string login, password;

	cout << "\n\t[VK BOT-GENERATOR Python 0.1 VERSION]" << endl; // Welcome
	cout << "\n\tSelect the \"location\" of the bot" << endl;
	cout << "\n\t 1) Group" << endl;
	cout << "\n\t 2) Conference\\Conversation" << endl;
	cout << "\n\t Choose: ";
	getline(cin, mode);

	string code = "";
	if (mode == "1)" || mode == "1") {
		clear();
		cout << "\n\t[VK BOT-GENERATOR Python 0.1 VERSION]" << endl; // Welcome
		cout << "\n\tTOKEN: ";
		getline(cin, token);
		GenerateCode BotPy(token);
		code = BotPy.GetCodePythonGroup(); // Generate and get code
	}
	else {
		clear();
		cout << "\n\t[VK BOT-GENERATOR Python 0.1 VERSION]" << endl; // Welcome
		cout << "\n\tLogin: ";
		getline(cin, login);
		cout << "\n\tPassword: ";
		getline(cin, password);
		GenerateCode BotPy(login, password);
		code = BotPy.GetCodePythonConf();
	}

	ofstream f("yourbot.py"); // Create file
	f << code; // Write in file bot code
	f.close();
	// Install dependencies?
	string dependencies;
	cout << "\n\tInstall the dependencies?" << endl;
	cout << "\n\t\tI hope you already have pip and python installed" << endl;
	cout << "\n\t\tY/n: ";
	getline(cin, dependencies);
	if (dependencies == "y" || dependencies == "Y") {
		// Install dependencies
		system("pip install vk_api");
		system("pip2 install vk_api");
		system("pip3 install vk_api");
	}
	cout << endl;
	// SUCCESSFULL!!
	cout << "\n\tBot is created." << endl;
	cout << "\n\tFilename: yourbot.py" << endl;
	
	cout << endl;
	string newBot;
	// Already
	cout << "\n\tCreate new bot?" << endl;
	cout << "\n\t\t Y/n: ";
	getline(cin, newBot);
	if (newBot == "y" || newBot == "Y") {
		// Clear Console and go to Main function
		clear();
		main();
	}
	else {
		// Bye
		cout << "\n\tGood luck!" << endl;
		system("pause");
		exit(0);
	}
}

void generateBotPhp() {
	clear(); // Clear Console
	string token;
	string secretKey;
	string confirmationKey;
	cout << "\n\t[VK BOT-GENERATOR PHP 0.1 VERSION]" << endl;
	cout << "\n\tTOKEN: ";
	getline(cin, token);
	cout << "\n\tSecret Key: ";
	getline(cin, secretKey);
	cout << "\n\tConfirmationKey: ";
	getline(cin, confirmationKey);
	GenerateCode BotPHP(token, confirmationKey, secretKey);

	string code = BotPHP.GetCodePhp(); // Generate and get code php
	fstream php("yourbot.php", 'w'); // Create file and
	php << code;					//					write code
	php.close();
	// SUCCESSFULL!!!!!
	cout << "\n\tBot is created." << endl;
	cout << "\n\tFilename: yourbot.php" << endl;

	string newBot;
	cout << "\n\tCreate new bot?" << endl;
	cout << "\n\t Y/n:" << endl;
	getline(cin, newBot);
	if (newBot == "y" || newBot == "Y") {
		clear(); // Clear and call main function
		main();
	}
	// Exit
	cout << "\n\tGood luck!" << endl;
	system("pause");
	exit(0);
}