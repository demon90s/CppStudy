#include <stdio.h>
#include <string>
#include <iostream>
#include "queue.h"

int main(int argc, char const *argv[])
{
	{
		Queue<int> queue;

		queue.push(1);
		queue.push(2);
		queue.push(3);
		queue.push(4);

		printf("first of queue: %d\n", queue.first());
		printf("last of queue: %d\n", queue.last());

		queue.pop();
		printf("after pop, first of queue: %d, last of queue: %d\n", queue.first(), queue.last());

		printf("before pop all, queue is empty? %s\n", queue.is_empty() ? "yes" : "no");
		while (!queue.is_empty()) {
			queue.pop();
		}
		printf("after pop all, queue is empty? %s\n", queue.is_empty() ? "yes" : "no");
	}

	{
		Queue<std::string> queue;

		queue.push("Hello");
		queue.push("World");
		queue.push("Boo");
		queue.push("Goo");

		printf("first of queue: %s\n", queue.first().c_str());
		printf("last of queue: %s\n", queue.last().c_str());

		queue.pop();
		printf("after pop, first of queue: %s, last of queue: %s\n", queue.first().c_str(), queue.last().c_str());

		printf("before pop all, queue is empty? %s\n", queue.is_empty() ? "yes" : "no");
		while (!queue.is_empty()) {
			queue.pop();
		}
		printf("after pop all, queue is empty? %s\n", queue.is_empty() ? "yes" : "no");
	}

	std::cin.get();
    return 0;
}
