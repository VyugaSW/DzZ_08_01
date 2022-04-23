
#include <iostream>
#include <Windows.h>

using namespace std;

// Задание 1
char line, sym, times;
void lineRoute(char a, char b) {

    int timed = 10;

    if (b == 'S')
        timed = 500;
    else if (b == 'N')
        timed = 250;

    if (a == 'V') {
        for (int i = 0; i < 8; i++) {
            Sleep(timed);
            cout << sym << endl;
        }
    }
    else if (a == 'H') {
        for (int i = 0; i < 8; i++) {
            Sleep(timed);
            cout << sym;
        }
    }
    else
        cout << "Ошибка!";
}
// ------



//Задание 2
int score;
int summa_user = 0, summa_PC = 0;
inline void summa(int b) { ::score = b; };
inline void cubes(int N) {
    string cube_one =
        "\t*******\n"
        "\t*     *\n"
        "\t*     *\n"
        "\t*  o  *\n"
        "\t*     *\n"
        "\t*     *\n"
        "\t*******\n";
    string cube_two =
        "\t*******\n"
        "\t*     *\n"
        "\t*  o  *\n"
        "\t*     *\n"
        "\t*  o  *\n"
        "\t*     *\n"
        "\t*******\n";
    string cube_three =
        "\t*******\n"
        "\t*     *\n"
        "\t* o   *\n"
        "\t*  o  *\n"
        "\t*   o *\n"
        "\t*     *\n"
        "\t*******\n";
    string cube_four =
        "\t*******\n"
        "\t*     *\n"
        "\t*  o  *\n"
        "\t* o o *\n"
        "\t*  o  *\n"
        "\t*     *\n"
        "\t*******\n";
    string cube_five =
        "\t*******\n"
        "\t*     *\n"
        "\t* o o *\n"
        "\t*  o  *\n"
        "\t* o o *\n"
        "\t*     *\n"
        "\t*******\n";
    string cube_six =
        "\t*******\n"
        "\t*     *\n"
        "\t* ooo *\n"
        "\t*     *\n"
        "\t* ooo *\n"
        "\t*     *\n"
        "\t*******\n";
    switch (N) {
    case(1):
        cout << cube_one;
        summa(1);
        break;
    case(2):
        cout << cube_two;
        summa(2);
        break;
    case(3):
        cout << cube_three;
        summa(3);
        break;
    case(4):
        cout << cube_four;
        summa(4);
        break;
    case(5):
        cout << cube_five;
        summa(5);
        break;
    case(6):
        cout << cube_six;
        summa(6);
        break;
    default:
        break;
    }
}
inline void stepUser() {
    cout << "\t|Ход человечка|\n";
    srand(time(NULL));
    cubes(rand() % 6 + 1);
    summa_user += score;
    Sleep(350);
    cubes(rand() % 6 + 1);
    summa_user += score;
}
inline void stepPC() {
    cout << "\t|Ход безэтичной машины|\n";
    srand(time(NULL));
    cubes(rand() % 6 + 1);
    summa_PC += score;
    Sleep(350);
    cubes(rand() % 6 + 1);
    summa_PC += score;
}
inline void win() {
    (summa_user > summa_PC) ? cout << "\t\t||ПОЛЬЗОВАТЕЛЬ ВЫЙГРАЛ||\n" : cout << "\t\t||ПК УМАЛИЛ СМЕРТНОГО||\n";
}
// ------



//Задание 3
int live;
int PCnum;
bool flag = true;
int score_user = 0;
void rand_num_level1() {
    srand(time(NULL));
    PCnum = rand() % 10 + 1;
    cout << PCnum << endl;
}
void rand_num_level2() {
    srand(time(NULL));
    PCnum = rand() % 100 + 10;
    cout << PCnum << endl;
}
void HELP(int a) {
    if (a > PCnum) cout << "\t===Ваше число больше загаданного===\n";
    else cout << "\t===Ваше число меньше загаданного===\n";
}
void level(int a) {
    int user;
    char hel;

    if (a == 1) {
        live = 5;
        rand_num_level1();
    }
    else if (a == 2) {
        live = 22;
        rand_num_level2();
    }

    while (live >= 0 && flag) {
        cout << "\t|ВАШИ ЖИЗНИ - " << live << "|" << endl;
        if (live > 0) {
            cout << "---------------\n";
            cout << "ПК загадал число\n" << "Предположите его - "; cin >> user;        //Ох, чаю, что вы разберётесь в этом вареве :))
            if (user == ::PCnum) {
                cout << "ОХ, ВЫ УГАДАЛИ!\n";
                (a == 1) ? score_user += live * 5: score_user += live * 10;
                cout << "Ваши очки - " << score << endl;
                break;
            }
            else {
                cout << "Нет :)\n";
                live -= 1;
            }
            cout << endl << "Подсказочку?(Y or N) - "; cin >> hel;
            if (hel == 'Y') {
                HELP(user);
                live -= 1;
            }
        }
        else if (live == 0) {
            cout << "Ох, вы проиграли (:\n";
            cout << "Число ПК было - " << PCnum << endl;
            live -= 1;
        }
    }
}
// ------

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Написать программу, которая выводит на экран линию
    //заданным символом, вертикальную или горизонтальную, при -
    //чем линия может выводиться быстро, нормально и медленно.
    //Общение с пользователем организовать через меню.

    /*cout << "ВЫВОД ЛИНИЙ\n";
    cout << "Символ?\n"; cin >> sym;
    cout << "Вертикальная(V)/Горизонтальная(H)?\n"; cin >> line;
    cout << "Медленно(S)/Быстро(F)/Нормально(N)?\n"; cin >> times;
    lineRoute(line, times);*/




    //Написать игру «Кубики». Пользователь и компьютер по
    //очереди бросают 2 кубика.Победитель — тот, у кого по резуль -
    //татам трех бросков сумма больше.Предусмотреть красивый
    //интерфейс игры.


    /*cout << "\t\t\t|Вам приветствует игра кубики|\n\n\n";
    int chosen;
    bool stop = true;
    while (stop) {
        summa_PC = 0; summa_user = 0;
        cout << "\t Кто начнёт свой ход? (Human - 1/PC - 0) - "; cin >> chosen;
        for (int i = 0; i < 5; i++) {
            if (chosen == 1) {
                stepUser();
                Sleep(1000);
                cout << "-------------------------------------------------------------------\n";
                Sleep(1000);
                stepPC();
            }
            else {
                stepPC();
                Sleep(1000);
                cout << "-------------------------------------------------------------------\n";
                Sleep(1000);
                stepUser();
            }
        }
        cout << "\n|||ОЧКИ ПК - " << summa_PC << endl;
        cout << "\n|||ОЧКИ СМЕРТНОГО - " << summa_PC << endl;
        win();
        Sleep(3500);
        system("cls");
        cout << "\t|Жаждете ещё раунд? (Y or N) - ";
        char s; cin >> s;
        if (s == 'N') {
            stop = false;
            cout << "\t Прощайте!\n";
        }
    }*/



    //  Написать игру «GUESS MY NUMBER». Пользователь
    //  угадывает число, которое «загадал» компьютер.Возможны
    //  2 уровня сложности : на первом уровне число от 1 до 10, на
    //  втором от 10 до 100. В начале игры пользователь выбирает
    //  уровень.
    //  В начале каждого уровня игроку даются «жизни» — 50 %
    //  от длины диапазона угадывания на первом уровне и 25 % — на
    //  втором(пример приведен ниже).За каждую ошибку игрок
    //  штрафуется — минус одна жизнь.Предусмотреть в игре воз -
    //  можность подсказки : «загаданное число больше — меньше
    //  твоего».Стоимость подсказки — одна жизнь(пользователь
    //  может принять подсказку в случае ошибки или отказаться от
    //  нее).Уровень продолжается, пока игрок жив или не угадает
    //  (состояние игрока «жив» — «убит» отображается рисунком
    //  в консоли).
    //  Очки после уровня — количество оставшихся жизней,
    //  умноженные на 5 для первого уровня и на 10 для второго.
    //  Результат игры, количество или «Проигрыш», вывести в консоль


    bool fl = true;
    while (fl) {
        cout << "Вас приветствует игра \"Угадай моё число!\"\n";
        int s;
        cout << "Выберите сложность (1 or 2) - "; cin >> s;
        if (s == 1) {
            level(1);
        }
        else
            level(2);


        cout << "Не желаете вновь начать игру? (Y or N) \n";
        char c; cin >> c;
        system("cls");
        if (c == 'N') fl = false;
    }






}
