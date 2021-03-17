#include <iostream>
#include <stdio.h>
#include <locale.h>

using namespace std;

class Kompleks{
    public:
        float deistv, mnim;
        string name;
    public:
        Kompleks();
        Kompleks(float, float, string);
        ~Kompleks();

        float getDeistv(){return deistv;};
        float getMnim(){return mnim;};

        void setDeistv(float a){ deistv = a; };
        void setMnim(float a){ mnim = a; };

        void Print(){
            if (mnim == 0)
                cout << "Комплексное число " << name << ": " << deistv << endl;
            else
                if (mnim == 1)
                    cout << "Комплексное число " << name << ": " << deistv << " + i" << endl;
                else
                    cout << "Комплексное число " << name << ": " << deistv << " + " << mnim << "i" << endl;
        };

        void Scan(){
            int x;

            cout << "Введите действительное значение: ";
            cin >> x;
            deistv = x;

            cout << "Введите мнимое значение: ";
            cin >> x;
            mnim = x;
        };
};

Kompleks :: Kompleks(){
    deistv = 1;
    mnim = 1;
    name = "NoName";
    cout << "Конструктор без параметров для " << name << " ( " << this << " )" << " сработал!" << endl << endl;
}

Kompleks :: Kompleks(float a, float b, string n){
    deistv = a;
    mnim = b;
    name = n;
    cout << "Конструктор с параметрами для " << name << " ( " << this << " )" << " сработал!" << endl << endl;
}

Kompleks :: ~Kompleks(){
    cout << "Диструктор для " << name << " ( " << this << " )" << " сработал!" << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int x = 1;
    Kompleks a/*, b(1,1, "ЧислоБ")*/;
    system ("pause");

    while (x){
        system ("cls");

        cout << "\t\tМеню" << endl;
        cout << "1) Вывод комплексного числа" << endl;
        cout << "2) Ввод значений действительного числа" << endl;


        cout << "Введите номер операции: ";
        cin >> x;

        switch (x){
            case 1:
                system ("cls");
                a.Print();
                system("pause");
                break;
            case 2:
                system ("cls");
                a.Scan();
                system("pause");
                break;
        }
    };

    return 0;
}
