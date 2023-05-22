/********************************************************
* Description: simply C++ linked demo
* Author: jiangxiaoyu
* Data: Fir Apr 28 2023
*********************************************************/

#include <iostream>
#include <string>

/*
1. create linked list
2. insert linked list
3. destory linked list
4. single linked list
5. double linked list
*/


namespace DesigeData
{
	//extern StaffInfomation;
}

typedef struct{
	int				ages;
	int 			salary;
	int				seniority;
	std::string 	name;
	std::string 	post;
	std::string 	education;
	void *			nextLinkedList;
}StaffInfomation;

class SingleLinkedList {
public:
	StaffInfomation * headerPointer, *currentPointer;
	void helper();
	void createLinkedList();
	void collectStaffInfomation(StaffInfomation *);
	void printStaffInfomation();
	void destoryStaffInfomation();
	void exitSystem();
};

class DoubleLinkedList {
public:
	void createLinkedList();
};


void SingleLinkedList::helper()
{
	std::cout << "\n\n" << std::endl;
	std::cout << "Simply staff information manager syatem" << std::endl;
	std::cout << "1) Create New Staff Information" << std::endl;
	std::cout << "2) Printf All Staff Information" << std::endl;
	std::cout << "3) Destory All Staff Information" << std::endl;
	std::cout << "4) Helper Manual" << std::endl;
	std::cout << "5) Exit" << std::endl;
/*
	int cmd = 0; std::cin << cmd;
	
	switch (cmd) {
	case 1: createLinkedList(); break;
	case 2: printStaffInfomation; break;
	case 3: destoryStaffInfomation: break;
	case 4:
	}
*/
}

void SingleLinkedList::collectStaffInfomation(StaffInfomation * staffInfo)
{
	std::cout << "-------------------------------" << std::endl;
	std::cout << "staff information system" << std::endl;
	std::cout << "\nstaff name:"; std::cin >> staffInfo->name;
	std::cout << "\nstaff ages:"; std::cin >> staffInfo->ages;
	std::cout << "\nstaff education:"; std::cin >> staffInfo->education;
	std::cout << "\nstaff post:"; std::cin >> staffInfo->post;
	std::cout << "\nstaff seniority:"; std::cin >> staffInfo->seniority;
	std::cout << "\nstaff salary:"; std::cin >> staffInfo->salary;
}

void SingleLinkedList::printStaffInfomation()
{
	StaffInfomation * LinkedHeader = headerPointer;
	while (LinkedHeader) {
		std::cout << "-------------------------------" << std::endl;
		std::cout << "\tstaff information system" << std::endl;
		printf("\tstaff name:%s\n", 		LinkedHeader->name.data());
		printf("\tstaff ages:%d\n", 		LinkedHeader->ages);
		printf("\tstaff education:%s\n", 	LinkedHeader->education.data());
		printf("\tstaff post:%s\n", 		LinkedHeader->post.data());
		printf("\tstaff seniority:%d\n", 	LinkedHeader->seniority);
		printf("\tstaff salary:%d\n", 		LinkedHeader->salary);
		std::cout << "-------------------------------" << std::endl;

		LinkedHeader = (StaffInfomation *)LinkedHeader->nextLinkedList;
	}
}

void SingleLinkedList::createLinkedList()
{
	StaffInfomation * staffInfo = new StaffInfomation{0};
	staffInfo->nextLinkedList = nullptr;
	/* linked list header->next -> next list/ header->next list */
	if (!headerPointer && !currentPointer) {
		headerPointer = currentPointer = staffInfo;
	}
	else {
		currentPointer->nextLinkedList = staffInfo;
		currentPointer = staffInfo;
	}
	collectStaffInfomation(staffInfo);
}

void SingleLinkedList::destoryStaffInfomation()
{
	while (headerPointer) {
		delete headerPointer;
		headerPointer = (StaffInfomation *)headerPointer->nextLinkedList;
	}
}


/* exit staff manage system */
void SingleLinkedList::exitSystem()
{
/* we need destruct temp memory */
	destoryStaffInfomation();
}

int main(int argc, char ** argv)
{

	SingleLinkedList test;

	do {
		test.helper();	
	
		int cmd = 0; std::cout << "please input flag:"; std::cin >> cmd;

    	switch (cmd) {
    	case 1: test.createLinkedList(); break;
    	case 2: test.printStaffInfomation(); break;
   	 	case 3: test.destoryStaffInfomation(); break;
    	case 4: test.helper(); break;
		case 5: test.exitSystem(); return 0;
		default: std::cout << "input invalid!" << std::endl;
	
    	}
	} while(1);

	return 0;
}



