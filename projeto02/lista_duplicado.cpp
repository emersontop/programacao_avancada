#include <iostream>
#include <random>

using namespace std;

//Satus: fazendo
//UFPE - CTG
//Alunos: Sanclay, Emerson


class Node{

public:
  //Inicializando as variaveis
  //Valor>> Guarda o valor atribuido ao Node
  float valor; 
  //next eh um ponteiro de no e aponta para seu sucessor 
  Node* next;
  //next eh um ponteiro de no e aponta para seu antecessor
  Node* prev;

  //Construtor
  Node(float valorNovo){
    //Instancia um o valorNovo a variavel.
    valor = valorNovo;
    //next e prev recebem NULL. Como o Node inicialmente nao esta ligado a nenhum outro no eles nao apontam para nada.
    next = NULL;
    prev = NULL;

    //prints para mostrar que o Node foi criado e seu respectivo valor.
    cout<<"No criado"<<endl;
    cout<<"O valor do Node e: "<<valor<<endl;
  };
};


class List{

public:
  //Atributos

  //head é ponteiro da class Node. Na CLass lista, tem a função de apontar para ultimo no que foi inserido na lista.
  Node* head;

  //construtor
  List(){
    //O Construtur inicia o head como NULL. Serve para indicar que a lista esta vazia.
    head =NULL;
    cout<<"Lista foi criada"<<endl;
  };
  //Metodos

  //metodo insertNode insere um Node na lista com o valor passado a ele
  void insertNode (float novoValor);
  void printList();
  void printList2();
};

//metodo da classe lista para inserir um Node
void List::insertNode (float novoValor){

  //Um Node eh instanciado com o valor passado ao metodo. Eh precios alocar um memoria nova por ser uma variavel craida dentro da funcao
  Node* NodeAdicionado;
  NodeAdicionado = new Node(novoValor);
  cout<<"Vamos inserir o Node com o valor: "<< NodeAdicionado->valor<<endl;

  //Teste para saber se a lista esta vazia ou nao. Como head aponta para o ultimo valor adicionado, se nenhum valor foi adicionado, head eh nulo
  if(head == NULL){
    //Lista vazia
    cout<<"A Lista esta vazia"<<endl;
    
    //como a lista esta vazia os atributos next e prev da classe Node devem ser NULL
    NodeAdicionado->next = NULL;
    NodeAdicionado->prev = NULL;
    
    //head deve receber o endereco de memoria do Node que foi adicioando a lista. head sempre aponta para o ultimo Node adicionado
    head = NodeAdicionado;

    cout<<"O Node com o valor: "<< NodeAdicionado->valor<<" foi adicionado!"<<endl;
  }else{
    //Lista nao esta vazia
    cout<<"A lista nao esta vazia"<<endl;
    //Com a lista nao esta vazia, o head aponta para o ultimo adicionado. Esse Node sera o sucessor do no adicionado logo:
    NodeAdicionado->next = head;
    //cout<<"valor do proximo no: "<<NodeAdicionado->next->valor<<endl;

    //Como o Node adicionado é o ultimo elemento, ele nao tem sucesso, sendo assim o atributo prev tem valor null
    NodeAdicionado->prev = NULL;

    //Para manter a ligacao entre os Nodes, temos que atualizar o valor do atributo prev do penultimo node que foi adicionado
    //Para isso usamos:
    head->prev = NodeAdicionado;
    
    //para finalizar a insercao do node na lista ele o atributo head deve receber o endereco do Node adicionado
    head = NodeAdicionado;

    cout<<"O Node com o valor: "<< NodeAdicionado->valor<<" foi adicionado!"<<endl;
  }
};

void List::printList(){
  int i;
  int resposta;
  i=1;
  Node *startLista = head;
  while(head!=NULL){
    cout<<"Posicao: "<<i<<" valor do Node: "<<head->valor<<endl;
    head = head->next;
    i++;
    // cout<<"Deseja continuar"<<endl;
    // cin>>resposta;
  }
  head = startLista;
};

void List::printList2(){
  int i;
  int resposta;
  i=1;
  Node *startLista = head;
  while(head!=NULL){
    //cout<<"Posicao: "<<i<<" valor do Node: "<<head->valor<<endl;
    if(head->next==NULL){
      //cout<<"Entrou no if"<<endl;
      break;
    }
    head = head->next;
    i++;
    // cout<<"Deseja continuar"<<endl;
    // cin>>resposta;
  }
  while(i>0){
    cout<<"Posicao: "<<i<<" valor do Node: "<<head->valor<<endl;
    head = head->prev;
    i--;
  }
  head = startLista;
};

class Hashtable
{
public:

  // TO COMPLETE

};


int main(){

  std::default_random_engine generator;
  std::normal_distribution<float> distribution(500.0,100.0);

  // Create a list
  List l;

  // Number of elements to store
  int nbElements = 3;

  // Random number to save
  int number;

  // Fill the list
  for (int i = 0; i < nbElements; i ++)
  {
    // Generate a new random number
    number = distribution(generator);
    // Add a node to the list
    l.insertNode(number);

  }
  
  cout << "Original list" << endl;
  l.printList();
  
  // Remove the duplicates in the list
  // l.removeDuplicates();
  
  
  cout << "Modified list" << endl;
  l.printList();

  return 0;
}
