#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\n******************************************************************************************************\n";
    std::cout << "Voce e um agente secreto e precisa invadir uma sala secreta de nivel " << Difficulty << "\n";
    std::cout << "e precisa digitar o codigo correto para continuar...";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty, // inicializando as variaveis com um intervalo randomico entre 
              CodeB = rand() % Difficulty + Difficulty, // 1 e o valor da dificuldade passada por parametro.
              CodeC = rand() % Difficulty + Difficulty; // ******* +1 no final pra excluir o zero *******
              
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "\n\nExistem 3 numeros no codigo\n";
    std::cout << "\nA soma deles eh: " << CodeSum << std::endl;
    std::cout << "E o produto deles eh: " << CodeProduct << std::endl;

    int GuessA,
        GuessB,
        GuessC;

    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "Voce digitou: " << GuessA << " " << GuessB << " " << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "Boa agente!!! Voce descobriu o codigo, continue!!! :)";
        return true;
    }
    else
    {
        std::cout << "Nao eh esse codigo! :( Tente de novo!";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // cria uma nova sequencia randomica baseada na hora do dia
    int LevelDificulty = 1;
    int const MaxDifficulty = 6;

    while (LevelDificulty <= MaxDifficulty) // loop ate o fim dos nivies
    {
        bool bLevelComplete = PlayGame(LevelDificulty);
        std::cin.clear();  //limpa os erros
        std::cin.ignore(); //descarta o buffer

        if (bLevelComplete)
        {
            ++LevelDificulty;
        }
    }

    std::cout << "\n\nParabens agente!! Voce descobriu todos os codigos. AGORA SAI DAQUI!\N";
    return 0;
}
