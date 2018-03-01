#include "Message.h"
#include "Folder.h"

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders) // 对每个包含m的folder
		f->addMsg(this);	 // 向该Folder添加一个指向本Message的指针
}

void Message::remove_from_Folders()
{
	for (auto f : folders)	// 对folders中每个指针
		f->remMsg(this);	// 从该Folder中删除本Message
}

void Message::save(Folder &f)
{
	folders.insert(&f);		// 将给定Folder添加到我们的Folder列表中
	f.addMsg(this);			// 将本Message添加到f的Message集合中
}

void Message::remove(Folder &f)
{
	folders.erase(&f);		// 将给定Folder从我们的Folder列表中删除
	f.remMsg(this);			// 将本Message从f的Message集合中删除
}

//----------------------------------------------

// implement 拷贝控制成员

Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);		// 将本消息添加到指向m的Folder中
}

Message::~Message()
{
	remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
	// 通过先删除指针再插入它们来处理自赋值的情况
	remove_from_Folders();	// 更新已有Folder
	contents = rhs.contents;// 从rhs拷贝消息内容
	folders = rhs.folders;	// 从rhs拷贝Folder指针
	add_to_Folders(rhs);	// 将本Message添加到那些Folder中
	return *this;
}

//----------------------------------------------

void swap(Message &lhs, Message &rhs)
{
	using std::swap;		// 在本例中严格来说并不重要，但这是一个好习惯
	// 将每个消息的指针从它（原来）所在Folder中删除
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();

	// 交换contents和Folder指针set
	swap(lhs.folders, rhs.folders);
	//swap(lhs.contents, rhs.contents); // 交换contents就看不出变化了。。

	// 将每个Message的指针添加到新的Folder中
	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}
