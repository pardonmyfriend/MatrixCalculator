#include "Functions.h"

int count_f{};

void color(int color) //zmiana atrybutów - koloru - znakow wyswietlanych w konsoli
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    //GetStdHandle(STD_OUTPUT_HANDLE) pobiera uchwyt do standardowego wyjscia
}

void gotoxy(int x, int y) //ustawienie okreslonej pozycji kursora w konsoli
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void ShowConsoleCursor(bool showFlag) //pokazywanie i ukrywanie widocznosci kursora w konsoli
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo; //informacje o kursorze konsoli

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; //korsor pokazywany/ukrywany w zaleznosci od zmiennej boolowskiej showflag
    SetConsoleCursorInfo(out, &cursorInfo);
}

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput) //zwraca aktualna pozycje kursora w konsoli
{
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        COORD invalid = { 0, 0 };
        return invalid;
    }
}

void menu()
{
    color(12);
    cout << " _   __      _ _          _       _" << endl;
    cout << "| | / /     | | |        | |     | |            " << endl;
    cout << "| |/ /  __ _| | | ___   _| | __ _| |_ ___  _ __ " << endl;
    cout << "|    ""\x5C"" / _` | | |/ / | | | |/ _` | __/ _ ""\x5C""| '__|" << endl;
    cout << "| |""\x5C""  ""\x5C"" (_| | |   <| |_| | | (_| | || (_) | |   " << endl;
    cout << "\x5C""_| ""\x5C""_/""\x5C""__,_|_|_|""\x5C""_""\x5C""""\x5C""__,_|_|""\x5C""__,_|""\x5C""__""\x5C""___/|_|   " << endl;
    cout << endl << endl;
    cout << "                      _" << endl;
    cout << "                     (_)                         " << endl;
    cout << " _ __ ___   __ _  ___ _  ___ _ __ _____   _     " << endl;
    cout << "| '_ ` _ ""\x5C"" / _` |/ __| |/ _ ""\x5C"" '__|_  / | | |    " << endl;
    cout << "| | | | | | (_| | (__| |  __/ |   / /| |_| |    " << endl;
    cout << "|_| |_| |_|""\x5C""__,_|""\x5C""___|_|""\x5C""___|_|  /___|""\x5C""__, |    " << endl;
    cout << "                                       __/ |    " << endl;
    cout << "                                      |___/     " << endl << endl;

    int Set[] = { 7, 7, 7 };
    int counter = 2;
    char key{};

    for (int i = 0;;)
    {
        gotoxy(18, 17);
        color(Set[0]);
        cout << "START";

        gotoxy(18, 18);
        color(Set[1]);
        cout << "UCZ SIE";

        gotoxy(18, 19);
        color(Set[2]);
        cout << "WYJDZ ";

        ShowConsoleCursor(false);
        key = _getch();

        if (key == 72 && counter >= 2 && counter <= 3) //72 - strzalka w gore
            counter--;
        else if (key == 80 && counter >= 1 && counter <= 2) //80 - strzalka w dol
            counter++;
        else if (key == '\r') //\r - carriage return - ENTER
        {
            system("cls"); //czyszczenie zawartosc konsoli
            ShowConsoleCursor(true);
            color(7);

            switch (counter)
            {
            case 1:
                calculator();
                return;
                break;
            case 2:
                learn();
                return;
                break;
            case 3:
                return;
                break;
            default:
                break;
            }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;

        if (counter == 1)
            Set[0] = 12;
        else if (counter == 2)
            Set[1] = 12;
        else if (counter == 3)
            Set[2] = 12;
    }
}

void calculator()
{
    int Set[] = { 7, 7, 7, 7, 7, 7, 7, 7, 7 };
    int counter = 2;
    char key{};

    for (int i = 0;;)
    {
        gotoxy(0, 0);
        color(Set[0]);
        cout << "Dodawanie macierzy" << endl;

        gotoxy(0, 1);
        color(Set[1]);
        cout << "Odejmowanie macierzy" << endl;

        gotoxy(0, 2);
        color(Set[2]);
        cout << "Mnozenie macierzy przez skalar" << endl;

        gotoxy(0, 3);
        color(Set[3]);
        cout << "Mnozenie macierzy" << endl;

        gotoxy(0, 4);
        color(Set[4]);
        cout << "Potegowanie macierzy" << endl;

        gotoxy(0, 5);
        color(Set[5]);
        cout << "Macierz transponowana" << endl;

        gotoxy(0, 6);
        color(Set[6]);
        cout << "Wyznacznik macierzy" << endl;

        gotoxy(0, 7);
        color(Set[7]);
        cout << "Macierz odwrotna" << endl;

        gotoxy(0, 8);
        color(Set[8]);
        cout << "POWROT DO MENU" << endl;

        ShowConsoleCursor(false);
        key = _getch();

        if (key == 72 && counter >= 2 && counter <= 9)
            counter--;
        else if (key == 80 && counter >= 1 && counter <= 8)
            counter++;
        else if (key == '\r')
        {
            system("cls");
            ShowConsoleCursor(true);
            color(7);

            switch (counter)
            {
            case 1:
                add_substr(createMatrix(), createMatrix(), 1);
                return;
                break;
            case 2:
                add_substr(createMatrix(), createMatrix(), 0);
                return;
                break;
            case 3:
                scalar(createMatrix());
                return;
                break;
            case 4:
                multiplication(createMatrix(), createMatrix());
                return;
                break;
            case 5:
                power(createMatrix());
                return;
                break;
            case 6:
                transpose(createMatrix());
                return;
                break;
            case 7:
                determinant(createMatrix());
                return;
                break;
            case 8:
                inverse(createMatrix());
                return;
                break;
            case 9:
                menu();
                return;
            default:
                break;
            }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;
        Set[5] = 7;
        Set[6] = 7;
        Set[7] = 7;
        Set[8] = 7;

        if (counter == 1)
            Set[0] = 12;
        else if (counter == 2)
            Set[1] = 12;
        else if (counter == 3)
            Set[2] = 12;
        else if (counter == 4)
            Set[3] = 12;
        else if (counter == 5)
            Set[4] = 12;
        else if (counter == 6)
            Set[5] = 12;
        else if (counter == 7)
            Set[6] = 12;
        else if (counter == 8)
            Set[7] = 12;
        else if (counter == 9)
            Set[8] = 12;
    }
}

Matrix createMatrix()
{
    Matrix m{};

    count_f++;

    cout << "Podaj wymiary macierzy ";
    cout << (count_f == 1 ? "A: " : "B: ") << endl;
    cout << "- ilosc wierszy: ";
    cin >> m.row;
    cout << "- ilosc kolumn: ";
    cin >> m.col;
    cout << endl;

    cout << "Wypelnij macierz ";
    cout << (count_f == 1 ? "A: " : "B: ") << endl;

    //dynamiczne tworzenie macierzy
    m.matrix = new double* [m.row];
    for (int i = 0; i < m.row; i++)
    {
        m.matrix[i] = new double[m.col];
        for (int j = 0; j < m.col; j++)
        {
            cout << (count_f == 1 ? "a" : "b") << i << j << " = ";
            cin >> m.matrix[i][j];
        }
    }

    cout << endl;

    return m;
}

void displayMatrix(Matrix m)
{
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
            cout << setw(5) << m.matrix[i][j] << " ";

        cout << endl;
    }
}

void add_substr(Matrix m2, Matrix m1, bool czyDodawac)
{
    if (m1.row != m2.row || m1.col != m2.col)
    {
        cout << "Macierze musza miec takie same wymiary!" << endl;
        count_f = 0;
        cout << endl;
        what_next();
        return;
    }

    Matrix w{};
    w.row = m1.row;
    w.col = m1.col;

    w.matrix = new double* [w.row];
    for (int i = 0; i < w.row; i++)
    {
        w.matrix[i] = new double[w.col];
        for (int j = 0; j < w.col; j++)
        {
            if (czyDodawac)
                w.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
            else
                w.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
        }
    }

    system("cls");

    cout << "A = " << endl;
    displayMatrix(m1);
    cout << endl;

    cout << "B = " << endl;
    displayMatrix(m2);
    cout << endl;

    color(12);
    cout << "A ";
    cout << (czyDodawac ? "+" : "-") << " B = " << endl;
    displayMatrix(w);
    color(7);

    for (int i = 0; i < w.row; i++)
    {
        delete[] m1.matrix[i];
        delete[] m2.matrix[i];
        delete[] w.matrix[i];
    }

    delete[] m1.matrix;
    delete[] m2.matrix;
    delete[] w.matrix;

    count_f = 0;

    cout << endl;
    what_next();
}

void scalar(Matrix m)
{
    double n{};
    cout << "Podaj liczbe przez ktora chcesz pomnozyc macierz: ";
    cin >> n;

    Matrix w{};
    w.row = m.row;
    w.col = m.col;

    w.matrix = new double* [w.row];
    for (int i = 0; i < w.row; i++)
    {
        w.matrix[i] = new double[w.col];
        for (int j = 0; j < w.col; j++)
            w.matrix[i][j] = n * m.matrix[i][j];
    }

    system("cls");

    cout << "A = " << endl;
    displayMatrix(m);
    cout << endl;

    color(12);
    cout << n << " * A = " << endl;
    displayMatrix(w);
    color(7);

    for (int i = 0; i < m.row; i++)
        delete[] m.matrix[i];

    for (int i = 0; i < w.row; i++)
        delete[] w.matrix[i];

    delete[] m.matrix;
    delete[] w.matrix;

    count_f = 0;

    cout << endl;
    what_next();
}

void multiplication(Matrix m2, Matrix m1)
{
    if (m1.col != m2.row)
    {
        cout << "Liczba kolumn macierzy pierwszej musi byc rowna liczbie wierszy macierzy drugiej!" << endl;
        count_f = 0;
        cout << endl;
        what_next();
        return;
    }

    Matrix w{};
    w.row = m1.row;
    w.col = m2.col;

    w.matrix = new double* [w.row];
    for (int i = 0; i < w.row; i++)
    {
        w.matrix[i] = new double[w.col];
        for (int j = 0; j < w.col; j++)
            w.matrix[i][j] = 0;
    }

    for (int i = 0; i < w.row; i++)
        for (int j = 0; j < w.col; j++)
            for (int k = 0; k < m2.row; k++)
                w.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];

    system("cls");

    cout << "A = " << endl;
    displayMatrix(m1);
    cout << endl;

    cout << "B = " << endl;
    displayMatrix(m2);
    cout << endl;

    color(12);
    cout << "A * B = " << endl;
    displayMatrix(w);
    color(7);

    for (int i = 0; i < m1.row; i++)
    {
        delete[] m1.matrix[i];
        delete[] w.matrix[i];
    }

    for (int i = 0; i < m2.row; i++)
        delete[] m2.matrix[i];

    delete[] m1.matrix;
    delete[] m2.matrix;
    delete[] w.matrix;

    count_f = 0;

    cout << endl;
    what_next();
}

void power(Matrix m)
{
    if (m.row != m.col)
    {
        cout << "Macierz musi byc kwadratowa!" << endl;
        count_f = 0;
        cout << endl;
        what_next();
        return;
    }

    Matrix w{};
    w.row = m.row;
    w.col = m.col;

    w.matrix = new double* [w.row];
    for (int i = 0; i < w.row; i++)
        w.matrix[i] = new double[w.col];

    Matrix h{};
    h.row = m.row;
    h.col = m.col;

    h.matrix = new double* [h.row];
    for (int i = 0; i < h.row; i++)
    {
        h.matrix[i] = new double[h.col];
        for (int j = 0; j < h.col; j++)
            h.matrix[i][j] = m.matrix[i][j];
    }

    int pow_;
    cout << "Podaj potege: ";
    cin >> pow_;

    for (int p = 1; p < pow_; p++)
    {
        for (int i = 0; i < w.row; i++)
            for (int j = 0; j < w.col; j++)
            {
                w.matrix[i][j] = 0;

                for (int k = 0; k < m.row; k++)
                    w.matrix[i][j] += h.matrix[i][k] * m.matrix[k][j];
            }

        for (int i = 0; i < w.row; i++)
            for (int j = 0; j < w.col; j++)
                h.matrix[i][j] = w.matrix[i][j];
    }

    system("cls");

    cout << "A = " << endl;
    displayMatrix(m);
    cout << endl;

    color(12);
    cout << "A^" << pow_ << " = " << endl;
    displayMatrix(w);
    color(7);

    for (int i = 0; i < m.row; i++)
    {
        delete[] m.matrix[i];
        delete[] w.matrix[i];
    }

    delete[] m.matrix;
    delete[] w.matrix;

    count_f = 0;

    cout << endl;
    what_next();
}

void transpose(Matrix m)
{
    Matrix w{};
    w.row = m.col;
    w.col = m.row;

    w.matrix = new double* [w.row];
    for (int i = 0; i < w.row; i++)
    {
        w.matrix[i] = new double[w.col];
        for (int j = 0; j < w.col; j++)
            w.matrix[i][j] = m.matrix[j][i];
    }

    system("cls");

    cout << "A = " << endl;
    displayMatrix(m);
    cout << endl;

    color(12);
    cout << "A^T = " << endl;
    displayMatrix(w);
    color(7);

    for (int i = 0; i < m.row; i++)
        delete[] m.matrix[i];

    for (int i = 0; i < w.row; i++)
        delete[] w.matrix[i];

    delete[] m.matrix;
    delete[] w.matrix;

    count_f = 0;

    cout << endl;
    what_next();
}

void determinant(Matrix m)
{
    if (m.row != m.col)
    {
        cout << "Macierz musi byc kwadratowa!" << endl;
        count_f = 0;
        cout << endl;
        what_next();
        return;
    }

    system("cls");

    cout << "A = " << endl;
    displayMatrix(m);
    cout << endl;

    color(12);
    cout << "detA = " << laplace(m) << endl;
    color(7);

    for (int i = 0; i < m.row; i++)
        delete[] m.matrix[i];

    delete[] m.matrix;

    count_f = 0;

    cout << endl;
    what_next();
}

double laplace(Matrix m)
{
    double wynik{};

    if (m.row <= 2)
        return m.matrix[0][0] * (m.row > 1 ? m.matrix[1][1] : 1) - (m.row > 1 ? m.matrix[0][1] * m.matrix[1][0] : 0);
    else
    {
        Matrix w{};
        w.row = m.row - 1;
        w.col = m.col - 1;

        int row_m;
        int row_w;

        w.matrix = new double* [w.row];
        for (int i = 0; i < w.row; i++)
            w.matrix[i] = new double[w.col];

        for (int row_act = 0; row_act < m.row; row_act++)
        {
            for (row_m = 0, row_w = 0; row_w < w.row; row_m++, row_w++)
            {
                row_m += (row_m == row_act ? 1 : 0);

                for (int colm = 0; colm < w.col; colm++)
                    w.matrix[row_w][colm] = m.matrix[row_m][colm + 1];
            }

            wynik += (double)m.matrix[row_act][0] * (double)pow(-1.0, row_act + 2.0) * laplace(w); //rekurencja
        }

        for (int i = 0; i < w.row; i++)
            delete[] w.matrix[i];

        delete[] w.matrix;
    }

    return wynik;
}

void inverse(Matrix m)
{
    int i, j;
    bool ver;

    if (m.row != m.col)
    {
        cout << "Macierz musi byc kwadratowa!" << endl;
        count_f = 0;
        cout << endl;
        what_next();
        return;
    }

    Matrix copy{};
    copy.row = m.row;
    copy.col = m.col;

    copy.matrix = new double* [copy.row];
    for (i = 0; i < copy.row; i++)
    {
        copy.matrix[i] = new double[copy.col];
        for (int j = 0; j < copy.col; j++)
            copy.matrix[i][j] = m.matrix[i][j];
    }

    Matrix w{};
    w.row = m.row;
    w.col = m.col;

    w.matrix = new double* [w.row];
    for (i = 0; i < w.row; i++)
        w.matrix[i] = new double[w.col];

    if (LUdist(m))
    {
        for (i = 0; i < w.row; i++)
        {
            for (j = 0; j < w.col; j++)
                w.matrix[i][j] = 0;

            w.matrix[i][i] = 1;
        }

        ver = true;
        for (i = 0; i < m.row; i++)
            if (!LUsolve(i, m, w))
            {
                ver = false;
                break;
            }
    }
    else
        ver = false;

    if (ver)
    {
        system("cls");

        cout << "A = " << endl;
        displayMatrix(copy);
        cout << endl;

        color(12);
        cout << "A^(-1) = " << endl;
        displayMatrix(w);
        color(7);

        for (i = 0; i < m.row; i++)
        {
            delete[] m.matrix[i];
            delete[] w.matrix[i];
        }
        delete[] m.matrix;
        delete[] w.matrix;

        count_f = 0;

        cout << endl;
        what_next();
    }
    else
    {
        for (i = 0; i < m.row; i++)
        {
            delete[] m.matrix[i];
            delete[] w.matrix[i];
        }
        delete[] m.matrix;
        delete[] w.matrix;

        count_f = 0;

        cout << "Macierz jest nieodwracalna." << endl;
        cout << endl;
        what_next();
    }
}

bool LUdist(Matrix m) //rozklad LU macierzy m
{
    for (int k = 0; k < m.row - 1; k++)
    {
        if (fabs(m.matrix[k][k]) < eps) //jezeli mniejsze od otoczenia 0 - blad - dzielnik 0
            return false;

        for (int i = k + 1; i < m.row; i++)
            m.matrix[i][k] /= m.matrix[k][k];

        for (int i = k + 1; i < m.row; i++)
            for (int j = k + 1; j < m.row; j++)
                m.matrix[i][j] -= m.matrix[i][k] * m.matrix[k][j];
    }

    return true;
}

bool LUsolve(int k, Matrix m, Matrix w) //wyznaczenie wektora X na podstawie macierzy m i w[i]
{
    double s;

    for (int i = 1; i < m.row; i++)
    {
        s = 0;

        for (int j = 0; j < i; j++)
            s += m.matrix[i][j] * w.matrix[j][k];

        w.matrix[i][k] -= s;
    }

    if (fabs(m.matrix[m.row - 1][m.row - 1]) < eps)
        return false;

    w.matrix[m.row - 1][k] /= m.matrix[m.row - 1][m.row - 1];

    for (int i = m.row - 2; i >= 0; i--)
    {
        s = 0;

        for (int j = i + 1; j < m.row; j++)
            s += m.matrix[i][j] * w.matrix[j][k];

        if (fabs(m.matrix[i][i]) < eps)
            return false;

        w.matrix[i][k] = (w.matrix[i][k] - s) / m.matrix[i][i];
    }

    return true;
}

void learn()
{
    setlocale(LC_ALL, "pl_PL"); //polskie znaki

    string str = "PODSTAWOWE DZIA£ANIA NA MACIERZACH\n\n";
    str += "DODAWANIE (ODEJMOWANIE) MACIERZY jest wykonalne dla macierzy o tych samych wymiarach. Polega ono\nna dodawaniu (odejmowaniu) odpowiednich elementów (elementy o tych samych wspó³rzêdnych) dwóch macierzy.\n\n";
    str += "MNO¯ENIE MACIERZY PRZEZ SKALAR polega na pomno¿eniu ka¿dego elementu macierzy przez dan¹ liczbê.\n\n";
    str += "MNO¯ENIE MACIERZY A i B jest mo¿liwe je¿eli macierz A ma tyle samo kolumn co macierz B ma wierszy.\nIloczynem macierzy A = [aij]n x p przez macierz B = [bij] p x m nazywamy macierz C = [cij]n x m tak¹, ¿e:\ncij = ai1 * b1j + ai2 * b2j + ... + aip * bpj\n\n";
    str += "POTÊGOWANIE MACIERZY dotyczy macierzy kwadratowych. Je¿eli macierz A podnosimy do k-tej potêgi, to w przemna¿amy\npodan¹ macierz przez sam¹ siebie k-krotnie.\n\n";
    str += "MACIERZ TRANSPONOWANA A^T wzglêdem macierzy A to macierz powsta³a z macierzy A przez przestawienie\nw niej wierszy na miejsce kolumn z zachowaniem kolejnoœci.\n\n";
    str += "WYZNACZNIK MACIERZY jest to liczba rzeczywista przyporz¹dkowana macierzy kwadratowej. Wyznacznik oznaczamy\nsymbolicznie detA.\n";
    str += "Je¿li macierz jest stopnia n = 1, to jej wyznacznik detA = a11.\n";
    str += "Je¿li stopieñ macierzy jest wiêkszy ni¿ 1, to jej wyznacznik obliczamy np. wed³ug rozwiniêcia Laplace'a.\n\n";
    str += "MACIERZ ODWROTNA jest okreœlona tylko dla macierzy kwadratowych, których wyznacznik jest niezerowy.\nMacierz odwrotna A^(-1) do macierzy kwadratowej A to macierz spe³niaj¹ca równanie\nA^(-1) * A = A * A^(-1) = I, gdzie I to macierz jednostkowa.";
    cout << str << endl << endl;

    int Set[] = { 7, 7, 7 };
    int counter = 2;
    char key{};

    COORD pos;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    pos = GetConsoleCursorPosition(hStdout);
    int h = static_cast<int>(pos.Y);

    for (int i = 0;;)
    {
        gotoxy(0, h);
        color(Set[0]);
        cout << "POBIERZ";

        gotoxy(0, h + 1);
        color(Set[1]);
        cout << "POWROT DO MENU";

        gotoxy(0, h + 2);
        color(Set[2]);
        cout << "WYJDZ";

        ShowConsoleCursor(false);
        key = _getch();

        if (key == 72 && counter >= 2 && counter <= 3)
            counter--;
        else if (key == 80 && counter >= 1 && counter <= 2)
            counter++;
        else if (key == '\r')
        {
            system("cls");
            ShowConsoleCursor(true);
            color(7);

            switch (counter)
            {
            case 1:
                download(str);
                return;
                break;
            case 2:
                menu();
                return;
                break;
            case 3:
                return;
                break;
            default:
                break;
            }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;

        if (counter == 1)
            Set[0] = 12;
        else if (counter == 2)
            Set[1] = 12;
        else if (counter == 3)
            Set[2] = 12;
    }
}

void download(string s)
{
    fstream plik("../DzialaniaNaMacierzach.txt", ios::out);

    if (plik.is_open())
    {
        plik << s;

        plik.close();

        cout << "Pobieranie zakonczone powodzeniem." << endl;
    }
    else
        cout << "Pobieranie sie nie powiodlo." << endl;

    cout << endl;
    what_next();
}

void what_next()
{
    int Set[] = { 7, 7, 7 };
    int counter = 2;
    char key{};

    COORD pos;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    pos = GetConsoleCursorPosition(hStdout);
    int h = static_cast<int>(pos.Y);

    for (int i = 0;;)
    {
        gotoxy(0, h);
        color(Set[0]);
        cout << "PRZEJDZ DO KALKULATORA";

        gotoxy(0, h + 1);
        color(Set[1]);
        cout << "POWROT DO MENU";

        gotoxy(0, h + 2);
        color(Set[2]);
        cout << "WYJDZ";

        ShowConsoleCursor(false);
        key = _getch();

        if (key == 72 && counter >= 2 && counter <= 3)
            counter--;
        else if (key == 80 && counter >= 1 && counter <= 2)
            counter++;
        else if (key == '\r')
        {
            system("cls");
            ShowConsoleCursor(true);
            color(7);

            switch (counter)
            {
            case 1:
                calculator();
                return;
                break;
            case 2:
                menu();
                return;
                break;
            case 3:
                return;
                break;
            default:
                break;
            }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;

        if (counter == 1)
            Set[0] = 12;
        else if (counter == 2)
            Set[1] = 12;
        else if (counter == 3)
            Set[2] = 12;
    }
}