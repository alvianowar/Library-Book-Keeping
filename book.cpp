#include <iostream>
#include <fstream>

using namespace std;
struct Book
{
    string name;
    string genre;
    string writerName;
};
int Greetings();
void BookList(Book b);
void Adminship();
void AddingBook(Book b);
//void Search(ifstream a);
int main()
{
    Adminship();
    return 0;
}
int Greetings()
{
    cout <<"Hello" << endl;
    cout << "Waiting for your command master. Or Do you prefer oniii-chan?."<<endl;
    char c;
    cout << "Press y if you want me to call oniii-chan." << endl;
    cin >> c;
    if(c == 'y')
    {
        cout << "Yes Oniii-chan." << endl;
        cout << "Untill now you have only written how to print a booklist from a file. So I'll present that to you." << endl;
        cout << "Come back again oniii-chan. We will write more function together." << endl <<  endl;
        cout << "Enter 1 to Print BookList.\n";
        cout << "Enter 2 to Print Specific Genre.\n";
        cout << "Entre 3 if you want to add Book.\n";
        int in;
        cin >> in;
        Book a;
        switch (in) {
            case 1:
                BookList(a);
                break;
            case 2:
                cout << " Idk yet. Shut the fuck up you baka ass Bitch. I have a life." << endl;
            case 3:
                AddingBook(a);
                break;
        }
    }
    else if(c == 'n')
    {
        cout << "Oniii-chan you have other woman in your life? How could you. You pathetic loser. I'm going to delete myself." << endl;
        ofstream input;
        input.open("book.cpp");
        string a = "Funk YOU";
        input << a;
        input.close();
        return 0;
    }
    return 1;
}
//void Search(ifstream a)
//{
//
//}
void BookList(Book b)
{
    ifstream inputFile;
    inputFile.open("booklist.txt", ios::binary);
    if(inputFile.fail())
        perror("booklist.txt");
    string input;
    do
    {
        getline(inputFile, input);
        b.name = input;
        getline(inputFile, input);
        b.genre = input;
        getline(inputFile, input);
        b.writerName = input;
        cout << "Name: " << b.name << "\nGenre: " << b.genre <<"\nWriter: " << b.writerName << endl << endl;
    } while(getline(inputFile,input));
    inputFile.close();
}
void Adminship()
{
    cout <<"Do you want to be my master? Or do you wanna login as a guest? Press Y to be mah master." << endl;
    char c;
    cin >> c;
    if(c == 'y')
    {
        string pswd;
        cout << "Please Enter the password.";
        cin >> pswd;
        if(pswd == "AAnowar")
            Greetings();
        else
            cout <<"You are not my master. You lying piece of garbage." << endl;
    }
    if(c == 'n')
    {
        cout << "Hello user. My master is a lazy piece of shit. He didn't wrote anything intersting in the code yet. So come back later. Gomen Gomen User-kun. " << endl;
    }
}
void AddingBook(Book a)
{
    cin.ignore();
    ofstream bookfile;
    cout <<"Enter name of the book: ";
    getline(cin, a.name);
    cout <<"\nEnter the genre name: ";
    getline(cin, a.genre);
    cout <<"\nEnter the writer name: ";
    getline(cin, a.writerName);
    string c = a.genre + ".txt";
    bookfile.open(c,ios::app);
    bookfile << a.name +"\n";
    bookfile << a.genre+"\n";
    bookfile << a.writerName+"\n";
    bookfile.close();
}
