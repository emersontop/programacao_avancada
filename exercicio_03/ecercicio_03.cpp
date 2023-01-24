#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

class Aluno{
    public:
        string nome;
        float lista_notas[3];
        int numero_de_notas =3;
        Aluno(string nome_aluno) : nome(nome_aluno){}
        void add_nota();
        void media();
};

void Aluno::add_nota(){
    for(int i=0;i<numero_de_notas;i++){
        cout<<"digite a nota "<<(i+1)<<" do aluno "<< nome <<endl;
        cin>> lista_notas[i];
    }
};

void Aluno::media(){
    float media =0;
    for(int i=0;i<numero_de_notas;i++){
        media += lista_notas[i];
    }
    media = media/numero_de_notas;
    cout << "A média do aluno "<< nome << "e : "<< media <<endl;
}

int quantidade_de_alunos(){
    int quantidadedealunos;
    cout << "Digite a quantidade de alunos que voce deseja cadastrar"<<endl;
    cin >> quantidadedealunos;
    return quantidadedealunos;
}

int main(){ 
    int numero_de_alunos;
    numero_de_alunos = quantidade_de_alunos();
    
    return 0;
}