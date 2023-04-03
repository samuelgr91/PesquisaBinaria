# ifndef buscabinaria_h
# define buscabinaria_h



typedef struct {
  int chave;
} TRegistro;

typedef struct No {
  TRegistro *v;
  int cont, max;
} TDicionario;


TDicionario* TDicionarioInicia (int);

void lerMalha (TDicionario *t,int tamanho);

void TDicionariolibera(TDicionario **t);

int TDicionario_Binario(TDicionario *t,int,int,int x);

void mensagem(TDicionario *t,int codigo,int resultado,int posicao);

void naoexiste(int codigo);

int TDicionario_Find(TDicionario *t,int codigo);

# endif
