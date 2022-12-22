#include <iostream>
#include <string>
#include <math.h>
#include "myfunctions.h"

using namespace std;

string requestString(){
    // vairaveis locais
    string text;

    cout << "Digite um angulo!" <<endl;
    cout << "EX01: > 30 se for em graus" <<endl;
    cout << "EX02: > 30.0 se for em radianos" <<endl;
    cout << "Valores com letras, espacos e/ou caracteres especiais serao considerados errados." <<endl;
    cin >> text;
    cout << "Voce digitou na funcao 1: " << text << endl;

    return text;
}

int analyseString(string text){
    //Variaveis
    bool caracter_errado;
    int tipo_de_ang;
    int conta_virg;
    int conta_ponto;
    string str_text;

    //iniciando as variaveis
    str_text = text;
    conta_ponto =0;
    conta_virg =0;

    //Analisando a string
    for (string::iterator it=str_text.begin(); it!=str_text.end(); ++it)
    {
        //Analisa se existe algum caracter errado
        if((*it!= '0' && *it!='1' && *it!='2' && *it!='3' && *it!='4' && *it!='5' && *it!='6' && *it!='7' && *it!='8' && *it!='9' && *it!='.' && *it!=','))
        {
            caracter_errado = true;
            //cout << "caracter errado" << endl;
        }

        //conta pontos
        if(*it=='.')
        {
            conta_ponto++;
        }
        //conta virgulas

        if(*it==',')
        {
            conta_virg++;
        }
    }

    // analisa ponto e virgula
    if(caracter_errado == false){
        if(conta_ponto>1 || conta_virg >1 || (conta_virg+conta_ponto) >1)
        {
            tipo_de_ang = 3; // Erro
            //cout << "ERRO! Virgula ou pontos errados" << endl;
        }
        if(conta_ponto == 1 && conta_virg == 0)
        {
            tipo_de_ang = 1;//dado float, angulo em radianos
            //cout << "Angulo em rad, ponto" << endl;
        }
        if(conta_ponto == 0 && conta_virg == 1)
        {
            tipo_de_ang = 1;//dado float, angulo em radianos
            cout << "Angulo em rad, virgula" << endl;
        }
        if(conta_ponto == 0 && conta_virg == 0)
        {
            tipo_de_ang = 0;//dado int, angulo em graus
            //cout << "Angulo em graus" << endl;
        }
    }
    else
    {
        tipo_de_ang = 3; // Erro
    }

    return tipo_de_ang;
}

void stringToAngle(string text, int &angle){
    int *p_angle = &angle;
    *p_angle = stoi(text);
}

void stringToAngle(string &text, float &angle){
    int i;
    string* p_str_text = &text;
    string str_text = text;
    float *p_angle = &angle;

    //corrigindo a variável text
    i=0;
    for (string::iterator it=str_text.begin(); it!=str_text.end(); ++it)
    {
        if(*it==',')
        {
            *p_str_text = str_text.replace(i,1,".");
        }

        i++;
    }

    *p_angle = stof(text);
}

void computeCosSin(int angle, float &cosValue, float &sinValue){
    //graus
    float *p_cosValue = &cosValue;
    float *p_sinValue = &sinValue;
    float angle_rad = (angle*3.14)/180;
    *p_cosValue =  sin(angle_rad);
    *p_sinValue = cos(angle_rad);
}

void computeCosSin2(float angle, float &cosValue, float &sinValue){
    //rad
    float *p_cosValue = &cosValue;
    float *p_sinValue = &sinValue;
    *p_cosValue =  sin(angle);
    *p_sinValue = cos(angle);
}