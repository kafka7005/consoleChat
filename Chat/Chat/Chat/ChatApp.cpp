#include "ChatApp.h"

bool ChatApp::registerUser(const std::string& login, const std::string& password)
{
	for (const auto& user : users)
	{
		if (user.getUserLogin() == login)
		{
			std::cout << "\x1B[31m������������ � ����� ������ ��� ����������!\n\033[0m";
			return false;
		}
	}
	users.push_back(User(login, password));
	std::cout << "\x1B[32m����������� ������ �������!\n\033[0m";
	return true;
}

User* ChatApp::loginUser(const std::string& login, const std::string& password)
{
	for (auto& user : users)
	{
		if (user.getUserLogin() == login && user.checkPassword(password))
		{
			std::cout << "\x1B[32m����������� �������!\n\033[0m";
			return &user;
		}
	}
	std::cout << "\x1B[31m�������� ��� ������������ ��� ������!\n\033[0m";
	return nullptr;
}

GroupChat& ChatApp::getChat(const std::string& user1, const std::string& user2)
{
	for (auto& chat : chats)
	{
		if (chat.hasChat(user1, user2))
		{
			return chat;
		}
	}
	chats.push_back(GroupChat());
	return chats.back();
}

void ChatApp::sendMessageToGeneralChat(const std::string& sender, const std::string& message)
{
	generalChat.sendMessage(sender, "\x1B[33m����� ���\033[0m", message, false); // false ��������, ��� ��� ��������� ���������
}

void ChatApp::showGeneralChat() const
{
	std::cout << "\x1B[33m\n����� ���:\n\033[0m";
	generalChat.showMessage(true); // true ��������, ��� ������������ ������ ��������� ���������

}

void ChatApp::exitApp() const
{
	std::cout << "\x1B[31m\n�� ����� �� ���������.\t�� ��������!\n\033[0m";
	exit(0);
}

const std::vector<User>& ChatApp::getUsers() const
{
	return users;
}

const std::vector<GroupChat>& ChatApp::getChats() const
{
	return chats;
}