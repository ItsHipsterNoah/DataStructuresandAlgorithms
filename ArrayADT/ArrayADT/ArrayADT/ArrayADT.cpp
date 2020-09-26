#include "Array.cpp"


int main()
{
    int choice, index, x, size;
    choice = index = x = size = 0;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    Array<int> array{ size };
    do
    {
        std::cout << std::endl;
        std::cout << " Menu " << std::endl;
        std::cout << " 1. Insert" << std::endl;
        std::cout << " 2. Delete" << std::endl;
        std::cout << " 3. Search" << std::endl;
        std::cout << " 4. Sum" << std::endl;
        std::cout << " 5. Display" << std::endl;
        std::cout << " 6. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter an element: ";
            std::cin >> x;
            std::cout << "Enter an index: ";
            std::cin >> index;
            array.Insert(index, x);
            break;
        case 2:
            std::cout << "Enter an index: ";
            std::cin >> index;
            array.Delete(index);
            break;
        case 3:
            std::cout << "Enter an element to search: ";
            std::cin >> x;
            std::cout << "Found " << x << " at position " << array.Search(x) << std::endl;
            break;
        case 4:
            std::cout << "Sum is: " << array.Sum();
            break;
        case 5:
            array.Display();
        default:
            break;
        }
    } while (choice != 6);
    return 0;
}

