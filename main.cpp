#include <iostream>
#include <ctime>
#include <string>
#include <unistd.h>

using namespace std;


string codegen() {
    char colors[8] = {
            'R',
            'V',
            'B',
            'M',
            'W',
            'N',
            'O',
            'G',
    };
    string final_word = "ZZZZ";
    srand((unsigned) time(nullptr));
    int count = 0;
    while (final_word[3] == 'Z'){
        int rn = rand()%8;
        if ((colors[rn] != final_word[0]) && (colors[rn] != final_word[1]) && (colors[rn] != final_word[2]) && (colors[rn] != final_word[3])) {
            final_word[count] = colors[rn];
            ++count;
        }
    }
    return final_word;
}
int main() {
    basic_string<char> code = codegen();
    bool solution = false;
    int goodPlaced;
    int goodnumbers;
    string useranswer;
    int nbTrials = 0;
    char n1 = code[0];
    char n2 = code[1];
    char n3 = code[2];
    char n4 = code[3];
    cout << "Ceci est un Mastermind en console, vous devez trouver le code forme de lettres representant les couleurs"<< endl << "Les lettres possibles sont: R, V, B, M, W, N, O, G." << endl;
    cout << "Il ne peut pas y avoir plusieurs fois la meme lettre dans le code." << endl;
    while (!solution) {
        cout << "Entrez les lettres que vous pensez etre dans le code." << endl;
        cin >> useranswer;
        goodnumbers = 0;
        goodPlaced = 0;
        int nbSame = 0;

        for (int i = 0; i < useranswer.length(); i++) {
            useranswer[i] = toupper(useranswer[i]);
        }

        for (int i = 0; i < 4; ++i) {
            nbSame += (useranswer[i] == useranswer[0]);
            nbSame += (useranswer[i] == useranswer[1]);
            nbSame += (useranswer[i] == useranswer[2]);
            nbSame += (useranswer[i] == useranswer[3]);

            if (useranswer[i] == code[i]) {
                ++goodPlaced;
                ++goodnumbers;
            } 
            else if ((useranswer[i] == code[0]) || (useranswer[i] == code[1]) || (useranswer[i] == code[2]) || (useranswer[i] == code[3])) {
                goodnumbers++;
            }

        }

        if ((nbSame > 4) or (useranswer.length() < 4)){
            cout << "Vous essayez de tricher ?" << endl;
        } 
        else if (goodPlaced == 4) {
            cout << "Bravo, vous avez gagne !" << endl << "Il vous a fallu " << nbTrials + 1<< " essais pour trouver."
                << endl << "Redemarrez le programme pour jouer a nouveau" << endl;
            solution = true;
            sleep(10);
            } 
        else {
            nbTrials += 1;
            cout << "Vous avez " << goodnumbers << " bonne(s) lettre(s), dont " << goodPlaced << " bien placee(s)." << endl;

        }
    }
    return 0;
}