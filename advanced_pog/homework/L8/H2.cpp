#include<bits/stdc++.h>
#include<Windows.h>
#include<time.h>
using namespace std;

class Screen{
    int length;
    int width;
public:
    Screen(int l, int w){ length = l; width = w; }
    void display(char * message, int len);
};

void Screen:: display(char * message, int len){
    int col = 0, line = 0;
    for(int i = 0; i < len-1; i++){
        printf("%c", message[i]);
        if(++col == width){
            printf("\n");
            col = 0;
            if(++line == width){
                printf("\n\n\n");
                line = 0;
            }
        }
    }
}

class Mainboard{
    int delay;
public:
    Mainboard(int d){ delay = d; }
    void encode(char * message, int * code, int len);
    void decode(char * message, int * code, int len);
};

void Mainboard:: encode(char * message, int *code, int len){
    for(int i = 0; i < len; i++){
        if(message[i] == ' ') code[i] = 26;
        else code[i] = message[i] - 'a';
        Sleep(delay);
    }
    code[len] = -1;
}

void Mainboard:: decode(char * message, int *code, int len){
    message = new char[len+1];
    for(int i = 0; i < len; i++){
        if(code[i] == 26) message[i] = ' ';
        else message[i] = ('a' + code[i]);
        Sleep(delay);
    }
    message[len] = '\0';
}

int globalMessage[10010];

class TestPhone{
protected:
    Screen screen;
    Mainboard mainboard;
public:
    TestPhone(int l, int w, int d): screen(l, w), mainboard(d) {}
    void sendMessage();
    void receiveMessage();
};

void TestPhone:: sendMessage(){
    string mes;
    getline(cin, mes);
    char * message = mes.c_str();
    int len = mes.length();
    mainboard.encode(message, globalMessage, len);
}

void TestPhone:: receiveMessage(){
    char *mes = NULL;
    int len = 0;
    for(int i = 0; globalMessage[i] != -1; i++) len++;
    mainboard.decode(mes, globalMessage, len);
    screen.display(mes, len);
}

class Release: public TestPhone{
public:
    Release(int l, int w, int d): TestPhone(l, w, d) {};
    void dateAndTime();
};

void Release:: dateAndTime(){
    char system_time[200];
    time_t now_time = time(NULL);
    strcpy(system_time, asctime(localtime(&now_time)));
    int len = 0;
    for(int i = 0; system_time[i]; i++) len++;
    screen.display(system_time, len);
}