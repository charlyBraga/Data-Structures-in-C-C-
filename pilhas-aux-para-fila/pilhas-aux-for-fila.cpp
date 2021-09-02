#include <iostream>


struct No{
	char Chave;
	No* Lig;
};typedef No *Pilha;



using namespace std;


bool PilhaVazia(Pilha P){
	if (P == NULL)
		return true;
	return false;
}

void DestroiPilha(Pilha &P){
    while(!PilhaVazia(P)){
        Pilha Temp = P;
        P = P -> Lig;
        delete Temp;
    }
    P = NULL;
}

void Empilha (Pilha& P, char chave){
	No *Temp = new No;
	Temp->Chave = chave;
	Temp->Lig = P;
	P = Temp;
}
bool Desenfileira (Pilha& P)	{
	if (PilhaVazia(P))
		return false;
	No *Temp = P;
	P = P->Lig;
	delete Temp;
	return true;
}

void ImprimePilha(Pilha P){
	 if (PilhaVazia(P)){
	 	cout << endl << "Pilha vazia" << endl;
	 	return;
	 }
	 char chave;
	 cout << endl << "Chaves da Pilha: " << endl;
	 while(!PilhaVazia(P)){
	 	cout << P->Chave << " ";
	 	P = P->Lig;
    }
}


void Enfileira(Pilha &P1, Pilha P2, char chave){//Usando duas pilhas adicionais

    while(P1!=NULL){
        Empilha(P2,P1->Chave);
        Desenfileira(P1);
    }
    Empilha(P1,chave);

    while(P2!=NULL){
        Empilha(P1,P2->Chave);
        Desenfileira(P2);
    }
    cout<<endl;
}



///////////// MAIN //////////
int main(){
	int n;
    Pilha P1=NULL, P2=NULL;
    cout<<"++++ Exercicio: Utilizar duas pilhas para simular uma fila ++++";
    cout<<"\n\nOrdem de insercao: A, B, C, D";
	Enfileira(P1, P2, 'A');
    cout<<"\nEnfileira";
    ImprimePilha(P1);
	Enfileira(P1, P2, 'B');
    cout<<"\nEnfileira";
    ImprimePilha(P1);
	Enfileira(P1, P2, 'C');
    cout<<"\nEnfileira";
    ImprimePilha(P1);
	Enfileira(P1, P2, 'D');
    cout<<"\nEnfileira";
    ImprimePilha(P1);

    cout<<"\n\nDesenfileira";
    Desenfileira(P1);
	ImprimePilha(P1);

    DestroiPilha(P1);

    cout<<endl;
    return 0;
}
