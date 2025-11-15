A ByteBros, desenvolvedora de jogos voltados para o ensino de lógica e programação, está desenvolvendo um novo título chamado Tetris Stack, um jogo eletrônico no qual os jogadores precisam organizar e posicionar peças utilizando estruturas de dados fundamentais como parte das mecânicas de jogo.

 

Designaram você como desenvolvedor(a) técnico(a) responsável pela estrutura de controle de peças do jogo, incluindo a implementação do sistema de fila de peças futuras. Seu trabalho é verificar se as regras de entrada, saída e troca entre as estruturas estão funcionando e se refletem a lógica do jogo.

 

Agora, você implementará um programa em C que simula a fila de peças futuras do Tetris Stack. As peças têm um tipo (como 'I', 'O', 'T', 'L’), que representa suas formas e um identificador numérico (id) exclusivo. O programa oferecerá ao jogador a opção de visualizar a fila, jogar uma peça (remoção da frente) ou adicionar uma nova peça ao final da fila.


Requisitos funcionais


Seu programa em C deverá:

 

Inicializar a fila de peças com um número fixo de elementos (por exemplo, 5).
 
Permitir as seguintes ações:
 

Jogar uma peça, isto é, remove a peça da frente da fila (dequeue).
 
Inserir nova peça ao final da fila (enqueue), se houver espaço.
 
Exibir o estado atual da fila após cada ação, mostrando o tipo (nome) e o id de cada peça.

Atributos das peças


Cada uma possui:
 

nome: caractere que representa o tipo da peça ('I', 'O', 'T', 'L').
 
id: número inteiro único que representa a ordem de criação da peça.
 
Lembre-se: as peças são geradas automaticamente por uma função chamada gerarPeca.
