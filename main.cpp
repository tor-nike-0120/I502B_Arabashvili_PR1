#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <math.h>

using namespace std;

class Kompleks{
        double deistv, mnim;
    public:
        Kompleks();
        Kompleks(double, double);
        ~Kompleks();

        Kompleks(const Kompleks &other){
            setDeistv(other.deistv);
            setMnim(other.mnim);
        }

        double getDeistv(){return deistv;}
        double getMnim(){return mnim;}

        void setDeistv(double a){ deistv = a; }
        void setMnim(double a){ mnim = a; }

        void Print(){
            if (mnim < 0)
                cout <<  deistv << mnim << "i";
            else
                if (mnim == 0)
                    cout << deistv;
                else
                    if (mnim == 1)
                        cout << deistv << "+i";
                    else
                        cout << deistv << "+" << mnim << "i";
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

        double Modul(){return sqrt(deistv * deistv + mnim * mnim);}

        Kompleks operator * (const Kompleks &other){
            Kompleks w;
            w.deistv = this->deistv * other.deistv - this->mnim * other.mnim;
            w.mnim = this->deistv * other.mnim + this->mnim * other.deistv;
            return w;
        }

        Kompleks operator * (double x){
            Kompleks w;
            w.deistv = this->deistv * x;
            w.mnim = this->mnim * x;
            return w;
        }

        Kompleks operator + (const Kompleks &other){
            Kompleks w;
            w.deistv = this->deistv + other.deistv;
            w.mnim = other.mnim + this->mnim;
            return w;
        }

        Kompleks operator + (double x){
            Kompleks w;
            w.deistv = this->deistv + x;
            w.mnim = this->mnim;
            return w;
        }

        Kompleks operator -= (const Kompleks &other){
            this->deistv = this->deistv - other.deistv;
            this->mnim = this->mnim - other.mnim;
            return Kompleks(*this);
        }
};

Kompleks :: Kompleks(){
    deistv = 1;
    mnim = 1;
    cout << "Konstruktor bez parametrov dlya ( " << this << " )" << " srabotal!" << endl << endl;
}

Kompleks :: Kompleks(double a, double b){
    deistv = a;
    mnim = b;
    cout << "Konstruktor s parametrami dlya ( " << this << " )" << " srabotal!" << endl << endl;
}

Kompleks :: ~Kompleks(){
    cout << "Destruktor dlya ( " << this << " )" << " srabotal!" << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int x = 1, p;
    Kompleks a, b(1, 1), q;
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
        cout << "12) KCH -= KCH" << endl;
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
                b.Scan();
                system ("cls");
                q = a * b;
                a.Print();
                cout << " * ";
                b.Print();
                cout << " = ";
                q.Print();
                cout << endl;
                system ("pause");
                break;
            case 9:
                system ("cls");
                cout << "Vvedite chislo: ";
                cin >> p;
                system ("cls");
                q = a * p;
                a.Print();
                cout << " * " << p << " = " << endl;
                q.Print();
                cout << endl;
                system ("pause");
                break;
            case 10:
                system ("cls");
                b.Scan();
                system ("cls");
                q = a + b;
                a.Print();
                cout << " + ";
                b.Print();
                cout << " = ";
                q.Print();
                cout << endl;
                system ("pause");
                break;
            case 11:
                system ("cls");
                cout << "Vvedite chislo: ";
                cin >> p;
                system ("cls");
                q = a + p;
                a.Print();
                cout << " + " << p << " = ";
                q.Print();
                cout << endl;
                system ("pause");
                break;
            case 12:
                system ("cls");
                b.Scan();
                system ("cls");
                a.Print();
                cout << " -= ";
                b.Print();
                cout << ": ";
                a -= b;
                a.Print();
                cout << endl;
                system ("pause");
                break;
        }
    };

    system ("cls");

    return 0;
}
