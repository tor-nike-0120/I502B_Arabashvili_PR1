#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <math.h>

using namespace std;

class Kompleks{
    public:
        float deistv, mnim;
        string name;
    public:
        Kompleks();
        Kompleks(float, float, string);
        ~Kompleks();

        Kompleks(const Kompleks &other){
            setDeistv(other.deistv);
            setMnim(other.mnim);
        }

        float getDeistv(){return deistv;}
        float getMnim(){return mnim;}
        string getName(){return name;}

        void setDeistv(float a){ deistv = a; }
        void setMnim(float a){ mnim = a; }

        void Print(){
            if (mnim < 0)
                cout << /*"Kompleksnoe chislo " <<*/ name << " = " << deistv << mnim << "i" << endl;
            else
                if (mnim == 0)
                    cout << /*"Kompleksnoe chislo " <<*/ name << " = " << deistv << endl;
                else
                    if (mnim == 1)
                        cout << /*"Комплексное число " <<*/ name << " = " << deistv << "+i" << endl;
                    else
                        cout << /*"Комплексное число " <<*/ name << " = " << deistv << "+" << mnim << "i" << endl;
        }

        void Scan(){
            int x;

            cout << "Vvedite deistvitelnoe znachenie: ";
            cin >> x;
            deistv = x;

            cout << "Vvedite mnimoe znachenie: ";
            cin >> x;
            mnim = x;
        }

        float Modul(){return sqrt(deistv * deistv + mnim * mnim);}

        void operator * (const Kompleks &other){
            this->deistv = this->deistv * other.deistv - this->mnim * other.mnim;
            this->mnim = this->deistv * other.mnim + this->mnim * other.deistv;
        }

        void operator * (float x){
            this->deistv *= x;
            this->mnim *= x;
        }

        void operator + (const Kompleks &other){
            this->deistv = this->deistv + other.deistv;
            this->mnim = other.mnim + this->mnim;
        }

        void operator + (float x){
            this->deistv += x;
        }

        void operator -= (const Kompleks &other){
            this->deistv = this->deistv - other.deistv;
            this->mnim = this->mnim - other.mnim;
        }
};

Kompleks :: Kompleks(){
    deistv = 1;
    mnim = 1;
    name = "NoName";
    cout << "Konstruktor bez parametrov dlya " << name << " ( " << this << " )" << " srabotal!" << endl << endl;
}

Kompleks :: Kompleks(float a, float b, string n){
    deistv = a;
    mnim = b;
    name = n;
    cout << "Konstruktor s parametrami dlya " << name << " ( " << this << " )" << " srabotal!" << endl << endl;
}

Kompleks :: ~Kompleks(){
    cout << "Destruktor dlya " << name << " ( " << this << " )" << " srabotal!" << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int x = 1, p;
    Kompleks a, b(1, 1, "Kompl 2");
    system ("pause");

    while (x){
        system ("cls");

        cout << "\t\tMenu" << endl;
        cout << "1) Vyvod kompleksnogo chisla" << endl;
        cout << "2) Vvod kompleksnogo chisla" << endl;
        cout << "3) Vyvod deistvitelnoi chasti" << endl;
        cout << "4) Vyvod mnimoi chasti" << endl;
        cout << "5) Vvod deistvitelnoi chasti" << endl;
        cout << "6) Vvod mnimoi chasti" << endl;
        cout << "7) Modul" << endl;
        cout << "8) KCH * KCH" << endl;
        cout << "9) KCH * CH" << endl;
        cout << "10) KCH + KCH" << endl;
        cout << "11) KCH + CH" << endl;
        cout << "12) KCH - KCH" << endl;
        cout << endl << "0) Vihod" << endl;

        cout << "Vvedite nomer operatsii: ";
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
            case 3:
                system ("cls");
                cout << "Deistvitelnaya chast: " << a.getDeistv() << endl;
                system("pause");
                break;
            case 4:
                system ("cls");
                cout << "Mnimaya chast: " << a.getMnim() << "i" << endl;
                system("pause");
                break;
            case 5:
                system ("cls");
                cout << "Vvedite deistvitelnuyu chast: ";
                cin >> p;
                a.setDeistv(p);
                break;
            case 6:
                system ("cls");
                cout << "Vvedite mnimuyu chast: ";
                cin >> p;
                a.setMnim(p);
                break;
            case 7:
                system ("cls");
                cout << "Modul: " << a.Modul() << endl;
                system ("pause");
                break;
            case 8:
                system ("cls");
                cout << "Dlya " << b.getName() << endl;
                b.Scan();
                system ("cls");
                a.Print();
                b.Print();
                cout << a.getName() << " * " << b.getName() << ": " << endl;
                a * b;
                a.Print();
                system ("pause");
                break;
            case 9:
                system ("cls");
                cout << "Vvedite chislo: ";
                cin >> p;
                system ("cls");
                cout << a.getName() << " * " << p << ": " << endl;
                a * p;
                a.Print();
                system ("pause");
                break;
            case 10:
                system ("cls");
                cout << "Dlya " << b.getName() << endl;
                b.Scan();
                system ("cls");
                a.Print();
                b.Print();
                cout << a.getName() << " + " << b.getName() << ": " << endl;
                a + b;
                a.Print();
                system ("pause");
                break;
            case 11:
                system ("cls");
                cout << "Vvedite chislo: ";
                cin >> p;
                system ("cls");
                cout << a.getName() << " + " << p << ": " << endl;
                a + p;
                a.Print();
                system ("pause");
                break;
            case 12:
                system ("cls");
                cout << "Dlya " << b.getName() << endl;
                b.Scan();
                system ("cls");
                a.Print();
                b.Print();
                cout << a.getName() << " - " << b.getName() << ": " << endl;
                a -= b;
                a.Print();
                system ("pause");
                break;
        }
    };

    system ("cls");

    return 0;
}
