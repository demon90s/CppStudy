#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include <set>
#include <string>
#include <memory>

#include "Message.h"

class Folder
{
public:
	Folder(const std::string &str) : name(str), messages(std::make_shared<std::set<Message*>>()) {}
	~Folder()
	{ 
		for (auto m : *messages)
			m->remove(*this);
	}

	void addMsg(Message *m) { messages->insert(m); }
	void remMsg(Message *m) { messages->erase(m); }

	const std::string &getName() const { return name; }
	void print() const;

private:
	std::string name;
	std::shared_ptr<std::set<Message*>> messages; // 使用智能指针共享底层对象
};

inline
void Folder::print() const
{
	using namespace std;

	cout << "Folder [" << name << "]:" << endl;

	size_t number = 0;
	for (auto m : *messages)
		cout << "\t" << number++ << ": " << m->contents << endl;
}

#endif // FOLDER_H
