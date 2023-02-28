===================================
UFPE - CTG

Programação avançada

===================================
Grupo:  Sanclay Augusto
        Emerson Guilherme

====================================
Arquivo de entrada:

    Os dados são identificados pelas tags e os valores são separados por virgulas.

    As tag são:

        oNumeroDeLinhas             //representa o numero de linhas do ambiente
        oNumeroDeColunas            //representa o numero de colunas do ambiente
        posicaoInicialX             //representa A posição inicial x do robô
        posicaoInicialY             //representa A posição inicial y do robô
        numObstaculoCelula          //Representa o numero de obstaculos celula que existem
        obstaculoCelulaX            //Coordenadas x do obstaculo celula
        obstaculoCelulaY            //Coordenadas y do obstaculo celula
        numObstaculoRetangulo       //Representa o numero de obstaculos retangulo que existem
        obstaculoRecInicial         //Coordenadas x y para o inicio do obstaculo triangulo
        obstaculoRecFinal           //Coordenadas x y para o fim do obstaculo triangulo
    
    Exemplo de entradas em um arquivo .txt

        oNumeroDeLinhas:8
        oNumeroDeColunas:8
        posicaoInicialX:0
        posicaoInicialY:0
        numObstaculoCelula:4
        obstaculoCelulaX:1,1,4,4,
        obstaculoCelulaY:1,2,3,4,
        numObstaculoRetangulo:1,
        obstaculoRecInicial:5,5,
        obstaculoRecFinal:7,7,

    OBS Arquivo entrada:
        Ao final das informações precisa da "," como mostrado.
        O nome do arquivo deve ser "entradas.txt"

OBS GEral:

    O modelo 2 não ficou completo.

====================================
Descrição visual do ambiente em formato de matriz
- 0 > Representa uma area vazia;
- 111 > Representa que a celula tem obstaculo
- 222 > representa o ponto de recarga/local inicial do robô.
- 200 > Representa area externa ao mapa
- 88 > representa a posicao atual do robô
- 1,2,3,... > Ambiente limpo.
