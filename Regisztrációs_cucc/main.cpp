#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string line;
fstream MyFile;
char loginreg;
string loginname;
string loginpass;
bool isNameOKLogin = false;
bool isPassOKLogin = false;

string regname;
string regpass;
bool isNameValid = false;
bool isPassValid = false;

void LoginName(){
MyFile.open("Accounts.txt");
try{
do{
    getline(MyFile, line);
    if(MyFile.eof()){
        throw 1;
    }
} while(loginname != line);
}
catch(int h){
    cout << "hiba: "<< h;
    MyFile.close();
    isNameOKLogin = false;
}
if (line == loginname){
    isNameOKLogin = true;
}
}

void LoginPass(){
try{
getline(MyFile, line);
if(line != loginpass){
    throw 2;
    isPassOKLogin = false;
}
if(line == loginpass){
    isPassOKLogin = true;
    cout << "Udvozoljuk!";
    MyFile.close();
}
}
catch(int h){
    cout << "hiba: " << h;
    MyFile.close();

}
}

void RegistName(){
try{
MyFile.open("Accounts.txt");
do{
    getline(MyFile, line);
    if(line == regname){
        throw 3;
    }
}while(MyFile.eof()== false);
}
catch (int h){
    cout << "hiba: " << h << " (ez a nev foglalt!)\n";
}
if(line != regname){
    MyFile.close();
    MyFile.open("Accounts.txt", ios::app | ios::ate);
    MyFile << regname <<"\n";
    isNameValid = true;
    MyFile.close();
}
}

void RegistPass(){
MyFile.open("Accounts.txt");
try{
do{
    getline(MyFile, line);
    if(line == regpass){
        throw 4;
    }
}while(MyFile.eof() == false);
}catch(int h){
    cout << "hiba: " << h << "(ez a jelszo foglalt!)\n";
    MyFile.close();
}
if(line != regpass){
    MyFile.close();
    MyFile.open("Accounts.txt", ios::ate | ios::app);
    MyFile << regpass << "\n";
}
}

int main()
{
    cout << "Belep vagy regisztral?" << "\n";
    cout << "Belepes (L), regisztracio (R)" << "\n\n";
    cin >> loginreg;
    if(loginreg == 'l'){
        cout << "Adja meg felhasznalonevet!\n";
        cin >> loginname;
        LoginName();
        if(isNameOKLogin == true){
            cout << "Adja meg jelszavat!\n";
            cin >> loginpass;
            LoginPass();
    }
    }
    if(loginreg == 'r'){
        cout << "Adja meg felhasznalonevet!\n";
        cin >>regname;
        RegistName();
        if(isNameValid == true){
            cout << "Adja meg jelszavat!\n";
            cin >> regpass;
            RegistPass();
        }
    }
    cout << "\nHello world!" << endl;
    return 0;
}
