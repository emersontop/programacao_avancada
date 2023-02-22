===================================
ERROS GERAIS:
- (não aceita valores de entrada amiores que 9): {corrigido agora aceita}
- (obstaculo fora do ambiente ou em cima do robô)

====================================
POSSIVEIS ERROS NA ENTRADA DE DADOS DO ARQUIVO:
- (sequencia de virgulas): ,,,,,,
- (espaços vazios): , ,     ,   ,
- (caracter invalido): letras, @, espaços {ISSO ATUALMENTE ELE LIMPA E NÃO DEIXA PASSAR}
- (tamanhos diferentes nas listas de obstaculos celula): [0,1,3] o outro [0,1,2,3,4,5]

====================================
Descrição visual do ambiente em formato de matriz
- 0 > Representa uma area vazia;
- 111 > Representa que a celula tem obstaculo
- 222 > representa o ponto de recarga/local inicial do robô.
- 88 > representa a posicao atual do robô
- 2 > Ambiente limpo
