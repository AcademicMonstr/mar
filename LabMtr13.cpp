#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// проеврка интервала?


//BAZA
void CreateMtr ( int32_t**& mtr, int32_t rows, int32_t cols)
{  
        mtr = new int32_t*[rows];

        for (int32_t i = 0; i < rows; ++i)
        {
            mtr[i] = new int32_t[cols];   
        }
}

void InputSize ( int32_t& rows, int32_t& cols )
{
    std::cout << "Enter rows and cols: ";
    std::cin >> rows >> cols;
}

void FillingMtr ( int32_t**& mtr, int32_t rows, int32_t cols )
{
    std::cout << "Input matrix elements: ";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cin >> mtr [i][j];
        }
    }
}

void InputInterval ( int32_t& first, int32_t& second )
{
    std::cout << "Enter range, first and second interval vakue: ";
    std::cin >> first >> second;
}

int ChooseMethod ( int& choice ){
    std::cout << "Choose the method for filling:\n1) Keyboard\n2) Random\nYour choise : ";
    std::cin >> choice;
    return choice;
}

void OutputMtr ( int32_t** mtr, int32_t rows, int32_t cols )
{
    std::cout << "Matrix:" << std::endl;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
        
            std::cout << std::setw(4) << mtr[i][j]; 
            
        }
        std::cout << std::endl;  
    }

}

void RandomMtr(int32_t**& mtr, int32_t rows, int32_t cols, int first, int second) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j){
            mtr[i][j] = std::rand() % (second - first + 1) + first;
        }
    }
}

// Поиск нуля
void FindZero ( int32_t** mtr, int32_t rows, int32_t cols, int zerorows ){

    bool check = false;
    
    for (int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            if ( mtr[i][j] == 0 ){
                check = true;
                zerorows = i;
                break;
            }
        }
        if ( check == true ){
            break;
        }
    }

    if ( zerorows == -1 ){
        std::cout << "Error, rows doesnt have zero";
    }
    else{
    std::cout << "First rows with zero: " << zerorows;
    }
}

//

int main()
{
    int rows = 0;
    int cols = 0;
    int32_t** mtr = nullptr;
    int choice = 0;
    int first = 0;
    int second = 0;
    int zerorows = -1;

    InputSize( rows, cols );
    CreateMtr( mtr, rows, cols );
    

    while(true)
    {
        ChooseMethod( choice );

        if ( choice == 1 )
        {
            FillingMtr( mtr, rows, cols );
            OutputMtr ( mtr, rows, cols );
            break;
        }
        else if ( choice == 2 )
        {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            InputInterval( first, second );
            RandomMtr( mtr, rows, cols, first, second );
            OutputMtr ( mtr, rows, cols );
            FindZero ( mtr, rows, cols, zerorows );
            break;
        }
        else 
        {
            std::cout << "Error. Wrong value, value 1 or 2 ";
        }
    }
}