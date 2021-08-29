#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int year;
    array<double, 5> rating;
};

template <typename T>
T checkValue(T& x) {
    if(cin.fail()) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Âû ââåëè íåäîïóñòèìîå çíà÷åíèå. Ïîâòîðèòå ââîä.\n";
        
        cin >> x;
        return checkValue(x);
    } else {
        cin.ignore(32767, '\n');
        return x;
    }
}

void setStudent (vector<Student>& vect) {
    vect.erase(vect.begin(), vect.end());
    
    system("cls");
    
    int how_many;
    cout << "Ñêîëüêî ñòóäåíòîâ âû õîòèòå ââåñòè? ";
    cin >> how_many;
    checkValue(how_many);
    
    system("cls");
    
    auto rating = [&](int &i, Student& st) { //ëÿìáäà äëÿ âûâîäà ìàññèâà èíòîâ èç student
        cout << "Ââåäèòå îöåíêè ñòóäåíòà ïî 1 ÷èñëó çà ðàç:\n";
        for(int it = 0; it < st.rating.size(); it++) {
            cin >> st.rating[it];
            checkValue(st.rating[it]);
        }
    };
    
    for(int i = 0; i < how_many; i++) { //ââîä äàííûõ â ñòðóêòóðó è çàïèñ ñòðóêòóðû â ìàññèâ
        Student st;
        cout << "Ââåäèòå èìÿ ñòóäåíòà ¹" << i + 1 << ": ";
        cin >> st.name;
        cout << "Ââåäèòå, íà êàêîì êóðñå ó÷èòñÿ ñòóäåíò ¹" << i + 1 << ": ";
        cin >> st.year;
        checkValue(st.year);
        rating(i, st);
        vect.push_back(st);
        system("cls");
    }
    
    sort(vect.begin(), vect.end()); // ñîðòèðîâêà ìàññèâà ïîñëå ââîäà
}

void printStudents(vector<Student>& vect) {
    system("cls");
    
    auto rating = [&](int& i) {
        for(int it = 0; it < vect[i].rating.size(); it++) {
            cout << vect[i].rating[it] << " ";
        }
        cout << endl;
    };
    
    cout << "Èìÿ\tÊóðñ\tÎöåíêè\n";
    
    for(int i = 0; i < vect.size(); i++) {
        cout << vect[i].name << "\t" << vect[i].year << "\t\t";
        rating(i);
    }
    system("pause");
}

void topRatingStudents(vector<Student>& vect) {
    system("cls");
    
    double mid_rate = 0;
    
    for(int i = 0; i < vect.size(); i++) {
        mid_rate += (
            vect[i].rating[0] + 
            vect[i].rating[1] + 
            vect[i].rating[2] + 
            vect[i].rating[3] + 
            vect[i].rating[4]) / 5;
    }
    
    mid_rate /= vect.size();
    
    auto rating = [&](int& i) {
        for(int it = 0; it < vect[i].rating.size(); it++) {
            cout << vect[i].rating[it] << " ";
        }
        cout << endl;
    };
    
    int none = 0; //ñ÷¸ò÷èê äëÿ îïðåäåëåíèÿ íàëè÷èÿ ñòóäåíòà ñ îöåíêîé, ïðåâûøàþùåé ñðåäíèé áàëë
    
    for(int i = 0; i < vect.size(); i++) {
        if((vect[i].rating[0] + 
            vect[i].rating[1] + 
            vect[i].rating[2] + 
            vect[i].rating[3] + 
            vect[i].rating[4]) / 5 > mid_rate) {
                cout << vect[i].name << "\t" << vect[i].year << "\t";
                rating(i);
        } else {
            none++;
            
            if(none == vect.size()) {
                cout << "Íåò íè îäíîãî ñòóäåíòà, îöåíêè êîòîðîãî ïðåâûøàþò ñðåäíèé áàëë.\n";
            }
        }
    }
    
    system("pause");
}

bool operator < (Student& st1, Student& st2) {
    return st1.name < st2.name;;
}

int main() {
    vector<Student> stud;
    int x = 0;
    system("chcp 1251");
    bool key = true;
    
    while(key) {
        system("cls");
        
        cout << "\t\tÂàñ ïðèâåòñòâóåò ïðîãðàììà ó÷¸òà ñòóäåíòîâ.\n" <<
            "1) Ââåñòè ñòóäåíòîâ.\n" <<
            "2) Âûâåñòè âñåõ ñòóäåíòîâ.\n" <<
            "3) Âûâåñòè ñòóäåíòîâ ñ îöåíêîé, ïðåâûøàþùåé ñðåäíèé áàëë.\n" <<
            "4) Âûõîä.\n\n";
            
        cin >> x;
        
        checkValue(x);
        
        switch(x) {
            case 1: {setStudent(stud); break;}
            case 2: {printStudents(stud); break;}
            case 3: {topRatingStudents(stud); break;}
            case 4: {key = false; break;}
            default: {cout << "Ïîâòîðèòå ââîä.\n";}
        }
    }
}
