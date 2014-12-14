#include "LinkedList.h"

int main(int argc, char **argv)
{
	LinkedList<int> list;
	int data = 0;
	int referenceData = 0;
	int choice = 0;
	bool quit = false;

	std::cout << "\n\nThis is an INTEGER-based linked list!\n\n";

	do
	{
		std::cout << "\n1. Append data\n"
				  << "2. Prepend data\n"
				  << "3. Insert before element x\n"
				  << "4. Insert after element x\n"
				  << "5. Delete node from head\n"
				  << "6. Delete node from tail\n"
				  << "7. Delete a specific node\n"
				  << "8. Show the list's data\n"
				  << "0. Quit\n\n"
				  << "     Select option: ";

		std::cin >> choice;

		switch (choice)
		{
		case 1:
			system("CLS");
			std::cout << "\nEnter data to add to the end of the list: ";
			std::cin >> data;
			list.append(data);
			break;
		case 2:
			system("CLS");
			std::cout << "\nEnter data to add to the front of the list: ";
			std::cin >> data;
			list.prepend(data);
			break;
		case 3:
			system("CLS");
			std::cout << "\nEnter reference data for new data to be placed before it: ";
			std::cin >> referenceData;
			std::cout << "\nNow please enter the new data: ";
			std::cin >> data;
			list.insertBefore(referenceData, data);
			break;
		case 4:
			system("CLS");
			std::cout << "\nEnter reference data for new data to be placed after it: ";
			std::cin >> referenceData;
			std::cout << "\nNow please enter the new data: ";
			std::cin >> data;
			list.insertAfter(referenceData, data);
			break;
		case 5:
			system("CLS");
			list.deleteFromHead();
			break;
		case 6:
			system("CLS");
			list.deleteFromTail();
			break;
		case 7:
			system("CLS");
			std::cout << "Enter data that is contained in an existing node,\nand I will remove that node from the list: ";
			std::cin >> data;
			list.deleteNode(data);
			break;
		case 8:
			system("CLS");
			std::cout << '\n';
			list.toString();
			break;
		case 0:
			quit = true;
			break;
		default:
			break;
		}

	
	} while (quit != true);

	return 0;
}

